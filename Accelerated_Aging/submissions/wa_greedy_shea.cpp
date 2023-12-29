#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int getBestChoice(int remainingBowls){
    if(remainingBowls == 0){
        return 0;
    }
    int bestChoice = 1;
    if(remainingBowls % 2 == 0){
        bestChoice = max(bestChoice, remainingBowls/2);
    }
    if(remainingBowls % 5 == 0){
        bestChoice = max(bestChoice, 3);
    }
    if(remainingBowls % 3 == 0){
        bestChoice = max(bestChoice, 2);
    }
    return bestChoice;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    
    int alice = 15, bob = 15;
    while(n > 0){
        int addAlice = getBestChoice(n);
        n -= addAlice;
        alice += addAlice;
        int addBob = getBestChoice(n);
        n -= addBob;
        bob += addBob;
    }
    cout << alice << " " << bob << endl;

}