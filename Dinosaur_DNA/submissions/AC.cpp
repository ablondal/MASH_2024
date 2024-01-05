#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Trie{
    Trie* nxt[26] = {nullptr};
    bool is_leaf = false;
    int leaf_id = 0;
    void leaves(string &s, int pos, vector<pair<int, int>> &res){
        if (is_leaf) res.emplace_back(pos, leaf_id);
        if (pos >= s.size()) return;

        Trie* n = nxt[s[pos]-'A'];
        if (n != nullptr) {
            n->leaves(s, pos+1, res);
        }
    }
    void add(string &s, int id, int pos=0){
        if (pos >= s.size()) {
            is_leaf = true;
            leaf_id = id;
        } else {
            if (nxt[s[pos]-'A'] == nullptr) {
                nxt[s[pos]-'A'] = new (struct Trie);
            }
            nxt[s[pos]-'A']->add(s, id, pos+1);
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(string &w: words){
        cin >> w;
    }
    sort(words.begin(), words.end(), [](string &a, string &b){return a.size() < b.size();});

    Trie T;
    vector<int> ans;
    for(int j=0; j<words.size(); ++j){
        // We're going to make a vector of whether a specific point in
        // the word is reachable using other words.
        // Furthermore, in order to reconstruct the word, you'll have to
        // keep track of parents.
        auto &w = words[j];
        vector<int> p(w.size()+1, -1);
        p[0] = 0;
        for(int i=0; i<w.size(); ++i){
            if (p[i] == -1) continue;
            vector<pair<int, int>> r;
            T.leaves(w,i,r);
            for (auto [pos, par] : r){
                p[pos] = par;
            }
        }
        if (p[w.size()] != -1){
            // We have found a solution!
            int back_pos = w.size();
            while(back_pos != 0){
                auto& nw = p[back_pos];
                ans.push_back(nw);
                back_pos -= words[nw].size();
            }
            reverse(ans.begin(), ans.end());
            ans.push_back(j);
            break;
        }
        T.add(w, j);
    }
    if (ans.size()) {
        cout << "Yes" << endl;
        int as = ans.size();
        for(int i=0; i<as-2; ++i){
            cout << words[ans[i]] << " + ";
        }
        cout << words[ans[as-2]] << " = ";
        cout << words[ans[as-1]] << endl;
    } else {
        cout << "No" << endl;
    }

}
