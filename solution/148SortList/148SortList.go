package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func sortListSplit(start, end *ListNode) *ListNode {
	pilot := start.Next
	if pilot != end {
		r := pilot
		p := r.Next
		for p != end {
			q := p.Next
			if p.Val < pilot.Val {
				start.Next = p
				p.Next = pilot
				start = p
				r.Next = q
			} else {
				r = r.Next
			}
			p = q
		}
	}
	return pilot
}

func sortListHelper(start, end *ListNode) {
	if start.Next == end {
		return
	}
	pilot := sortListSplit(start, end)
	sortListHelper(start, pilot)
	sortListHelper(pilot, end)
}

func sortList(head *ListNode) *ListNode {
	dummy := ListNode{0, head}
	sortListHelper(&dummy, nil)
	return dummy.Next
}

func main() {

}
