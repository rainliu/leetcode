package main

import "fmt"

func wordBreak(s string, wordDict []string) bool {
	n := len(wordDict)
	m := make(map[string]struct{})
	for k := 0; k < n; k++ {
		m[wordDict[k]] = struct{}{}
	}
	l := len(s)
	E := make([]bool, l+1)
	for i := 1; i < l+1; i++ {
		if _, ok := m[s[:i]]; ok {
			E[i] = true
		} else {
			for j := 1; j < i; j++ {
				if _, ok := m[s[j:i]]; ok && E[j] {
					E[i] = true
					break
				}
			}
		}
	}
	return E[l]
}

func main() {
	fmt.Printf("%v\n", wordBreak("leetcode", []string{"leex", "code"}))
}
