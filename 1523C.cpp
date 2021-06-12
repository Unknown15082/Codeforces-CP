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
const int maxn = 1e3;
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
int p[maxn];
string res[maxn];

int n;
int crr = 1;

void search(int x){
    int c = 1;
    int base = x;
    while (crr < n){
        if (v[crr] == 1){
            // New level
            p[crr] = base;
            crr++;
            search(crr - 1);
        }
        else if (v[crr] == c+1){
            // Same level
            p[crr] = p[x];
            base = crr;
            c++;
            crr++;
        }
        else{
            return;
        }
    }
}

void reset(){
    for (int i=0; i<maxn; i++){
        crr = 1;
        v[i] = 0;
        p[i] = 0;
        res[i] = "";
    }
}

int main_program(){
    reset();
    cin >> n;
    for (int i=0; i<n; i++) cin >> v[i];
    p[0] = -1;
    search(0);
    res[0] = "1";
    cout << "1\n";
    for (int i=1; i<n; i++){
        if (p[i] == -1) res[i] = to_string(v[i]);
        else res[i] = res[p[i]] + "." + to_string(v[i]);
        cout << res[i] << "\n";
    }
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