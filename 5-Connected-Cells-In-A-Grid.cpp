#include <bits/stdc++.h>
#include <queue>

using namespace std;

/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

vector<pair<int, int>> getNeighbours(const vector<vector<int>>& matrix, int r, int c) {
    
    vector<pair<int, int>> neighbours;

    if (r+1 < (int)matrix.size()) neighbours.push_back({r+1, c  });
    if (c+1 < (int)matrix[0].size()) neighbours.push_back({r  , c+1});
    if (r-1 >= 0) neighbours.push_back({r-1, c  });
    if (c-1 >= 0) neighbours.push_back({r  , c-1});

    if (r+1 < (int)matrix.size() && c+1 < (int)matrix[0].size()) neighbours.push_back({r+1, c+1});
    if (r+1 < (int)matrix.size() && c-1 >= 0) neighbours.push_back({r+1, c-1});
    if (r-1 >= 0 && c-1 >= 0) neighbours.push_back({r-1, c-1});
    if (r-1 >= 0 && c+1 < (int)matrix[0].size()) neighbours.push_back({r-1, c+1});

    return neighbours;
}

int getRegionSize(const vector<vector<int>>& matrix, vector<vector<bool>>& visited, int r, int c) {
    queue<pair<int, int>> neighbouringQueue;
    neighbouringQueue.push({r, c});

    int regionSize = 0;
    while (!neighbouringQueue.empty()) {
        std::pair<int, int> current = neighbouringQueue.front();
        neighbouringQueue.pop();

        regionSize++;
        visited[current.first][current.second] = true;
        vector<pair<int, int>> neighbours = getNeighbours(matrix, current.first, current.second);

        for (pair<int, int> neighbour : neighbours) {
            if (visited[neighbour.first][neighbour.second]) {
                continue;
            }
            visited[neighbour.first][neighbour.second] = true;

            if (matrix[neighbour.first][neighbour.second] == 0) {
                continue;
            }
            neighbouringQueue.push(neighbour);
        }
    }
    return regionSize;
}

int connectedCell(vector<vector<int>> matrix) {
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

    int maxRegionSize = 0;
    for (int r = 0; r < (int)matrix.size(); r++) {
        for (int c = 0; c < (int)matrix[0].size(); c++) {

            bool visitedStatus = visited[r][c];
            if (visitedStatus) {
                continue;
            }

            if (matrix[r][c] == 0) {
                visited[r][c] = true;
                continue;
            }

            maxRegionSize = max(maxRegionSize, getRegionSize(matrix, visited, r, c));
        }
    }
    return maxRegionSize;
}

int main()
{
    std::cout << connectedCell(
        {
            {1,1,0,0,0},
            {0,1,1,0,0},
            {0,0,1,0,1},
            {1,0,0,0,1},
            {0,1,0,1,1}
        }
    );
}