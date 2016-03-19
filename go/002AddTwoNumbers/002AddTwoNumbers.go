package AddTwoNumbers

/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

//Definition for singly-linked list.
type ListNode struct {
	Val int
    Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{0, nil}
	var q,l *ListNode

	c := 0
	for l1!=nil && l2!=nil{
		p := &ListNode{l1.Val + l2.Val + c, nil}
		if p.Val >=10 {
			c = 1
			p.Val -= 10
		}else{
			c = 0
		}
		if dummy.Next == nil{
			dummy.Next = p
		}else{
			q.Next = p
		}
		q = p
		l1 = l1.Next
		l2 = l2.Next
	}

	if l1!= nil{
		l = l1
	}else if l2!=nil{
		l = l2
	}else{
		l = nil
	}

	for l!=nil{
		p := &ListNode{l.Val + c, nil}
		if p.Val >=10 {
			c = 1
			p.Val -= 10
		}else{
			c = 0
		}
		if dummy.Next == nil{
			dummy.Next = p
		}else{
			q.Next = p
		}
		q = p	
		l = l.Next
	}

	if c!=0 {
		p := &ListNode{c, nil}
		if dummy.Next == nil{
			dummy.Next = p
		}else{
			q.Next = p
		}
	}

	return dummy.Next;
}