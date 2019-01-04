package main

import (
	"fmt"
	"sort"
)

/**
 * Definition for an interval.
 */
type Interval struct {
	Start int
	End   int
}

type ByStart []Interval

func (a ByStart) Len() int           { return len(a) }
func (a ByStart) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByStart) Less(i, j int) bool { return a[i].Start < a[j].Start }

func merge(intervals []Interval) []Interval {
	if len(intervals) == 0 {
		return nil
	}
	sort.Sort(ByStart(intervals))

	results := make([]Interval, 1)
	results[0] = intervals[0]
	for i := 1; i < len(intervals); i++ {
		last := len(results) - 1
		if intervals[i].Start >= results[last].Start &&
			intervals[i].Start <= results[last].End {
			if results[last].End < intervals[i].End {
				results[last].End = intervals[i].End
			}
		} else {
			results = append(results, intervals[i])
		}
	}
	return results
}

func main() {
	intervals := []Interval{
		{2, 6},
		{1, 3},
		{3, 4},
		{15, 18},
		{8, 10},
	}
	fmt.Printf("%v\n", merge(intervals))
}
