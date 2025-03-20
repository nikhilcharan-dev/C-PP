// #include <bits/stdc++.h>
// using namespace std;

// using ld = long double;

// void solve() {
//     int n, a, b;
//     cin >> n >> a >> b;


// }


// int main() {
//     solve();
// }


#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes
    int n, a, b;
    cin >> n >> a >> b;

    int count[n + 1][6 * n + 1] = {0};

    for(int i = 1; i <= 6; i++) count[1][i] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= 6 * n; j++) {
            for(int k= max(1, j - 6); k < j; k++){
                count[i][j] += count[i-1][k];
            }
        }
    }

    long double sum = 0;
    for(int i = a; i <= b; i++) sum += 
    cout << fixed << setprecision(6) << sum;
}