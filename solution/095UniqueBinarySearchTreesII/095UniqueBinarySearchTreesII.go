package main

import "fmt"

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/*
T(0) = 1
T(1) = 1
T(2) = T(0)*T(1) + T(1)*T(0)
T(3) = T(0)*T(2) + T(1)*T(1) + T(2)*T(0)
T(4) = T(0)*T(3) + T(1)*T(2) + T(3)*T(0)
T(5) = T(0)*T(4) + T(1)*T(3) + T(2)*T(2) + T(3)*T(1) + T(4)*T(0)
T(n) = Sum(Sum{T(k)*T(n-1-k)})
*/
func generateTreesHelper(nums []int) []*TreeNode {
	n := len(nums)
	var results []*TreeNode
	for k := 0; k < n; k++ {
		left := generateTreesHelper(nums[:k])
		right := generateTreesHelper(nums[k+1:])
		if len(left) > 0 && len(right) > 0 {
			for i := 0; i < len(left); i++ {
				for j := 0; j < len(right); j++ {
					results = append(results, &TreeNode{nums[k], left[i], right[j]})
				}
			}
		} else if len(left) > 0 {
			for i := 0; i < len(left); i++ {
				results = append(results, &TreeNode{nums[k], left[i], nil})
			}
		} else if len(right) > 0 {
			for j := 0; j < len(right); j++ {
				results = append(results, &TreeNode{nums[k], nil, right[j]})
			}
		} else {
			results = append(results, &TreeNode{nums[k], nil, nil})
		}
	}
	return results
}

func generateTrees(n int) []*TreeNode {
	if n <= 0 {
		return nil
	} else if n <= 1 {
		return []*TreeNode{
			&TreeNode{1, nil, nil},
		}
	}
	nums := make([]int, n)
	for k := 0; k < n; k++ {
		nums[k] = k + 1
	}
	return generateTreesHelper(nums)
}

func main() {
	fmt.Printf("%v\n", generateTrees(3))
}
