package main

import (
	"fmt"
)

func addBinary(a string, b string) string {
	na := len(a)
	nb := len(b)
	nc := na + 1
	if na < nb {
		nc = nb + 1
	}
	r := make([]byte, nc)
	c := byte(0)
	for na != 0 && nb != 0 {
		na--
		nb--
		nc--
		d := byte(a[na]-'0') + byte(b[nb]-'0') + c
		c = d / 2
		r[nc] = (d % 2) + '0'
	}
	for na != 0 {
		na--
		nc--
		d := byte(a[na]-'0') + c
		c = d / 2
		r[nc] = (d % 2) + '0'
	}
	for nb != 0 {
		nb--
		nc--
		d := byte(b[nb]-'0') + c
		c = d / 2
		r[nc] = (d % 2) + '0'
	}
	if c != 0 {
		r[0] = c + '0'
		return string(r)
	}
	return string(r[1:])
}

func main() {
	fmt.Printf("%s\n", addBinary("11", "1"))
	fmt.Printf("%s\n", addBinary("11", "0"))
	fmt.Printf("%s\n", addBinary("11", "11"))
	fmt.Printf("%s\n", addBinary("10", "1"))
}
