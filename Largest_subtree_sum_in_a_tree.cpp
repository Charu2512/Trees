// C++ program to find largest subtree
// sum in a given binary tree.
#include <bits/stdc++.h>
using namespace std;

// Structure of a tree node.
struct Node {
	int key;
	Node *left, *right;
};

// Function to create new tree node.
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// Helper function to find largest
// subtree sum recursively.
int sum(Node* root)
{
  if(root==NULL)
    return 0;
  return root->key+sum(root->left)+sum(root->right);
}
void findLargestSubtreeSumUtil(Node* root, vector<int> &v)
{
	if(root==NULL)
      return;
  findLargestSubtreeSumUtil(root->left,v);
  v.push_back(sum(root));
  findLargestSubtreeSumUtil(root->right,v);
  
  

  }

// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
	// If tree does not exist,
	// then answer is 0.
	if (root == NULL)	
		return 0;
	vector<int> v;
	// Variable to store maximum subtree sum.
	findLargestSubtreeSumUtil(root, v);
    sort(v.begin(),v.end());
  int t=v.size();
  return v[t-1];
}

// Driver function
int main()
{
	/*
			1
			/ \
			/	 \
		-2	 3
		/ \	 / \
		/ \ / \
		4	 5 -6	 2
	*/

	Node* root = newNode(1);
	root->left = newNode(-2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(-6);
	root->right->right = newNode(2);

	cout << findLargestSubtreeSum(root);
	return 0;
}
