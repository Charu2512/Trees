/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        if(root==NULL)
            return res;
        queue<Node*> q;
        
        q.push(root);
        while(q.empty()==false)
        {   int p=q.size();
         vector<int> v;
         for(int j=0;j<p;j++){
            
           
            Node* t=q.front();
            v.push_back(t->val);
            q.pop();
            int len=(t->children).size();
            for(int i=0;i<len;i++)
            {
                q.push(t->children[i]);
            }
            
             
         }
          res.push_back(v);
            
        }
        return res;
        
    }
};
