package TwoSum

import (
	"testing"
)


func TestTwoSum(t *testing.T) {
	nums :=[][]int{
		{2, 7, 11, 15},
		{2, 7, 11, 15},
		{2, 7, 11, 15},
	}

	target := []int{
		9,
		18,
		17,
	}

	golden := [][]int{
		{0, 1},
		{1, 2},
		{0, 3},
	}
	
	for i:=0; i<len(target); i++{
		result := twoSum(nums[i], target[i])
		if golden[i][0]==result[0]&&golden[i][1]==result[1] {
			t.Log("Passing")
		}else{
			t.Fail()
		}
	}
}