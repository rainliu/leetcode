package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isValidBSTHelper(root *TreeNode, bMostLeft bool) int {
	if bMostLeft {
		for root.Left != nil {
			root = root.Left
		}
		return root.Val
	} else {
		for root.Right != nil {
			root = root.Right
		}
		return root.Val
	}
}

func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if root.Left != nil && root.Right != nil {
		return isValidBST(root.Left) && isValidBST(root.Right) &&
			isValidBSTHelper(root.Left, false) < root.Val &&
			isValidBSTHelper(root.Right, true) > root.Val
	} else if root.Left != nil {
		return isValidBST(root.Left) && isValidBSTHelper(root.Left, false) < root.Val
	} else if root.Right != nil {
		return isValidBST(root.Right) && isValidBSTHelper(root.Right, true) > root.Val
	} else { //both left and right are nil
		return true
	}
}

func main() {

}
