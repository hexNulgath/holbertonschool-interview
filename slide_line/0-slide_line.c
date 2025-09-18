#include "slide_line.h"
#include <stddef.h> /* For size_t */

/* Helper function prototypes */
static int slide_left(int *line, size_t size);
static int slide_right(int *line, size_t size);

/**
 * slide_line - Slides and merges an array of integers like 2048
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);

    return 1;
}

/**
 * slide_left - Slides and merges array to the left
 * @line: Pointer to the array
 * @size: Number of elements
 * Return: 1 if line was changed, 0 otherwise
 */
static int slide_left(int *line, size_t size)
{
    size_t i, pos = 0;
    int changed = 0;

    /* Slide all numbers to the left */
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (pos != i)
            {
                line[pos] = line[i];
                line[i] = 0;
                changed = 1;
            }
            pos++;
        }
    }

    /* Merge adjacent equal numbers */
    for (i = 0; i < size - 1; i++)
    {
        if (line[i] == line[i + 1] && line[i] != 0)
        {
            line[i] *= 2;
            line[i + 1] = 0;
            changed = 1;
            i++; /* Skip next element as it's now 0 */
        }
    }

    /* Slide again to fill any gaps created by merging */
    pos = 0;
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (pos != i)
            {
                line[pos] = line[i];
                line[i] = 0;
                changed = 1;
            }
            pos++;
        }
    }

    return changed;
}

/**
 * slide_right - Slides and merges array to the right
 * @line: Pointer to the array
 * @size: Number of elements
 * Return: 1 if line was changed, 0 otherwise
 */
static int slide_right(int *line, size_t size)
{
    int i, pos = size - 1;
    int changed = 0;

    /* Slide all numbers to the right */
    for (i = size - 1; i >= 0; i--)
    {
        if (line[i] != 0)
        {
            if (pos != i)
            {
                line[pos] = line[i];
                line[i] = 0;
                changed = 1;
            }
            pos--;
        }
    }

    /* Merge adjacent equal numbers */
    for (i = size - 1; i > 0; i--)
    {
        if (line[i] == line[i - 1] && line[i] != 0)
        {
            line[i] *= 2;
            line[i - 1] = 0;
            changed = 1;
            i--; /* Skip previous element as it's now 0 */
        }
    }

    /* Slide again to fill any gaps created by merging */
    pos = size - 1;
    for (i = size - 1; i >= 0; i--)
    {
        if (line[i] != 0)
        {
            if (pos != i)
            {
                line[pos] = line[i];
                line[i] = 0;
                changed = 1;
            }
            pos--;
        }
    }

    return changed;
}