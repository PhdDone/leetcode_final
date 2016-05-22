//http://www.cnblogs.com/jcliBlogger/p/4851799.html
/*
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
*/

class ValidWordAbbr {
public:
  ValidWordAbbr(vector<string> &dictionary) {
    for(auto i : dictionary) {
      string key = i[0] + to_string(i.length() - 2) + i[i.length() - 1];
      if(d.find(key) == d.end()) {
	unordered_set<string> list;
	list.insert(i);
	d.insert(pair<string, unordered_set<string>>(key, list));
      } else {
	d[key].insert(i);
      }
    }
  }

  bool isUnique(string word) {
    string key = word[0] + to_string(word.length() - 2) + word[word.length() - 1];
    if(d.find(key) == d.end())
      return true;
    else if(d[key].size() == d[key].count(word)) //!!!only one
      return true;
    return false;
  }
    
private:
  unordered_map<string, unordered_set<string>> d;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
