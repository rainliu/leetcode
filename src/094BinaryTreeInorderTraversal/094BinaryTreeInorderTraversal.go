package main

import "fmt"

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversalRecursive(root *TreeNode, result []int) []int {
	if root != nil {
		result = inorderTraversalRecursive(root.Left, result)
		result = append(result, root.Val)
		result = inorderTraversalRecursive(root.Right, result)
	}
	return result
}

type stack []*TreeNode

func (s stack) Empty() bool       { return len(s) == 0 }
func (s stack) Peek() *TreeNode   { return s[len(s)-1] }
func (s *stack) Push(i *TreeNode) { (*s) = append((*s), i) }
func (s *stack) Pop() *TreeNode {
	d := (*s)[len(*s)-1]
	(*s) = (*s)[:len(*s)-1]
	return d
}

func inorderTraversal(root *TreeNode) []int {
	var result []int
	//result = inorderTraversalRecursive(root, result)
	var s stack
	m := make(map[*TreeNode]bool)
	if root != nil {
		s.Push(root)
	}
	for !s.Empty() {
		p := s.Peek()
		ok := p.Left != nil
		if ok && !m[p.Left] {
			s.Push(p.Left)
		} else {
			r := s.Pop()
			m[r] = true
			result = append(result, r.Val)
			if r.Right != nil {
				s.Push(r.Right)
			}
		}
	}
	return result
}

func main() {
	p3 := TreeNode{3, nil, nil}
	p2 := TreeNode{2, &p3, nil}
	root := TreeNode{1, nil, &p2}
	fmt.Printf("%v\n", inorderTraversal(&root))
}
