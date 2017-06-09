package main

import "bytes"

func reverse(s string) string {
	var b bytes.Buffer
	for i := 0; i < len(s); i++ {
		b.WriteByte(s[len(s)-1-i])
	}
	return b.String()
}
func convertToTitle(n int) string {
	var b bytes.Buffer
	for n != 0 {
		c := byte((n - 1) % 26)
		b.WriteByte('A' + c)
		n = (n - 1) / 26
	}

	return reverse(b.String())
}

func main() {

}
