#include <iostream>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if (n <= 2) return 0; //2 is prime number
    bool isPrime[n];

    for (int i = 0; i < n; ++i) {
      isPrime[i] = true;
    }
    
        
    for (int i = 2; i * i < n; ++i) {  // i * i < n
      if (isPrime[i]) {
	for (int j = 2; j * i < n; ++j) { // j * i < n
	  isPrime[j * i] = false;
	}
      }
    }
    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (isPrime[i]) ++count;
    }
    return count;
  }
};

int main() {
  Solution s;
  cout << s.countPrimes(3);
  return 0;
}
