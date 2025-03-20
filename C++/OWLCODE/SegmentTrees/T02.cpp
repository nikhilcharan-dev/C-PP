// Segment Tree with updates
#include<bits/stdc++.h>
using namespace std;

typedef struct SegmentTree {
    int n;
    
    vector<int> tree; // SegmentTree DS
    vector<int> lazy; // Lazy Propagation for Range Updates

    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0); // Initially No updates
        build(nums, 0, 0, n - 1);
    }

    void build(const vector<int>& nums, int i, int L, int R) {
        if(L == R) {
            tree[i] = nums[L];
            return;
        }
        int mid = (L + R) / 2;
        build(nums, 2 * i + 1, L, mid);
        build(nums, 2 * i + 2, mid + 1, R);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }

    void buildUpdate(int i, int L, int R, int index, int newVal) {
        if(L == R) {
            tree[i] += newVal;
            return;
        }
        int mid = (L + R) / 2;
        if(index <= mid) {
            buildUpdate(2 * i + 1, L, mid, index, newVal);
        } else {
            buildUpdate(2 * i + 2, mid + 1, R, index, newVal);
        }
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }

    void update(int index, int newVal) {
        buildUpdate(0, 0, n - 1, index, newVal);
    }

    int queryMin(int i, int start, int end, int L, int R) {
        UpdateLazy(i, start, end);
        if(L <= start && end <= R) return tree[i];
        if(end < L || start > R) return INT_MAX;
        int mid = (start + end) / 2;
        return min(queryMin(2 * i + 1, start, mid, L, R), queryMin(2 * i + 2, mid + 1, end, L, R));
    }

    int getMin(int L, int R) {
        return queryMin(0, 0, n - 1, L, R);
    }

    void UpdateLazy(int i, int start, int end) {
        if(lazy[i] != 0) {
            tree[i] += lazy[i];
            if(start != end) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    void lazyPropagate(int i, int start, int end, int L, int R, int val) {
        UpdateLazy(i, start, end);
        if(start > R || end < L) return;
        if(L <= start && end <= R) {
            lazy[i] += val;
            UpdateLazy(i, start, end);
            return;
        }
        int mid = (start + end) / 2;
        lazyPropagate(2 * i + 1, start, mid, L, R, val);
        lazyPropagate(2 * i + 2, mid + 1, end, L, R, val);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }

} SegmentTree;

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree sgt(arr);
    cout << sgt.getMin(2, 4) << '\n';
    sgt.update(2, -2);
    cout << sgt.getMin(2, 4) << '\n';
}