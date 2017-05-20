package main

/**
 * Definition for singly-linked list.
 **/
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if n <= 0 {
		return head
	}
	dummy := ListNode{0, head}
	p := &dummy
	q := &dummy
	for i := 0; i < n; i++ {
		q = q.Next
	}
	for q.Next != nil {
		q = q.Next
		p = p.Next
	}
	p.Next = p.Next.Next
	return dummy.Next
}

func main() {

}
