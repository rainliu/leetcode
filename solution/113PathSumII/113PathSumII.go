package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSumHelper(root *TreeNode, sum int, results [][]int, result []int) [][]int {
	result = append(result, root.Val)
	if root.Left == nil && root.Right == nil {
		if sum == root.Val {
			r := make([]int, len(result))
			copy(r, result)
			results = append(results, r)
		}
	} else {
		if root.Left != nil {
			results = pathSumHelper(root.Left, sum-root.Val, results, result)
		}
		if root.Right != nil {
			results = pathSumHelper(root.Right, sum-root.Val, results, result)
		}
	}
	result = result[:len(result)-1]
	return results
}

func pathSum(root *TreeNode, sum int) [][]int {
	if root == nil {
		return nil
	}
	var results [][]int
	var result []int
	results = pathSumHelper(root, sum, results, result)
	return results
}

func main() {

}
