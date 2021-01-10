#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T> using uset = unordered_set<T>;
template <typename T> using umset = unordered_multiset<T>;
template <typename T1, typename T2> using umap = unordered_map<T1, T2>;
template <typename T> using v2 = vector<vector<T>>;
template <typename T1, typename T2> using p2 = pair<T1, T2>;
template <typename T> using v1 = vector<T>;

using ld = long double;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

// ----------- solution ----------- //

class Solution {
public:
  int minimumHammingDistance(vector<int>& source,
                             vector<int>& target,
                             vector<vector<int>>& allow) {
    int n = source.size(), ans = n;

    vector<vector<int>> g(n);
    for (auto& i : allow) {
      g[i[0]].emplace_back(i[1]);
      g[i[1]].emplace_back(i[0]);
    }

    vector<int> vis(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        q.emplace(i);
        vis[i] = 1;
        vector<int> nA, nB;
        while (!q.empty()) {
          int node = q.front();
          q.pop();
          nA.emplace_back(source[node]);
          nB.emplace_back(target[node]);
          for (int& j : g[node]) {
            if (!vis[j]) {
              vis[j] = 1;
              q.emplace(j);
            }
          }
        }

        sort(nA.begin(), nA.end());
        sort(nB.begin(), nB.end());
        for (int j = 0, k = 0; j < nA.size() && k < nB.size();) {
          if (nA[j] == nB[k]) ans--, j++, k++;
          else if (nA[j] < nB[k])
            j++;
          else
            k++;
        }
      }
    }

    return ans;
  }
};

class Solution1 {
public:
  int minimumHammingDistance(vector<int>& source,
                             vector<int>& target,
                             vector<vector<int>>& allowedSwaps) {
    int n = source.size();
    vector<vector<int>> G(n);
    for (auto e : allowedSwaps) {
      G[e[0]].push_back(e[1]);
      G[e[1]].push_back(e[0]);
    }
    vector<int> vis(n);
    int ans = n;
    for (int i = 0; i < n; i += 1) {
      if (not vis[i]) {
        queue<int> q;
        vector<int> A, B;
        q.push(i);
        vis[i] = 1;
        while (not q.empty()) {
          int u = q.front();
          q.pop();
          A.push_back(source[u]);
          B.push_back(target[u]);
          for (int v : G[u]) {
            if (not vis[v]) {
              vis[v] = 1;
              q.push(v);
            }
          }
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (int k = 0, j = 0; k < A.size() and j < B.size();) {
          if (A[k] == B[j]) {
            ans -= 1;
            k += 1;
            j += 1;
          } else if (A[k] < B[j])
            k += 1;
          else
            j += 1;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution solution{};
  vector<int> nums1{41, 37, 51, 100, 25, 33, 90, 49, 65, 87, 11, 18, 15, 18},
      nums2{41, 92, 69, 75, 29, 13, 53, 21, 17, 81, 33, 19, 33, 32};
  vector<vector<int>> nums3{
      {0, 11},  {5, 9},  {6, 9},   {5, 7},   {8, 13}, {4, 8},  {12, 7},
      {8, 2},   {13, 5}, {0, 7},   {6, 4},   {8, 9},  {4, 12}, {6, 1},
      {10, 0},  {10, 2}, {7, 3},   {11, 10}, {5, 2},  {11, 1}, {3, 0},
      {8, 5},   {12, 6}, {2, 1},   {11, 2},  {4, 9},  {2, 9},  {10, 6},
      {12, 10}, {4, 13}, {13, 2},  {11, 9},  {3, 6},  {0, 4},  {1, 10},
      {5, 11},  {12, 1}, {10, 4},  {6, 2},   {10, 7}, {3, 13}, {4, 5},
      {13, 10}, {4, 7},  {0, 12},  {9, 10},  {9, 3},  {0, 5},  {1, 9},
      {5, 10},  {8, 0},  {12, 11}, {11, 4},  {7, 9},  {7, 2},  {13, 9},
      {12, 3},  {8, 6},  {7, 6},   {8, 12},  {4, 3},  {7, 13}, {0, 13},
      {2, 0},   {3, 8},  {8, 1},   {13, 6},  {1, 4},  {0, 9},  {2, 3},
      {8, 7},   {4, 2},  {9, 12}};
  int ans = solution.minimumHammingDistance(nums1, nums2, nums3);
  cout << ans << endl;
  return 0;
}
