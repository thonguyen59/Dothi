#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

// Hàm kiểm tra xem đỉnh u có kề với đỉnh i không
bool isAdjacent(const map<string, set<string>>& graph, const string& u, const string& i) {
    auto it = graph.find(u);
    if (it != graph.end()) {
        return it->second.find(i) != it->second.end();
    }
    return false;
}

// Hàm tìm số lượng đỉnh lân cận của đỉnh u
int findNeighborsCount(const map<string, set<string>>& graph, const string& u) {
    auto it = graph.find(u);
    if (it != graph.end()) {
        return it->second.size();
    }
    return 0;
}

int main() {
    int e, n;
    cin >> e >> n;

    map<string, set<string>> graph;

    for (int ii = 0; ii < e; ii++) {
        string u, i;
        cin >> u >> i;
        graph[u].insert(i);
    }

    for (int ii = 0; ii < n; ii++) {
        int op;
        cin >> op;
        if (op == 1) {
            string u, i;
            cin >> u >> i;

            if (isAdjacent(graph, u, i)) {
                cout << "TRUE" << endl;
            } else {
                cout << "FALSE" << endl;
            }
        } else if (op == 2) {
            string u;
            cin >> u;
            cout << findNeighborsCount(graph, u) << endl;
        }
    }

    return 0;
}
