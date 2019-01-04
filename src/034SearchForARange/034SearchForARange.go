package main

import "fmt"

func binarySearch(nums []int, lo, hi, target int, left bool) (int, bool) {
	for lo <= hi {
		mi := lo + (hi-lo)/2
		if nums[mi] == target {
			return mi, true
		} else if nums[mi] > target {
			hi = mi - 1
		} else {
			lo = mi + 1
		}
	}
	if left {
		return lo, false
	} else {
		return hi, false
	}
}

func searchRange(nums []int, target int) []int {
	n := len(nums)
	lo := 0
	hi := n - 1
	mi, find := binarySearch(nums, lo, hi, target, false)
	if !find {
		return []int{-1, -1}
	}
	l := mi
	r := mi
	find = true
	for find {
		l, find = binarySearch(nums, lo, l-1, target, true)
	}
	find = true
	for find {
		r, find = binarySearch(nums, r+1, hi, target, false)
	}
	return []int{l, r}
}

func main() {
	fmt.Printf("%v\n", searchRange([]int{5, 7, 7, 8, 8, 10}, 8))
	fmt.Printf("%v\n", searchRange([]int{5, 7, 7, 8, 10}, 8))
	fmt.Printf("%v\n", searchRange([]int{5, 7, 7, 10}, 8))
}
