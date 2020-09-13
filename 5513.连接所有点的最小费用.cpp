#include "Header.h"

class Solution {
  // 不自定义类的话而使用vector记录边的话会超时
  struct E {
    int  a, b, w;
    bool operator<(const E& e) const {
      return w < e.w;
    }
  };

public:
  vector<int> block;  //记录属于哪个块
  int         findBlock(int x) {
    return block[x] == x ? x : findBlock(block[x]);
  }

  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 1)
      return 0;
    // 计算出所有任意两点的距离
    vector<E> ds;
    // vector<vector<int>> ds;使用双vector会超时，比自定义struct慢5倍左右
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        ds.push_back({i, j, cal(points[i], points[j])});
      }
    }
    // 排序后的vector可以当做是优先队列使用
    sort(ds.begin(), ds.end());
    //第几个点对应第几个连通块
    for (int i = 0; i < n; i++)
      block.push_back(i);

    //初始化
    int ans = 0, cnt = 0;
    for (auto& e : ds) {
      // 如果两个点不是同一个连通块，则需要合并，合并需要朝着小的方向进行
      int b1 = findBlock(e.a), b2 = findBlock(e.b);
      // int b1 = block[e.a], b2 = bloc[e.b];
      // 这样的话需要维护当前某个块的其他所有点，比较难，而使用findBlock函数可以递归找到最底层属于哪个块
      if (b1 == b2)
        continue;
      // 更新使得b1和b2在同一个块中，亲测以下两种方式都可行，相当于在找底层块的时候将b1和b2之间进行了连通

      block[b2] = b1;  //或者block[b1] = b2;
      ans += e.w;
      cnt++;
      // 边的个数为点的个数减一时表示结束
      if (cnt == points.size() - 1)
        return ans;
    }
    return ans;
  }

  int cal(vector<int>& p1, vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }
};
