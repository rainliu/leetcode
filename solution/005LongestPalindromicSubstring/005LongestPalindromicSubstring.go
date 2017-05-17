package main

import "fmt"

func longestPalindromeHelpCenter(s string, c int) int {
	l := 1
	for c-l >= 0 && c+l < len(s) && s[c-l] == s[c+l] {
		l++
	}
	return l
}

func longestPalindromeHelpSymetry(s string, c int) int {
	l := 0
	for c-l >= 0 && c+1+l < len(s) && s[c-l] == s[c+1+l] {
		l++
	}
	return l
}

func longestPalindrome(s string) string {
	center := 0
	length := 0
	symetry := false
	l := 0
	for c := 0; c < len(s); c++ {
		l1 := longestPalindromeHelpCenter(s, c)
		l2 := longestPalindromeHelpSymetry(s, c)
		if l1*2-1 > l2*2 && l1*2-1 > length {
			center = c
			length = l1*2 - 1
			symetry = false
			l = l1
		} else if l1*2-1 < l2*2 && l2*2 > length {
			center = c
			length = l2 * 2
			symetry = true
			l = l2
		}
	}

	if symetry {
		return s[center-l+1 : center+1+l]
	} else {
		return s[center-l+1 : center+l]
	}
}

func main() {
	fmt.Printf("%s\n", longestPalindrome("babad"))
	fmt.Printf("%s\n", longestPalindrome("cbbd"))
}
