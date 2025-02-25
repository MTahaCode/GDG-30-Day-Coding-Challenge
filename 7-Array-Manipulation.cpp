#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> array(n + 1, 0);

    for (vector<int> query: queries) {
        array[query[0]] += query[2]; 
        array[query[1]] += -query[2];
    }

    long highest = 0, sum = 0;
    for (long val : array) {
        sum += val;
        highest = max(highest, sum);
    }
    
    return highest;
}

int main()
{
    std::cout << arrayManipulation(10, {{1,5,3}, {4,8,7}, {6,9,1}}) << std::endl;
    std::cout << arrayManipulation(5, {{1,2,100}, {2,5,100}, {3,4,100}}) << std::endl;

    return 0;
}
