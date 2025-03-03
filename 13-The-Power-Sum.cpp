#include <bits/stdc++.h>
#include <map>

using namespace std;

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

int powerSumRecurr(int X, int N, map<pair<int, int>, int>& dp, int num = 1) {
    if (X == 0) return 1;
    if (X < 0 || X < pow(num, N)) return 0;

    pair<int, int> key = {X, num};

    if (dp.find(key) != dp.end()) {
        return dp[key];
    }

    dp[key] = powerSumRecurr(X - pow(num, N), N, dp, num + 1) + powerSumRecurr(X, N, dp, num + 1);

    return dp[key];
}

int powerSum(int X, int N) {
    map<pair<int, int>, int> dp;
    return powerSumRecurr(X, N, dp, 1);
}

int main() {
    std::cout << powerSum(1000, 2) << std::endl;
}