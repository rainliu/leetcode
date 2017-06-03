package main

func getRow(rowIndex int) []int {
	if rowIndex < 0 {
		return nil
	}
	result := make([]int, rowIndex+1)
	result[0] = 1
	for i := 0; i < rowIndex+1; i++ {
		for j := i; j >= 0; j-- {
			if j-1 >= 0 {
				result[j] += result[j-1]
			}
		}
	}
	return result
}

func main() {

}
