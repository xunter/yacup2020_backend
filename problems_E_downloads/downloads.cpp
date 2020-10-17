#include <stdio.h>
#include <iostream>
#include <math.h>
#include <sys/stat.h>

bool is_file_exists(char *filename);

struct filetrans {
 int destid;
 int sourcecount;
 int *sourceids = 0;
};

int N = pow(10, 6);
int *wiresfrom = 0;
int *wiresto = 0;
int Q = pow(10, 9);
filetrans *transes = 0;


bool is_servers_wired(int srcid, int destid, int *path = 0, int pathi = 0);

int main() {
 /*
 FILE *fin = stdin;
 FILE *fout = stdout;
 
 if (is_file_exists("input.txt")) {
  fin = fopen("input.txt", "r");
 }
*/

 scanf("%d", &N);
 
 wiresfrom = (int *)calloc(N, sizeof(int));
 wiresto = (int *)calloc(N, sizeof(int));
 for (int i = 0; i < N; i++) {
  scanf("%d %d", &wiresfrom[i], &wiresto[i]);
 }
 

 scanf("%d", &Q);
 transes = (filetrans *)malloc(Q * sizeof(filetrans));
 for (int i = 0; i < Q; i++) {
  filetrans &trans = transes[i];
  scanf("%d %d", &trans.destid, &trans.sourcecount);
  trans.sourceids = (int *)malloc(trans.sourcecount * sizeof(int));
  for (int j = 0; j < trans.sourcecount; j++) {
   scanf("%d", &trans.sourceids[j]);
  }
 }

 for (int i = 0; i < Q; i++) {
  filetrans &trans = transes[i];
  //printf("trans destid=%d sourcecount=%d\n", trans.destid, trans.sourcecount);
  int avs = 0;
  int *avids = (int *)calloc(trans.sourcecount, sizeof(int));
  int avidsi = 0;
  for (int j = 0; j < trans.sourcecount; j++) {
   //printf("trans sourceid=%d\n", trans.sourceids[j]);
   if (is_servers_wired(trans.destid, trans.sourceids[j])) {
    avs++;
    avids[avidsi++] = trans.sourceids[j];
   }
  }
  
  printf("%d", avs);
  for (int j = 0; j < avidsi; j++) {
   printf(" %d", avids[j]);
  }
  printf("\n");

  free(avids);
 }
 
 for (int i = 0; i < Q; i++) {
  free(transes[i].sourceids);
 }
 free(transes);
 free(wiresfrom);
 free(wiresto);
 return 0;
}

bool is_servers_wired(int srcid, int destid, int *path, int pathi) {
 if (path == 0) {
  path = (int *)calloc(N, sizeof(int));
 }
 path[pathi] = srcid;
 bool isanyneighboorwired = false;
 for (int i = 0; i < N; i++) {
  if (wiresfrom[i] == srcid && wiresto[i] == destid || wiresfrom[i] == destid && wiresto[i] == srcid) {
   isanyneighboorwired = true;
   break;
  } 
 }
 if (!isanyneighboorwired) {
  for (int i = 0; i < N; i++) {   
   if (wiresfrom[i] == srcid) {	
    bool circ = false;
    for (int j = 0; j < pathi + 1; j++) {
     if (path[j] == wiresto[i]) circ = true;
    }
    if (!circ && is_servers_wired(wiresto[i], destid, path, pathi + 1)) {
     isanyneighboorwired = true;
     break;
    }
   }
   if (wiresto[i] == srcid) {
    bool circ = false;
    for (int j = 0; j < pathi + 1; j++) {
     if (path[j] == wiresfrom[i]) circ = true;
    }
    if (!circ && is_servers_wired(wiresfrom[i], destid, path, pathi + 1)) {
     isanyneighboorwired = true;
     break;
    }
   }
  }
 }

 if (pathi == 0) free(path);
 return isanyneighboorwired;
}

bool is_file_exists(char *filename) {
 struct stat   buffer;   
 return (stat (filename, &buffer) == 0);
}