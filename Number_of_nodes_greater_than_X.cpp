// C++ program to find number of nodes
// greater than x
#include <bits/stdc++.h>
using namespace std;

// Structure of a node of n-ary tree
struct Node {
	int key;
	vector<Node*> child;
};

// Utility function to create
// a new tree node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	return temp;
}

// Function to find nuber of nodes
// gretaer than x
int nodesGreaterThanX(Node* root, int x)
{
	if(root==NULL)
      return 0;
  int count=0;
  if(root->key>x)
    count++;
  for(int i=0;i<root->child.size();i++)
  {
    count+=nodesGreaterThanX(root->child[i],x);
  }
  return count;
}

// Driver program
int main()
{
	/* Let us create below tree
*		 5
*		 / | \
*	 1 2 3
*	 / / \ \
*	 15 4 5 6
*/

	Node* root = newNode(5);
	(root->child).push_back(newNode(1));
	(root->child).push_back(newNode(2));
	(root->child).push_back(newNode(3));
	(root->child[0]->child).push_back(newNode(15));
	(root->child[1]->child).push_back(newNode(4));
	(root->child[1]->child).push_back(newNode(5));
	(root->child[2]->child).push_back(newNode(6));

	int x = 1;

	cout << "Number of nodes greater than "
		<< x << " are ";
	cout << nodesGreaterThanX(root, x)
		<< endl;

	return 0;
}
