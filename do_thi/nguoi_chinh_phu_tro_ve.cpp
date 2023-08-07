#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Node {
    Point pos;
    int time;
    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

int dijkstra(vector<vector<int>>& grid, Point start, Point end) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({start, 0});
    dist[start.x][start.y] = 0;

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.pos.x == end.x && curr.pos.y == end.y) {
            return curr.time;
        }

        for (int i = 0; i < 8; ++i) {
            int nextX = curr.pos.x + dx[i];
            int nextY = curr.pos.y + dy[i];

            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n &&
                grid[nextX][nextY] == 0 && curr.time + 1 < dist[nextX][nextY]) {
                pq.push({Point(nextX, nextY), curr.time + 1});
                dist[nextX][nextY] = curr.time + 1;
            }
        }
    }

    return -1;
}

int main() {
    int m, n, startX, startY, endX, endY;
    cin >> m >> n >> startX >> startY >> endX >> endY;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    Point start(startX, startY);
    Point end(endX, endY);

    int result = dijkstra(grid, start, end);
    cout << result << endl;

    return 0;
}
