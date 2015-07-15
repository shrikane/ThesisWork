#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void Replace(const string& bits, int start, vector<string>* res) {

  int idx = bits.find("100", start);
  while (idx != string::npos) {
    string tmp = bits;
    tmp.replace(idx,3,"011");
//    cout << bits << " -> " << tmp << endl;
    (*res).push_back(tmp);
    // possible replacement might have become available due to previous replace
    int next = idx >= 2 ? idx-2 : idx+2;
    Replace(tmp, next, res);
    idx = bits.find("100", idx+1);  
  }
}

int main(int argc, char** argv) {

  int N;
  cin >> N;
  
  vector<int> fib;
  int first = 1, second = 2;
  fib.push_back(first);
  fib.push_back(second);
  while (1) {
    int res = first + second;
    if (res > N)
    	break;
    fib.push_back(res);
    first = second;
    second = res;
  }
//  std::copy(fib.begin(), fib.end(), std::ostream_iterator<int>(cout, " "));

  string bits(fib.size(),'0');
  while (N > 0) {
    vector<int>::reverse_iterator rit = std::find_if(fib.rbegin(),fib.rend(),std::bind2nd(std::less_equal<int>(),N));
    int idx = rit - fib.rbegin();
    bits[idx] = '1';
    N -= *rit;
  }
//  cout << bits << endl;

  vector<string> res;
  res.push_back(bits);
  Replace(bits, 0, &res);
  
  std::copy(res.begin(),res.end(),std::ostream_iterator<string>(cout,"\n"));
  return 0;
}