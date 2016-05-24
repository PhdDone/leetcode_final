/*Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */

/*Linkedin Apple Twitter*/

//https://leetcode.com/discuss/45105/16ms-28ms-c-solutions-with-explanations

class Solution { 
public: 
  int maxPoints(vector<Point>& points) {
    map<pair<int, int>, int> slopes;
    int maxp = 0, n = points.size();
    for (int i = 0; i < n; i++) {
      slopes.clear();
      int duplicate = 1; //including it self
      for (int j = i + 1; j < n; j++) {
	if (points[j].x == points[i].x && points[j].y == points[i].y) {
	  duplicate++; //have several points in one place
	  continue;
	}
	int dx = points[j].x - points[i].x;
	int dy = points[j].y - points[i].y;
	int dvs = gcd(dx, dy);
	slopes[make_pair(dx / dvs, dy / dvs)]++;
      }
      maxp = max(maxp, duplicate); // duplicate is at least 1
      for (auto slope : slopes)
	if (slope.second + duplicate > maxp)
	  maxp = slope.second + duplicate;
    } 
    return maxp;
  }
  //num2 is always the smaller one
private:
  int gcd(int num1, int num2)
    while (num2) {
      int temp = num2; 
      num2 = num1 % num2;
      num1 = temp;
    }
    return num1;
  }
};
