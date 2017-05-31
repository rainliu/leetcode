package main

import (
	"fmt"
	"strconv"
)

func backtracking(s string, n int, result string, results []string) []string {
	if n == 4 {
		if s == "" {
			results = append(results, result)
		}
	} else {
		var l int
		if len(s) > 4 {
			l = 4
		} else {
			l = len(s) + 1
		}
		for k := 1; k < l; k++ {
			ss := s[:k]
			val, err := strconv.Atoi(ss)
			if err != nil {
				continue
			} else if val > 255 || k != len(strconv.Itoa(val)) {
				continue
			}
			if n == 0 {
				results = backtracking(s[k:], n+1, ss, results)
			} else {
				results = backtracking(s[k:], n+1, result+"."+ss, results)
			}
		}
	}

	return results
}

func restoreIpAddresses(s string) []string {
	var results []string
	results = backtracking(s, 0, "", results)
	return results
}

func main() {
	fmt.Printf("%v\n", restoreIpAddresses("25525511135"))
	fmt.Printf("%v\n", restoreIpAddresses("2552501135"))
}
