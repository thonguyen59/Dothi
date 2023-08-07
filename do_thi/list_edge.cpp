#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Hàm kiểm tra xem đỉnh u có kề với đỉnh i không
bool isAdjacent(const vector<set<int>>& graph, int u, int i) {
    for (int v : graph[u]) {
        if (v == i) {
            return true;
        }
    }
    return false;
}

// Hàm tìm các đỉnh lân cận của đỉnh u
set<int> findNeighbors(const vector<set<int>>& graph, int u) {
    return graph[u];
}

int main() {
    int v, e, n;
    cin >> v >> e >> n;

    // Khởi tạo đồ thị có v đỉnh
    vector<set<int>> graph(v + 1);

    // Đọc các cạnh và xây dựng đồ thị
    for (int j = 0; j < e; j++) {
        int u, i;
        cin >> u >> i;
        graph[u].insert(i);
    }

    // Xử lý các thao tác
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, i;
            cin >> u >> i;
            cout << (isAdjacent(graph, u, i) ? "TRUE" : "FALSE") << endl;
        } else if (op == 2) {
            int u;
            cin >> u;
            set<int> neighbors = findNeighbors(graph, u);
            if (neighbors.empty()) {
                cout << "NONE" << endl;
            } else {
                for (int v : neighbors) {
                    cout << v << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
