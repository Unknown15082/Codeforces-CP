#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int q=0; q<t; q++){
        int n, m, k; cin >> n >> m >> k;
        int tt = (m+n+1)*(m+n-2)/2;
        if (n>1) tt -= n*(n-1)/2;
        if (m>1) tt -= m*(m-1)/2;
        if (tt==k) cout << "YES\n";
        else cout << "NO\n";
    }
}