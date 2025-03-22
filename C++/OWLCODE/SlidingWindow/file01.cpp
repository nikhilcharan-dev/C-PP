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

void InfiniteVoid() {
    // DATTEBAYO!
    int n;
    cin >> n;
    vll nums = scan<ll>(n);
    sort(all(nums));
    vll ans;
    int i = 0, j = n >> 1;
    int optimal = 0;
    while(i < n >> 1 && j < n) {
        ans.pb(nums[j++]);
        ans.pb(nums[i++]);
    }
    if(n & 1) ans.pb(nums[j]);
    for(int i = 1; i < n - 1; i++) {
        if(ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
            optimal++;
        }
    }
    peek(optimal);
    peek(ans);
}

int main() {
    InfiniteVoid();
    return 0;
}