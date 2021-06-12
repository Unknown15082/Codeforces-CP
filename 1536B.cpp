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

string s;
string tmp;
int n;
bool f = false;

void backtrack(int i, int crr){
	if (f) return;
	if (i >= crr){
		for (int j=0; j<=n-crr; j++){
			if (s.substr(j, crr) == tmp){
				return;
			}
		}
        f = true;
        cout << tmp << "\n";
        return;
	}

	for (int v=97; v<=122; v++){
		tmp += char(v);
		backtrack(i+1, crr);
		tmp = tmp.substr(0, i);
	}
}

int main_program(){
    cin >> n;
    cin >> s;
    f = false;
    for (int i=1; i<=1000; i++){
    	if (f) break;
    	backtrack(0, i);
    }
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