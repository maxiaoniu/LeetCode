/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    private LinkedList<Integer> listVal = new LinkedList<>();
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root == null)
            return listVal;
        inorderTraversal(root.left);
        listVal.add(root.val);
        inorderTraversal(root.right);
        return listVal;
        
    }
}