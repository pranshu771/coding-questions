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

int depth(node *root) {
    if(!root) {
        return 0;
    }

    return 1 + max(depth(root->left),depth(root->right));
}

bool isBalanced(node *root) {
    if(!root) {
        return true;
    }

    if(abs(depth(root->left)-depth(root->right)<=1)&&isBalanced(root->left)&&isBalanced(root->right)) {
        return true;
    }
    else {
        return false;

    }
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
        bool ans = isBalanced(root);
        cout << ans << endl;
    }
}