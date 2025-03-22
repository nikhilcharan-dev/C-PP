   /*Nikhil Codes*/
#include <bits/stdc++.h>
using namespace std;

#define MOD (1e9 + 7)
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

static const auto _ = [] {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

/*
-----Global Variables
*/
long long len;                          
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

void Problem3() {
    // DATTEBAYO!
    ll n, k;
    cin >> n >> k;
    vll nums = scan<ll>(n);

    map<ll, vector<ll>> mp;

    int i = 0, j = 0;
    for(int i = 0; i < k; i++) mp[nums[i]].push_back(i);

    cout << mp.begin()->second.front() << " ";
    
    for(int i = k; i < n; i++) {
        mp[nums[i - k]] = {mp[nums[i - k]].begin() + 1, mp[nums[i - k]].end()};
        mp[nums[i]].push_back(i);
        cout << mp.begin()->second.front() << " ";
    }

}

void Problem4() {
    ll n, k;
    cin >> n >> k;

    vll nums = scan<ll>(n);
    
}

int main() {
    Problem4();
    return 0;
}

// 1 3 1 4 7 1 7 7 