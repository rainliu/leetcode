package main

func singleNumber(nums []int) int {
	n := len(nums)
	e := nums[0]
	for i := 1; i < n; i++ {
		e ^= nums[i]
	}
	return e
}

func main() {

}
