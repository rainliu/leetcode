package main

func singleNumber(nums []int) int {
	n := len(nums)
	count := make(map[int]int)
	for i := 0; i < n; i++ {
		count[nums[i]] = count[nums[i]] + 1
	}
	for key, value := range count {
		if value == 1 {
			return key
		}
	}
	return 0
}

func main() {

}
