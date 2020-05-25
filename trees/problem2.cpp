#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;

    node (int data) {
        this->data = data;
        left = right = NULL;
    }
};

void insert(node* root,int key) {

    if(!root) {
        root = new node(key);
        return;
    }
    queue<node *> q;
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(!temp->left) {
            temp->left = new node(key);
            break;
        }
        else {
            q.push(temp->left);
        }

        if(!temp->right) {
            temp->right = new node(key);
            break;
        }
        else {
            q.push(temp->right);
        }
    }

    return;
}

node* createBinaryTree(int *arr,int n) {
    node *root = new node(arr[0]);
    for (int i = 1; i < n; i++)
    {
        insert(root, arr[i]);
    }
    return root;
}

void printInOrder(node* root) {

    if(!root) {
        
        return;
    }

    
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int FindSum(node *root) {
    if(!root) {
        return 0;
    }

    return root->data + FindSum(root->left) + FindSum(root->right);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n;i++) {
            cin >> arr[i];
        }
        
        node* root=createBinaryTree(arr,n);
        int sum = FindSum(root);
        cout << sum << endl;
    }
}