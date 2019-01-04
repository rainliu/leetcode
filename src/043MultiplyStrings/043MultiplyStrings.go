package main

import (
	"bytes"
	"fmt"
)

func multiplyHelper(num1 string, num2 byte) []byte {
	c := byte(0)
	var result []byte
	d2 := byte(num2 - '0')
	for i := len(num1) - 1; i >= 0; i-- {
		d1 := byte(num1[i] - '0')
		s := d1*d2 + c
		c = s / 10
		result = append(result, s-c*10)
	}
	if c != 0 {
		result = append(result, c)
	}
	return result
}

func additionHelper(results, result []byte, k int) ([]byte, int) {
	var i int
	c := byte(0)
	for i = k; i < k+len(result); i++ {
		s := results[i] + result[i-k] + c
		c = s / 10
		results[i] = s - c*10
	}
	if c != 0 {
		results[i] = c
		return results, i
	} else {
		return results, i - 1
	}

}

func multiply(num1 string, num2 string) string {
	if num1 == "0" || num2 == "0" {
		return "0"
	}
	results := make([]byte, len(num1)+len(num2))
	var n int
	k := 0
	for i := len(num2) - 1; i >= 0; i-- {
		result := multiplyHelper(num1, num2[i])
		results, n = additionHelper(results, result, k)
		k++
	}
	var b bytes.Buffer
	for i := n; i >= 0; i-- {
		b.WriteByte('0' + byte(results[i]))
	}
	return b.String()
}

func main() {
	fmt.Printf("%v\n", multiply("128", "238"))
	fmt.Printf("%v\n", multiply("9", "9"))
}
