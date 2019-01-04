package main

import (
	"bytes"
	"fmt"
)

/*
0(n-1)            2(n-1)					4(n-1)
1         n-1+n-2 2(n-1)+1 					4(n-1)+1
.        .								.
.      .							.
.   (n-1)+1                3(n-1)+1
n-1				  3(n-1) 					5(n-1)

*/
func convert(s string, numRows int) string {
	l := len(s)
	if numRows <= 1 || l <= numRows {
		return s
	}
	var b bytes.Buffer
	var i, j int

	i = 0
	for i*(numRows-1) < l {
		b.WriteByte(s[i*(numRows-1)])
		i += 2
	}

	for j = 1; j < numRows-1; j++ {
		i = 0
		for i*(numRows-1)+j < l || i*(numRows-1)-j < l {
			if i*(numRows-1)-j >= 0 {
				b.WriteByte(s[i*(numRows-1)-j])
			}
			if i*(numRows-1)+j < l {
				b.WriteByte(s[i*(numRows-1)+j])
			}
			i += 2
		}
	}

	i = 1
	for i*(numRows-1) < l {
		b.WriteByte(s[i*(numRows-1)])
		i += 2
	}

	return b.String()
}

func main() {
	fmt.Printf("%s\n", convert("abcd", 3))
	fmt.Printf("%s\n", convert("PAYPALISHIRING", 1))
	fmt.Printf("%s\n", convert("PAYPALISHIRING", 2))
}
