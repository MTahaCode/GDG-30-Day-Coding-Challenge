#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

class BinarySearchTreeNode {
public:
    int data;
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;

    BinarySearchTreeNode(int node_data) {
        data = node_data;
        left = right = NULL;
    }
};

BinarySearchTreeNode* insert_node_into_binary_search_tree(BinarySearchTreeNode* root, int node_data) {
    if (!root) {
        root = new BinarySearchTreeNode(node_data);
    } else {
        if (node_data <= root->data) {
            root->left = insert_node_into_binary_search_tree(root->left, node_data);
        } else {
            root->right = insert_node_into_binary_search_tree(root->right, node_data);
        }
    }

    return root;
}

void print_binary_search_tree_inorder_traversal(BinarySearchTreeNode* root, string sep, ofstream& fout) {
    if (!root) {
        return;
    }

    print_binary_search_tree_inorder_traversal(root->left, sep, fout);

    if (root->left) {
        fout << sep;
    }

    fout << root->data;

    if (root->right) {
        fout << sep;
    }

    print_binary_search_tree_inorder_traversal(root->right, sep, fout);
}

BinarySearchTreeNode* listToBST(SinglyLinkedListNode* head) {
    if (!head) return nullptr;
    if (!head->next) {
        return new BinarySearchTreeNode(head->data);
    }
    
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    while (fast && fast->next && fast->next->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    //now slow is in the middle

    SinglyLinkedListNode* leftList = head;
    SinglyLinkedListNode* rightList = slow->next;

    if (prev) {
        prev->next = nullptr;
    }
    else {
        leftList = nullptr;
    }

    BinarySearchTreeNode* currBinary = new BinarySearchTreeNode(slow->data);
    currBinary->left = listToBST(leftList);
    currBinary->right = listToBST(rightList);
    return currBinary;
}

int main() {
    //-10,-9,-3,0,5,9,11,15
}