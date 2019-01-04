package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int, t int) [][]int {
	var r [][]int
	n := len(nums)
	for k := 0; k < n-2; k++ {
		i := k + 1
		j := n - 1
		target := t - nums[k]
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

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	var r4 [][]int
	n := len(nums)
	for k := n - 1; k >= 3; k-- {
		r3 := threeSum(nums[:k], target-nums[k])
		if r3 != nil {
			for i := 0; i < len(r3); i++ {
				r4 = append(r4, []int{r3[i][0], r3[i][1], r3[i][2], nums[k]})
			}
		}
		for k >= 3 && nums[k] == nums[k-1] {
			k--
		}
	}
	return r4
}

func main() {
	fmt.Printf("%v\n", fourSum([]int{1, 0, -1, 0, -2, 2}, 0))
}
