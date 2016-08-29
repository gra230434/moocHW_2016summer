//
//  main.c
//  compro_Final10244_0829
//
//  Created by WeiKevin on 2016/8/29.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>
#define MAX 30

int table[MAX][MAX]={{0}};
int step, number=0;
int tmpA=0, tmpB=1, tmpC=1, tmpD=0, point=0;

int pointx( int x,int y ){
  int i, j;
  for ( i = 0; i < x; i++) {
    for ( j = 0; j < y; j++) {
      if ( table[i][j] == point ) {
        return i+1;
      }
    }
  }
  return -1;
}

int pointy( int x,int y ){
  int i, j;
  for ( i = 0; i < x; i++) {
    for ( j = 0; j < y; j++) {
      if ( table[i][j] == point ) {
        return j+1;
      }
    }
  }
  return -1;
}

void printfanswer( int x,int y ) {
  int i, j;
  for ( i = 0; i < x; i++) {
    for ( j = 0; j < y; j++) {
      printf("%d", table[i][j] );
      if ( j == y-1 ) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  }
}

void intotable( int x,int y ) {
  int who = step % 4;
  int i;
  if ( number <= x * y ) {
    switch (who) {
      case 1:
        for ( i = 0; i < y; i++) {
          if (table[tmpA][i]==0) {
            table[tmpA][i]=number;
            number ++;
          }
        }
        step ++;
        tmpA ++;
        intotable(x,y);
        break;

      case 2:
        for ( i = 0; i < x; i++) {
          if (table[i][y-tmpB]==0) {
            table[i][y-tmpB]=number;
            number ++;
          }
        }
        step ++;
        tmpB ++;
        intotable(x,y);
        break;

      case 3:
        for ( i = 0; i < y; i++) {
          if (table[x-tmpC][y-i-1]==0) {
            table[x-tmpC][y-i-1]=number;
            number ++;
          }
        }
        step ++;
        tmpC ++;
        intotable(x,y);
        break;

      case 0:
        for ( i = 0; i < x; i++) {
          if (table[x-i-1][tmpD]==0) {
            table[x-i-1][tmpD]=number;
            number ++;
          }
        }
        step ++;
        tmpD ++;
        intotable(x,y);
        break;
      }
  }
}

int main(int argc, const char * argv[]) {
  int x=0,y=0;

  scanf("%d %d %d",&x ,&y, &point );
  number = 1;
  step = 1;
  intotable(x,y);
  printf("%d %d\n",pointx(x,y) ,pointy(x,y) );
  return 0;
}
