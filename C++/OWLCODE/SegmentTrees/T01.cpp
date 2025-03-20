// Segment Trees
// 1 <= L <= R <= 10^12
// L * R <= 10^6

// find min, max, sum from [L, R]

/*
    Recursively populate min values from bottom-up approach
    1. No Overlap
    2. Partial Overlap
    3. Complete Overlap
*/




#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SegmentTree {
    vector<ll> minTree, maxTree, sumTree;
    ll n;

    SegmentTree(const vector<ll>& A) {
        n = A.size();
        minTree.resize(4 * n);
        maxTree.resize(4 * n);
        sumTree.resize(4 * n);
        build(A, 0, 0, n - 1);
    }

    void build(const vector<ll>& A, ll node, ll start, ll end) {
        if (start == end) {
            minTree[node] = maxTree[node] = sumTree[node] = A[start];
            return;
        }
        ll mid = (start + end) / 2;
        build(A, 2 * node + 1, start, mid);
        build(A, 2 * node + 2, mid + 1, end);
        minTree[node] = min(minTree[2 * node + 1], minTree[2 * node + 2]);
        maxTree[node] = max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
        sumTree[node] = sumTree[2 * node + 1] + sumTree[2 * node + 2];
    }

    ll queryMin(ll node, ll start, ll end, ll L, ll R) {
        if (start > R || end < L) return LLONG_MAX;
        if (start >= L && end <= R) return minTree[node];
        ll mid = (start + end) / 2;
        return min(queryMin(2 * node + 1, start, mid, L, R), queryMin(2 * node + 2, mid + 1, end, L, R));
    }

    ll queryMax(ll node, ll start, ll end, ll L, ll R) {
        if (start > R || end < L) return LLONG_MIN;
        if (start >= L && end <= R) return maxTree[node];
        ll mid = (start + end) / 2;
        return max(queryMax(2 * node + 1, start, mid, L, R), queryMax(2 * node + 2, mid + 1, end, L, R));
    }

    ll querySum(ll node, ll start, ll end, ll L, ll R) {
        if (start > R || end < L) return 0;
        if (start >= L && end <= R) return sumTree[node];
        ll mid = (start + end) / 2;
        return querySum(2 * node + 1, start, mid, L, R) + querySum(2 * node + 2, mid + 1, end, L, R);
    }

    ll getMin(ll L, ll R) {
        return queryMin(0, 0, n - 1, L, R);
    }

    ll getMax(ll L, ll R) {
        return queryMax(0, 0, n - 1, L, R);
    }

    ll getSum(ll L, ll R) {
        return querySum(0, 0, n - 1, L, R);
    }
};

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) cin >> A[i];
    
    SegmentTree segTree(A);
    
    while (q--) {
        ll type, L, R;
        cin >> type >> L >> R;
        if (type == 1) cout << segTree.getMin(L, R) << "\n";
        else if (type == 2) cout << segTree.getMax(L, R) << "\n";
        else cout << segTree.getSum(L, R) << "\n";
    }
}


1 2 3 4 5

    1 2 - 3 5
1 - 2 -- 3 - 4 -- 5


// Note: Segment Trees are not Segment Trees but are Trees that are represented in a Array form.