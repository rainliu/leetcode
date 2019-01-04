package main

func maxProfit(prices []int) int {
	n := len(prices)
	local := 0
	global := 0
	for i := 1; i < n; i++ {
		diff := local + prices[i] - prices[i-1]
		if diff < 0 {
			local = 0
		} else {
			local = diff
		}
		if local > global {
			global = local
		}
	}
	return global
}

func main() {

}
