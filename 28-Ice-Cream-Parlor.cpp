#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'icecreamParlor' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. INTEGER_ARRAY arr
 */

vector<int> icecreamParlor(int m, vector<int> arr) {
    std::unordered_map<int, int> priceMap;

    for (int i=0; i<arr.size(); i++) {
        int complement = m - arr[i];

        if (priceMap.count(complement)) {
            return {priceMap[complement], i+1};
        }

        priceMap[arr[i]] = i+1;
    }
    return {-1, -1};
}

int main() {
    list<int> List({1,2,3});
    while(List.size()) {
        std::cout << *List.begin() << std::endl;
        List.pop_front();
    }

    vector<int> Answer = icecreamParlor(4, {1,4,5,3,2});
    std::cout << Answer[0] << " : " << Answer[1] << std::endl << std::endl;

    Answer = icecreamParlor(4, {2,2,4,3});
    std::cout << Answer[0] << " : " << Answer[1] << std::endl;
}