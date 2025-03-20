#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 31;
const int MOD = 1e9 + 7;

ll compute_hash(const string& s) {
    ll hash_value = 0;
    ll p_pow = 1; // p^0 = 1 initially
    for (char c : s) {
        int char_val = c - 'a' + 1; // Convert 'a' to 1, 'b' to 2, etc.
        hash_value = (hash_value + char_val * p_pow) % MOD;
        p_pow = (p_pow * P) % MOD;
    }
    return hash_value;
}

int main() {
    string s = "hello";
    cout << "Hash of " << s << ": " << compute_hash(s) << endl;
    return 0;
}
