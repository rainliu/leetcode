package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	dummy := ListNode{0, head}
	p := dummy.Next
	var q *ListNode
	if p != nil {
		q = p.Next
	} else {
		return nil
	}
	for q != nil {
		if p.Val == q.Val {
			q = q.Next
			p.Next = q
		} else {
			q = q.Next
			p = p.Next
		}
	}
	p.Next = q

	return dummy.Next
}

func main() {

}
