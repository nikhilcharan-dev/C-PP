#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool ispalindrome(string str) {
    string rev;
    rev.reserve(str.size());
    remove_copy_if(str.begin(), str.end(), back_inserter(rev), [](char c) {
        return !isalnum(c);
    });
    transform(rev.begin(), rev.end(), rev.begin(), ::tolower);
    return rev == string(rev.rbegin(), rev.rend());
}

int main() {
    cout << ispalindrome("1221");
}