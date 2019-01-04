package main

import "fmt"

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	var i int
	for i = 0; i < len(strs[0]); i++ {
		match := true
		for j := 1; j < len(strs); j++ {
			if i >= len(strs[j]) || strs[j][i] != strs[0][i] {
				match = false
				break
			}
		}
		if !match {
			break
		}
	}
	return strs[0][:i]
}

func main() {
	strs := []string{"abc", "abcde", "", "abcdefg"}
	fmt.Printf("%s\n", longestCommonPrefix(strs))
	strs2 := []string{}
	fmt.Printf("%s\n", longestCommonPrefix(strs2))
}
