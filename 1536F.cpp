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
const int maxn = 2e6;
const int inf = 2e9;
const ll llinf = 1e18;

void fastio(string finp = "", string fout = ""){
    if (fopen(finp.c_str(), "r")){
        freopen(finp.c_str(), "r", stdin);
        freopen(fout.c_str(), "w", stdout);
    }
}

#define int long long


int binpow(int n, int a){
	if (a == 0) return 1;
	int t = binpow(n, a/2);
	if (a%2 == 0){
		return t*t % mod;
	}
	return (t*t % mod)*n % mod;
}

		
int fact[maxn+1], inv[maxn+1];
void precalc_fact(){
	fact[0] = 1; inv[0] = 1;
	for (int i=1; i<=maxn; i++){
		fact[i] = (fact[i-1]*i)%mod;
		inv[i] = binpow(fact[i], mod-2);
	}
}

int coeff(int n, int k){
    if (n < k || k < 0) return 0;
	return ((fact[n]*inv[k])%mod * inv[n-k])%mod;
}

int n;

int f(int x){
	if (x == n) return (2*fact[n])%mod;
	return (2 * (fact[x] * (coeff(x, n-x) + coeff(x-1, n-x-1))%mod)%mod)%mod;
}

int main_program(){
    cin >> n;
    int res = 0;
    for (int x = 2; x <= n; x += 2){
    	res += f(x);
    	res %= mod;
    }

    cout << res << "\n";
}

int pre_main(){
    precalc_fact();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        fastio("input.txt", "output.txt");
    #endif

    int multitest = 0;
    int t = 1;
    if (multitest){
        cin >> t;
    }
    pre_main();
    while (t--){
        main_program();
    }
}