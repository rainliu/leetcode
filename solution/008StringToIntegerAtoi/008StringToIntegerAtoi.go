package main

import "fmt"
import "math"

func myAtoi(str string) int {
	n := len(str)
	var sign bool
	i := 0
	for i < n && str[i] == ' ' {
		i++
	}
	if i < n && (str[i] == '+' || str[i] == '-') {
		if str[i] == '-' {
			sign = true
		}
		i++
	}

	val := 0
	for i < n && str[i] >= '0' && str[i] <= '9' {
		d := int(str[i] - '0')
		if (sign && (val > math.MaxInt32/10 || (val == math.MaxInt32/10 && d >= 7))) ||
			(!sign && (val > math.MaxInt32/10 || (val == math.MaxInt32/10 && d >= 8))) {
			if sign {
				return math.MinInt32
			} else {
				return math.MaxInt32
			}
		}
		val = val*10 + d
		i++
	}

	if sign {
		return -val
	} else {
		return val
	}
}

func main() {
	fmt.Printf("%d\n", myAtoi(""))
	fmt.Printf("%d\n", myAtoi("  +120  "))
	fmt.Printf("%d\n", myAtoi("  -120  "))
	fmt.Printf("%d\n", myAtoi("  -120w  "))
	fmt.Printf("%d\n", myAtoi("  -2147483648  "))
	fmt.Printf("%d\n", myAtoi(" 2147483647 w"))
	fmt.Printf("%d\n", myAtoi(" -2147483647 w"))
	fmt.Printf("%d\n", myAtoi("  +2147483648  "))
	fmt.Printf("%d\n", myAtoi("  -21474836483800  "))
}
