package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	dummy := ListNode{0, head}
	p := &dummy
	q := p.Next
	for i := 1; i < m; i++ {
		p = p.Next
		q = q.Next
	}
	for i := m; i < n; i++ {
		r := q.Next
		o := p.Next
		p.Next = r
		q.Next = r.Next
		r.Next = o
	}
	return dummy.Next
}

func main() {

}
