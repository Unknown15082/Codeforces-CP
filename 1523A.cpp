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
const int maxn = 1e4;
const int inf = 2e9;
const ll llinf = 1e18;

void fastio(string finp = "", string fout = ""){
    if (fopen(finp.c_str(), "r")){
        freopen(finp.c_str(), "r", stdin);
        freopen(fout.c_str(), "w", stdout);
    }
}

#define int long long

int l[maxn], r[maxn];

int main_program(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int prev = inf;
    for (int i=0; i<n; i++){
    	if (s[i] == '0'){
    		l[i] = prev;
    	}
    	else{
    		l[i] = 0;
    		prev = 0;
    	}
    	prev++;
    }
    for (int i=n-1; i>=0; i--){
    	if (s[i] == '0'){
    		r[i] = prev;
    	}
    	else{
    		r[i] = 0;
    		prev = 0;
    	}
    	prev++;
    }
    for (int i=0; i<n; i++){
    	if (s[i] == '1') cout << "1";
    	else{
    		if (min(l[i], r[i]) <= k && l[i] != r[i]){
    			cout << "1";
    		}
    		else{
    			cout << "0";
    		}
    	}
    }
    cout << "\n";
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
    while (t--){
        main_program();
    }
}