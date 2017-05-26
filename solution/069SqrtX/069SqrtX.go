package main

import (
	"fmt"
	"math"
)

func mySqrt(x int) int {
	if x < 0 {
		return math.MinInt32
	} else if x == 0 {
		return 0
	}
	lo := 1
	hi := (x >> 1)
	for lo <= hi {
		mi := lo + (hi-lo)/2
		if mi <= x/mi && mi >= x/(mi+1) {
			return mi
		} else if mi > x/mi {
			hi = mi - 1
		} else {
			lo = mi + 1
		}
	}

	return lo
}

func main() {
	fmt.Printf("%d\n", mySqrt(-1))
	fmt.Printf("%d\n", mySqrt(0))
	fmt.Printf("%d\n", mySqrt(1))
	fmt.Printf("%d\n", mySqrt(2))
	fmt.Printf("%d\n", mySqrt(3))
	fmt.Printf("%d\n", mySqrt(4))
	fmt.Printf("%d\n", mySqrt(5))
	fmt.Printf("%d\n", mySqrt(9))
	fmt.Printf("%d\n", mySqrt(15))
	fmt.Printf("%d\n", mySqrt(16))
}
