#include <bits/stdc++.h>
using namespace std;

int n, m, totalCells = 0, bestAns = INT_MAX;
vector<bool> present, covered;
vector<vector<int>> rectCells, rectList;

void dfs(int used, int coveredCount) {
    if (used >= bestAns) return;
    if (coveredCount == totalCells) {
        bestAns = used;
        return;
    }
    int start = 0;
    while (start < n*m && (!present[start] || covered[start])) start++;
    for (int rid : rectList[start]) {
        auto &cells = rectCells[rid];
        bool ok = true;
        for (int c : cells) if (covered[c]) { ok = false; break; }
        if (!ok) continue;
        for (int c : cells) covered[c] = true;
        dfs(used + 1, coveredCount + cells.size());
        for (int c : cells) covered[c] = false;
    }
}

int main() {
    cin >> n >> m;
    present.assign(n*m, false);
    covered.assign(n*m, false);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        int x; cin >> x;
        if (x == 0) { present[i*m + j] = true; totalCells++; }
    }
    vector<vector<int>> rightLen(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = m-1; j >= 0; j--) {
        if (!present[i*m + j]) rightLen[i][j] = 0;
        else rightLen[i][j] = 1 + (j+1 < m ? rightLen[i][j+1] : 0);
    }
    rectList.assign(n*m, {});
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        int id0 = i*m + j;
        if (!present[id0]) continue;
        int minW = INT_MAX;
        for (int i1 = i; i1 < n; i1++) {
            if (rightLen[i1][j] == 0) break;
            minW = min(minW, rightLen[i1][j]);
            for (int w = 1; w <= minW; w++) {
                vector<int> cells;
                for (int ii = i; ii <= i1; ii++) for (int jj = j; jj < j + w; jj++)
                    cells.push_back(ii*m + jj);
                int rid = rectCells.size();
                rectCells.push_back(cells);
                rectList[id0].push_back(rid);
            }
        }
    }
    for (int id = 0; id < n*m; id++)
        sort(rectList[id].begin(), rectList[id].end(),
             [&](int a, int b){ return rectCells[a].size() > rectCells[b].size(); });
    dfs(0, 0);
    cout << bestAns;
    return 0;
}
