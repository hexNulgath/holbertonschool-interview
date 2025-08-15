#!/usr/bin/python3
"""count.py"""
from collections import defaultdict
import requests


def count_words(
        subreddit, word_list, after=None, word_counts=None, access_token=None):
    """
    Recursively count keywords in hot post titles of a subreddit.

    Args:
        subreddit (str): The subreddit to search
        word_list (list): List of keywords to count
        after (str, optional): Reddit API pagination token
        word_counts (defaultdict, optional): Accumulated word counts
        access_token (str, optional): OAuth2 access token


    Returns:
        None: Prints results to stdout
    """
    # Initialize word_counts on first call
    if word_counts is None:
        word_counts = defaultdict(int)
        # Convert word_list to lowercase and remove duplicates
        word_list = [word.lower() for word in word_list]

    # Get OAuth token if we don't have one
    if access_token is None:
        auth = requests.auth.HTTPBasicAuth(
            'H8grgk6g5MGhFRutcE0vSA', 'PkvloyaALyYe4T9GFTBcdwZfpXEJPA')
        data = {'grant_type': 'client_credentials'}
        headers = {'User-Agent': 'Student_test'}

        try:
            response = requests.post(
                'https://www.reddit.com/api/v1/access_token',
                auth=auth, data=data, headers=headers
            )
            response.raise_for_status()
            access_token = response.json()['access_token']
        except Exception:
            return  # Invalid credentials or other error

    # Make API request for posts
    headers = {
        'User-Agent': 'count_words/0.1 by YOUR_USERNAME',
        'Authorization': f'bearer {access_token}'
    }
    params = {'limit': 100}
    if after:
        params['after'] = after

    try:
        response = requests.get(
            f'https://oauth.reddit.com/r/{subreddit}/hot',
            headers=headers,
            params=params,
            allow_redirects=False
        )

        # Handle 3XX redirects (invalid subreddits)
        if response.status_code >= 300 and response.status_code < 400:
            return

        response.raise_for_status()
        data = response.json()

        # Process posts
        for post in data['data']['children']:
            title = post['data']['title']
            for word in title.split():
                # Clean the word (remove punctuation and make lowercase)
                cleaned = ''.join(c for c in word if c.isalnum()).lower()
                if cleaned in word_list:
                    word_counts[cleaned] += 1

        # Recursively process next page if exists
        if data['data']['after']:
            return count_words(
                subreddit, word_list,
                data['data']['after'], word_counts, access_token
            )
        else:
            # No more posts, print results
            sorted_counts = sorted(
                word_counts.items(),
                key=lambda item: (-item[1], item[0])
            )
            for word, count in sorted_counts:
                print(f"{word}: {count}")

    except Exception:
        return
