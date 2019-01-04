package main

import (
	"fmt"
)

func isPalindrome(s string) bool {
	lo := 0
	hi := len(s) - 1
	for lo <= hi {
		if s[lo] != s[hi] {
			return false
		} else {
			lo++
			hi--
		}
	}
	return true
}
func backtracking(s string, results [][]string, result []string) [][]string {
	if s == "" {
		r := make([]string, len(result))
		copy(r, result)
		results = append(results, r)
	} else {
		for k := 1; k <= len(s); k++ {
			if isPalindrome(s[:k]) {
				result = append(result, s[:k])
				results = backtracking(s[k:], results, result)
				result = result[:len(result)-1]
			}
		}
	}
	return results
}

func partition(s string) [][]string {
	var results [][]string
	var result []string
	results = backtracking(s, results, result)
	return results
}

func main() {
	fmt.Printf("%v\n", partition("aabcbaa"))
}
