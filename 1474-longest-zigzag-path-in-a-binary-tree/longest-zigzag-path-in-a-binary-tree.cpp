/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    int len=0;
    void dfs(TreeNode* node,int steps,bool flag){
        if(!node) return;
        len=max(len,steps);
        if(flag){
            dfs(node->left,steps+1,false);
            dfs(node->right,1,true);
        }
        else{
            dfs(node->right,steps+1,true);
            dfs(node->left,1,false);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,0,true);
        return len;
    }
};