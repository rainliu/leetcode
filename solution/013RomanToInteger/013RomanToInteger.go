package main

import (
	"fmt"
)

var LUT = map[byte]int{
	'I': 1,
	'V': 5,
	'X': 10,
	'L': 50,
	'C': 100,
	'D': 500,
	'M': 1000,
}

func romanToInt(s string) int {
	if len(s) == 0 {
		return 0
	}
	n := len(s) - 1
	v := LUT[s[n]]
	n--
	for n >= 0 {
		if LUT[s[n]] < LUT[s[n+1]] {
			v -= LUT[s[n]]
		} else {
			v += LUT[s[n]]
		}
		n--
	}
	return v
}

func main() {
	fmt.Printf("%d\n", romanToInt("MCMXCIX"))
	fmt.Printf("%d\n", romanToInt("M"))
	fmt.Printf("%d\n", romanToInt("MMCDXX"))
}
