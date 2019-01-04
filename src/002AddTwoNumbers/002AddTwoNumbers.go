package main

import (
	"fmt"
)

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var dummy ListNode
	r := &dummy

	c := 0
	for l1 != nil && l2 != nil {
		v := l1.Val + l2.Val + c
		c = v / 10
		v %= 10
		r.Next = &ListNode{v, nil}
		r = r.Next
		l1 = l1.Next
		l2 = l2.Next
	}

	var l *ListNode
	if l1 != nil {
		l = l1
	} else {
		l = l2
	}

	for l != nil {
		v := l.Val + c
		c = v / 10
		v %= 10
		r.Next = &ListNode{v, nil}
		r = r.Next
		l = l.Next
	}

	if c != 0 {
		r.Next = &ListNode{c, nil}
	}

	return dummy.Next
}

func main() {
	l3 := &ListNode{6, nil}
	l2 := &ListNode{4, l3}
	l1 := &ListNode{2, l2}

	r3 := &ListNode{4, nil}
	r2 := &ListNode{6, r3}
	r1 := &ListNode{5, r2}

	l := addTwoNumbers(l1, r1)
	for l != nil {
		fmt.Printf("%d->", l.Val)
		l = l.Next
	}
}
