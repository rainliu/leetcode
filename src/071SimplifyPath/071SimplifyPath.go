package main

import "fmt"
import "bytes"

type stack []string

func (s stack) Empty() bool    { return len(s) == 0 }
func (s stack) Front() string  { return s[len(s)-1] }
func (s *stack) Push(b string) { (*s) = append((*s), b) }
func (s *stack) Pop() string {
	d := (*s)[len(*s)-1]
	(*s) = (*s)[:len(*s)-1]
	return d
}

func simplifyPath(path string) string {
	if path == "" {
		return path
	}
	n := len(path)
	var s1, s2 stack
	i := 0
	j := 0
	for j < n {
		if path[j] == '/' {
			if j-i > 0 {
				s1.Push(path[i:j])
			}
			for j+1 < n && path[j+1] == '/' {
				j++
			}
			i = j + 1
		} else if j+1 == n {
			if j+1-i > 0 {
				s1.Push(path[i : j+1])
			}
		}
		j++
	}

	c := 0
	for !s1.Empty() {
		b := s1.Pop()
		if b == ".." {
			c++
		} else if b == "." {
			//do nothing
		} else if c > 0 {
			c--
		} else {
			s2.Push(b)
		}
	}
	var b bytes.Buffer
	empty := s2.Empty()
	for !s2.Empty() {
		b.WriteString("/")
		b.WriteString(s2.Pop())
	}
	if empty {
		b.WriteString("/")
	}
	return b.String()
}

func main() {
	fmt.Printf("%v\n", simplifyPath("/"))
	fmt.Printf("%v\n", simplifyPath("///home/"))
	fmt.Printf("%v\n", simplifyPath("/home"))
	fmt.Printf("%v\n", simplifyPath("/a/./b/../../c/"))
	fmt.Printf("%v\n", simplifyPath("/a/./b/../../c"))
	fmt.Printf("%v\n", simplifyPath("/../"))
	fmt.Printf("%v\n", simplifyPath("/..//home//foo"))
}
