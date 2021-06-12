#include <bits/stdc++.h>
using namespace std;

// Type
typedef double db;
typedef long long ll;
typedef long double ld;

// Pair/Vector
typedef pair<int, int> ii;
typedef pair<ld, ld> dd;
typedef vector<int> vi;
typedef vector<db> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;

// I/O
#define prec(n) fixed << setprecision(n)
#define endl "\n"

// Const
#define PI acos(-1.0)
const int allmod[2] = {int(1e9)+7, 998244353};
//const int mod = allmod[0];
const int maxn = 405;
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

int n, mod;

int binpow(int n, int a){
	if (a == 0) return 1;
	int t = binpow(n, a/2);
	if (a%2 == 0){
		return t*t % mod;
	}
	return (t*t % mod)*n % mod;
}


int fact[maxn+1], inv[maxn+1], pow2[maxn+1];
void precalc_fact(){
	fact[0] = 1; inv[0] = 1;
	for (int i=1; i<=maxn; i++){
		fact[i] = (fact[i-1]*i)%mod;
		inv[i] = binpow(fact[i], mod-2);
	}
}

int coeff(int n, int k){
	return ((fact[n]*inv[k])%mod * inv[n-k])%mod;
}

int coeff_lst[maxn][maxn], dp[maxn][maxn];

signed main(){
    //fastio("input.txt", "output.txt");
    cin >> n >> mod;
    precalc_fact();
    // Pre-calc powers of 2
    pow2[0] = 1;
    for (int i=1; i<=n; i++) pow2[i] = (pow2[i-1] * 2)%mod;
    // Pre-calc binomical coefficients
    for (int i=0; i<=n; i++){
    	for (int j=0; j<=i; j++){
    		coeff_lst[i][j] = coeff(i, j);
    	}
    }
    // Dynamic programming
    dp[0][0] = 1; // Base case
    for (int i=0; i<n; i++){
    	for (int j=0; j<=i; j++){
    		for (int k=1; i+k <= n; k++){
    			//cout << "(Old) dp[" << i+k+1 << "][" << j+k << "] = " << dp[i+k+1][j+k] << "\n";
    			dp[i + k + 1][j + k] += ((dp[i][j] * pow2[k-1])%mod * coeff_lst[j+k][k])%mod;
    			dp[i + k + 1][j + k] %= mod;
    			//cout << "(New) dp[" << i+k+1 << "][" << j+k << "] = " << dp[i+k+1][j+k] << "\n";
    		}
    	}
    }
    /*for (int i=0; i<=n+1; i++){
    	for (int j=0; j<=n+1; j++){
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }*/
    // Output answer
    int res = 0;
    for (int i=0; i<=n; i++){
    	res += dp[n+1][i];
    	res %= mod;
    }
    cout << res;
}