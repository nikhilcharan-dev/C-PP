#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

vector<long long> fact(MAXN + 1), invFact(MAXN + 1);

long long power(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = power(fact[i], MOD - 2, MOD);
    }
}

long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * invFact[r] % MOD * invFact[n - r] % MOD) % MOD;
}

int main() {
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        cout << nCr(n, r) << '\n';
    }

    return 0;
}
