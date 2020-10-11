#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>

int N = pow(10, 5);
int X = pow(10, 9);
int K = pow(10, 9);

int *t_arr = 0;

int main() {
 scanf("%d %d %d", &N, &X, &K);
 t_arr = (int *)calloc(N, sizeof(int));

 for (int i = 0; i < N; i++) scanf("%d", &t_arr[i]);

 int k = 0;
 int c = 0;
 int cabs = 0;
 while (k < K) {
  for (int i = 0; i < N; i++) {
   int ti = t_arr[i];
   for (int ci = 0; ci <= c; ci++) {
    if (cabs == ti + ci * X) {
     //printf("cabs=%d, c=%d, ci=%d, ti=%d\n", cabs, c, ci, i);
     k++;
     break;
    }
   }
  }
  cabs++;
  if ((cabs - 1) > 0 && (cabs - 1) % X == 0) {
   c++;
  }
 }

 printf("%d\n", cabs);
 /*
 printf("N=%d, X=%d, K=%d\n", N, X, K);

 printf("t_arr = [");
 for (int i = 0; i < N; i++) printf(i == N - 1 ? "%d" : "%d,", t_arr[i]);
 printf("]\n", N, X, K);
 */

 free(t_arr);
 return 0;
}