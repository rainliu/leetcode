package main

import "fmt"

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func reorderList(head *ListNode) {
	if head == nil {
		return
	}
	n := 0
	p := head
	for p != nil {
		p = p.Next
		n++
	}
	m := (0 + n - 1) / 2
	mid := head
	for m != 0 {
		mid = mid.Next
		m--
	}

	var q, r *ListNode
	p = mid
	q = p.Next
	for q != nil {
		r = q.Next
		q.Next = p
		p = q
		q = r
	}
	mid.Next = nil

	q = head
	for q != nil {
		r = q.Next
		o := p.Next
		q.Next = p
		p.Next = r
		q = r
		p = o
	}
	return
}

func main() {
	next := &ListNode{2, nil}
	head := &ListNode{1, next}
	reorderList(head)
	for head != nil {
		fmt.Printf("%d ", head.Val)
		head = head.Next
	}
}
