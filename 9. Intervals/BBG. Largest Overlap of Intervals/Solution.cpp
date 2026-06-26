#include <vector>

struct Interval
{
    int start;
    int end;
    Interval(int start, int end) : start(start), end(end) {}
};
    
int largest_overlap_of_intervals(std::vector<Interval> intervals)
{
    std::vector<std::pair<int, char>> events;

    for (Interval& interval : intervals)
    {
        events.push_back(std::make_pair(interval.start, 's'));
        events.push_back(std::make_pair(interval.end, 'e'));
    }
    std::sort(events.begin(), events.end());

    int largestOverlap {0};
    int currOverlap {0};

    for (auto& [_, e] : events)
        if (e == 's')
        {
            ++currOverlap;
        }
        else
        {
            --currOverlap;
        }
        
        largestOverlap = std::max(largestOverlap, currOverlap);

    return largestOverlap;
}