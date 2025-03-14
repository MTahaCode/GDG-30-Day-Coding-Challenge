#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'climbingStairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int climbingStairsWithDp(int n, std::map<int, int>& dp) {
    if (n <= 1) return 1;
    if (n == 2) return 2;

    if (dp.find(n) != dp.end()) {
        return dp[n];
    }

    dp[n] = climbingStairsWithDp(n-1, dp) + climbingStairsWithDp(n-2, dp);
    return dp[n];
}

int climbingStairs(int n) {
    std::map<int, int> dp;
    return climbingStairsWithDp(n, dp);
}

int main() {
    std::cout << "The Value: " << climbingStairs(4) << std::endl;
}