package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorder(nums []int, lo, hi int) *TreeNode {
	if lo <= hi {
		mi := lo + (hi-lo)/2
		root := &TreeNode{nums[mi], nil, nil}
		root.Left = inorder(nums, lo, mi-1)
		root.Right = inorder(nums, mi+1, hi)
		return root
	} else {
		return nil
	}
}
func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	return inorder(nums, 0, len(nums)-1)
}

func main() {

}
