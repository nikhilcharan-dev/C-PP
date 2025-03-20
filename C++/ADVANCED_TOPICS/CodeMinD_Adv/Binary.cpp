#include <bits/stdc++.h>
using namespace std;

void solver() {
    int num;
    cin >> num;
    string ans = bitset<32> (num).to_string();
    int i = ans.find_first_not_of('0');
    string res(ans.begin() + i, ans.end());
    cout << res << endl;
}

int main() {
    int Tcases;
    cin >> Tcases;
    while(Tcases--) {
        solver();
    }
    return 0;
}