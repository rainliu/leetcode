package main

import "fmt"

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)

	for j := 0; j < len(nums); j++ {
		if i, ok := m[nums[j]]; !ok {
			m[target-nums[j]] = j
		} else {
			return []int{i, j}
		}
	}
	return nil
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9
	fmt.Printf("%v\n", twoSum(nums, target))
}
