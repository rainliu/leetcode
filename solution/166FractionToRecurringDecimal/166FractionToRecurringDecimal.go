package main

import (
	"bytes"
	"fmt"
	"strconv"
)

func abs(a int) int {
	if a < 0 {
		return -a
	} else {
		return a
	}
}
func fractionToDecimal(numerator int, denominator int) string {
	repeat := make(map[int]int)
	var b, c, e bytes.Buffer
	sign := 1
	if (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) {
		sign = -1
	}
	numerator = abs(numerator)
	denominator = abs(denominator)
	d := numerator / denominator
	if sign == -1 {
		b.WriteString("-")
	}
	b.WriteString(strconv.Itoa(d))
	m := numerator % denominator
	if m != 0 {
		b.WriteString(".")
		i := 0
		repeat[m] = i
		for m != 0 {
			d = (m * 10) / denominator
			n := (m * 10) % denominator
			i++
			if idx, ok := repeat[n]; ok {
				c.WriteString(strconv.Itoa(d) + ")")
				a := c.String()
				for j := 0; j < idx; j++ {
					e.WriteByte(a[j])
				}
				e.WriteString("(")
				e.WriteString(a[idx:])
				return b.String() + e.String()
			} else {
				repeat[n] = i
				c.WriteString(strconv.Itoa(d))
				m = n
			}
		}
	}
	return b.String() + c.String()
}

func main() {
	fmt.Printf("%v\n", fractionToDecimal(1, 2))
	fmt.Printf("%v\n", fractionToDecimal(2, 1))
	fmt.Printf("%v\n", fractionToDecimal(2, 3))
	fmt.Printf("%v\n", fractionToDecimal(1, 13))
	fmt.Printf("%v\n", fractionToDecimal(1, 6))
	fmt.Printf("%v\n", fractionToDecimal(-1, -2147483648))
}
