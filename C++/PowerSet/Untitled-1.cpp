   /*Nikhil Codes*/
#include <bits/stdc++.h>
using namespace std;
 
#define MOD (1e9 + 7)
#define PI M_PI // acos(-1.0);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define setpoint(x) fixed << setprecision(x)
 
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
T gcd(T a, T b) {
    return b == 0? a : gcd(b, a % b);
}
 
template<typename T>
T setBits(T var) {
    return __builtin_popcount(var);
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
    cout << endl;
}
 
template<typename T>
void peek(T var) {
    cout << var << endl;
}
 
 
void InfiniteVoid() {
    int n; cin >> n;
    vll nums = scan<ll>(n);
    
    for(int i = 0; i < pow(2, n); i++) {
        int sum = 0;
        string Bit = bitset<32> (i).to_string();

        string bit = string(Bit.rbegin(), Bit.rend());

        
        for(int j = 0; j < n; j++) {
            if(bit[j] == '1') sum += nums[j];
            else sum -= nums[j];
        }
        
        if(sum == 0 || sum % 360 == 0) {
            peek("YES");
            return;
        }
        
    }
    
    peek("NO");
}
 
int main() {
    InfiniteVoid();
    return 0;
}