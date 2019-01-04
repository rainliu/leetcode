package main

import "sort"

func backtracking(candidates, a []int, target, k, sum int, results [][]int) [][]int {
	if sum > target {
		//do nothing
	} else if sum == target {
		result := make([]int, len(a))
		copy(result, a)
		results = append(results, result)
	} else {
		for i := k; i < len(candidates); i++ {
			sum += candidates[i]
			a = append(a, candidates[i])

			results = backtracking(candidates, a, target, i+1, sum, results)

			a = a[:len(a)-1]
			sum -= candidates[i]

			for i+1 < len(candidates) && candidates[i+1] == candidates[i] {
				i++
			}
		}
	}

	return results
}

func combinationSum2(candidates []int, target int) [][]int {
	var results [][]int
	var a []int
	sort.Ints(candidates)
	results = backtracking(candidates, a, target, 0, 0, results)
	return results
}

func main() {

}
