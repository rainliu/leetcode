package main

import "fmt"

func generateParenthesisHelper(results []string, result string, l, r, n int) []string {
	if l < n {
		results = generateParenthesisHelper(results, result+"(", l+1, r, n)
	} else {
		for r < n {
			result += ")"
			r++
		}
		results = append(results, result)
		return results
	}
	if l > r {
		results = generateParenthesisHelper(results, result+")", l, r+1, n)
	}
	return results
}
func generateParenthesis(n int) []string {
	var results []string
	results = generateParenthesisHelper(results, "(", 1, 0, n)
	return results
}

func main() {
	fmt.Printf("%v\n", generateParenthesis(1))
	fmt.Printf("%v\n", generateParenthesis(2))
	fmt.Printf("%v\n", generateParenthesis(3))
}
