#include "Header.h"

class ThroneInheritance {
public:
  ThroneInheritance(string kingName) {
    alive[kingName] = true;
    king = move(kingName);
  }

  void birth(string parentName, string childName) {
    alive[childName] = true;
    generation[parentName].emplace_back(childName);
  }

  void death(string name) {
    alive[name] = false;
  }

  vector<string> getInheritanceOrder() {
    names.clear();
    dfs(king);
    return names;
  }

private:
  inline void dfs(string human) {
    if (alive[human])
      names.emplace_back(human);
    for (auto p : generation[human])
      dfs(p);
  }

  string king;
  vector<string> names;
  unordered_map<string, bool> alive;
  unordered_map<string, vector<string>> generation;
};
