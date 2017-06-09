package main

type TwoSum struct {
	m map[int]int
	a []int
}

/** Initialize your data structure here. */
func Constructor() TwoSum {
	return TwoSum{m: make(map[int]int)}
}

/** Add the number to an internal data structure.. */
func (this *TwoSum) Add(number int) {
	this.a = append(this.a, number)
	this.m[number]++
}

/** Find if there exists any pair of numbers which sum is equal to the value. */
func (this *TwoSum) Find(value int) bool {
	for i := 0; i < len(this.a); i++ {
		if count, ok := this.m[value-this.a[i]]; ok {
			if value-this.a[i] == this.a[i] {
				if count > 1 {
					return true
				}
			} else {
				return true
			}
		}
	}
	return false
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(number);
 * param_2 := obj.Find(value);
 */

func main() {

}
