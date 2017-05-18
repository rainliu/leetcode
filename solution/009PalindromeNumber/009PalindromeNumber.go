package main

import "fmt"

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	} else if x < 10 {
		return true
	}
	n := 1
	y := x
	for y != 0 {
		y /= 10
		n *= 10
	}
	n /= 10
	for x != 0 {
		if x/n != x-(x/10)*10 {
			return false
		}
		x = x - (x/n)*n
		x = x / 10
		n /= 100
	}
	return true
}

func main() {
	fmt.Printf("%v\n", isPalindrome(-121))
	fmt.Printf("%v\n", isPalindrome(0))
	fmt.Printf("%v\n", isPalindrome(1234))
	fmt.Printf("%v\n", isPalindrome(1221))
	fmt.Printf("%v\n", isPalindrome(121))
	fmt.Printf("%v\n", isPalindrome(12))
	fmt.Printf("%v\n", isPalindrome(-2147447412))
}
