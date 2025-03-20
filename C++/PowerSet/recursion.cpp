#include <bits/stdc++.h>
using namespace std;

int lastOcc(int *arr, int n, int key, int prev, int idx) {
    if(idx == n && prev == -1) return -1;
    else if(idx == n && prev != -1) return prev;

    if(arr[idx] == key) {
        prev = idx;
    }

    return lastOcc(arr, n, key, prev, idx + 1);
}


int main() {
    int arr[] = {1, 2, 1, 6, 8, 2, 7};
    int ans = lastOcc(arr, 7, 2, -1, 0);
    if(ans != -1) cout << "Last Occ " << ans;
    else cout << "Element Not Found";
}