package main

func reverse(nums []int, lo, hi int) {
	for lo <= hi {
		nums[lo], nums[hi] = nums[hi], nums[lo]
		lo++
		hi--
	}
}
func rotate(nums []int, k int) {
	n := len(nums)
	if n == 0 {
		return
	}
	k = ((k % n) + n) % n
	if k == 0 {
		return
	}
	reverse(nums, 0, n-1-k)
	reverse(nums, n-k, n-1)
	reverse(nums, 0, n-1)
}

func main() {

}
