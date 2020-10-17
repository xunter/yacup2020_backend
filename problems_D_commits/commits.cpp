#include <stdio.h>
#include <iostream>
#include <math.h>

#define REQ_COUNT_MAX 25

int main() {
 int n = pow(10, 6);
 fscanf(stdin, "%d", &n);
  
 int m = 0;
 int d = n;
 int rc = 0;
 int l1 = 0;
 
 while (rc++ < REQ_COUNT_MAX) {
  int mnext = l1 + d;
  fprintf(stdout, "%d\n", mnext);
  fflush(stdout);
  
  int r;
  fscanf(stdin, "%d", &r);
  if (r == 0) {
   m = mnext;
  } else {
   l1 = mnext;
  }
  if (d == 1) break;
  d = ceil(d / 2);
 }
 
 if (m > 0) {	 
  fprintf(stdout, "! %d", m);
  fflush(stdout);
 }

 return 0;
}