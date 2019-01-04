package main

import "fmt"

func isPalindrome(s string) bool {
	n := len(s)
	i := 0
	j := 0
	b := []byte(s)
	for j < n {
		if (b[j] >= 'a' && b[j] <= 'z') ||
			(b[j] >= 'A' && b[j] <= 'Z') ||
			(b[j] >= '0' && b[j] <= '9') {
			b[i], b[j] = b[j], b[i]
			if b[i] >= 'A' && b[i] <= 'Z' {
				b[i] += 'a' - 'A'
			}
			i++
		}
		j++
	}
	lo := 0
	hi := i - 1
	bPalindrome := true
	for lo <= hi {
		if b[lo] == b[hi] {
			lo++
			hi--
		} else {
			return false
		}
	}
	return bPalindrome
}

func main() {
	fmt.Printf("%v\n", isPalindrome("0P"))
	fmt.Printf("%v\n", isPalindrome("race a car"))
}
