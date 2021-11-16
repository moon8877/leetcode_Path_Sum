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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        vector<int> pathLength;
        int count = 0;
        dfs(root,pathLength,count);
        for(int i=0;i<pathLength.size();++i){
            if(pathLength[i]==targetSum){
                return true;
            }
        }
        return false;
        
    }
private:
    void dfs(TreeNode* root,vector<int>& pathLength,int count){
        if(root->left==nullptr && root->right==nullptr){
            pathLength.push_back(count+(root->val));
            return;
        }
        if(root->left){
            dfs(root->left,pathLength,count+(root->val));
        }
        if(root->right){
            dfs(root->right,pathLength,count+(root->val));
        }
    }
};
