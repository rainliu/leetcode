package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	m := make(map[byte]int)
	i := -1
	j := 0
	l := 0
	for j < len(s) {
		if k, ok := m[s[j]]; ok {
			if j-1-i > l {
				l = j - 1 - i
			}
			for n := i + 1; n <= k; n++ {
				delete(m, s[n])
			}
			i = k
		}
		m[s[j]] = j

		j++
	}
	if j-1-i > l {
		l = j - 1 - i
	}
	return l
}

func main() {
	fmt.Printf("%v\n", lengthOfLongestSubstring("abcabcbb"))
	fmt.Printf("%v\n", lengthOfLongestSubstring("bbbbb"))
	fmt.Printf("%v\n", lengthOfLongestSubstring("pwwkew"))
	fmt.Printf("%v\n", lengthOfLongestSubstring("abcabcde"))
}
