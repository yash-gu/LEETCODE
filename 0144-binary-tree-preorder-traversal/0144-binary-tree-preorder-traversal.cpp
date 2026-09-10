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
    void preorder(vector<int>& ans,TreeNode* temp ){
        if (temp == nullptr) return;
        ans.push_back(temp->val);
        preorder(ans,temp->left);
        preorder(ans,temp->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode*temp=root;
        
        preorder(ans,temp);
        return ans;
    }
    
};