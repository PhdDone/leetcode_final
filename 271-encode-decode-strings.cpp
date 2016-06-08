/*Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.*/


class Codec {
public:

  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    stringstream ss;
    for (auto str : strs) {
      ss << str.size() << "#" << str;
    }
    return ss.str();
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> res;
    int cur = 0;
    int N = s.size();
    while (cur < N) {
      int index = s.find('#', cur);
      int len = stoi(s.substr(cur, index - cur));
      res.push_back(s.substr(index+1, len));
      cur = index + len + 1;
    }
    return res;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
