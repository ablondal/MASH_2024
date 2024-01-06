#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<int> skills(n);
    for(int i = 0; i < n; i++){
        cin >> skills[i];
    }

    sort(all(skills));

    int weakestTeam = INT_MAX;
    for(int i = 0; i < (n/2); i++){
        int teamSkill = skills[i] + skills[n - 1 - i];
        weakestTeam = min(weakestTeam, teamSkill);
    }

    cout << weakestTeam << endl;
}