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

    if (intervals.size() == 0) {
        return 0;
    }

    std::sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& interval1, const vector<int>& interval2) {
            if (interval1[0] == interval2[0]) {
                return interval1[1] < interval2[1];
            }
            return interval1[0] < interval2[0];
        }
    );

    int minRemovable = 0;
    int lastEnd = intervals[0][1];

    for (int i=1; i<intervals.size(); i++) {
        vector<int>& curr_interval = intervals[i];

        if (curr_interval[0] < lastEnd) {
            minRemovable++;
            lastEnd = min(lastEnd, curr_interval[1]);
        }
        else {
            lastEnd = curr_interval[1];
        }
    }
    return minRemovable;
}

int main()
{
    std::cout << removeOverlapping({ {1,2}, {2,3}, {3,4}, {1,3} });
}