package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTreeHelper(preorder, inorder []int, inorder_idx_map map[int]int, start int) *TreeNode {
	mi := inorder_idx_map[preorder[0]] - start
	root := &TreeNode{preorder[0], nil, nil}
	if mi-1 >= 0 {
		root.Left = buildTreeHelper(preorder[1:mi+1], inorder[:mi], inorder_idx_map, start)
	}
	if mi+1 <= len(inorder)-1 {
		root.Right = buildTreeHelper(preorder[mi+1:], inorder[mi+1:], inorder_idx_map, start+mi+1)
	}
	return root
}
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 || len(inorder) == 0 || len(preorder) != len(inorder) {
		return nil
	}
	inorder_idx_map := make(map[int]int)
	for i := 0; i < len(inorder); i++ {
		inorder_idx_map[inorder[i]] = i
	}
	return buildTreeHelper(preorder, inorder, inorder_idx_map, 0)
}

func main() {

}
