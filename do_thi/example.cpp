#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {

    int e, n;
    cin >> e >> n;

    map<string, set<string> > graph;

    for (int ii = 0; ii < e; ii++) {
        string u, i;
        cin >> u >> i;

        graph[u].insert(i);
    }

    for (auto x: graph) {

        cout << x.first;

        for (auto i: x.second) {
            cout << i << " ";
        }
        cout << endl;
    }


    for (int ii = 0; ii < n; ii++) {
        int op;
        cin >> op;
        if (op == 1) {
            string u, i;
            cin >> u >> i;

            if (graph[u].find(i) == graph[u].end()) cout << "FALSE";
            else cout << "TRUE";
            cout << endl;
        }

        if (op == 2) {
            string u;
            cin >> u;
            cout << graph[u].size();
        }
    }

    return 0;
}