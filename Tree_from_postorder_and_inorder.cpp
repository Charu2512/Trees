/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int find(int in[],int start,int end,int val)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==val)
        return i;
    }
}

Node *helper(int in[],int post[],int in_s,int in_e,int post_s,int post_e)
{
    if(in_s>in_e)
    return NULL;
    int val=post[post_e];
    int pos=find(in,in_s,in_e,val);
    int l_in_s=in_s;
    int l_in_e=pos-1;
    int l_post_s=post_s;
    int l_post_e=l_in_e-l_in_s+l_post_s;
    int r_in_s=pos+1;
    int r_in_e=in_e;
   
    int r_post_e=post_e-1;
     int r_post_s=r_post_e-r_in_e+r_in_s;
     Node* temp=new Node(val);
     temp->left=helper(in,post,l_in_s,l_in_e,l_post_s,l_post_e);
     temp->right=helper(in,post,r_in_s,r_in_e,r_post_s,r_post_e);
     return temp;
    
    
}
Node *buildTree(int in[], int post[], int n) {
    return helper(in,post,0,n-1,0,n-1);
    
}
