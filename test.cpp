/*38 count and say http://bangbingsyb.blogspot.com/2014/11/leetcode-count-and-say.html
165 compare version number http://yucoding.blogspot.com/2015/03/leetcode-question-compare-version.html
230 remove linked list element 
240 search a 2d matrix ii http://bookshadow.com/weblog/2015/07/23/leetcode-search-2d-matrix-ii/
347 top k frequent elements https://www.hrwhisper.me/leetcode-top-k-frequent-elements/
351 android unlock patterns http://www.cnblogs.com/grandyang/p/5541012.html
*/

#include<iostream>
using namespace std;

class A
{
public:
  void foo()
  {
    printf("1\n");
  }
  virtual void fun()
  {
    printf("2\n");
  }
};
class B : public A
{
public:
  void foo()
  {
    printf("3\n");
  }
  void fun()
  {
    printf("4\n");
  }
};
int main(void)
{
  /*  A a;
  B b;
  A *p = &a;
  p->foo();
  p->fun();
  p = &b;
  p->foo();
  p->fun();
  */
  unsigned* a = new unsigned;
  *a = 3;
  cout << a << endl;
  cout << *a << endl;
  delete a;
  return 0;
}
