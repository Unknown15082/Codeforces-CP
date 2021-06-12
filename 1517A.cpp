#include <bits/stdc++.h>
using namespace std;
#define int long long

int sumdigit(int x){
    int s = 0;
    while (x>0){
        s += x%10;
        x /= 10;
    }
    return s;
}

signed main(){
    int t; cin >> t;
    for (int q=0; q<t; q++){
        int n; cin >> n;
        if (n%2050 != 0){
            cout << "-1\n";
        }
        else{
            cout << sumdigit(n/2050);
            cout << "\n";
        }
    }
}