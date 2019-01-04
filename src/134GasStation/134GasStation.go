package main

import "fmt"

func canCompleteCircuit(gas []int, cost []int) int {
	n := len(gas)
	left := make([]int, n)
	sum := 0
	for i := 0; i < n; i++ {
		left[i] = gas[i] - cost[i]
		sum += left[i]
	}
	if sum < 0 {
		return -1
	}
	start := 0
	for {
		sum := 0
		var i int
		for i = 0; i < n; i++ {
			sum += left[(start+i)%n]
			if sum < 0 {
				break
			}
		}
		if i == n {
			return start
		} else {
			start += i + 1
		}
	}
	return -1
}

func main() {
	fmt.Printf("%v\n", canCompleteCircuit([]int{4, 5, 6, 7, 8}, []int{5, 4, 5, 3, 2}))
}
