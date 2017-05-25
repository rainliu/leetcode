package main

import "fmt"

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

func backtracking(nums, a []int, k, n int, target *int) string {
	var result string
	if k == n {
		*target = *target - 1
		r := make([]byte, n)
		for i := 0; i < n; i++ {
			r[i] = byte(nums[a[i]]) + '0'
		}
		result = string(r)
	} else {
		k++
		c := contruct_cands(nums, a, k, n)
		for i := 0; i < len(c); i++ {
			a = append(a, c[i])
			result = backtracking(nums, a, k, n, target)
			if *target == 0 {
				break
			}
			a = a[0 : len(a)-1]
		}
	}
	return result
}

//this backtracking solution Timeout for getPermutation(9, 161191)
func getPermutation(n int, k int) string {
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i] = i + 1
	}
	var a []int
	return backtracking(nums, a, 0, n, &k)
}

func main() {
	fmt.Printf("%s\n", getPermutation(3, 1))
	fmt.Printf("%s\n", getPermutation(3, 2))
	fmt.Printf("%s\n", getPermutation(3, 3))
	fmt.Printf("%s\n", getPermutation(3, 4))
	fmt.Printf("%s\n", getPermutation(9, 161191))
}
