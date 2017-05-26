package main

import "fmt"

func plusOne(digits []int) []int {
	if digits == nil || len(digits) == 0 {
		return nil
	}
	n := len(digits)
	c := 1
	for i := n - 1; i >= 0; i-- {
		digits[i] += c
		c = digits[i] / 10
		digits[i] %= 10
	}
	if c != 0 {
		digits_c := make([]int, n+1)
		copy(digits_c[1:], digits)
		digits_c[0] = c
		return digits_c
	} else {
		return digits
	}
}

func main() {
	fmt.Printf("%v\n", plusOne([]int{0}))
	fmt.Printf("%v\n", plusOne([]int{9}))
	fmt.Printf("%v\n", plusOne([]int{1, 0}))
	fmt.Printf("%v\n", plusOne([]int{1, 9}))
	fmt.Printf("%v\n", plusOne([]int{9, 9, 9}))
}
