package main

import (
	"fmt"
	"math"
)

func reverse(x int) int {
	y := 0
	for x != 0 {
		d := x - (x/10)*10
		if (x > 0 && y > math.MaxInt32/10) || (x < 0 && y < math.MinInt32/10) {
			return 0
		}
		y = y*10 + d
		x /= 10
	}
	return y
}

func main() {
	fmt.Printf("%d\n", reverse(123))
	fmt.Printf("%d\n", reverse(-123))
	fmt.Printf("%d\n", reverse(-1<<31))
	fmt.Printf("%d\n", reverse(1<<31-1))
	fmt.Printf("%d\n", reverse(2463847412))
	fmt.Printf("%d\n", reverse(-2463847412))
	fmt.Printf("%d\n", reverse(-2663847412))
}
