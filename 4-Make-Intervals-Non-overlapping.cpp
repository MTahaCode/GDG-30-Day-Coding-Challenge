#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'removeOverlapping' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY intervals as parameter.
 */

int removeOverlapping(vector<vector<int>> intervals) {

    std::sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& interval1, const vector<int>& interval2) {
            if (interval1[0] == interval2[0]) {
                return interval1[1] < interval2[1];
            }
            return interval1[0] < interval2[0];
        }
    );

    int minRemovable = 0;

    int index = 0;
    while (index < intervals.size() - 1) {
        vector<int>& current = intervals[index];
        vector<int>& next = intervals[index + 1];

        if (current[1] > next[0]) {
            intervals.erase(intervals.begin() + index + 1);
            minRemovable++;
        }
        else {
            index++;
        }
    }
    return minRemovable;
}

int main()
{
    std::cout << removeOverlapping({ {1,2}, {2,3}, {3,4}, {1,3} });
}