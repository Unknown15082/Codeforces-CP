#include <bits/stdc++.h>
using namespace std;

const int maxn = 200001;

int v[maxn];

struct mov{
    int i, j, x, y;
};

typedef vector<mov> vi;
vi vm;

int main(){
    int t; cin >> t;
    vm.assign(maxn, mov());
    for (int q=0; q<t; q++){
        int c=0;
        int n; cin >> n;
        int mn = 0, idx = 0;
        for (int k=0; k<n; k++){
            cin >> v[k];
            if (k==0 || mn > v[k]){
                mn = v[k];
                idx = k;
            }
        }
        if (idx != 0){
            vm[c].i = 1;
            vm[c].j = idx+1;
            vm[c].x = v[idx];
            vm[c].y = v[0];
            c++;
        }
        for (int k=1; k<n; k++){
            vm[c].i = 1;
            vm[c].j = k+1;
            vm[c].x = mn;
            vm[c].y = mn+k;
            c++;
        }
        cout << c << "\n";
        for (int k=0; k<c; k++){
            cout << vm[k].i << " " << vm[k].j << " " << vm[k].x << " " << vm[k].y << "\n";
        }
    }
}