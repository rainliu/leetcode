package main

import (
	"fmt"
	"math"
	"sort"
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func threeSumClosest(nums []int, target int) int {
	n := len(nums)
	if n < 3 {
		return 0
	}
	sort.Ints(nums)
	targetdiff := math.MaxInt32
	targetclosest := target
	for k := 0; k < n-2; k++ {
		i := k + 1
		j := n - 1
		target2 := target - nums[k]
		for i < j {
			if nums[i]+nums[j] == target2 {
				return target
			} else if nums[i]+nums[j] < target2 {
				if abs(nums[i]+nums[j]+nums[k]-target) < targetdiff {
					targetclosest = nums[i] + nums[j] + nums[k]
					targetdiff = abs(targetclosest - target)
				}
				i++
			} else {
				if abs(nums[i]+nums[j]+nums[k]-target) < targetdiff {
					targetclosest = nums[i] + nums[j] + nums[k]
					targetdiff = abs(targetclosest - target)
				}
				j--
			}
		}
	}
	return targetclosest
}

func main() {
	fmt.Printf("%d\n", threeSumClosest([]int{-1, 2, 1, -4, 3, 2, 43, 1, -34}, 1))
}
