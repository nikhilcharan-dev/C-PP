#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> nums(n + 1, vector<int>(n + 1));
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1)); // 1 to N indices
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> nums[i][j];
            prefix[i][j] = nums[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << prefix[c][d] - prefix[a - 1][d] - prefix[c][b - 1] + prefix[a - 1][b - 1] << endl;
    }

    return 0;
}
