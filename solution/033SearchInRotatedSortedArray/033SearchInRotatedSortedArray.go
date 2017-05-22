package main

import "fmt"

func search(nums []int, target int) int {
	n := len(nums)
	lo := 0
	hi := n - 1
	for lo <= hi {
		mi := lo + (hi-lo)/2
		if nums[mi] == target {
			return mi
		} else if nums[mi] >= nums[hi] {
			if nums[mi] > target && nums[lo] <= target {
				hi = mi - 1
			} else {
				lo = mi + 1
			}
		} else {
			if nums[mi] < target && nums[hi] >= target {
				lo = mi + 1
			} else {
				hi = mi - 1
			}
		}
	}

	return -1
}

func main() {
	fmt.Printf("%v\n", search([]int{4, 5, 6, 7, 0, 1, 2}, 3))
	fmt.Printf("%v\n", search([]int{4, 5, 6, 7, 0, 1, 2}, 4))
	fmt.Printf("%v\n", search([]int{4, 5, 6, 7, 0, 1, 2}, 7))
}
