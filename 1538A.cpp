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

auto allmin(){return 0;}
template <typename T, typename... Args>
auto allmin(T a, Args... args){
    if (sizeof...(args) == 0) return a;
    return min(a, (T)allmin(args...));
}

void fastio(string finp = "", string fout = ""){
    if (fopen(finp.c_str(), "r")){
        freopen(finp.c_str(), "r", stdin);
        freopen(fout.c_str(), "w", stdout);
    }
}

#define int long long

int main_program(){
    int n; cin >> n;
    int mn = llinf, mx = -llinf, a = 0, b = 0;

    for (int i=0; i<n; i++){
    	int x; cin >> x;
    	if (x < mn){
    		mn = x;
    		a = i;
    	}
    	if (x > mx){
    		mx = x;
    		b = i;
    	}
    }

    if (a > b){
    	int tmp = a; a = b; b = tmp;
    }

    cout << allmin(b+1, n-a, a+1+n-b) << "\n";
}

int pre_main(){
    
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //fastio("input.txt", "output.txt");
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
