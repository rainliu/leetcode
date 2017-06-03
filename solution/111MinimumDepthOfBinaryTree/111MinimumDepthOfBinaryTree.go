package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left != nil && root.Right != nil {
		return 1 + min(minDepth(root.Left), minDepth(root.Right))
	} else if root.Left != nil {
		return 1 + minDepth(root.Left)
	} else if root.Right != nil {
		return 1 + minDepth(root.Right)
	} else {
		return 1
	}
}

func main() {

}
