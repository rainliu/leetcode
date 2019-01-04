package main

import "fmt"

func backtracking(n int, target int, k int, results [][]int, a []bool) [][]int {
	if k == n-1 {
		c := 0
		for i := 0; i < n; i++ {
			if a[i] {
				c++
			}
		}
		if c == target {
			result := make([]int, target)
			c = 0
			for i := 0; i < n; i++ {
				if a[i] {
					result[c] = i + 1
					c++
				}
			}
			results = append(results, result)
		}
	} else {
		k++
		cands := []bool{false, true}
		for i := 0; i < len(cands); i++ {
			a[k] = cands[i]
			results = backtracking(n, target, k, results, a)
		}
	}
	return results
}
func combine(n int, k int) [][]int {
	var results [][]int
	a := make([]bool, n)
	results = backtracking(n, k, -1, results, a)
	return results
}

func main() {
	fmt.Printf("%v\n", combine(4, 2))
}
