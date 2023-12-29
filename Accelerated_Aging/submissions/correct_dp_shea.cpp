#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int bound = 1e5 + 7;
vector<int> dp(bound);

int getBowls(int index) {
    return index - dp[index];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 4; i <= n; i++){
        dp[i] = getBowls(i-1) + 1;
        if(i % 2 == 0){
            dp[i] = max(dp[i], getBowls(i/2) + i/2);
        }
        if(i % 3 == 0){
            dp[i] = max(dp[i], getBowls(i-2) + 2);
        }
        if(i % 5 == 0){
            dp[i] = max(dp[i], getBowls(i-3) + 3);
        }
    }
    cout << dp[n] + 15 << ' ' << (n - dp[n]) + 15 << endl;
}