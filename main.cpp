#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// allocate a new node
struct node* new_node(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// count leaf nodes in a binary tree
unsigned int count_leaf_node(struct node* node) {
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return 1;
    } else {
        return count_leaf_node(node->left) +
            count_leaf_node(node->right);
    }
}

int main() {
    struct node* root = new_node(1);

    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    cout << "Leaf count of the tree: " << count_leaf_node(root) << endl;

    return 0;
}
