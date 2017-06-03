package main

func generate(numRows int) [][]int {
	if numRows <= 0 {
		return nil
	}
	var results [][]int
	result := make([]int, numRows)
	result[0] = 1
	for i := 0; i < numRows; i++ {
		for j := i; j >= 0; j-- {
			if j-1 >= 0 {
				result[j] += result[j-1]
			}
		}
		r := make([]int, i+1)
		copy(r, result[:i+1])
		results = append(results, r)
	}
	return results
}

func main() {

}
