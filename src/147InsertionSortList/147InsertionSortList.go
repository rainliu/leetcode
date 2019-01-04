package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func insertionSortList(head *ListNode) *ListNode {
	dummy := ListNode{0, head}
	r := &dummy
	p := head
	for p != nil {
		q := p.Next

		l := &dummy
		o := dummy.Next
		for o != p && o.Val <= p.Val {
			l = l.Next
			o = o.Next
		}
		if o.Val > p.Val {
			l.Next = p
			p.Next = o
			r.Next = q
		} else {
			r = r.Next
		}
		p = q
	}

	return dummy.Next
}

func main() {
	//4,19,14,5,-3,1,8,5,11,15
}
