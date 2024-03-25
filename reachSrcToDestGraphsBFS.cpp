#include <bits/stdc++.h>
using namespace std;

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

template<typename T>
class Graph {
public:

    bool isValid(int row, int col) {
        return (row >= 0) && (row < 5) && (col >= 0) && (col < 5);
    }

    int bfs(int maze[5][5], T src, T dest) {
        map<T, int> dist;
        map<T, T> parent;
        queue<T> q;

        bool visited[5][5];
        memset(visited, false, sizeof visited);

        visited[src.first][src.second] = true;

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while (!q.empty()) {
            T node = q.front();
            if (node.first == dest.first and node.second == dest.second) {
                T temp = dest;
                while (temp != src) {
                    cout << "(" << temp.first << ", " << temp.second << ") <-- ";
                    temp = parent[temp];
                }
                cout << "(" << src.first << ", " << src.second << ")" << endl;
                return dist[node];
            }

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int row = node.first + rowNum[i];
                int col = node.second + colNum[i];

                if (isValid(row, col) && maze[row][col] < maze[node.first][node.second] && !visited[row][col]) {
                    visited[row][col] = true;
                    dist[make_pair(row, col)] = dist[node] + 1;
                    parent[make_pair(row, col)] = node;
                    q.push(make_pair(row, col));
                }
            }
        }
        return -1;
    }
};

int main() {
    int maze[5][5] = {{13, 8, 19, 11, 23},
                        {1, 5, 3, 1, -2},
                        {-1, -7, 14, 19 -7},
                        {9, -8, -11, -17, -15},
                        {14, 29, 28, 24, 25}};

    Graph<pair<int, int>> g;
    cout << g.bfs(maze, make_pair(0, 0), make_pair(3, 3)) << endl;

    return 0;
}
