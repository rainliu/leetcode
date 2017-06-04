package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumNumbersHelper(root *TreeNode, sum int) int {
	if root.Left == nil && root.Right == nil {
		return sum
	} else {
		sum2 := 0
		if root.Left != nil {
			sum2 += sumNumbersHelper(root.Left, sum*10+root.Left.Val)
		}
		if root.Right != nil {
			sum2 += sumNumbersHelper(root.Right, sum*10+root.Right.Val)
		}
		return sum2
	}
}

func sumNumbers(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return sumNumbersHelper(root, root.Val)
}

func main() {

}
