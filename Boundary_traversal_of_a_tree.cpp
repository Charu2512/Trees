#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> printBoundary(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void print_leftb(Node* root,vector<int> &res)
{  
    if(root==NULL)
    return ;
    if(root->left)
    {
        res.push_back(root->data);
        print_leftb(root->left,res);
    }
    else if(root->right)
    {
        res.push_back(root->data);
        print_leftb(root->right,res);
    }
}
void print_rightb(Node* root,vector<int> &v)
{   
    if(root==NULL)
    return ;
    if(root->right)
    {
        print_rightb(root->right,v);
        v.push_back(root->data);
    }
    else if(root->left)
    {
        
        print_rightb(root->left,v);
        v.push_back(root->data);
    }
    
}
void print_leafnodes(Node* root,vector<int> &v)
{   
    if(root==NULL)
    return ;
    print_leafnodes(root->left,v);
    if(root->left==NULL && root->right==NULL)
    v.push_back(root->data);
    print_leafnodes(root->right,v);
}

vector <int> printBoundary(Node *root)
{  vector<int> leftb;
   vector<int> rightb;
   vector<int> leaf_nodes;
   vector<int> res;

          
      if(root==NULL)
      return res;
      
      print_leftb(root->left,leftb);
      print_rightb(root->right,rightb);
      print_leafnodes(root->left,leaf_nodes);
      print_leafnodes(root->right,leaf_nodes);
      res.push_back(root->data);
      for(int i=0;i<leftb.size();i++)
      {
          res.push_back(leftb[i]);
      }
      for(int j=0;j<leaf_nodes.size();j++)
      {
          res.push_back(leaf_nodes[j]);
      }
      for(int k=0;k<rightb.size();k++)
      {
          res.push_back(rightb[k]);
      }
      return res;
      
      
    
}
