package main

import "fmt"

func max3(a, b, c int) int {
	if a >= b && a >= c {
		return a
	} else if b >= a && b >= c {
		return b
	} else {
		return c
	}
}
func min3(a, b, c int) int {
	if a <= b && a <= c {
		return a
	} else if b <= a && b <= c {
		return b
	} else {
		return c
	}
}
func maxProduct(nums []int) int {
	n := len(nums)
	localMax := nums[0]
	localMin := nums[0]
	global := nums[0]
	for i := 1; i < n; i++ {
		tmp := max3(nums[i], nums[i]*localMax, nums[i]*localMin)
		localMin = min3(nums[i], nums[i]*localMax, nums[i]*localMin)
		localMax = tmp
		if localMax > global {
			global = localMax
		}
		//fmt.Printf("(%d,%d,%d) ", localMax, localMin, global)
	}
	return global
}

func main() {
	fmt.Printf("=%v\n", maxProduct([]int{2, -5, -2, -4, 3}))
	fmt.Printf("=%v\n", maxProduct([]int{-2, 1, 2, -2, 3, -3}))
	fmt.Printf("%v\n", maxProduct([]int{2, 3, -2, 4}))
	fmt.Printf("%v\n", maxProduct([]int{2, 3, -2, -4}))
}
