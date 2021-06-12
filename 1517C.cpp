#include <bits/stdc++.h>
using namespace std;

const int maxn = 501;

int r[maxn][maxn], v[maxn];

int main(){
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> v[i];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) r[i][j] = 0;
    }
    for (int i=n-1; i>=0; i--){
        int k = v[i];
        int a=i, b=i;
        r[a][b] = k;
        for (int j=0; j<k-1; j++){
            //Move
            if (a+1<n && r[a+1][b] == 0) a++;
            else b--;
            //Stamp
            r[a][b] = k;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            cout << r[i][j] << " ";
        }
        cout << "\n";
    }
}