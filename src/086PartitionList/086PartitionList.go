package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	dummy := ListNode{0, head}
	p := &dummy
	q := head
	for q != nil && q.Val < x {
		p = p.Next
		q = q.Next
	}
	if q != nil {
		r := q.Next
		o := q
		for r != nil {
			if r.Val < x {
				p.Next = r
				o.Next = r.Next
				r.Next = q
				r = o.Next
				p = p.Next
			} else {
				o = o.Next
				r = r.Next
			}
		}
	}
	return dummy.Next
}
func main() {

}
