package main

func maxArea(height []int) int {
	n := len(height)
	i := 0
	j := n - 1
	var low, area int
	for i < j {
		if height[i] <= height[j] {
			low = height[i]
		} else {
			low = height[j]
		}
		if low*(j-i) > area {
			area = low * (j - i)
		}
		if height[i] <= height[j] {
			i++
		} else {
			j--
		}
	}

	return area
}

func main() {

}
