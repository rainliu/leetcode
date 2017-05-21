package main

import "fmt"
import "math"

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func divide(dividend int, divisor int) int {
	if divisor == 0 {
		return math.MaxInt32
	} else if divisor == 1 {
		return dividend
	} else if dividend == math.MinInt32 || divisor == math.MinInt32 {
		if dividend == math.MinInt32 && divisor == math.MinInt32 {
			return 1
		} else if dividend == math.MinInt32 {
			if divisor == -1 {
				return math.MaxInt32
			}
		} else { //if divisor == math.MinInt32 {
			return 0
		}
	} else if abs(dividend) < abs(divisor) {
		return 0
	}
	sign := false
	if (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) {
		sign = true
	}
	dividend = abs(dividend)
	divisor = abs(divisor)
	result := 0
	for dividend >= divisor {
		n := uint(1)
		for divisor <= dividend>>n {
			n++
		}
		if n >= 1 {
			result += 1 << (n - 1)
			dividend -= divisor << (n - 1)
		}
	}
	if sign {
		return -result
	}
	return result
}

func main() {
	fmt.Printf("%v\n", divide(math.MinInt32, -1))
	fmt.Printf("%v\n", divide(100, 0))
	fmt.Printf("%v\n", divide(100, 1))
	fmt.Printf("%v\n", divide(100, 2))
	fmt.Printf("%v\n", divide(100, 3))
	fmt.Printf("%v\n", divide(100, 33))
	fmt.Printf("%v\n", divide(100, 50))
	fmt.Printf("%v\n", divide(100, 100))
	fmt.Printf("%v\n", divide(100, 101))
}
