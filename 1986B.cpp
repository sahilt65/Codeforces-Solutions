#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple <int, int, int> cell;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void stabilizeMatrix(vector<vector<int> >& matrix, int n, int m) {
    priority_queue<cell, vector<cell>, greater<cell> > pq;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pq.emplace(matrix[i][j], i, j);
        }
    }

    while (!pq.empty()) {
        int value, x, y;
        tie(value, x, y) = pq.top();
        pq.pop();

        bool isPeak = true;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (isValid(nx, ny, n, m) && matrix[nx][ny] >= value) {
                isPeak = false;
                break;
            }
        }

        if (isPeak) {
            matrix[x][y]--;
            pq.emplace(matrix[x][y], x, y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        stabilizeMatrix(matrix, n, m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
