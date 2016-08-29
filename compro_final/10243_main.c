//
//  main.c
//  compro_Final10243_0828
//
//  Created by WeiKevin on 2016/8/28.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>

int arraydouble[10][10]={{0}};
int arrayanswer[8][8]={{0}};
int maxnum;

void printfanswer( void ) {
  int i, j, count = maxnum-2;
  for ( i = 0; i < count; i++) {
    for ( j = 0; j < count; j++) {
      printf("%d", arrayanswer[i][j] );
      if ( j == count-1 ) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  }
}

int maxnumber(int x,int y){
  int i, j, count=3;
  int maxnumber = arraydouble[x][y];
  //printf("%d\n", maxnumber);
  for ( i = 0; i < count; i++) {
    for ( j = 0; j < count; j++) {
      //printf("%d:%d\n", maxnumber,arraydouble[x+i][y+j]);
      if ( maxnumber < arraydouble[x+i][y+j] ) {
        maxnumber = arraydouble[x+i][y+j];
      }
    }
  }

  return maxnumber;
}

int main(int argc, const char * argv[]) {
  int i, j;

  scanf("%d", &maxnum);
  for ( i=0; i < maxnum; i++ ){
    for ( j = 0; j < maxnum; j++) {
      scanf("%d", &arraydouble[i][j]);
    }
  }

  for ( i=0; i < maxnum-2; i++ ){
    for ( j = 0; j <  maxnum-2; j++) {
      arrayanswer[i][j]=maxnumber(i,j);
    }
  }

  printfanswer();
  return 0;
}
