package main

import "fmt"
import "math"

func abs(a int) int64 {
	if a < 0 {
		return -int64(a)
	}
	return int64(a)
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
	dividend2 := abs(dividend)
	divisor2 := abs(divisor)
	result := 0
	for dividend2 >= divisor2 {
		n := uint(1)
		for divisor2 <= dividend2>>n {
			n++
		}
		if n >= 1 {
			result += 1 << (n - 1)
			dividend2 -= divisor2 << (n - 1)
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
