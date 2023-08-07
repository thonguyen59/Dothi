#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);

    // Đọc các kênh nối và xây dựng đồ thị
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        //Đồ thị vô hướng
        graph[v].push_back(u);
    }

    int s;
    cin >> s;

    vector<bool> isAttacked(N + 1, false);

    // Queue - Tìm kiếm theo chiều rộng
    queue<int> q;
    q.push(s);
    isAttacked[s] = true;

    int count = 1;
    // Duyệt BFS để tìm tất cả các máy tính bị tấn công
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!isAttacked[v]) {
                q.push(v);
                isAttacked[v] = true;
                count++;
            }
        }
    }

    cout << count << endl;

    for (int i = 1; i <= N; i++) {
        if (isAttacked[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
