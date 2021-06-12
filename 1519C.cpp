#include <bits/stdc++.h>
using namespace std;

// Type
typedef double db;
typedef long long ll;
typedef long double ld;

// Pair/Vector
typedef pair<int, int> ii;
typedef pair<ld, ld> dd;
typedef vector<ll> vi;
typedef vector<db> vd;
typedef vector<ld> vld;
typedef vector<vi> vvi;

// I/O
#define prec(n) fixed << setprecision(n)
#define endl "\n"

// Const
#define PI acos(-1.0)
const int allmod[2] = {int(1e9)+7, 998244353};
const int mod = allmod[0];
const int maxn = 2e5+5;
const int inf = 2e9;
const ll llinf = 1e18;

void fastio(string finp = "", string fout = ""){
    if (fopen(finp.c_str(), "r")){
        freopen(finp.c_str(), "r", stdin);
        freopen(fout.c_str(), "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

#define int long long

signed main(){
    //fastio("input.txt", "output.txt");
    int t; cin >> t;
    for (int q=0; q<t; q++){
    	int n; cin >> n;
    	vvi reg; reg.assign(n+5, vi());
    	vvi sss; sss.assign(n+5, vi());
    	vi uni; uni.assign(n+5, 0);

    	for (int i=0; i<n; i++) cin >> uni[i];

    	for (int i=0; i<n; i++){
    		int k; cin >> k;
    		reg[uni[i]].push_back(k);
    	}
    	for (int i=1; i<=n; i++){
    		sort(reg[i].begin(), reg[i].end(), greater<int>());
    		sss[i].assign(reg[i].size() + 1, 0);
    		for (int j=1; j<=reg[i].size(); j++){
    			sss[i][j] = sss[i][j-1] + reg[i][j-1];
    		}
    	}
    	vi res;
        res.assign(n+5, 0);
        for (int i=1; i<=n; i++){
            for (int k=1; k<=reg[i].size(); k++){
                res[k] += sss[i][(reg[i].size() / k)*k];
            }
        }
        for (int i=1; i<=n; i++) cout << res[i] << " ";
        cout << "\n";
    }
}