#include "Header.h"

class OrderedStream {
 public:
  OrderedStream(int n) {
    num = n;
    ptr = 1;
  }

  vector<string> insert(int id, string value) {
    ma[id] = value;
    vector<string> res;
    if (id == ptr) {
      int tmp = id;
      auto iter = ma.find(ptr);
      iter++;
      res.emplace_back(ma[id]);
      while (iter != ma.end()) {
        if (iter->first == tmp + 1) res.emplace_back(iter->second);
        else
          break;
        tmp = iter->first;
        iter++;
      }
      ptr = tmp + 1;
    }

    return res;
  }

 private:
  int ptr;
  int num;

  map<int, string> ma;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
