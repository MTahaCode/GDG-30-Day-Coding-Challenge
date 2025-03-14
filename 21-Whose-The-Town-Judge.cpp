#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'findTownJudge' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY trust
 */

int findTownJudge(int n, vector<vector<int>> trust) {
    std::vector<int> truster(n, 0);
    std::vector<int> trustee(n, 0);

    for(std::vector<int> curr : trust) {
        truster[curr[0] - 1]++;
        trustee[curr[1] - 1]++;
    }

    for (int i=0; i<n; i++) {
        if (truster[i] == 0 && trustee[i] == n - 1) {
            return i+1;
        }
    }
    return -1;
}

int main() {

}