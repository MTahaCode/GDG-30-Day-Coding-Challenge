class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = nullptr;
            right = nullptr;
        }
};
  
Node* lca(Node *root, int v1,int v2) {
    if (!root) return nullptr;
    if (root->data == v1 || root->data == v2) return root;

    Node* left = lca(root->left, v1, v2);
    Node* right = lca(root->right, v1, v2);

    if (left && right) return root;
    return (left) ? left : right;
}

int main() {

}