package main

import "fmt"

/*
T(0) = 1
T(1) = 1
T(2) = T(0)*T(1) + T(1)*T(0)
T(3) = T(0)*T(2) + T(1)*T(1) + T(2)*T(0)
T(4) = T(0)*T(3) + T(1)*T(2) + T(3)*T(0)
T(5) = T(0)*T(4) + T(1)*T(3) + T(2)*T(2) + T(3)*T(1) + T(4)*T(0)
T(n) = Sum(Sum{T(k)*T(n-1-k)})
*/
func numTrees(n int) int {
	if n <= 1 {
		return 1
	}
	T := make([]int, n+1)
	T[0] = 1
	T[1] = 1
	for i := 2; i <= n; i++ {
		for k := 0; k < i; k++ {
			T[i] = T[i] + T[k]*T[i-1-k]
		}
	}
	return T[n]
}

func main() {
	fmt.Printf("%v\n", numTrees(8))
}
