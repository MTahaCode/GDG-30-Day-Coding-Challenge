#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'containerWithMostWater' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY height as parameter.
 */

int containerWithMostWater(vector<int> height) {

    int maxArea = 0;
    int leftWall = 0, rightWall = height.size() - 1;
    while (leftWall < rightWall) {
        int currHeight = std::min(height[leftWall], height[rightWall]);
        int currWidth = rightWall - leftWall;
        maxArea = std::max(currHeight * currWidth, maxArea);

        (height[leftWall] < height[rightWall]) ? leftWall++ : rightWall--;
        std::cout << "Current Area: " << maxArea << std::endl;
    }
    return maxArea;
}

int main() {
    std::cout << containerWithMostWater({1,8,6,2,5,4,8,3,7}) << std::endl;
}