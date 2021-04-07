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
    int find(vector<int>in,int start,int end, int root)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i]==root)
                return i;
        }
        return -1;
        
    }
    TreeNode* helper(vector<int> pre,vector<int> in ,int in_l,int in_r,int pre_l,int pre_r)
    {
        if(in_l>in_r || pre_l>pre_r)
            return NULL;
        int data=pre[pre_l];
        int pos=find(in,in_l,in_r,data);
             int l_in_s=in_l;
             int l_in_e=pos-1;
             int l_pre_s=pre_l+1;
             int l_pre_e=l_in_e-l_in_s+l_pre_s;
             int r_in_s=pos+1;
             int r_in_e=in_r;
             int r_pre_s=l_pre_e+1;
             int r_pre_e=pre_r;
        TreeNode* temp=new TreeNode(data);
        temp->left=helper(pre,in,l_in_s,l_in_e,l_pre_s,l_pre_e);
        temp->right=helper(pre,in,r_in_s,r_in_e,r_pre_s,r_pre_e);
        return temp;
                 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int a=preorder.size();
        int b=inorder.size();
        return helper(preorder,inorder,0,b-1,0,a-1);
        
        
    }
};
