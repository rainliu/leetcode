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

func upsideDownBinaryTreeHelper(root *TreeNode) (*TreeNode, *TreeNode) {
	if root.Left == nil {
		return root, root
	}
	newRoot, right := upsideDownBinaryTreeHelper(root.Left)
	right.Left = root.Right
	right.Right = root
	root.Left = nil
	root.Right = nil
	return newRoot, root
}
func upsideDownBinaryTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	root, _ = upsideDownBinaryTreeHelper(root)
	return root
}

func main() {
	n4 := &TreeNode{4, nil, nil}
	n5 := &TreeNode{5, nil, nil}
	n2 := &TreeNode{2, n4, n5}
	n3 := &TreeNode{3, nil, nil}
	n1 := &TreeNode{1, n2, n3}
	root := upsideDownBinaryTree(n1)
	fmt.Printf("\n")
	for root != nil {
		fmt.Printf("%d ", root.Val)
		if root.Left != nil {
			fmt.Printf("%d ", root.Left.Val)
		}
		if root.Right != nil {
			//fmt.Printf("%d ", root.Right.Val)
		}
		root = root.Right
	}
}
