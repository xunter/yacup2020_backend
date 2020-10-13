#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>

int K = pow(10, 3);
int N = pow(10, 6);

int *n_arr = 0;
//int *n_inuse_arr = 0;

int main() {
 scanf("%d %d", &K, &N);
 n_arr = (int *)calloc(N, sizeof(int));
 //n_inuse_arr = (int *)calloc(N, sizeof(int));

 for (int i = 0; i < N; i++) scanf("%d", &n_arr[i]);

 int scores_petya = 0;
 int scores_vasya = 0;

 /*
 int steps_left = N;
 int scores_total = 0;

 int ninusei = 0;

 while (steps_left > 0 && scores_total < K && scores_vasya < K && scores_petya < K) {
  int ni = -1;
  while (ni == -1 && ninusei < N) {
   ni = ceil(rand() % N);
   for (int i = 0; i < ninusei + 1; i++) {
    if (n_inuse_arr[i] == n_arr[ni]) {
     ni = -1;
     break;
    }
   }
  }

  int n = n_arr[ni];
  n_inuse_arr[ninusei++] = n;
  printf("ni=%d, n=%d\n", ni, n, scores_total, );

  if (n % 5 == 0 && n % 3 == 0) {

  } else if (n % 5 == 0) {
   scores_vasya += 1;
  } else if (n % 3 == 0) {
   scores_petya += 1;
  } else {

  }

  scores_total += 1;
  steps_left--;
 }
 */

 for (int ni = 0; ni < N; ni++) {
  int n = n_arr[ni];

  if (n % 5 == 0 && n % 3 == 0) {

  } else if (n % 5 == 0) {
   scores_vasya += 1;
  } else if (n % 3 == 0) {
   scores_petya += 1;
  } else {

  }

  if (scores_petya == K || scores_vasya == K) break;
 }

 if (scores_petya == scores_vasya) {
  printf("Draw\n");
 } else if (scores_petya == K) {
  printf("Petya\n");
 } else if (scores_vasya == K) {
  printf("Vasya\n");
 }

 free(n_arr);
 //free(n_inuse_arr);
 return 0;
}