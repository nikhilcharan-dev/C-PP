#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n; cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> powerSet(2 * (n - 1), 0);
}