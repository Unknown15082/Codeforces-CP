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
const int maxn = 1e5;
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

        int c = 0, mn = -1, sm = 0;

    	for (int i=0; i<n; i++){
    		cin >> v[i];
            if (v[i] > 0){
                c++;
                if (c == 1) mn = v[i];
                else mn = min(mn, v[i]);
            }
            if (v[i] < 0) sm++;
    	}
    	
        sort(v, v+n);
        int r1 = 0;
        if (c > 0){
            int crr = v[n-c];
            r1 = 1;
            for (int i = n-c-1; i>=0; i--){
                if (crr - v[i] >= mn){
                    r1++;
                    crr = v[i];
                }
            }
        }

        cout << max(r1, n-c) << "\n";
    }
}