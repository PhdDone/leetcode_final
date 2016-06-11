/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

  Note:
  (1) 1 is a super ugly number for any given primes.
  (2) The given numbers in primes are in ascending order.
    (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/
//https://www.hrwhisper.me/leetcode-ugly-number-i-ii/


//https://www.hrwhisper.me/leetcode-super-ugly-number/

struct Node {
  int val,index,prime;
  Node(int index,int val,int prime):index(index),val(val),prime(prime){}
  bool operator < (const Node &b)const { //overload < !!
    return val > b.val;
  }
};

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector <int> ugly_nums(n, 0);
    ugly_nums[0] = 1;
    priority_queue<Node> q;
    for (int j = 0; j < primes.size(); j++) {
      q.push(Node(0, primes[j], primes[j]));
    }
    
    for (int i = 1; i < n; i++) {
      Node cur = q.top(); 
      ugly_nums[i] = cur.val;
      do {
	cur = q.top(); q.pop();
	cur.val = cur.prime * ugly_nums[++cur.index];
	q.push(cur);
      } while (q.top().val == ugly_nums[i])； ////may have several same min values in the
	       //priority Q, say [2, 7], we will get 14 twice
    }
    return ugly_nums[n - 1];
  }
};
