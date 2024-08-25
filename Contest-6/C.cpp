#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;
    int p[n+1];
    int min = 1e9, cnt = 0;
    for(int i=1; i<=n; i++){
        cin >> p[i];
        if(p[i] < min){
            min = p[i];
            cnt ++;
        }
    }
    cout << cnt;
}