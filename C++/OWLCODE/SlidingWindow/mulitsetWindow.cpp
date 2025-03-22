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

ll abss(ll a) {
    if(a < 0) {
        return a * -1;
    }
    return a;
} 

void InfiniteVoid() {
    // DATTEBAYO!
    ll n, k;
    cin >> n >> k;

    vll nums = scan<ll>(n);
    vll ans;
    multiset<ll> l, r;
    ll lsum = 0, rsum = 0;

    auto balance = [&]() {
        if(l.size() > r.size() + 1) {
            r.insert(*l.rbegin());
            rsum += *l.rbegin();
            lsum -= *l.rbegin();
            l.erase(--l.end());
            
        }

        if(l.size() < r.size()) {
            l.insert(*r.begin());
            lsum += *r.begin();
            rsum -= *r.begin();
            r.erase(r.begin());
        }
    };

    for(int i = 0; i < n; i++) {
        if(l.empty() or nums[i] <= *l.rbegin()) {
            l.insert(nums[i]);
            lsum += nums[i];
        } else {
            r.insert(nums[i]);
            rsum += nums[i];
        }

        balance();

        if (i >= k) {
            ll out = nums[i - k];
            auto it = l.find(out);
            if (it != l.end()) {
                l.erase(it);
                lsum -= *it;
            } else {
                it = r.find(out);
                if (it != r.end()) {
                    r.erase(it);
                    rsum -= *it;
                }
            }
            balance();
        }

        if(i >= k - 1) {
            ll median = *l.rbegin();
            ll val = ((l.size() * median) - lsum) + (rsum - r.size() * median);
            ans.pb(val);
        }
    }

    peek(ans);
}

int main() {
    InfiniteVoid();
    return 0;
}