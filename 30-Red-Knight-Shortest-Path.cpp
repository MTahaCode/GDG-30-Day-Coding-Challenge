#include <bits/stdc++.h>
#include <queue>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'printShortestPath' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER i_start
 *  3. INTEGER j_start
 *  4. INTEGER i_end
 *  5. INTEGER j_end
 */

const std::vector<pair<string, pair<int, int>>> MoveMap = {
    {"UL", {-2, -1} },
    {"UR", {-2,  1} },
    {"R" , {0 ,  2} },
    {"LR", {2 ,  1} },
    {"LL", {2 , -1} },
    {"L" , {0 , -2} },
};

vector<std::tuple<int, int, string>> getValidMoves(int n, int i, int j) {
    vector<tuple<int, int, string>> ValidMoves;

    for (const auto& curr : MoveMap) {
        int new_i = i + curr.second.first;
        int new_j = j + curr.second.second;

        if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n) {
            continue;
        }
        ValidMoves.push_back({new_i, new_j, curr.first});
    }
    return ValidMoves;
}

//i is row and j is col
void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    
    std::queue<pair<int, int>> Bfs;
    std::map<pair<int, int>, pair<pair<int, int>, string>> parent;
    std::set<pair<int, int>> Visited;

    Bfs.push({i_start, j_start});
    
    while (!Bfs.empty()) {
        auto [i, j] = Bfs.front();
        Bfs.pop();

        //add to visited
        // Visited.insert({i, j});

        //if found do return stuff
        if (i == i_end && j == j_end) {
            
            vector<string> path;
            pair<int, int> current = {i, j};

            while (current != pair<int, int>{i_start, j_start}) {
                auto [parent_pos, move] = parent[current];
                path.push_back(move);
                current = parent_pos;
            }

            std::cout << path.size() << std::endl;
            reverse(path.begin(), path.end());
            for (const string& move: path) {
                std::cout << move << " ";
            }
            std::cout << std::endl;
            return;
        }

        vector<tuple<int, int, string>> validMoves = getValidMoves(n, i, j);
        for (const auto& move : validMoves) {
            auto [move_i, move_j, move_path] = move;

            if ( Visited.count({move_i, move_j}) ) {
                continue;
            }
            // vector<string> newPath = path;
            // newPath.push_back(move_path);
            Visited.insert({move_i, move_j});
            parent[{move_i, move_j}] = {{ i, j}, move_path};
            Bfs.push({move_i, move_j});
        }
    }
    std::cout << "Impossible";
}

int main() {
    printShortestPath(7, 6, 6, 0, 1);
}