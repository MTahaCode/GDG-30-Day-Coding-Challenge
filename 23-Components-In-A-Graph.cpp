#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */

int countConnectedNodes(
    int& Current, 
    std::unordered_map<int, vector<int>>& Connects, 
    std::unordered_set<int>& Visited
) {
    if (Visited.count(Current)) {
        return 0;
    }
    Visited.insert(Current);
    int counter = 1;
    for(int neigbour : Connects[Current]) {
        counter += countConnectedNodes(neigbour, Connects, Visited);
    }
    return counter;
}

vector<int> componentsInGraph(vector<vector<int>> gb) {

    //vectors converted into dictionary
    std::unordered_map<int, vector<int>> Connects;
    for (std::vector<int> con : gb) {
        Connects[con[0]].push_back(con[1]);
        Connects[con[1]].push_back(con[0]);
    }

    std::unordered_set<int> Visited;
    int min = INT_MAX;
    int max = INT_MIN;
    for (std::pair<int, vector<int>> Pair : Connects) {

        int counter = countConnectedNodes(Pair.first, Connects, Visited);
        if (counter >= 2) {
            min = std::min(min, counter);
        }
        max = std::max(max, counter);
    }
    return {min, max};
}

int main() {

    std::vector<vector<int>> bg = {{1, 6}, {2, 7}, {3, 8}, {4, 9}, {2, 6}};
    for (int val : componentsInGraph(bg)) {
        std::cout << val << " ";
    }
}