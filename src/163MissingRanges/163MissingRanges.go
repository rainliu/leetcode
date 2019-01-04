package main

import (
	"fmt"
	"strconv"
)

func findMissingRanges(nums []int, lower int, upper int) []string {
	n := len(nums)
	i := 0
	var diff int
	var result []string
	for i < n {
		if i == 0 {
			diff = nums[i] - lower
			if diff == 1 {
				result = append(result, strconv.Itoa(lower))
			} else if diff > 1 {
				result = append(result, strconv.Itoa(lower)+"->"+strconv.Itoa(nums[i]-1))
			}
		} else {
			diff = nums[i] - nums[i-1]
			if diff == 2 {
				result = append(result, strconv.Itoa(nums[i]-1))
			} else if diff > 2 {
				result = append(result, strconv.Itoa(nums[i-1]+1)+"->"+strconv.Itoa(nums[i]-1))
			}
		}
		i++
	}
	if i == 0 {
		if lower != upper {
			result = append(result, strconv.Itoa(lower)+"->"+strconv.Itoa(upper))
		} else {
			result = append(result, strconv.Itoa(lower))
		}
	} else {
		diff = upper - nums[i-1]
		if diff == 1 {
			result = append(result, strconv.Itoa(upper))
		} else if diff > 1 {
			result = append(result, strconv.Itoa(nums[i-1]+1)+"->"+strconv.Itoa(upper))
		}
	}

	return result
}

func main() {
	fmt.Printf("%v\n", findMissingRanges([]int{0, 1, 3, 50, 75}, 0, 99))
	fmt.Printf("%v\n", findMissingRanges([]int{0, 1, 3, 50, 75, 98}, 0, 99))
}
