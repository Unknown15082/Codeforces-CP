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

// I/O
#define prec(n) fixed << setprecision(n)
#define endl "\n"

// Const
#define PI acos(-1.0)
const int allmod[2] = {int(1e9)+7, 998244353};
const int mod = allmod[0];
const int maxn = 100;
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

int v[maxn];

signed main(){
    //fastio("input.txt", "output.txt");
    int t; cin >> t;
    for (int q=0; q<t; q++){
    	int n; cin >> n;
    	for (int i=0; i<n; i++) cin >> v[i];
        if (v[0] == n && v[n-1] == 1){
            cout << 3 << "\n";
            continue;
        }
    	if (v[0] == 1 || v[n-1] == n){
            bool f = false;
    		for (int i=0; i<n; i++){
    			if (v[i] != i+1){
    				cout << 1 << "\n";
                    f = true;
    				break;
    			}
    		}
            if (!f) cout << 0 << "\n";
    	}
    	else cout << 2 << "\n";
    }
}