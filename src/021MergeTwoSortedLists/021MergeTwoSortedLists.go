package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := ListNode{0, nil}
	p := &dummy
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			p.Next = &ListNode{l1.Val, nil}
			l1 = l1.Next
		} else {
			p.Next = &ListNode{l2.Val, nil}
			l2 = l2.Next
		}
		p = p.Next
	}
	var l *ListNode
	if l1 != nil {
		l = l1
	} else {
		l = l2
	}
	for l != nil {
		p.Next = &ListNode{l.Val, nil}
		l = l.Next
		p = p.Next
	}

	return dummy.Next
}

func main() {

}
