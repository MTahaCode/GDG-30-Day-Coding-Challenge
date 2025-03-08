#include <bits/stdc++.h>
#include <queue>

using namespace std;

int cookies(int k, vector<int> A) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> Queue(A.begin(), A.end());

    int counter = 0;
    while (Queue.size() > 1 && Queue.top() < k) {
        int least = Queue.top();
        Queue.pop();

        int second_least = Queue.top();
        Queue.pop();

        Queue.push(least + 2 * second_least);
        counter++;
    }
    return (Queue.top() >= k) ? counter : -1;
}

int main() {
    std::cout << cookies(9, {2,7,3,6,4,6});
}