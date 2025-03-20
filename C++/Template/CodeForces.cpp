/*Nikhil Codes*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define PI M_PI // acos(-1.0)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define setpoint(x) fixed << setprecision(x)
#define ln "\n"

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
const ll MOD = 1e9 + 7; 
const ll N5 = 1e5;
const ll N6 = 1e6;
const ll N7 = 1e7;
/*                                                 
-----Global Variables
*/

class CP {
private:
    vll SPF;
    vll fact, invFact;

public:
    CP() {
        SPF.resize(N7 + 1); 
        fact.resize(N6 + 1, 1); 
        invFact.resize(N6 + 1, 1); 
        factorial(N6); 
    }

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        return (a / gcd(a, b)) * b;
    }

    bool isPrime(ll num) {
        if(num < 2) return false;
        if(num < 4) return true;
        if(num % 2 == 0 || num % 3 == 0) return false;
        for(ll i = 5; i * i <= num; i += 6) {
            if(num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    vector<ll> PrimeSeive(ll num) {
        vector<bool> primes(num + 1, true);
        for(ll i = 2; i * i <= num; i++) {
            if(primes[i]) {
                for(ll j = i * i; j <= num; j += i) {
                    primes[j] = false;
                }
            }
        }

        vector<ll> Primes;
        for(ll i = 2; i <= num; i++) {
            if(primes[i]) {
                Primes.push_back(i);
            }
        }
        return Primes;
    }

    void setSPF() {
        for(int i = 0; i <= N7; i++) {
            SPF[i] = i;
        }
    
        for(int i = 2; i * i <= N7; i++) {
            if(SPF[i] == i) {
                for(int j = i * i; j <= N7; j += i) {
                    if(SPF[j] == j) {
                        SPF[j] = i;
                    }
                }
            }
        }
    }

    ll power(ll N, ll R, ll mod = MOD) {
        if(R == 0) return 1;
        if(R == 1) return N;
        ll p = power(N, R / 2, mod);
        p = ((p % mod) * (p % mod)) % mod;
        if(R & 1) {
            return (p * N) % mod;
        }
        return p;
    }

    ll factorial(ll n) {
        for(int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }
    
    ll nCr(int n, int r) {
        if (r > n || r < 0) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }
    
};

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
}

void Testcases() {
    int Tcases;
    cin >> Tcases;
    while(Tcases--) {
        InfiniteVoid();
    }
}

int main() {
    Testcases();
    return 0;
}