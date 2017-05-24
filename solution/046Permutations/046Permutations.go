package main

func contruct_cands(nums, a []int, k, n int) []int {
	perm := make([]bool, n)
	for i := 0; i < len(a); i++ {
		perm[a[i]] = true
	}
	var c []int
	for i := 0; i < n; i++ {
		if perm[i] == false {
			c = append(c, i)
		}
	}
	return c
}

func backtracking(nums, a []int, k, n int, results [][]int) [][]int {
	if k == n {
		result := make([]int, n)
		for i := 0; i < n; i++ {
			result[i] = nums[a[i]]
		}
		results = append(results, result)
	} else {
		k++
		c := contruct_cands(nums, a, k, n)
		for i := 0; i < len(c); i++ {
			a = append(a, c[i])
			results = backtracking(nums, a, k, n, results)
			a = a[0 : len(a)-1]
		}
	}

	return results
}

func permute(nums []int) [][]int {
	var results [][]int
	var a []int
	results = backtracking(nums, a, 0, len(nums), results)
	return results
}

func main() {

}
