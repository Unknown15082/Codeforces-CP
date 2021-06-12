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
typedef pair<char, int> ci;

// I/O
#define prec(n) fixed << setprecision(n)
#define endl "\n"

// Const
#define PI acos(-1.0)
const int allmod[2] = {int(1e9)+7, 998244353};
const int mod = allmod[0];
const int maxn = 3e5;
const int inf = 2e9;
const ll llinf = 1e18;

void fastio(string finp = "", string fout = ""){
    if (fopen(finp.c_str(), "r")){
        freopen(finp.c_str(), "r", stdin);
        freopen(fout.c_str(), "w", stdout);
    }
}

#define int long long

vector<ci> v;

int n;

void upd(int x){
    int y = x;
    while (y){

        if (y >= (n+1)/2){
            if (v[y].first == '?') v[y].second = 2;
            else v[y].second = 1;
        }
        else{
            if (v[y].first == '?'){
                v[y].second = v[y*2].second + v[y*2 + 1].second;
            }
            else{
                v[y].second = v[y*2 + 49 - ll(v[y].first)].second;
            }
        }

        y /= 2;
    }
}

int main_program(){
    int k; cin >> k;
    n = (1 << k) - 1;
    v.assign(n+1, ci());
    string s; cin >> s;
    for (int i=1; i<=s.length(); i++){
    	char c = s[i-1];
    	int b = (n+1)-i;
    	v[b].first = c;

    	if (i <= (n+1)/2){
    		// leaf
    		if (c == '?') v[b].second = 2;
    		else v[b].second = 1;
    	}
    	else{
    		if (c == '?') v[b].second = v[b*2].second + v[b*2+1].second;
    		else v[b].second = v[b*2 + 49 - ll(c)].second;
    	}
    }

    

    int t; cin >> t;
    for (int q=0; q<t; q++){
        int a; char c;
        cin >> a >> c;
        int b = (n+1)-a;

        v[b].first = c;
        upd(b);

        cout << v[1].second << "\n";

        /*cout << "DEBUG after iteration " << q+1 << ":\n";
        for (int i=1; i<=n; i++){
            cout << i << " " << v[i].first << " " << v[i].second << "\n";
        }
        cout << "\n";*/
    }
}

int pre_main(){
    
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