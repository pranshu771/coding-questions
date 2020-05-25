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

void printLevelOrder(node *root) {
    if(!root) {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node *temp=q.front();
        q.pop();
        if (temp == NULL)
        {
            if(q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
        }
        else {
            cout << temp->data <<" ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
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

        printLevelOrder(root);
        cout << endl;
    }
}