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
	r := &dummy
	p := dummy.Next
	var q *ListNode
	if p != nil {
		q = p.Next
	} else {
		return nil
	}
	duplicated := false
	for q != nil {
		if p.Val == q.Val {
			duplicated = true
			q = q.Next
		} else {
			if duplicated {
				r.Next = q
				duplicated = false
			} else {
				r = p
			}
			p = q
			q = q.Next
		}
	}
	p.Next = q

	return dummy.Next
}

func main() {

}
