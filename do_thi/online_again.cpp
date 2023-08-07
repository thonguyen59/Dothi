#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    unordered_set<int> hashTable;
    int x, ms;
    while (true) {
        cin >> x;
        if (x == 0) break;
        cin >> ms;
        if (x == 1) hashTable.insert(ms);
        else if (x == 2) cout << (hashTable.count(ms) > 0) << endl;
    }
}