package main

import "fmt"

func searchInsert(nums []int, target int) int {
	n := len(nums)
	lo := 0
	hi := n - 1
	for lo <= hi {
		mi := lo + (hi-lo)/2
		if nums[mi] == target {
			return mi
		} else if nums[mi] > target {
			hi = mi - 1
		} else {
			lo = mi + 1
		}
	}
	return lo
}

func main() {
	fmt.Printf("%d\n", searchInsert([]int{1, 3, 5, 6}, 5))
	fmt.Printf("%d\n", searchInsert([]int{1, 3, 5, 6}, 2))
	fmt.Printf("%d\n", searchInsert([]int{1, 3, 5, 6}, 7))
	fmt.Printf("%d\n", searchInsert([]int{1, 3, 5, 6}, 0))
}
