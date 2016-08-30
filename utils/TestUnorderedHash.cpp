#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

struct Key
{
  std::string first;
  std::string second;
  int         third;

  bool operator==(const Key &other) const
  { return (first == other.first
                        && second == other.second
            && third == other.third);
  }
};

struct KeyHasher
{
  std::size_t operator()(const Key& k) const
  {
    using std::size_t;
    using std::hash;
    using std::string;

    size_t h1 = hash<string>()(k.first);
    size_t h2 = hash<string>()(k.second);
    size_t h3 = hash<int>()(k.third);
    return (h1 ^ (h2 << 1)) ^ (h3 << 1); //hash_combine
  }
};

int main()
{
  std::unordered_map<Key,std::string, KeyHasher> m6 = {
    { {"John", "Doe", 12}, "example"},
    { {"Mary", "Sue", 21}, "another"}
  };

  cout << m6[{"Mary", "Sue", 21}] << endl;
}

