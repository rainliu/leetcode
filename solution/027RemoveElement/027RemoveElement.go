package main

import "fmt"

func removeElement(nums []int, val int) int {
	i := len(nums) - 1
	j := len(nums) - 1
	for j >= 0 {
		if nums[j] == val {
			nums[j], nums[i] = nums[i], nums[j]
			i--
		}
		j--
	}
	return i + 1
}

func main() {
	nums := []int{3, 2, 2, 3, 1}
	fmt.Printf("%v\n", nums[:removeElement(nums, 3)])
}
