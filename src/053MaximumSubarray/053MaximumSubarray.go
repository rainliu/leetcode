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
		//local optimal must contain nums[i]
		//so, if local<0, then only nums[i], otherwise nums[i]+local
		local = max(nums[i], nums[i]+local)
		global = max(global, local)
	}
	return global
}

func main() {
	fmt.Printf("%v\n", maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}))
}
