/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

  If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

  The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
					 1,2,3 → 1,3,2
					 3,2,1 → 1,2,3
					 1,1,5 → 1,5,1
*/

/*
Analysis:
Well, this is more like a math problem, and I don't know how to solve it.
From the wikipedia, one classic algorithm to generate next permutation is:
Step 1: Find the largest index k, such that A[k]<A[k+1]. If not exist, this is the last permutation. (in this    problem just sort the vector and return.)
Step 2: Find the largest index l, such that A[l]>A[k].
Step 3: Swap A[k] and A[l].
Step 4: Reverse A[k+1] to the end.
*/

class Solution {
public:
  void nextPermutation(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int sz = num.size();
    int k=-1;
    int l;
    //step1
    for (int i=0;i<sz-1;i++) {
      if (num[i]<num[i+1]){
	k=i;
      }
    }
    if (k==-1) {
      sort(num.begin(),num.end());
      return;
    }
         
    //step2
    for (int i=k+1;i<sz;i++) {
      if (num[i]>num[k]) {
	l=i;
      }
    }
    //step3        
    swap(num[l], num[k]);
    //step4
    reverse(num.begin()+k+1,num.end());
  }
};
