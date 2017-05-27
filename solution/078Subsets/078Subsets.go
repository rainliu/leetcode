package main

import "fmt"

func backtracking(nums []int, k, n int, a []bool, results [][]int) [][]int {
	if k == n-1 {
		var result []int
		for i := 0; i < n; i++ {
			if a[i] {
				result = append(result, nums[i])
			}
		}
		results = append(results, result)
	} else {
		k++
		cands := []bool{false, true}
		for i := 0; i < len(cands); i++ {
			a[k] = cands[i]
			results = backtracking(nums, k, n, a, results)
		}
	}
	return results
}

func subsets(nums []int) [][]int {
	var results [][]int
	a := make([]bool, len(nums))
	results = backtracking(nums, -1, len(nums), a, results)
	return results
}

func main() {
	fmt.Printf("%v\n", subsets([]int{1, 2, 3}))
}
