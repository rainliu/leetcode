package main

import "fmt"

func trailingZeroes(n int) int {
	sum := 0
	for n != 0 {
		sum += n / 5
		n /= 5
	}
	return sum
}

func main() {
	fmt.Printf("%v\n", trailingZeroes(1808548329))
	fmt.Printf("%v\n", trailingZeroes(100))
}
