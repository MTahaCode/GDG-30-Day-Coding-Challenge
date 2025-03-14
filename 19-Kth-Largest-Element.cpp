#include <bits/stdc++.h>
#include <queue>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kthLargest' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY nums
 *  2. INTEGER k
 */

int kthLargest(vector<int> nums, int k) {
    priority_queue<int, vector<int>, std::greater<int>> Queue;

    for (int num : nums) {
        Queue.push(num);

        if (Queue.size() > k) {
            Queue.pop();
        }
    }

    return Queue.top();
}

int main() {
    std::cout << kthLargest({3, 2, 1, 5, 6, 4}, 2);
}