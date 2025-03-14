#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'canFinish' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. INTEGER numCourses
 *  2. 2D_INTEGER_ARRAY prerequisites
 */

bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
    // std::unordered_map<int, std::pair<int, bool>> Course_to_PreReq_and_Visited;

    // for (std::vector<int> preReq : prerequisites) {
    //     Course_to_PreReq_and_Visited[preReq[0]] = {preReq[1], false};
    // }

    // std::unordered_set<int> Visited;
    // for (std::pair<int, std::pair<int, bool>> entry : Course_to_PreReq_and_Visited) {
    //     if (entry.second.second) continue;

    //     int original = entry.first;
    //     int current = entry.first;
    //     while (Course_to_PreReq_and_Visited.count(current)) {
    //         Course_to_PreReq_and_Visited[current].second = true;
    //         current = Course_to_PreReq_and_Visited[current].first;

    //         if (current == original) return false;
    //     }
    // }
    // return true;

    std::unordered_map<int, int> Map;
    for (std::vector<int> preReq : prerequisites) {
        Map[preReq[0]] = preReq[1];
    }

    std::unordered_set<int> Visited;
    for (std::pair<int, int> entry : Map) {
        if (Visited.find(entry.first) != Visited.end()) continue;

        int slow = entry.first, fast = entry.first;
        while (Map.count(fast) && Map.count(Map[fast])) {
            slow = Map[slow];
            fast = Map[Map[fast]];

            if (slow == fast) return false;
        } 
    }
    return true;
}

int main() {
    std::cout << ((canFinish(3, {{0,1},{1,2},{2,0}})) ? "true" : "false") << std::endl;
}