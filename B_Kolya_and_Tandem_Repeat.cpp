#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <iomanip>
 using namespace std;
 int Max;
 int main() {
 //ifstream cin("input.txt");
 //ofstream cout("output.txt");
 string s;
 cin >> s;
 int K;
 cin >> K;
 for (int i = 0; i < K; i++)
  s += "*";
 for (int N = 2; N <= (int)s.length(); N += 2) {
  for (int i = 0; i <= (int)s.length() - N; i++) {
   bool tr = 1;
   for (int j = i; j < i + N / 2; j++) {
    if (s[j] != s[j + N / 2] && s[j + N / 2] != '*')
     tr = 0;
   }
   if (tr) {
    Max = N;
    break;
   }
  }
 }
 cout << Max << endl;
 return 0;
}