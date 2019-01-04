package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Node struct {
	t *TreeNode
	l int
}

type Queue []Node

func (q *Queue) Empty() bool { return len(*q) == 0 }
func (q *Queue) Push(n Node) { *q = append(*q, n) }
func (q *Queue) Pop() (n Node) {
	n = (*q)[0]
	*q = (*q)[1:]
	return
}

func reverse(numbers [][]int) [][]int {
	for i := 0; i < len(numbers)/2; i++ {
		j := len(numbers) - i - 1
		numbers[i], numbers[j] = numbers[j], numbers[i]
	}
	return numbers
}

func levelOrderBottom(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}
	var results [][]int
	var result []int
	var q Queue
	q.Push(Node{root, 0})
	last := -1
	for !q.Empty() {
		p := q.Pop()
		if p.l != last {
			if result != nil {
				results = append(results, result)
			}
			last = p.l
			result = nil
		}
		result = append(result, p.t.Val)
		if p.t.Left != nil {
			q.Push(Node{p.t.Left, p.l + 1})
		}
		if p.t.Right != nil {
			q.Push(Node{p.t.Right, p.l + 1})
		}
	}
	if result != nil {
		results = append(results, result)
	}
	return reverse(results)
}

func main() {

}
