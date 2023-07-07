class Solution {
public:
    void helper(TreeNode* root, int target,vector<vector<int>>&ans,int sum,vector<int>&tp){
        if(root==NULL){
            return;
        }
        tp.push_back(root->val);
        sum+=root->val;
        if(sum==target && root->left==NULL && root->right==NULL){
            ans.push_back(tp);
        }
        helper(root->left,target,ans,sum,tp);
        helper(root->right,target,ans,sum,tp);
        sum-=root->val;
        tp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int>tp;
        helper(root,target,ans,0,tp);
        return ans;
    }
};