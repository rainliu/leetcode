package main

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

			results = backtracking(candidates, a, target, i, sum, results)

			a = a[:len(a)-1]
			sum -= candidates[i]
		}
	}

	return results
}

func combinationSum(candidates []int, target int) [][]int {
	var results [][]int
	var a []int
	results = backtracking(candidates, a, target, 0, 0, results)
	return results
}

func main() {

}
