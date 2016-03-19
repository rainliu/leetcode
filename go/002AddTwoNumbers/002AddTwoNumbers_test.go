package AddTwoNumbers

import (
	"testing"
)

/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
func TestAddTwoNumbers(t *testing.T) {
	p := &ListNode{0, nil}
	var q *ListNode = nil
	g := &ListNode{0, nil}

	r := addTwoNumbers(p, q)
	if r.Val == g.Val {
		t.Log("Pass")
	}else{
		t.Fail()
	}
}