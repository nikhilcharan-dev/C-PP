#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> PrimeSeive(int num) {
    vector<bool> isPrime(num + 1, true);
    for(int i = 2; i <= num; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= num; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for(int i = 2; i <= num; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int num;
    cin >> num;

    vector<int> primes = PrimeSeive(num);
    for(auto& prime: primes) {
        cout << prime << " ";
    }

    return 0;
}
