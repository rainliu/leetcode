package main

import (
	"bytes"
)

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	l := len(s)
	var b bytes.Buffer
	for j := 0; j < numRows; j++ {
		println(j)
		i := 0
		if j == 0 || j == numRows-1 { //only (2N-2)*0+j, (2N-2)*1+j, ... for j = 0 or N-1
			for j+(2*numRows-2)*i < l {
				b.WriteByte(s[(2*numRows-2)*i+j])
				print(s[(2*numRows-2)*i+j])

				i++
			}
		} else { //(2N-2)*0-j, (2N-2)*0+j, (2N-2)*1-j, (2N-2)*1+j, ...
			for (2*numRows-2)*i-j < l || (2*numRows-2)*i+j < l {
				if (2*numRows-2)*i-j >= 0 {
					b.WriteByte(s[(2*numRows-2)*i-j])
					print(s[(2*numRows-2)*i-j])
				}
				if (2*numRows-2)*i+j < l {
					b.WriteByte(s[(2*numRows-2)*i+j])
					print(s[(2*numRows-2)*i+j])
				}

				i++
			}
		}
		println("")
	}
	return b.String()
}
