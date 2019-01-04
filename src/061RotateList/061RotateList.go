package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	n := 0
	r := head
	for r != nil {
		n++
		r = r.Next
	}
	if n == 0 {
		return head
	}
	k = k % n
	if k <= 0 {
		return head
	}
	dummy := ListNode{0, head}
	p := &dummy
	q := p
	for i := 0; i < k; i++ {
		if q.Next != nil {
			q = q.Next
		} else {
			return dummy.Next
		}
	}
	for q.Next != nil {
		q = q.Next
		p = p.Next
	}
	if p != &dummy {
		q.Next = dummy.Next
		dummy.Next = p.Next
		p.Next = nil
	}
	return dummy.Next
}

func main() {

}
