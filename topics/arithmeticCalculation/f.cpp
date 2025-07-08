#include <bits/stdc++.h>
using namespace std;

int n, m, best = INT_MAX, total = 0;
vector<bool> present;
vector<vector<int>> rectCells, rectList;

void dfs(vector<bool>& covered, int used, int coveredCnt) {
    if (used >= best) return;
    if (coveredCnt == total) {
        best = used;
        return;
    }
    int i = 0;
    while (i < n*m && (!present[i] || covered[i])) ++i;
    for (int rid : rectList[i]) {
        auto& cells = rectCells[rid];
        bool ok = true;
        for (int c : cells) if (covered[c]) { ok = false; break; }
        if (!ok) continue;
        for (int c : cells) covered[c] = true;
        dfs(covered, used + 1, coveredCnt + cells.size());
        for (int c : cells) covered[c] = false;
    }
}

int main() {
    cin >> n >> m;
    present.assign(n*m, false);
    for (int i = 0; i < n; i++)
        for (int j = 0, x; j < m; j++)
            if (cin >> x, x == 0)
                present[i*m + j] = true, total++;

    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < m; j1++)
            for (int i2 = i1; i2 < n; i2++)
                for (int j2 = j1; j2 < m; j2++) {
                    vector<int> cells;
                    bool ok = true;
                    for (int i = i1; i <= i2; i++)
                        for (int j = j1; j <= j2; j++) {
                            int idx = i*m + j;
                            if (!present[idx]) ok = false;
                            cells.push_back(idx);
                        }
                    if (ok) rectCells.push_back(cells);
                }

    rectList.assign(n*m, {});
    for (int rid = 0; rid < (int)rectCells.size(); rid++)
        for (int c : rectCells[rid])
            rectList[c].push_back(rid);

    for (int i = 0; i < n*m; i++)
        sort(rectList[i].begin(), rectList[i].end(),
             [&](int a, int b){ return rectCells[a].size() > rectCells[b].size(); });

    vector<bool> covered(n*m, false);
    dfs(covered, 0, 0);
    cout << best << "\n";
    return 0;
}
