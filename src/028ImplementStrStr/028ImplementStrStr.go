package main

import (
	"fmt"
)

func strStr(haystack string, needle string) int {
	j := 0
	for j = 0; j < len(haystack)-len(needle)+1; j++ {
		i := 0
		for i = 0; i < len(needle); i++ {
			if haystack[j+i] != needle[i] {
				break
			}
		}
		if i == len(needle) {
			return j
		}
	}
	return -1
}

func main() {
	fmt.Printf("%v\n", strStr("abcdef", "def"))
	fmt.Printf("%v\n", strStr("abcdef", "daf"))
	fmt.Printf("%v\n", strStr("abcdef", "ab"))
}
