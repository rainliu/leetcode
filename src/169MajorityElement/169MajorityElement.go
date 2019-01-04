package main

import "fmt"

func partition(nums []int, lo, hi int) int {
	pilot := lo
	i := lo
	j := lo + 1
	for j <= hi {
		if nums[j] <= nums[pilot] {
			i++
			nums[i], nums[j] = nums[j], nums[i]
		}
		j++
	}
	nums[i], nums[pilot] = nums[pilot], nums[i]
	return i
}

func majorityElement1(nums []int) int {
	n := len(nums)
	lo := 0
	hi := n - 1
	k := lo + (hi-lo)/2
	for lo <= hi {
		pilot := partition(nums, lo, hi)
		if pilot == k {
			return nums[k]
		} else if pilot > k {
			hi = pilot - 1
		} else {
			lo = pilot + 1
		}
	}
	return nums[k]
}

func majorityElement(nums []int) int {
	m := make(map[int]int)
	n := len(nums)
	for i := 0; i < n; i++ {
		m[nums[i]]++
		if m[nums[i]] > (n >> 1) {
			return nums[i]
		}
	}
	return 0
}

func main() {
	nums := []int{-1, 100, 2, 100, 100, 4, 100}
	fmt.Printf("%v:%v\n", majorityElement(nums), nums)

}
