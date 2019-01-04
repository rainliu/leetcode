package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) [][]int {
	n := len(nums)
	if n < 3 {
		return nil
	}
	sort.Ints(nums)
	var r [][]int
	for k := 0; k < n-2; k++ {
		i := k + 1
		j := n - 1
		target := -nums[k]
		for i < j {
			if nums[i]+nums[j] == target {
				r = append(r, []int{nums[k], nums[i], nums[j]})
				for i < j && nums[i] == nums[i+1] {
					i++
				}
				i++
				for i < j && nums[j-1] == nums[j] {
					j--
				}
				j--
			} else if nums[i]+nums[j] < target {
				for i < j && nums[i] == nums[i+1] {
					i++
				}
				i++
			} else {
				for i < j && nums[j-1] == nums[j] {
					j--
				}
				j--
			}
		}
		for k < n-2 && nums[k] == nums[k+1] {
			k++
		}
	}
	return r
}

func main() {
	fmt.Printf("%v\n", threeSum([]int{
		-1, 0, 1, 1, 2, 2, -1, -4,
	}))
	fmt.Printf("%v\n", threeSum([]int{
		-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6,
	}))
}
