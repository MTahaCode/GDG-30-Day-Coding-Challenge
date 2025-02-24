#include <bits/stdc++.h>
#include <stack>

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

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* current1 = head1;
    SinglyLinkedListNode* current2 = head2;

    while (current1 != current2) {
        current1 = (current1->next == nullptr) ? head2 : current1->next;
        current2 = (current2->next == nullptr) ? head1 : current2->next;
    }
    return (!current1) ? -1 : current1->data;
}

int main() {
    // Creating two separate linked lists
    SinglyLinkedList list1;
    SinglyLinkedList list2;

    // Inserting nodes into the first list
    list1.insert_node(1);
    list1.insert_node(2);
    list1.insert_node(3);

    // Inserting nodes into the second list
    list2.insert_node(6);
    list2.insert_node(7);

    // Creating a merge point
    SinglyLinkedListNode* mergeNode = new SinglyLinkedListNode(8);
    list1.tail->next = mergeNode; // Connecting list1 to merge node
    list2.tail->next = mergeNode; // Connecting list2 to merge node

    // Continuing the merged list
    mergeNode->next = new SinglyLinkedListNode(9);
    mergeNode->next->next = new SinglyLinkedListNode(10);

    //printing the nodes
    SinglyLinkedListNode* current1 = list1.head;
    while (current1) {
        std::cout << current1->data << " ";
        current1 = current1->next;
    }
    std::cout << std::endl;

    SinglyLinkedListNode* current2 = list2.head;
    while (current2) {
        std::cout << current2->data << " ";
        current2 = current2->next;
    }
    std::cout << std::endl;

    // Finding the merge node
    int mergeData = findMergeNode(list1.head, list2.head);

    // Output the result
    cout << "Merge Node Data: " << mergeData << endl;

    // Free allocated memory
    free_singly_linked_list(list1.head);
    free_singly_linked_list(list2.head);

    return 0;
}