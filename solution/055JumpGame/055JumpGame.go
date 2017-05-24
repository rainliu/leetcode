package main

import "fmt"

func canJump(nums []int) bool {
	n := len(nums)
	i := 0
	for i < n-1 {
		if nums[i] == 0 {
			return false
		}
		k := i
		m := i
		for j := 1; j <= nums[i]; j++ {
			if i+j >= n-1 {
				return true
			} else if i+j+nums[i+j] > k {
				k = i + j + nums[i+j]
				m = i + j
			}
		}
		i = m
	}
	return i >= n-1
}

func main() {
	fmt.Printf("true  vs %v\n", canJump([]int{0}))
	fmt.Printf("true  vs %v\n", canJump([]int{1}))
	fmt.Printf("true  vs %v\n", canJump([]int{1, 2}))
	fmt.Printf("true  vs %v\n", canJump([]int{2, 0}))
	fmt.Printf("false vs %v\n", canJump([]int{1, 0, 2}))
	fmt.Printf("true  vs %v\n", canJump([]int{2, 3, 1, 1, 4}))
	fmt.Printf("false vs %v\n", canJump([]int{3, 2, 1, 0, 4}))
	fmt.Printf("true  vs %v\n", canJump([]int{1, 1, 2, 2, 0, 1, 1}))
	fmt.Printf("true  vs %v\n", canJump([]int{5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0}))
}
