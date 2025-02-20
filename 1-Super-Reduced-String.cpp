#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    //have a two char window, when encountered splice then go one step back do it till none left

    int windowIndex = 0;
    while (!s.empty()) {
        if (windowIndex == s.length() - 1) {
            return s;
        }

        if (s[windowIndex] == s[windowIndex + 1]){
            s.erase(s.begin() + windowIndex, s.begin() + windowIndex + 2);
            windowIndex = std::max(windowIndex - 1, 0);
        }
        else {
            windowIndex++;
        }
    }
    return "Empty String";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}