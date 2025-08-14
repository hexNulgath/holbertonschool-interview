#!/usr/
"""count.py"""
import praw
from collections import defaultdict


def count_words(subreddit, word_list, after=None, word_counts=None):
    # Initialize word_counts on first call
    if word_counts is None:
        word_counts = defaultdict(int)
        # Convert word_list to lowercase and remove duplicates
        word_list = [word.lower() for word in word_list]

    # Create Reddit instance
    reddit = praw.Reddit(
        client_id='H8grgk6g5MGhFRutcE0vSA',
        client_secret='PkvloyaALyYe4T9GFTBcdwZfpXEJPA',
        user_agent='count_words/0.1 by YOUR_USERNAME'
    )

    try:
        # Get hot posts for the subreddit
        sub = reddit.subreddit(subreddit)
        posts = sub.hot(limit=100, params={'after': after} if after else None)

        # Process each post's title
        for post in posts:
            title_words = post.title.split()
            for word in title_words:
                # Clean the word (remove punctuation and make lowercase)
                cleaned = ''.join(c for c in word if c.isalnum()).lower()
                if cleaned in word_list:
                    word_counts[cleaned] += 1

        # Check if there are more posts to process
        if hasattr(posts, '_listing') and hasattr(
                posts._listing, 'after') and posts._listing.after:
            return count_words(
                subreddit, word_list, posts._listing.after, word_counts)
        else:
            # No more posts, print results
            sorted_counts = sorted(
                word_counts.items(),
                key=lambda item: (-item[1], item[0])
            )
            for word, count in sorted_counts:
                print(f"{word}: {count}")

    except Exception as e:
        # Invalid subreddit or other error - print nothing
        return
