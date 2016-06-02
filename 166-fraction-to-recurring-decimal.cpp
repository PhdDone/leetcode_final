

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (Numerator == 0) return "0"; //check 0
    long long int Numerator = numerator;
    long long int Denominator = denominator;
        
    long long int Remainder = 0;
    bool isNegative = false;
    if (Numerator < 0) {
      Numerator = -Numerator;
      isNegative = !isNegative;
    }
    if (Denominator < 0) {
      Denominator = -Denominator;
      isNegative = !isNegative;
    }
        
    ostringstream result;
    if (isNegative) {
      result << "-";
    }
    result << Numerator / Denominator;
    Remainder = Numerator % Denominator;
        
    if (Remainder == 0) {
      return result.str();
    }
    unordered_map<int, int> remainderIndex;
    vector<int> values;
    result << ".";
    //for loop!!
    for (int i = 0; Remainder && (remainderIndex.find(Remainder) == remainderIndex.end()); ++i) {
      remainderIndex[Remainder] = i;
      Remainder *= 10;
      values.push_back(Remainder / Denominator);
      Remainder %= Denominator;
    }
        
    if (Remainder == 0) {
      for (int i = 0; i < values.size(); ++i) {
	result << values[i];
      }
      return result.str();
    }
        
    else {
      int index = remainderIndex[Remainder];
      for (int i = 0; i < index; ++i) {
	result << values[i];
      }
      result << "(";
      for (int i = index; i < values.size(); ++i) {
	result << values[i];
      }
      result << ")";
      return result.str();
    }
    return "";
        
  }
};
