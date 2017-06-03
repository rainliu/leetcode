package main

func maxProfit(prices []int) int {
	n := len(prices)
	profit := 0
	for i := 1; i < n; i++ {
		diff := prices[i] - prices[i-1]
		if diff > 0 {
			profit += diff
		}
	}
	return profit
}

func main() {

}
