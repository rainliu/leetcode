package main

func climbStairs(n int) int {
	if n < 2 {
		return 1
	}
	fn_2 := 1
	fn_1 := 1
	fn := 0
	for i := 2; i <= n; i++ {
		fn = fn_2 + fn_1
		fn_2 = fn_1
		fn_1 = fn
	}
	return fn
}

func main() {

}
