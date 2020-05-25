#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node (int data) {
        this->data = data;
        left = right = NULL;
    }
};

void InOrder(Node *temp) {
    if(!temp) {
        return;
    }
    InOrder(temp->left);
    cout << temp->data<<" ";
    InOrder(temp->right);
}

void insert(Node *temp,int key) {

    if(!temp) {
        temp = new Node(key);
        return;
    }

    queue<Node *> q;
    q.push(temp);

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if(!temp->left) {
            temp->left = new Node(key);
            break;
        }
        else {
            q.push(temp->left);
        }
        if(!temp->right) {
            temp->right = new Node(key);
            break;
        }
        else {
            q.push(temp->right);
        }
    }
}

int main() {
    // Node *root = new Node(2);
    // root->left = new Node(11);
    // root->right = new Node(9);
    // root->right->left = new Node(15);
    // root->right->right = new Node(8);
    // root->left->left = new Node(7);
    Node *root = NULL;

    insert(root,32);
    InOrder(root);
    cout << endl;
}