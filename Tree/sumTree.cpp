#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree()
{
    int data;
    cout<< "enter the data" << endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    cout<<"enter the data for "<< root->data<<" left"<<endl;
    root->left = buildTree();
    cout<<"enter the data for "<<root->right<<" right"<<endl;
    root->right = buildTree();

    return root;

}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int sumTree(Node*& root){
    if(root == NULL){
        return 0;
    }

    int leftsum = sumTree(root->left);
    int rightsum = sumTree(root->right);
    root->data = leftsum + root->data + rightsum;

    return root->data;
}

int main()
{
    Node* root = buildTree();
    levelOrderTraversal(root);
    cout<<endl;
    sumTree(root);
    levelOrderTraversal(root);
}

