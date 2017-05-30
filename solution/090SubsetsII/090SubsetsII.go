package main

import (
	"fmt"
	"sort"
)

func backtracking(nums []int, k, n int, a []int, results [][]int) [][]int {
	for i := k; i < n; i++ {
		a = append(a, nums[i])
		result := make([]int, len(a))
		copy(result, a)
		results = append(results, result)
		results = backtracking(nums, i+1, n, a, results)
		a = a[:len(a)-1]
		for i+1 < n && nums[i+1] == nums[i] {
			i++
		}
	}
	return results
}

func subsetsWithDup(nums []int) [][]int {
	var results [][]int
	var a, result []int
	sort.Ints(nums)
	results = append(results, result)
	results = backtracking(nums, 0, len(nums), a, results)
	return results
}

func main() {
	fmt.Printf("%v\n", subsetsWithDup([]int{1, 2, 2}))
}
