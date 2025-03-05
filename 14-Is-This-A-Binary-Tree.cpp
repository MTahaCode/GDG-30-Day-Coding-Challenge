#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

bool checkBstRecur(Node* curr, int Max = INT_MAX, int Min = INT_MIN) {
    if (!curr) return true;

    if (Max <= curr->data || curr->data <= Min) return false;

    return checkBstRecur(curr->left, curr->data, Min) && checkBstRecur(curr->right, Max, curr->data);
}

bool checkBST(Node* root) {
    return checkBstRecur(root);
}

int main() {
    
}