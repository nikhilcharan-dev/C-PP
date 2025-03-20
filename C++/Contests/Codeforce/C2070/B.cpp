/*Nikhil Codes*/
#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007
#define PI M_PI // acos(-1.0)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define setpoint(x) fixed << setprecision(x)
#define ln "\n"

typedef long long ll;
typedef vector<int> vii;
typedef vector<ll> vll;

#define forI(n) for(int i = 0; i < (n); i++)
#define forJ(n) for(int j = 0; j < (n); j++)
#define rofI(n) for(int i = (n) - 1; i >= 0; i--)
#define forIJ(n) for(int j = i; j < (n); j++)

// static const auto _ = [] {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return 0;
// }();

/*
-----Global Variables
*/
const ll N = 1e9;                        
/*                                                 
-----Global Variables
*/

template<typename T>
void getval(T& var) {
    cin >> var;
}

template<typename T>
vector<T> scan(ll var) {
    vector<T> arr(var);
    forI(var) {
        cin >> arr[i];
    }
    return arr;
}

template<typename T>
void peek(const vector<T>& var) {
    for (const auto& elem : var) {
        cout << elem << " ";
    }
    cout << "\n";
}

template<typename T>
void peek(T var) {
    cout << var << ln;
}

void InfiniteVoid() {
    // DATTEBAYO!
    ll n, x, k;
    cin >> n >> x >> k;

    string dir;
    cin >> dir;

    int cur = x;
    int zeros = 0;
    int firstZero = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(dir[i] == 'L') {
            cur--;
        } else {
            cur++;
        }

        if(!cur) {
            firstZero = min(firstZero, i);
            zeros++;
        }

    }

    if(!cur) {
        peek((k - n) / n + 1);
    } else {
        peek(zeros);
    }
}


void Testcases() {
    int Tcases;
    cin >> Tcases; 
    while(Tcases--) {
        cout << "processing: ";
        InfiniteVoid();
        cout << "Done!!!";
    }
}

int main() {
    Testcases();
    return 0;
}