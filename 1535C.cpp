#include <bits/stdc++.h>
using namespace std;

// Type
typedef long long ll;
typedef long double ld;

// Pair/Vector
typedef pair<int, int> ii;
typedef pair<ld, ld> dd;
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<dd> vdd;

// I/O
#define prec(n) fixed << setprecision(n)
#define endl "\n"

// Const
#define PI acos(-1.0)
const int allmod[2] = {int(1e9)+7, 998244353};
const int mod = allmod[0];
const int maxn = 1e9;
const int inf = 2e9;
const ll llinf = 1e18;

void fastio(string finp = "", string fout = ""){
    if (fopen(finp.c_str(), "r")){
        freopen(finp.c_str(), "r", stdin);
        freopen(fout.c_str(), "w", stdout);
    }
}

#define int long long

int get(char c, int x){
    if (c == '?') return -1;
    return (ll(c) - 48 + x)%2;
}

int main_program(){

    string s; cin >> s;
    int p = 0, q = 0;
    int state = -1;
    int last = 0;
    int res = 0;
    while (p < s.length()){
        if (q == s.length()){
            res += q-p;
            p++;
        }
        else{
            int k = get(s[q], q-p);
            if (k == -1){
                // upd
                state = max(state, k);
                q++;
            }
            else{
                if (state + k == 1){
                    // false
                    res += (q - p + q - last) * (last - p + 1) / 2;
                    p = last+1;
                    last = q;
                    state = get(s[q], q-p);
                }
                else{
                    last = q;
                    q++;
                    state = max(state, k);
                }
            }
        }
    }

    cout << res << "\n";
}

int pre_main(){
    
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        fastio("input.txt", "output.txt");
    #endif

    int multitest = 1;
    int t = 1;
    if (multitest){
        cin >> t;
    }
    pre_main();
    while (t--){
        main_program();
    }
}