//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//BFS and stack

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) 
            return res;
        int level = 0;
        vector<TreeNode*> current;
        vector<TreeNode*> next;
        
        current.push_back(root);
        res.push_back(vector<int>(1,root->val));
        
        while(!current.empty()) {
            vector<int> vals;
            while(!current.empty()) {
                TreeNode* n = current.back();
                current.pop_back();
                
                //from left to right
                if(level%2){
                    if(n->left)  {next.push_back(n->left);  vals.push_back(n->left->val);}
                    if(n->right) {next.push_back(n->right); vals.push_back(n->right->val);}
                }
                else{
                    if(n->right) {next.push_back(n->right); vals.push_back(n->right->val);}
                    if(n->left)  {next.push_back(n->left);  vals.push_back(n->left->val);}
                }
            }
            if(!vals.empty())
                res.push_back(vals);
            swap(current, next);
            ++level;
        }
    }
};
