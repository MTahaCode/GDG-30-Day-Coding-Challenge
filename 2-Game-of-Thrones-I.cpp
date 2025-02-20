#include <bits/stdc++.h>
#include <map>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {

    map<char, int> palindromeCounter;

    for (int i=0; i < s.length(); i++) {
        palindromeCounter[s[i]]++;
    }

    int oddCounter = 0;
    for (std::pair<char, int> Pair : palindromeCounter) {
        if (Pair.second % 2 == 1) {
            oddCounter++;
        }
    }
    return (oddCounter > 1) ? "NO" : "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
