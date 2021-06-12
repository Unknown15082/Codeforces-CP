#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    for (int q=0; q<t; q++){
        int r, b, d; cin >> r >> b >> d;
        if (r>b){
            int tmp = r;
            r = b;
            b = tmp;
        }
        if (b<=(d+1)*r) cout << "YES\n";
        else cout << "NO\n";
    }
}