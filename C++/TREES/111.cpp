#include <bits/stdc++.h>
void multiply(int A[][2], int B[][2]){
    int a = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    int b = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    int c = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    int d = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}
void expo(int a[][2], int e){
    if (e == 0)return;
    expo(a, e/2);
    multiply(a, a);
    int temp[2][2] = {{1,1},{1,0}};
    if (1&e) multiply(a,temp);
}
int fib(int n){
    int a[2][2] = {{1,1},{1,0}};
    expo(a,n-1);
    return a[0][0];
} 
int fibSum(int n){
    if (n<=0) return 0;
    int s = fib(n+1)+fib(n) - 1;
    return s;
}
int fiboSum(int n , int m)
{
	// Write your code here
    int a = fibSum(m);
    int b = fibSum(n-1);
    return a-b;
}