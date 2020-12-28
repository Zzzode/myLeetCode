#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>

#include <stdlib.h>
#include <string.h>

using namespace std;

class Solution
{
public:
    vector<string> computeSimilarities(vector<vector<int>> &docs)
    {
        int _size = docs.size();
        vector<string> _res;
        unordered_map<int, vector<int>> _map;

        int _help[_size][_size];
        memset(_help, 0, sizeof(_help));

        for (int i = 0; i < _size; i++)
        {
            for (int j = 0; j < docs[i].size(); j++)
            {
                if(_map.find(docs[i][j]) == _map.end()){
                    _map.insert(pair<int, vector<int>>(docs[i][j], vector<int>()));
                } else {
                    for(auto a : _map[docs[i][j]]){
                        _help[i][a]++;
                    }
                }
                _map[docs[i][j]].push_back(i);
            }

            for (int k = 0; k < _size; k++)
            {
                if(_help[i][k] > 0){
                    ostringstream out;
                    out.precision(4);
                    out << fixed << (double)_help[i][k] / (double)(docs[i].size() + docs[k].size() - _help[i][k]) + 1e-9;
                    _res.push_back(to_string(k) + "," + to_string(i) + ": " + out.str());
                }
            }
        }

        return _res;
    }
};
