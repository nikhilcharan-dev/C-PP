#include <iostream>
#include <algorithm>

using namespace std;

string smallestString(string& s, int n) {
    string minString = s;
    int reverseCount = 0;
    int addCount = 0;

    for (int i = 0; i < n; ++i) {
        if (reverseCount % 2 == 0) {
            reverse(minString.begin(), minString.end());
            minString += s;
            addCount++;
        } else {
            minString += string(minString.rbegin(), minString.rend());
            addCount++;
        }
        reverseCount++;
    }

    if (reverseCount % 2 != 0) {
        reverse(minString.begin(), minString.end());
    }

    return minString;
}

int main() {
    int Tcases; cin >> Tcases;
    while(Tcases) {
        int num;
        cin >> num;

        string s;
        cin >> s;

        string result = smallestString(s, num);
        cout << result << endl;

        Tcases--;
    }
    return 0;
}
