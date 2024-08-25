#include<bits/stdc++.h>
#define ll long long
using namespace std;

int Solve(int b){
    vector<int> f = {0, 1, 1};
    if(b == 2) return 3;
    int size = f.size();
    while(1){
        int tmp = f[size - 1] + f[size - 2];
        tmp %= b;
        if(tmp == 0 & f[size - 1] == 1) return size;
        f.push_back(tmp);
        size++;
    }
    delete &f;
}
int main(){
    int n;
    cin >> n;
    while(n --){
        int b;
        cin >> b;
        cout << Solve(b) << endl;
    }
}