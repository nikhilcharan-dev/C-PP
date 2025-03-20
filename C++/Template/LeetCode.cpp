   /*Nikhil Codes*/
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
T gcd(T a, T b) {
    return b == 0? a : gcd(b, a % b);
}

template<typename T>
T setBits(T var) {
    return __builtin_popcount(var);
}


template<typename T>
void peek(const vector<T>& var) {
    cout << "Container contains: ";
    for (const auto& elem : var) {
        cout << elem << " ";
    }
    cout << endl;
}

template<typename T>
void peek(T var) {
    cout << "Variable contains: " << var << endl;
}

template<typename type, typename V>
void fillV(type& arr, const V& val) {
    fill(all(arr), val);
}

int todigit(char c) {
    return c & 15;
}

bool isvowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
