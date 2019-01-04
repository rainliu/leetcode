package main

import "strconv"

func evalRPN(tokens []string) int {
	var stack []int
	for i := 0; i < len(tokens); i++ {
		var c int
		if tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" {
			b := stack[len(stack)-1]
			a := stack[len(stack)-2]
			stack = stack[:len(stack)-2]
			switch tokens[i] {
			case "+":
				c = a + b
			case "-":
				c = a - b
			case "*":
				c = a * b
			default: //"/"
				c = a / b
			}
		} else {
			c, _ = strconv.Atoi(tokens[i])
		}
		stack = append(stack, c)
	}
	if len(stack) == 1 {
		return stack[0]
	} else {
		return 0
	}
}

func main() {

}
