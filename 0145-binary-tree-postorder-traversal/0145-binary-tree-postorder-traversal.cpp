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
    void postorder(vector<int>& ans,TreeNode* temp){
        if(temp==NULL)return;
        postorder(ans,temp->left);
        postorder(ans,temp->right);
        ans.push_back(temp->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* temp=root;
        vector<int> ans;
        postorder(ans,temp);
        return ans;
        
    }
};