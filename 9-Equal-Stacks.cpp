#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    //first find the total height of all
    //then one by one minus it from each from top
    //once they are all same return

    int h1_height = accumulate(h1.begin(), h1.end(), 0);
    int h2_height = accumulate(h2.begin(), h2.end(), 0);
    int h3_height = accumulate(h3.begin(), h3.end(), 0);

    int h1_index = 0, h2_index = 0, h3_index = 0;
    while (h1_height > 0 && h2_height > 0 && h3_height > 0 && !(h1_height == h2_height && h2_height == h3_height)) {
        int minimum_height = std::min({h1_height, h2_height, h3_height});
        
        if (h1_height > minimum_height) {
            h1_height -= h1[h1_index];
            h1_index++;
        }
        if (h2_height > minimum_height) {
            h2_height -= h2[h2_index];
            h2_index++;
        }
        if (h3_height > minimum_height) {
            h3_height -= h3[h3_index];
            h3_index++;
        }
    }
    return std::min({h1_height, h2_height, h3_height});
}

int main() {
    std::cout << equalStacks({1,2,1,1}, {1,1,2}, {1,1}) << std::endl;
}