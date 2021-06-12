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
const int mod = allmod[0];
const int maxn = 1e9;
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

int query(int a, int b){
	int l = b-a+1;
	int t;
	cout << "? " << a+1 << " " << b+1 << "\n";
	cout << flush;
	cin >> t;
	return l-t; 
}

signed main(){
    //fastio("input.txt", "output.txt");
    int n, t, k; cin >> n >> t >> k;
    int l = 0, r = n-1, c = 0;
    while (l<r){
    	int mid = (l+r)/2;
    	int x = query(l, mid);
    	if (x == -1){
    		return 0;
    	}
    	if (x >= k-c){
    		r = mid;
    	}
    	else{
    		l = mid+1;
    		c += x;
    	}
    }
    cout << "! " << l+1;
    return 0;
}