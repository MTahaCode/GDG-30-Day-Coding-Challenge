#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

// Function to calculate cost of roads and library for a connected component
long nodeCost(
    int node,
    unordered_map<int, vector<int>>& Graph, 
    unordered_set<int>& Visited,
    int c_lib,
    int c_road
) {
    stack<int> node_stack;
    node_stack.push(node);
    Visited.insert(node);  // Mark as visited when adding

    int component_size = 0;

    while (!node_stack.empty()) {
        int curr = node_stack.top();
        node_stack.pop();
        component_size++;

        for (int child : Graph[curr]) {
            if (!Visited.count(child)) {
                Visited.insert(child);
                node_stack.push(child);
            }
        }
    }

    // One library for the component + roads for the remaining nodes
    return c_lib + (component_size - 1) * c_road;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if (c_lib <= c_road) {
        return (long)n * c_lib;  // It's cheaper to build a library in each city
    }

    unordered_map<int, vector<int>> Graph;
    for (const auto& connection : cities) {
        Graph[connection[0]].push_back(connection[1]);
        Graph[connection[1]].push_back(connection[0]);
    }

    long total_cost = 0;
    unordered_set<int> Visited;

    for (int i = 1; i <= n; i++) {
        if (!Visited.count(i)) {
            // Ensure isolated cities are processed
            total_cost += nodeCost(i, Graph, Visited, c_lib, c_road);
        }
    }

    return total_cost;
}

int main() {
    /*
    6 6 2 5     n = 6, cities[] size m = 6, c_lib = 2, c_road = 5
    1 3         cities = [[1, 3], [3, 4],...]
    3 4
    2 4
    1 2
    2 3
    5 6
*/

// 3 3 2 1     n = 3, cities[] size m = 3, c_lib = 2, c_road = 1
// 1 2         cities = [[1, 2], [3, 1], [2, 3]]
    std::cout << roadsAndLibraries(6, 2, 5, {{1,3}, {3,4}, {2,4}, {1,2}, {2,3}, {5,6}}) << std::endl;
    std::cout << roadsAndLibraries(3, 2, 1, {{1, 2}, {3, 1}, {2, 3}}) << std::endl;
}