//Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> rightSideView(TreeNode* root) {
  vector<int> res;
  if(root == nullptr)
    return res;
  queue<TreeNode*> current;
  queue<TreeNode*> next;
  current.push(root);
  while(!current.empty()) {
  while(!current.empty()) {
    TreeNode* node =  current.front();
    current.pop();
    
    if(current.empty()) {
      res.push_back(node->val);
    }
    
    if(node->left) next.push(node->left);
    if(node->right) next.push(node->right);
    
  }
  swap(next,current);
  }
  return res;
}
};
