package main

import "container/heap"

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

// An Item is something we manage in a priority queue.
type Item struct {
	value    int // The value of the item; arbitrary.
	priority int // The priority of the item in the queue.
	index    int // The index of the item in the heap.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}

func mergeKLists(lists []*ListNode) *ListNode {
	var pq PriorityQueue
	for i := 0; i < len(lists); i++ {
		if lists[i] != nil {
			pq = append(pq, &Item{
				value:    i,
				priority: lists[i].Val,
				index:    i,
			})
		}
	}
	heap.Init(&pq)
	dummy := ListNode{0, nil}
	p := &dummy
	for pq.Len() > 0 {
		item := heap.Pop(&pq).(*Item)
		p.Next = &ListNode{item.priority, nil}
		p = p.Next
		lists[item.value] = lists[item.value].Next
		if lists[item.value] != nil {
			heap.Push(&pq, &Item{
				value:    item.value,
				priority: lists[item.value].Val,
			})
		}
	}
	return dummy.Next
}

func main() {

}
