// C++ program to check if a node exists
// in a binary tree
#include <iostream>
using namespace std;

// Binary tree node
struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

// Function to traverse the tree in preorder
// and check if the given node exists in it
bool ifNodeExists(struct Node* root, int key)
{
	if(root==NULL)
      return false;
    if(root->data ==key)
      return true;
  return(ifNodeExists(root->left,key) || ifNodeExists(root->right,key));}
// Driver Code
int main()
{
	struct Node* root = new Node(0);
	root->left = new Node(1);
	root->left->left = new Node(3);
	root->left->left->left = new Node(7);
	root->left->right = new Node(4);
	root->left->right->left = new Node(8);
	root->left->right->right = new Node(9);
	root->right = new Node(2);
	root->right->left = new Node(5);
	root->right->right = new Node(6);

	int key = 4;

	if (ifNodeExists(root, key))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
