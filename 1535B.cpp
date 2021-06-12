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
const int maxn = 2000;
const int inf = 2e9;
const ll llinf = 1e18;

void fastio(string finp = "", string fout = ""){
    if (fopen(finp.c_str(), "r")){
        freopen(finp.c_str(), "r", stdin);
        freopen(fout.c_str(), "w", stdout);
    }
}

#define int long long

int v[maxn];

void reset(){
	for (int i=0; i<maxn; i++) v[i] = 0;
}

int main_program(){
    reset();
    int n; cin >> n;
    int even = 0, odd = 0;
    for (int i=0; i<n; i++){
    	int a; cin >> a;
    	if (a%2 == 0) even++;
    	else{
    		v[odd] = a;
    		odd++;
    	}
    }

    int res = (even-1)*even / 2;
    res += even * odd;

    for (int i=0; i<odd-1; i++){
    	for (int j=i+1; j<odd; j++){
    		if (__gcd(v[i], v[j]) > 1) res++;
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