package main

import "fmt"

func search(nums []int, target int) bool {
	n := len(nums)
	if n == 0 {
		return false
	}
	lo := 0
	hi := n - 1
	for lo < hi && nums[lo] == nums[hi] {
		hi--
	}
	for lo < hi && nums[lo] == nums[lo+1] {
		lo++
	}
	for lo < hi && nums[hi-1] == nums[hi] {
		hi--
	}
	for lo <= hi {
		mi := lo + (hi-lo)/2
		if nums[mi] == target {
			return true
		} else if nums[mi] >= nums[hi] {
			if target >= nums[lo] && target < nums[mi] {
				hi = mi - 1
			} else {
				lo = mi + 1
			}
		} else {
			if target > nums[mi] && target <= nums[hi] {
				lo = mi + 1
			} else {
				hi = mi - 1
			}
		}

		for lo < hi && nums[lo] == nums[hi] {
			hi--
		}
		for lo < hi && nums[lo] == nums[lo+1] {
			lo++
		}
		for lo < hi && nums[hi-1] == nums[hi] {
			hi--
		}
	}
	return false
}

func main() {
	fmt.Printf("%v\n", search([]int{5, 1, 3}, 3))
	fmt.Printf("%v\n", search([]int{1, 0, 0, 0, 1}, 1))
	fmt.Printf("%v\n", search([]int{4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 0, 1, 1, 1, 2}, 7))
	fmt.Printf("%v\n", search([]int{4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 0, 1, 1, 1, 2}, 3))
	fmt.Printf("%v\n", search([]int{0, 0, 1, 1, 1, 24, 4, 5, 5, 5, 6, 6, 6, 7}, 3))
	fmt.Printf("%v\n", search([]int{0, 0, 1, 1, 1, 24, 4, 5, 5, 5, 6, 6, 6, 7}, 7))
}
