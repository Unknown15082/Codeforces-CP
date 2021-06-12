#include <bits/stdc++.h>
using namespace std;

const int maxn = 200001;

int sleft[maxn], sright[maxn];
int n, l, r, a;

void reset(){
    for (int i=0; i<maxn; i++){
        sleft[i] = 0;
        sright[i] = 0;
    }
}

int main(){
    int t; cin >> t;
    for (int q=0; q<t; q++){
        reset();
        // Input
        cin >> n >> l >> r;
        for (int i=0; i<l; i++){
            cin >> a;
            sleft[a]++;
        }
        for (int i=0; i<r; i++){
            cin >> a;
            sright[a]++;
        }
        int res = n/2 + abs(l-r)/2;
        // Calc
        for (int i=0; i<=n; i++){
            if (sleft[i] >= sright[i]){
                sleft[i] -= sright[i];
                res -= sright[i];
                sright[i] = 0;
            }
            else{
                sright[i] -= sleft[i];
                res -= sleft[i];
                sleft[i] = 0;
            }
        }
        int c=0;
        if (l>=r){
            for (int i=0; i<=n; i++) c += sleft[i]/2;
        }
        else{
            for (int i=0; i<=n; i++) c += sright[i]/2;
        }
        res -= min(c, abs(l-r)/2);
        cout << res << "\n";
    }
}