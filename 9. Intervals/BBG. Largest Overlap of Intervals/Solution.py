from typing import List

class Interval:
    def __init__(self, start: int, end: int):
        self.start = start
        self.end = end


def largest_overlap_of_intervals(intervals: List[Interval]) -> int:
    sweeping_line = []

    for interval in intervals:
        sweeping_line.append((interval.start, 's'))
        sweeping_line.append((interval.end, 'e'))

    sweeping_line.sort()

    largest_overlap = 0
    curr_overlap = 0

    for _, char in sweeping_line:
        if char == 's':
            curr_overlap += 1
        else:
            curr_overlap -= 1
        
        largest_overlap = max(largest_overlap, curr_overlap)

    return largest_overlap