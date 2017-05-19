package main

import (
	"bytes"
	"fmt"
)

var LUT = [][]string{
	[]string{
		//1   2     3     4     5    6      7      8       9
		"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
	[]string{
		//10  20    30    40    50   60     70     80      90
		"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
	[]string{
		//100 200   300   400   500  600    700    800     900
		"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
	[]string{
		//1000 2000 3000
		"M", "MM", "MMM"}}

func intToRoman(num int) string {
	var b bytes.Buffer

	n := 1000
	k := 3
	for n != 0 {
		d := num / n
		if d != 0 {
			b.WriteString(LUT[k][d-1])
		}
		num = num - d*n
		k--
		n /= 10
	}

	return b.String()
}

func main() {
	fmt.Printf("%s\n", intToRoman(1))
	fmt.Printf("%s\n", intToRoman(9))
	fmt.Printf("%s\n", intToRoman(11))
	fmt.Printf("%s\n", intToRoman(99))
	fmt.Printf("%s\n", intToRoman(2420))
	fmt.Printf("%s\n", intToRoman(1999))
	fmt.Printf("%s\n", intToRoman(3999))
}
