#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
	public:
		int key;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};


// Use this function to create a Binary Search Tree (BST) tree with the following values
// {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1}
Node* createTree() {
    Node* root = new Node(13);

    // Level 1
    root->left = new Node(0);
    root->right = new Node(21);

    // Level 2
    root->left->left = new Node(-2);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(99);

    // Level 3
    root->left->left->right = new Node(-1);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(12);
    root->right->left->right = new Node(18);

    // Level 4
    root->right->left->right->right = new Node(19);

    return root;
}

// Write a function that will search the BST for a target value
//	input: integer target to search for,
			// pointer to root Node
// 	returns: true or false depending on if the value is found
// You should write this function recursively! What is the base case? What is the general case?
bool searchTree(int target, Node* root) {
	// Base cases
    if (root == nullptr) {
        return false;
    }
    if (root->key == target) {
        return true;
    }

    // General case:
    if (target < root->key) {
        return searchTree(target, root->left);
    } else {
        return searchTree(target, root->right);
    }
	
}

// Write a function that will return the total number of Nodes in the tree
// 	input: pointer to the root Node
// 	returns: number of nodes currently in the tree
// You should write this function recursively!
int treeSize(Node* root) {
	// Base case
    if (root == nullptr) {
        return 0;
    }

    // General case
    return 1 + treeSize(root->left) + treeSize(root->right);

}

// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {
	// Base case
    if (root == nullptr) {
        return 0;
    }

    // General case
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}