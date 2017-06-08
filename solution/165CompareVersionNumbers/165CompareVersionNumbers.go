package main

import (
	"fmt"
	"strconv"
	"strings"
)

func compareVersion(version1 string, version2 string) int {
	v1 := strings.Split(version1, ".")
	v2 := strings.Split(version2, ".")
	n1 := len(v1)
	n2 := len(v2)
	var n int
	if n1 < n2 {
		n = n2
	} else {
		n = n1
	}
	var d1, d2 int
	for i := 0; i < n; i++ {
		if i < n1 {
			d1, _ = strconv.Atoi(v1[i])
		} else {
			d1 = 0
		}
		if i < n2 {
			d2, _ = strconv.Atoi(v2[i])
		} else {
			d2 = 0
		}
		if d1 > d2 {
			return 1
		} else if d1 < d2 {
			return -1
		}
	}
	return 0
}

func main() {
	fmt.Printf("%d\n", compareVersion("1.0.0", "1"))
	fmt.Printf("%d\n", compareVersion("0.1", "1.1"))
	fmt.Printf("%d\n", compareVersion("1.1", "1.10"))
	fmt.Printf("%d\n", compareVersion("1.2", "13.37"))
	fmt.Printf("%d\n", compareVersion("0.1", "1"))
	fmt.Printf("%d\n", compareVersion("1.2", "1"))
	fmt.Printf("%d\n", compareVersion("10.6.5", "10.6"))
	fmt.Printf("%d\n", compareVersion("10.0.0", "10"))
}
