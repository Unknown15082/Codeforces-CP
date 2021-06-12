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

ii v[maxn];
int dp[maxn][2];
vi adj[maxn];

void dfs(int x, int parent){
	dp[x][0] = 0;
	dp[x][1] = 0;

	for (int i=0; i<adj[x].size(); i++){
		int k = adj[x][i];
		if (k != parent){
			dfs(k, x);
			dp[x][0] += max(dp[k][0] + abs(v[x].first - v[k].first), dp[k][1] + abs(v[x].first - v[k].second));
			dp[x][1] += max(dp[k][0] + abs(v[x].second - v[k].first), dp[k][1] + abs(v[x].second - v[k].second));	
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //fastio("input.txt", "output.txt");
    int t; cin >> t;
    for (int q=0; q<t; q++){
    	int n; cin >> n;
    	fill(adj, adj+n, vi());
    	for (int i=0; i<n; i++){
    		cin >> v[i].first >> v[i].second;
    	}
    	for (int i=0; i<n-1; i++){
    		int a, b; cin >> a >> b; a--; b--;
    		adj[a].push_back(b);
    		adj[b].push_back(a);
    	}

    	dfs(0, -1);
    	cout << max(dp[0][0], dp[0][1]) << "\n";
    }
}