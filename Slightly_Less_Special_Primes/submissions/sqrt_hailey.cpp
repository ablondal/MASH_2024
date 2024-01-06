#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Sieve of Eratosthenes, O(n log log n)
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= n; i++) {
        int j_max = ceil(sqrt(i));
        for (int j = 2; j <= j_max; j++) {
            if (i%j == 0) {
                isPrime[i] = false;
                break;
            }
        }
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    // Let C=gcd(a, b), A=a/c, B=b/c.
    // Then we need to find two adjacent primes A, B
    // such that C is the (B-A)-th smallest prime and A*C+B*C+1 is prime again.
    int counter = 0;
    for (int i = 0; i < (int)primes.size()-1; i++) {
        int A = primes[i];
        int B = primes[i+1];
        if (B-A-1 > primes.size()) {
            continue;
        }
        int C = primes[B-A-1];
        int x = A*C+B*C+1;
        if (x <= n && isPrime[x]) {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}