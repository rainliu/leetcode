package main

import "fmt"

var d2m = []string{ //0  1  2    3     4,    5,    6,    7,     8     9
	"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

func letterCombinationsHelper(digits string, d, n int, s string, results []string) []string {
	str := d2m[digits[d]-'0']
	for i := 0; i < len(str); i++ {
		if d+1 < n {
			results = letterCombinationsHelper(digits, d+1, n, s+string(str[i]), results)
		} else {
			results = append(results, s+string(str[i]))
		}
	}
	return results
}
func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return nil
	}
	var results []string
	results = letterCombinationsHelper(digits, 0, len(digits), "", results)
	return results
}

func main() {
	fmt.Printf("%v\n", letterCombinations("23"))
	fmt.Printf("%v\n", letterCombinations("232"))
}
