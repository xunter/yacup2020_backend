#include <stdio.h>
#include <iostream>

int main() {
 std::string jewelry_str;
 std::string rocks_str;
 std::getline(std::cin, jewelry_str);
 std::getline(std::cin, rocks_str);

 int cnt = 0;
 std::string jewelry_uniqs_str;
 for (int i = 0; i < jewelry_str.length(); i++) {
  if (jewelry_uniqs_str.find(jewelry_str[i]) != std::string::npos) {
   continue;
  }
  jewelry_uniqs_str += jewelry_str[i];
  for (int j = 0; j < rocks_str.length(); j++) {
   if (rocks_str[j] == jewelry_str[i]) {
    cnt++;
   }
  }
 }

 printf("%d\n", cnt);
 return 0;
}