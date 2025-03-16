#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shortestPath' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY a
 *  2. 2D_INTEGER_ARRAY queries
 */

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int a_star(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    int rows = grid.size();
    if (rows == 0) return -1;
    int cols = grid[0].size();
    if (cols == 0) return -1;

    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<>> pq;

    auto heuristic = [&](pair<int, int> pos) {
        return abs(pos.first - end.first) + abs(pos.second - end.second);
    };

    dist[start.first][start.second] = grid[start.first][start.second];
    int start_priority = dist[start.first][start.second] + heuristic(start);
    pq.push({start_priority, start});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int stored_priority = current.first;
        auto [row, col] = current.second;

        int stored_cost = stored_priority - heuristic({row, col});
        if (stored_cost > dist[row][col]) continue;

        if (row == end.first && col == end.second) return dist[row][col];

        for (int i = 0; i < 4; ++i) {
            int new_row = row + dx[i];
            int new_col = col + dy[i];

            if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols) continue;

            int new_cost = dist[row][col] + grid[new_row][new_col];

            if (new_cost < dist[new_row][new_col]) {
                dist[new_row][new_col] = new_cost;
                int priority = new_cost + heuristic({new_row, new_col});
                pq.push({priority, {new_row, new_col}});
            }
        }
    }

    return -1;
}

vector<int> shortestPath(vector<vector<int>> grid, vector<vector<int>> queries) {
    vector<int> results;
    for (auto& query : queries) {
        int start_row = query[0], start_col = query[1];
        int end_row = query[2], end_col = query[3];

        if (start_row < 0 || start_row >= grid.size() || 
            start_col < 0 || start_col >= grid[0].size() ||
            end_row < 0 || end_row >= grid.size() || 
            end_col < 0 || end_col >= grid[0].size()) {
            results.push_back(-1);
            continue;
        }

        int cost = a_star(grid, {start_row, start_col}, {end_row, end_col});
        results.push_back(cost);
    }
    return results;
}

int main() {

}