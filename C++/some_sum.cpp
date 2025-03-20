/*Nikhil Codes*/
#include <bits/stdc++.h>
using namespace std;

#define MOD (1e9 + 7)
#define PI M_PI // acos(-1.0)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define setpoint(x) fixed << setprecision(x)
#define ln "\n"
#define N 10000000

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
-----Global Variables [Add BE, Sieve, GCD, SPF, Inverse Modulo]
*/
long long len;
ll SPF[N + 1];
/*                                                 
-----Global Variables
*/

// Prime seive
vector<int> PrimeSeive(int num) {
    vector<bool> isPrime(num + 1, true);
    for(int i = 2; i * i <= num; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= num; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for(int i = 2; i <= num; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Modified Sieve
void setSPF() {
    for(int i = 0; i <= N; i++) {
        SPF[i] = i;
    }

    for(int i = 2; i * i <= N; i++) {
        if(SPF[i] == i) {
            for(int j = i * i; j <= N; j += i) {
                if(SPF[j] == j) {
                    SPF[j] = i;
                }
            }
        }
    }
}


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


void cancel(vll& nums, map<ll, ll> mp) {
    for(auto& num: nums) {
        for(auto& m: mp) {
            int k = m.first;
            int v = m.second;
            if(num % k != 0) continue;
            while (num % k == 0 && v > 0) {
                num /= k;
                v--;
            }
            if(!v) mp.erase(k);
        }
    }
}

void InfiniteVoid() {
    // DATTEBAYO!

    ll n, m;
    cin >> n >> m;

    vll nume = scan<ll>(n);
    vll deno = scan<ll>(m);

    map<ll, ll> np, dp, ndp;

    forI(n) {
        ll x = nume[i];
        ll cnt = 0;
        while(x > 1) {
            np[SPF[x]]++;
            x /= SPF[x];
        }
    }

    forI(m) {
        ll x = deno[i];
        ll cnt = 0;
        while(x > 1) {
            dp[SPF[x]]++;
            x /= SPF[x];
        }
    }

    for(auto& k: np) {
        if(dp.find(k.first) != dp.end()) {
            ndp[k.first] = min(k.second, dp[k.first]);
        }
    }

    cancel(nume, ndp);
    cancel(deno, ndp);

    cout << nume.size() << " " << deno.size() << "\n";
    peek(nume);
    peek(deno);
}


int main() {
    setSPF();
    InfiniteVoid();
    return 0;
}