package main

import "fmt"

func titleToNumber(s string) int {
	sum := 0
	for i := 0; i < len(s); i++ {
		sum = sum*26 + int(s[i]-'A') + 1
	}
	return sum
}

func main() {
	fmt.Printf("%v\n", titleToNumber("AB"))
}
