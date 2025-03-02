#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'circularGame' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

int circularGame(int n, int k) {
    int result = 0;

    for (int i=2; i<=n; i++) {
        result = (result + k) % i;
    }
    return result + 1;
}

int main() {
    std::cout << circularGame(6, 2) << std::endl;
}