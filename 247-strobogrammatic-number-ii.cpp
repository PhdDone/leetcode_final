class Solution {
public:
  vector<string> findStrobogrammatic(int n) {
    vector<string> strobos;
    if (n & 1) strobos = {"0", "1", "8"}; //odd length then the middle one is 0, 1 or 8
    else strobos = {""}; //even number then no middle
    vector<string> bases = {"00", "11", "69", "88", "96"};
    int m = bases.size();
    while (n > 1) {
      n -= 2;
      vector<string> temp; 
      for (string strobo : strobos)
	for (int i = n < 2; i < m; i++) //the last one(n == 1) or (n == 0)
	  temp.push_back(bases[i][0] + strobo + bases[i][1]);
      strobos = move(temp);
    }
    return strobos;
  }
};
