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

void printZigZagTree(node *root) {

    if(root==NULL) {
        return;
    }

    stack<node *> cur;
    stack<node *> next;
    cur.push(NULL);
    cur.push(root);
    next.push(NULL);
    node *first;

    while(!cur.empty()) {
        first = cur.top();
        if(first)
    }

    node *first;
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

        printZigZagTree(root);
        
    }
}