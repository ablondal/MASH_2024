#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Sieve of Eratosthenes, O(n log log n)
    vector<bool> sieve(n+1, true);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            int j = i*2;
            while (j <= n) {
                sieve[j] = false;
                j += i;
            }
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
        if (x <= n && sieve[x]) {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}