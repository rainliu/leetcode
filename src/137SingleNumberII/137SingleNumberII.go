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

func singleNumber(nums []int) int {
	n := len(nums)
	one1 := 0
	two1 := 0
	thr1 := 0
	for i := 0; i < n; i++ {
		two1 |= one1 & nums[i]
		one1 ^= nums[i]
		thr1 = two1 & one1
		one1 = one1 &^ thr1
		two1 = two1 &^ thr1
	}
	return one1
}

func main() {

}
