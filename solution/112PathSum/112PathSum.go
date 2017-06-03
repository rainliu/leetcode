package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}
	if root.Left == nil && root.Right == nil {
		return sum == root.Val
	} else if root.Left != nil && root.Right != nil {
		return hasPathSum(root.Left, sum-root.Val) || hasPathSum(root.Right, sum-root.Val)
	} else if root.Left != nil {
		return hasPathSum(root.Left, sum-root.Val)
	} else {
		return hasPathSum(root.Right, sum-root.Val)
	}
}
func main() {

}
