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
const int maxn = 2e5+10;
const int inf = 2e9;
const ll llinf = 1e18;

void fastio(string finp = "", string fout = ""){
    if (fopen(finp.c_str(), "r")){
        freopen(finp.c_str(), "r", stdin);
        freopen(fout.c_str(), "w", stdout);
    }
}

#define int long long

struct Point{
	int val, prev, next;

	void __init__(int x, int y, int z){
		val = x;
		prev = y;
		next = z;
	}
};

int main_program(){
    map<int, Point> mp;

    int n; cin >> n;
    int crr = 0, pcrr, ncrr;
    int a; cin >> a;

    mp[crr] = Point();
    mp[crr].__init__(a, crr, crr);
    
    bool f = true;

    for (int i=1; i<n; i++){
        cin >> a;
        pcrr = mp[crr].prev;
        ncrr = mp[crr].next;

        if (a == mp[crr].val || a == mp[pcrr].val || a == mp[ncrr].val){
            mp[i] = Point();
            mp[i].__init__(a, crr, crr);
            
            if (a == mp[crr].val){
                crr = crr;
            }
            else if (a == mp[pcrr].val){
                crr = pcrr;
            }
            else{
                crr = ncrr;
            }
        }
        else{
            if (a < mp[crr].val){

                if (pcrr == crr){
                    mp[i] = Point();
                    mp[i].__init__(a, i, crr);
                    mp[crr].prev = i;
                }
                else{
                    if (a < mp[pcrr].val){
                        f = false;
                    }
                    mp[i] = Point();
                    mp[i].__init__(a, pcrr, crr);
                    mp[pcrr].next = i;
                    mp[crr].prev = i;
                }
            }
            else{

                if (ncrr == crr){
                    mp[i] = Point();
                    mp[i].__init__(a, crr, i);
                    mp[crr].next = i;
                }
                else{
                    if (a > mp[ncrr].val){
                        f = false;
                    }
                    mp[i] = Point();
                    mp[i].__init__(a, crr, ncrr);
                    mp[crr].next = i;
                    mp[ncrr].prev = i;
                }
            }
            crr = i;
        }
    }

    if (f) cout << "YES\n";
    else cout << "NO\n";
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