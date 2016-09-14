

class Solution {
public:
  string simplifyPath(string path) {
    string ret, curDir;
    vector<string> allDir;

    path.push_back('/');
    for(int i=0; i<path.size(); i++) {
      if(path[i]=='/') {
        if(curDir.empty()) {
          continue;
        }
        else if(curDir==".") {
          curDir.clear();
        }
        else if(curDir=="..") {
          if(!allDir.empty())
            allDir.pop_back();
          curDir.clear();
        }
        else {
          allDir.push_back(curDir);
          curDir.clear();
        }
      }
      else {
        curDir.push_back(path[i]);
      }
    }


    for(int i=0; i<allDir.size(); i++)
      ret.append("/"+allDir[i]);
    if(ret.empty()) ret = "/";
    return ret;
  }
};



// bug below /... => /
class Solution {
public:
  string simplifyPath(string path) {
    vector<string> dirs;
    int N = path.size();
    for(auto i = 0; i < N;) {
      ++i;
      auto j = path.find("/", i); //return index!!
      string dir;
      if (j == string::npos) {
        dir = path.substr(i);
      } else {
        dir = path.substr(i, j - i);
      }//substr takes index and length
      //auto dir = string(i, j);

      if (!dirs.empty() && dir != ".") { // "///"=> dir.empty() == true
        if (dir == "..") {
          if (!dirs.empty()) dirs.pop_back();
        } else {
          dirs.push_back(dir);
        }
      }
      cout << j << endl;
      i = j; //update i to the next "/"
    }

    stringstream output;
    if (dirs.empty()) {
      output << "/";
    } else {
      for (auto d : dirs) {
        output << "/" << d;
      }
    }

    return output.str();
  }
};
