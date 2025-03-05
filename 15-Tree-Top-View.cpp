#include <iostream>
#include <queue>
#include <map>

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

void topView(Node* root) {
    
    std::map<int, int> topViewMap;

    std::queue<std::pair<Node*, int>> Queue;
    Queue.push({root, 0});
    while(!Queue.empty()) {
        std::pair<Node*, int> current = Queue.front();
        Queue.pop();

        if (!current.first) continue;

        if (topViewMap.find(current.second) == topViewMap.end()) {
            topViewMap[current.second] = current.first->data;
        }

        Queue.push({current.first->left, current.second - 1});
        Queue.push({current.first->right, current.second + 1});
    }

    for (std::pair<int, int> curr : topViewMap) {
        std::cout << curr.second << " ";
    }
}

int main() {

}