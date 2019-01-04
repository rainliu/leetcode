package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTreeHelper(postorder, inorder []int, inorder_idx_map map[int]int, start int) *TreeNode {
	mi := inorder_idx_map[postorder[len(postorder)-1]] - start
	root := &TreeNode{postorder[len(postorder)-1], nil, nil}
	if mi-1 >= 0 {
		root.Left = buildTreeHelper(postorder[:mi], inorder[:mi], inorder_idx_map, start)
	}
	if mi+1 <= len(inorder)-1 {
		root.Right = buildTreeHelper(postorder[mi:len(postorder)-1], inorder[mi+1:], inorder_idx_map, start+mi+1)
	}
	return root
}
func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(postorder) == 0 || len(inorder) == 0 || len(postorder) != len(inorder) {
		return nil
	}
	inorder_idx_map := make(map[int]int)
	for i := 0; i < len(inorder); i++ {
		inorder_idx_map[inorder[i]] = i
	}
	return buildTreeHelper(postorder, inorder, inorder_idx_map, 0)
}

func main() {

}
