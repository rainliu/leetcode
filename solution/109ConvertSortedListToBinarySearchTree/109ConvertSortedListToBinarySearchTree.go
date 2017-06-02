package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorder(head *ListNode, lo, hi int) (*ListNode, *TreeNode) {
	if lo <= hi {
		mi := lo + (hi-lo)/2
		head, left := inorder(head, lo, mi-1)
		root := &TreeNode{head.Val, left, nil}
		head = head.Next
		head, root.Right = inorder(head, mi+1, hi)
		return head, root
	} else {
		return head, nil
	}
}

func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	p := head
	n := 0
	for p != nil {
		p = p.Next
		n++
	}
	_, root := inorder(head, 0, n-1)
	return root
}

func main() {

}
