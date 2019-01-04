package main

func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1
	} else if n < 0 {
		return 1 / myPow(x, -n)
	} else if x == 0 {
		return 0
	} else if n == 1 {
		return x
	}

	z := myPow(x, n/2)
	if n%2 == 1 {
		return z * z * x
	} else {
		return z * z
	}
}

func main() {

}
