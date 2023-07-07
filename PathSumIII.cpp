class Solution {
public:
    void helper(TreeNode*root,int targetSum,  unordered_map<long,long>&mp,int &ans,long sum){
        if(!root) return;
        sum+=root->val;         
        ans += mp[sum - targetSum];
        mp[sum]++;
        helper(root->left,targetSum,mp,ans,sum);
        helper(root->right,targetSum,mp,ans,sum);
        mp[sum]--;
    }
   
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int ans=0;long sum=0;
        unordered_map<long,long>mp;
        mp[0]=1;
        helper(root,targetSum,mp,ans,sum);
        return ans;
    }
};
//super understandable solution
//https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method
// reason for line and mp[sum]-- is to avoid the path from root to current node
// remember mp[0]=1;
