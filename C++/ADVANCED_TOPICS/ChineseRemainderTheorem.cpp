#include <bits/stdc++.h>
using namespace std;

// Inverse Mod
int mod_inverse(int a, int m) {
    int m0 = m, y = 0, x = 1;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    return (x + m0) % m0;
}

int minimum_x(vector<int>& n, vector<int>& a) {
    int N = 1;
    for(auto& num: n) N *= num;

    for(int i = 0; i < a.size(); i++) {
        int Ni = N / n[i];
        int Mi = mod_inverse(Ni, n[i]);
        int X = a[i] * Ni * Mi;
    }
}

int main() {
    vector<int> n = {3, 4, 5}; // Moduli
    vector<int> a = {2, 3, 1}; // Remainders

    int result = minimum_x(n, a);
}