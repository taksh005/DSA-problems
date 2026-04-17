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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> LOT;
        queue<TreeNode*> q;
        if(root == nullptr) return LOT;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->right != nullptr) q.push(node->right);
                if(node->left != nullptr) q.push(node->left);
            }
            LOT.push_back(level[0]);
        }
        return LOT;
    }
};