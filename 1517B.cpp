#include <bits/stdc++.h>
using namespace std;

const int inf = (int)1e9 + 1;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    int t; cin >> t;
    for (int q=0; q<t; q++){
        int n, m; cin >> n >> m;
        vvi v;
        v.assign(n, vi());
        for (int i=0; i<n; i++){
            v[i].assign(m, 0);
            for (int j=0; j<m; j++) cin >> v[i][j];
            sort(v[i].begin(), v[i].end());
        }
        /*cout << "DEBUG:\n";
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++) cout << v[i][j] << " ";
            cout << "\n";
        }*/
        vvi res;
        res.assign(n, vi());
        for (int i=0; i<n; i++){
            res[i].assign(m, 0);
        }
        vii index;
        index.assign(n, ii(0, m-1));
        /*cout << "DEBUG:\n";
        for (int i=0; i<n; i++){
            cout << index[i].first << " " << index[i].second << "\n";
        }*/
        for (int j=0; j<m; j++){
            int mn = inf, imn = -1;
            for (int i=0; i<n; i++){
                if (v[i][index[i].first] < mn){
                    mn = v[i][index[i].first];
                    imn = i;
                }
            }
            //cout << "v[1][0] = " << v[1][0] << "\n";
            //cout << "DEBUG: " << mn << " " << imn << "\n";
            for (int i=0; i<n; i++){
                if (i==imn){
                    res[i][j] = v[i][index[i].first];
                    index[i].first++;
                }
                else{
                    res[i][j] = v[i][index[i].second];
                    index[i].second--;
                }
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++) cout << res[i][j] << " ";
            cout << "\n";
        }
    }
}