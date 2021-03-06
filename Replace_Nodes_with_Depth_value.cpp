// CPP program to replace every key value
// with its depth.
#include<bits/stdc++.h>
using namespace std;

/* A tree node structure */
struct Node
{
	int data;
	struct Node *left, *right;
};

/* Utility function to create a
new Binary Tree node */
struct Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;	
	return temp;
}

// Helper function replaces the data with depth
// Note : Default value of level is 0 for root.
void replaceNode(struct Node *node, int level=0)
{
	if(node==NULL)
      return ;
  node->data=level;
  replaceNode(node->left,level+1);
  replaceNode(node->right,level+1);
  
}

// A utility function to print inorder
// traversal of a Binary Tree
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data <<" ";
	printInorder(node->right);
}

/* Driver function to test above functions */
int main()
{
	struct Node *root = new struct Node;

	/* Constructing tree given in
	the above figure */
	root = newNode(3);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	
	cout << "Before Replacing Nodes\n";	
	printInorder(root);
	replaceNode(root);
	cout << endl;
	
	cout << "After Replacing Nodes\n";
	printInorder(root);
	
	return 0;
}
