package main

func sortColors(nums []int) {
	n := len(nums)
	if n <= 1 {
		return
	}
	i := 0
	j := n - 1
	k := 0
	for k <= j {
		if nums[k] < 1 {
			nums[i], nums[k] = nums[k], nums[i]
			i++
		} else if nums[k] > 1 {
			nums[j], nums[k] = nums[k], nums[j]
			j--
		} else {
			k++
		}
	}
}

func main() {

}
