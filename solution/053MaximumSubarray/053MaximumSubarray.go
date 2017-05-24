package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	local := nums[0]
	global := nums[0]
	for i := 1; i < len(nums); i++ {
		local = max(nums[i], local+nums[i])
		global = max(local, global)
	}
	return global
}

func main() {
	fmt.Printf("%v\n", maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}))
}
