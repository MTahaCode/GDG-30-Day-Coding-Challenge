#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'find_repeated_sequences' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING s as parameter.
 */

vector<string> find_repeated_sequences(string s) {
    std::unordered_map<string, int> SeqMap;
    std::vector<string> Repeated;

    for (int i=0; i+10<=s.length(); i++) {
        string sequence = s.substr(i, 10);
        SeqMap[sequence]++;

        if (SeqMap[sequence] == 2) {
            Repeated.push_back(sequence);
        }
    }
    return Repeated;
}

int main()
{
    cout << find_repeated_sequences("AAAAACCC").size();
}