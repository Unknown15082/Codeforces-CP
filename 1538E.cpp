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

struct Variable{
	int cnt; string first, second;
};

map<string, Variable> mp;
int crr;

void _assign(string var, string val){
	mp[var] = Variable();
	if (val.length() < 4){
		mp[var].first = val;
		mp[var].second = val;
		mp[var].cnt = 0;
	}
	else{
		mp[var].first = val.substr(0, 4);
		mp[var].second = val.substr(val.length() - 4, 4);
		mp[var].cnt = 0;
		for (int i=3; i<val.length(); i++){
			if (val[i] == 'a' && val[i-1] == 'h' && val[i-2] == 'a' && val[i-3] == 'h') mp[var].cnt++;
		}
	}
	crr = mp[var].cnt;
}

void _eval(string var, string v1, string v2){
	string tmp = mp[v1].second + mp[v2].first;
	int tmpcnt = 0;
	for (int i=3; i<tmp.length(); i++){
		if (tmp[i] == 'a' && tmp[i-1] == 'h' && tmp[i-2] == 'a' && tmp[i-3] == 'h') tmpcnt++;
	}
	if (mp[v1].second == "haha") tmpcnt--;
	if (mp[v2].first == "haha") tmpcnt--;

	string strtmp;
	strtmp = mp[v1].first + mp[v2].first;
	if (strtmp.length() < 4) mp[var].first = strtmp;
	else mp[var].first = strtmp.substr(0, 4);
	strtmp = mp[v1].second + mp[v2].second;
	if (strtmp.length() < 4) mp[var].second = strtmp;
	else mp[var].second = strtmp.substr(strtmp.length() - 4, 4);
	mp[var].cnt = mp[v1].cnt + mp[v2].cnt + tmpcnt;
	crr = mp[var].cnt;
}

int main_program(){
	mp.clear();
	int n; cin >> n;
	for (int i=0; i<n; i++){
		string var; cin >> var;
		string op; cin >> op;
		if (op == ":="){
			string val; cin >> val;
			_assign(var, val);
		}
		else{
			string v1, v2; cin >> v1 >> v2 >> v2;
			_eval(var, v1, v2);
		}
	}
	cout << crr << "\n";
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