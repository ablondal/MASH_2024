#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<vector<ld>> distributions(m + 1, vector<ld>(n + 1));
    for(int i = 0; i <= m; i++){
        vector<ld> distribution = distributions[i];
        distribution[0] = 1;
        ld probability;
        for(int j = 0; j < n; j++){
            vector<ld> nextDistribution(n+1);
            cin >> probability;
            for(int k = 0; k < n; k++){
                nextDistribution[k] += distribution[k] * (1 - probability);
                nextDistribution[k+1] += distribution[k] * probability;
            }
            distribution = nextDistribution;
        }
        distributions[i] = distribution;
    }

    vector<vector<ld>> aiPrefixSums(m, vector<ld>(n+1));
    for(int i = 0; i < m; i++){
        for(int j = 0; j <= n; j++){
            if(j == 0){
                aiPrefixSums[i][j] = distributions[i+1][j];
            }else{
                aiPrefixSums[i][j] = aiPrefixSums[i][j-1] + distributions[i+1][j];
            }
        }
    }

    ld answer = 0;
    for(int i = 1; i <= n; i++){
        ld add = distributions[0][i];
        for(int j = 0; j < m; j++){
            add *= aiPrefixSums[j][i-1];
        }
        answer += add;
    }

    cout << fixed << setprecision(6) << answer << endl;
}