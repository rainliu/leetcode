package main

import (
	"math"
)

func findPeakElement(nums []int) int {
	n := len(nums)
	global := math.MinInt32
	index := 0
	var left, right int
	for i := 0; i < n; i++ {
		if i == 0 {
			left = math.MinInt32
		} else {
			left = nums[i-1]
		}
		if i == n-1 {
			right = math.MinInt32
		} else {
			right = nums[i+1]
		}
		if nums[i] >= left && nums[i] >= right && nums[i] > global {
			global = nums[i]
			index = i
		}
	}
	return index
}

func main() {

}
