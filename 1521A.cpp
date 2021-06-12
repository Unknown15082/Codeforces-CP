#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    for (int q=0; q<t; q++){
        int a, b; cin >> a >> b;
        if (b==1){
            cout << "NO\n";
        }
        else if (b==2){
            cout << "YES\n";
            cout << a << " " << a*3 << " " << a*4 << "\n";
        }
        else{
            cout << "YES\n";
            cout << a << " " << a * (b-1) << " " << a*b << "\n";
        }
    }
}