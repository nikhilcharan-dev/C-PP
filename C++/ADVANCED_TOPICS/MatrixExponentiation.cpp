class Fibonacci {
    const long long MOD = 10;
    public:
        int fib(int n){
            if(n == 0 || n == 1) return n;
            
            vector<vector<long long>> M = {
                {1, 1}, {1, 0}
            };
            
            vector<vector<long long>> N = {
                {1, 0}, {0, 0}
            };
            
            vector<vector<long long>> res = matrixExponentiation(M, n - 1);
            matrixMultiplication(res, N);
            return res[0][0] % MOD;
        }
    private:
        vector<vector<long long>> matrixExponentiation(vector<vector<long long>>& M, int p) {
            vector<vector<long long>> ans = {
                {1, 0}, {0, 1}
            };
            while(p) {
                if(p & 1) {
                    matrixMultiplication(ans, M);
                }
                matrixMultiplication(M, M);
                p >>= 1;
            }
            return ans;
        }
        void matrixMultiplication(vector<vector<long long>>& A, vector<vector<long long>>& B) {
            vector<vector<long long>> C(A.size(), vector<long long>(B.size(), 0));
            C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
            C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
            C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
            C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
            A[0][0] = C[0][0];
            A[0][1] = C[0][1];
            A[1][0] = C[1][0];
            A[1][1] = C[1][1];
        }
};
