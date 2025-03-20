long long power(int N,int R) {
    if(R == 0) return 1;
    if(R == 1) return N;
    long long p = power(N, R / 2);
    p = ((p % MOD) * (p % MOD)) % MOD;
    if(R & 1) {
        return (p * N) % MOD;
    }
    return p;
}
