package main

import "fmt"

type MinStack struct {
	norm []int
	mini []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	if len(this.norm) == 0 {
		this.mini = append(this.mini, x)
	} else {
		if x <= this.mini[len(this.mini)-1] {
			this.mini = append(this.mini, x)
		}
	}
	this.norm = append(this.norm, x)
}

func (this *MinStack) Pop() {
	x := this.norm[len(this.norm)-1]
	if x == this.mini[len(this.mini)-1] {
		this.mini = this.mini[:len(this.mini)-1]
	}
	this.norm = this.norm[:len(this.norm)-1]
}

func (this *MinStack) Top() int {
	return this.norm[len(this.norm)-1]
}

func (this *MinStack) GetMin() int {
	return this.mini[len(this.mini)-1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 */
func main() {
	obj := Constructor()
	obj.Push(-2)
	obj.Push(0)
	obj.Push(-3)
	obj.Push(-3)
	fmt.Printf("%d\n", obj.GetMin())
	obj.Pop()
	fmt.Printf("%d\n", obj.GetMin())
	obj.Pop()
	fmt.Printf("%d\n", obj.GetMin())
	obj.Top()
	obj.GetMin()
	obj.Pop()
	fmt.Printf("%d\n", obj.GetMin())
}
