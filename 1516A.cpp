#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
    int t; cin >> t;
    for (int q=0; q<t; q++){
        int n, k; cin >> n >> k;
        vi v; v.assign(n, 0);
        for (int i=0; i<n; i++) cin >> v[i];
        int j=0;
        while (j<n-1 && k>0){
            while (v[j]==0 && j<n-1) j++;
            v[j]--;
            v[n-1]++;
            k--;
            while (v[j]==0 && j<n-1) j++;
        }
        for (int i=0; i<n; i++) cout << v[i] << " ";
        cout << "\n";
    }
}