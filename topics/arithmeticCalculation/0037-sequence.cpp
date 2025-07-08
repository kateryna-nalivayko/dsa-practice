/*The lecture cycle at Potokolyand University is dedicated to the study of sequences. The professor calls a sequence of integers a1, a2, …, an harmonious if each number, 
except a1 and an, equals the sum of its neighbors: a2 = a1 + a3, a3 = a2 + a4, …, an-1 = an-2 + an. For example, the sequence [1, 2, 1, -1] is harmonious since 2 = 1 + 1, 
and 1 = 2 + (-1). Consider sequences of equal length: A = [a1, a2, …, an] and B = [b1, b2, …, bn]. The distance between these sequences is defined as d(A, B) = | a1 - b1 | + | a2 - b2 | + … + | an - bn |.
 For example, d([1, 2, 1, -1], [1, 2, 0, 0]) = | 1 - 1 | + | 2 - 2 | + | 1 - 0 | + |-1 - 0 | = 0 + 0 + 1 + 1 = 2. At the end of the lecture, the professor wrote on the board a sequence of n integers B = [b1, b2, …, bn] 
 and asked the students as homework to find a harmonious sequence A = [a1, a2, …, an], such that d(A, B) is minimized. To facilitate the checking process, the professor asks to write down only the sought minimum distance d(A, B) as the answer.*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>
#include <queue>
 
using namespace std;
 
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
 
typedef long double ld;
 
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
 
inline int myrand() {
  return abs((rand() << 15) ^ rand());
}
 
inline int rnd(int x) {
  return myrand() % x;
}
 
#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "sequence"
 
const int INF = (int) 1.01e9;
const ld EPS = 1e-9;
 
void precalc() {
}
 
int n;
const int maxn = (int) 3e5 + 10;
int a[maxn];
 
bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  return 1;
}
 
const int maxb = maxn / 3 + 10;
int b[3][maxb];
long long sum[3][maxb];
int cnts[3];
 
long long getFunc(int x, int y) {
  int values[3] = {x, x + y, y};
 
  long long res = 0;
  for (int r = 0; r < 3; ++r) {
    int x = values[r];
    int pos = lower_bound(b[r], b[r] + cnts[r], x) - b[r];
    res += (long long) (pos - (cnts[r] - pos)) * x + sum[r][cnts[r]] - 2 * sum[r][pos];
  }
  assert(res >= 0ll);
  return res;
}
 
const int BOUND = (int) 2e9 + 1;
 
long long solveY(int x, int &y) {
  int left = -BOUND, right = BOUND;
  while (left + 2 < right) {
    int m1 = left + (0LL + right - left) / 2, m2 = m1 + 1;
    long long f1 = getFunc(x, m1);
    long long f2 = getFunc(x, m2);
    if (f1 < f2) {
      right = m2;
    } else {
      left = m1;
    }
  }
  long long res = -1;
  for (int cy = left + 1; cy < right; ++cy) {
    long long cur = getFunc(x, cy);
    if (res < cur) {
      res = cur;
      y = cy;
    }
  }
  assert(res >= 0ll);
  return res;
}
 
long long solveX(int &x, int &y) {
  int left = -BOUND, right = BOUND;
  while (left + 2 < right) {
    int m1 = left + (0LL + right - left) / 2, m2 = m1 + 1;
    int y1, y2;
    long long f1 = solveY(m1, y1);
    long long f2 = solveY(m2, y2);
    if (f1 < f2) {
      right = m2;
    } else {
      left = m1;
    }
  }
  long long res = -1;
  for (int cx = left + 1; cx < right; ++cx) {
    int cy;
    long long cur = solveY(cx, cy);
    if (res < cur) {
      res = cur;
      x = cx;
      y = cy;
    }
  }
  assert(res >= 0ll);
  return res;
}
 
void solve() {
  for (int r = 0; r < 3; ++r) {
    cnts[r] = 0;
    for (int i = r, odd = 0; i < n; i += 3, odd ^= 1) {
      b[r][cnts[r]++] = (!odd ? a[i] : -a[i]);
    }
    sort(b[r], b[r] + cnts[r]);
    sum[r][0] = 0;
    for (int i = 0; i < cnts[r]; ++i) {
      sum[r][i + 1] = sum[r][i] + b[r][i];
    }
  }
  int x, y;
  long long res = solveX(x, y);
  printf(LLD "\n", res);
}
 
int main() {
  srand(rdtsc());
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
 
  precalc();
  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
