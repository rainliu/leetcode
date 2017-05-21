package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	dummy := ListNode{0, head}
	r := &dummy
	for r.Next != nil && r.Next.Next != nil {
		e := r.Next
		o := r.Next.Next

		r.Next = o
		e.Next = o.Next
		o.Next = e

		r = r.Next.Next
	}
	return dummy.Next
}

func main() {

}
