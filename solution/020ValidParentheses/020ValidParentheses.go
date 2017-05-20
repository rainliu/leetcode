package main

import "fmt"

type Stack []byte

func (s Stack) Empty() bool {
	return len(s) == 0
}
func (s *Stack) Push(b byte) {
	(*s) = append((*s), b)
}
func (s *Stack) Pop() byte {
	d := (*s)[len(*s)-1]
	(*s) = (*s)[:len(*s)-1]
	return d
}

var m = map[byte]byte{
	')': '(',
	']': '[',
	'}': '{',
}

func isValid(s string) bool {
	n := len(s)
	var stack Stack
	for i := 0; i < n; i++ {
		switch s[i] {
		case '(':
			fallthrough
		case '{':
			fallthrough
		case '[':
			stack.Push(s[i])
		default:
			if stack.Empty() || m[s[i]] != stack.Pop() {
				return false
			}
		}
	}
	return stack.Empty()
}

func main() {
	fmt.Printf("%v\n", isValid("(())[{()}]"))
}
