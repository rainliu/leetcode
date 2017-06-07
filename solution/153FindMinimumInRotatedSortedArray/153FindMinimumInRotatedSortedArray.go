package main

func findMin(nums []int) int {
	n := len(nums)
	lo := 0
	hi := n - 1
	for lo < hi {
		mi := lo + (hi-lo)/2
		if nums[mi] > nums[hi] {
			lo = mi + 1
		} else {
			hi = mi
		}
	}
	return nums[hi]
}

func main() {

}
