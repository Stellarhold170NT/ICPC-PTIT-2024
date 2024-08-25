#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define psi pair<int, string>

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    unordered_map<string, int> store1, store2, store3;
    unordered_map<string, int> ID;
    for (int i = 0; i < n1; ++i) {
        string id;
        int quantity;
        cin >> id >> quantity;
        store1[id] += quantity;
        if (!ID[id])
            ID[id] = i + 1;
    }

    for (int i = 0; i < n2; ++i) {
        string id;
        int quantity;
        cin >> id >> quantity;
        store2[id] += quantity;
    }

    for (int i = 0; i < n3; ++i) {
        string id;
        int quantity;
        cin >> id >> quantity;
        store3[id] += quantity;
    }

    vector<psi> result;

    for (const auto& item : store1) {
        string id = item.first;
        if (store1[id] >= 20 && store2[id] >= 20 && store3[id] >= 20) {
            result.push_back({ ID[id], id });
        }
    }

    sort(result.begin(), result.end(), [&](psi a, psi b) {
        return a.first < b.first;
        });

    cout << result.size() << " ";
    for (auto x : result) {
        cout << x.second << " ";
    }

    return 0;
}