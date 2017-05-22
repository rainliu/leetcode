package main

import (
	"fmt"
	"sort"
)

func nextPermutation(nums []int) {
	n := len(nums)
	if n <= 1 {
		return
	}
	i := n - 2
	j := n - 1
	for i >= 0 {
		if nums[i] < nums[j] {
			break
		}
		i--
		j--
	}
	if i >= 0 {
		k := n - 1
		for k >= j {
			if nums[i] >= nums[k] {
				k--
			} else {
				nums[i], nums[k] = nums[k], nums[i]
				break
			}
		}
	}
	sort.Ints(nums[j:])
}

func main() {
	nums0 := []int{1, 3, 2}
	nextPermutation(nums0)
	fmt.Printf("%v\n", nums0)

	nums1 := []int{1, 2, 3}
	nextPermutation(nums1)
	fmt.Printf("%v\n", nums1)

	nums2 := []int{3, 2, 1}
	nextPermutation(nums2)
	fmt.Printf("%v\n", nums2)

	nums3 := []int{1, 1, 5}
	nextPermutation(nums3)
	fmt.Printf("%v\n", nums3)

	nums4 := []int{1, 3, 0}
	nextPermutation(nums4)
	fmt.Printf("%v\n", nums4)

	nums5 := []int{6, 9, 8, 7, 3, 2, 1}
	nextPermutation(nums5)
	fmt.Printf("%v\n", nums5)
}
