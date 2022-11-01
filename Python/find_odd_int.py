"""
Find the odd int

Given an array of integers, find the one that appears an odd number of times.

There will always be only one integer that appears an odd number of times.
"""

from typing import List


def find_it(sequence: List[int]) -> List[int]:
    """Given an array, find the values that appear an odd number of times.

    Parameters
    -----------
    sequence: :class:`list`
        An array of values to search through.

    Returns a :class:`list` of the odd values.
    """

    return list(set([value for value
                     in sequence
                     if (sequence.count(value) % 2) != 0]))


if __name__ == '__main__':
    # Sample test cases:
    sample: List[int] = [1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5]
    print('Result of Sample #1:', find_it(sample))  # [-1]

    sample = [20, -1, 2, -2, 5, 5, 3, 3, 5, 5, 1, 2, 4, 4, 20, -1, -2]
    print('Result of Sample #2:', find_it(sample))  # [1]

