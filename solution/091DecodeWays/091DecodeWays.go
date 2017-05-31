package main

import "fmt"

func numDecodings(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	} else if s[0] == '0' {
		return 0
	} else if n == 1 {
		return 1
	}
	fn_2 := 0
	fn_1 := 1
	var fn int
	for i := 1; i <= n; i++ {
		if s[i-1] == '0' {
			if i == 1 {
				//do nothing
			} else if s[i-2] == '1' || s[i-2] == '2' {
				fn = fn_2
			} else {
				return 0
			}
		} else if s[i-1] >= '1' && s[i-1] <= '6' {
			if i == 1 {
				fn = fn_1
			} else if s[i-2] == '1' || s[i-2] == '2' {
				fn = fn_2 + fn_1
			} else {
				fn = fn_1
			}
		} else { //'7'-'9'
			if i == 1 {
				fn = fn_1
			} else if s[i-2] == '1' {
				fn = fn_2 + fn_1
			} else {
				fn = fn_1
			}
		}
		fn_2 = fn_1
		fn_1 = fn
	}
	return fn
}

func main() {
	fmt.Printf("%v\n", numDecodings("126"))
	fmt.Printf("%v\n", numDecodings("129"))
	fmt.Printf("%v\n", numDecodings("120"))
	fmt.Printf("%v\n", numDecodings("12030"))
	fmt.Printf("%v\n", numDecodings("12923349453232"))

}
