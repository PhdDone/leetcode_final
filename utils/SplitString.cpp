#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int SplitByStringStream() {
  string dir1 = "/hello/world/file";
  vector<string> tokens;
  istringstream ss(dir1);
  string token;
  while (getline(ss, token, '/')) {
    tokens.push_back(token);
  }
  for (auto& t : tokens) {
    cout << t << endl;
  }
  return 0;
}

void SplitByFind() {
  string dir1 = "/hello/test/r1";
  int begin = dir1.find('/');
  while (begin >= 0 && begin < dir1.size()) {
    if (begin == dir1.size() - 1) {
      auto token = 
    dir1 = dir1.substr(begin);
    int end = dir1.find('/');
    if (end == -1) {
    }
}

int main() {
  //SplitByStringStream();
  SplitByFind();
  return 0;
}
