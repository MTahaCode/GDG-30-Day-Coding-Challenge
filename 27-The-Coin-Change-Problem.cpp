#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

long getWays_recurr(int n, const vector<long>& c, std::map<pair<int,int>, long>& dp, int index = 0) {
    if (index >= (int)c.size() || n < 0) return 0;
    if (n == 0) return 1;

    std::pair<int, int> key = {n, index};
    if (dp.find(key) != dp.end()) return dp[key];

    dp[key] = getWays_recurr(n - c[index], c, dp, index) + getWays_recurr(n, c, dp, index + 1);
    return dp[key];
}

long getWays(int n, vector<long> c) {
    std::sort(c.begin(), c.end());
    std::map<pair<int, int>, long> dp;
    return getWays_recurr(n, c, dp);
}

int main() {
    std::cout << getWays(10, {1,2,3}) << std::endl;
}