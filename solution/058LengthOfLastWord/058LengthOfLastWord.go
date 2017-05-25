package main

func lengthOfLastWord(s string) int {
	n := len(s)
	j := n - 1
	for j >= 0 && s[j] == ' ' {
		j--
	}
	i := j
	for j >= 0 && s[j] != ' ' {
		j--
	}
	return i - j
}

func main() {

}
