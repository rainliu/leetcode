package main

import (
	"fmt"
	"sort"
)

type sortRunes []rune

func (s sortRunes) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s sortRunes) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s sortRunes) Len() int {
	return len(s)
}

func SortString(s string) string {
	r := []rune(s)
	sort.Sort(sortRunes(r))
	return string(r)
}

func groupAnagrams(strs []string) [][]string {
	var results [][]string
	m := make(map[string]int)
	for j := 0; j < len(strs); j++ {
		s := SortString(strs[j])
		if i, ok := m[s]; ok {
			results[i] = append(results[i], strs[j])
		} else {
			results = append(results, []string{strs[j]})
			m[s] = len(results) - 1
		}
	}
	return results
}

func main() {
	fmt.Printf("%v\n", groupAnagrams([]string{"eat", "tea", "tan", "ate", "nat", "bat"}))
}
