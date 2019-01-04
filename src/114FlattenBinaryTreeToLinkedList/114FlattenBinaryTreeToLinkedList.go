package main

/**
 * Definition for a binary tree node.
 */type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func flattenHelper(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	} else if root.Left == nil && root.Right == nil {
		return root
	} else if root.Left != nil && root.Right != nil {
		rightLast := flattenHelper(root.Right)
		leftLast := flattenHelper(root.Left)
		leftLast.Right = root.Right
		root.Right = root.Left
		root.Left = nil
		return rightLast
	} else if root.Right != nil {
		return flattenHelper(root.Right)
	} else {
		leftLast := flattenHelper(root.Left)
		root.Right = root.Left
		root.Left = nil
		return leftLast
	}
}

func flatten(root *TreeNode) {
	flattenHelper(root)
}

func main() {

}
