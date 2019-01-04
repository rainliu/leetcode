package main

import "fmt"

func removeDuplicates(nums []int) int {
	n := len(nums)
	if n <= 2 {
		return n
	}
	i := 0
	j := 1
	c := 1
	for j < n {
		if nums[i] == nums[j] {
			if c < 2 {
				nums[i+1], nums[j] = nums[j], nums[i+1]
				c++
				i++
			}
			j++
		} else {
			nums[i+1], nums[j] = nums[j], nums[i+1]
			i++
			j++
			c = 1
		}
	}
	return i + 1
}

func main() {
	nums := []int{1, 1, 1, 2, 2, 3}
	fmt.Printf("%v\n", nums[0:removeDuplicates(nums)])

	nums = []int{1, 2, 3, 2, 2, 2, 2, 3, 1, 3, 3}
	fmt.Printf("%v\n", nums[0:removeDuplicates(nums)])
}
