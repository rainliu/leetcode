package main

import "fmt"
import "bytes"

func countAndSayHelper(s string) string {
	var b bytes.Buffer
	i := 0
	j := 0
	c := byte(0)
	for j < len(s) {
		if s[i] == s[j] {
			c++
		} else {
			b.WriteByte('0' + c)
			b.WriteByte(s[i])
			i = j
			c = 1
		}
		j++
	}
	if c != 0 {
		b.WriteByte('0' + c)
		b.WriteByte(s[i])
	}
	return b.String()
}
func countAndSay(n int) string {
	if n <= 0 {
		return ""
	}
	s := "1"
	for i := 1; i < n; i++ {
		s = countAndSayHelper(s)
	}
	return s
}

func main() {
	fmt.Printf("%v\n", countAndSay(1))
	fmt.Printf("%v\n", countAndSay(2))
	fmt.Printf("%v\n", countAndSay(3))
	fmt.Printf("%v\n", countAndSay(4))
	fmt.Printf("%v\n", countAndSay(30))
}
