#include "Header.h"

class FrontMiddleBackQueue {
  public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        v.emplace(v.begin(), val);
    }

    void pushMiddle(int val) {
        if (v.empty()) v.emplace_back(val);
        else {
            int mid = v.size() / 2;
            v.emplace(v.begin() + mid, val);
        }
    }

    void pushBack(int val) {
        v.emplace_back(val);
    }

    int popFront() {
        int res;
        if (v.empty()) res = -1;
        else {
            res = v.front();
            v.erase(v.begin());
        }
        return res;
    }

    int popMiddle() {
        int res;
        if (v.empty()) res = -1;
        else {
            int mid = (v.size() - 1) / 2;
            res = v[mid];
            v.erase(v.begin() + mid);
        }
        return res;
    }

    int popBack() {
        int res;
        if (v.empty()) res = -1;
        else {
            res = v.back();
            v.pop_back();
        }
        return res;
    }

  private:
    vector<int> v;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
