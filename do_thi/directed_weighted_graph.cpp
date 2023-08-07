#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int main() {
    int v, e, n;
    cin >> v >> e >> n;

    unordered_map<string, int> vertexToIndex;
    vector<string> vertices(v);
    vector<set<pair<int, int>>> adjList(v);

    // Đọc tên các đỉnh và lưu tên và chỉ số tương ứng
    for (int i = 0; i < v; i++) {
        cin >> vertices[i];
        vertexToIndex[vertices[i]] = i;
    }

    // Đọc thông tin cạnh và trọng số
    for (int i = 0; i < e; i++) {
        string u, v;
        int weight;
        cin >> u >> v >> weight;

        adjList[vertexToIndex[u]].insert({vertexToIndex[v], weight});
    }

    // Xử lý các thao tác
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            string u, v;
            cin >> u >> v;

            int uIndex = vertexToIndex[u];
            int vIndex = vertexToIndex[v];
            bool found = false;

            for (const auto& edge : adjList[uIndex]) {
                if (edge.first == vIndex) {
                    cout << edge.second << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "FALSE" << endl;
            }
        } else if (op == 2) {
            string u;
            cin >> u;

            int uIndex = vertexToIndex[u];
            stringstream ss;

            for (const auto& edge : adjList[uIndex]) {
                ss << edge.second << " ";
            }

            string result = ss.str();
            if (result.empty()) {
                cout << "NONE" << endl;
            } else {
                result.pop_back();
                cout << result << endl;
            }
        }
    }

    return 0;
}
