//
//  main.c
//  compro_Final10243_0828
//
//  Created by WeiKevin on 2016/8/28.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>

#define MAX 10
int table[MAX][MAX] = {{0}};
int queennum, castlenum, totalnum;
int tmpqunum, tmpcalnum;
int answer = 0;

void printfanswer( void ) {
  int i, j;
  for ( i = 0; i < totalnum; i++) {
    for ( j = 0; j < totalnum; j++) {
      printf( "%d", table[i][j] );
      if (j==totalnum-1) {
        printf( "\n" );
      } else {
        printf( " " );
      }
    }
  }
}

void claeranswer( void ) {
  int i, j;
  for ( i = 0; i < totalnum; i++) {
    for ( j = 0; j < totalnum; j++) {
      table[i][j] = 0;
    }
  }
}

int forqueenattact( int x, int y, int check ) {
  int tmpx=x, tmpy=y;
  int i;
  switch ( check ) {
    case 5:
    for ( i = 0; i < MAX; i++) {
      if ( tmpx-i >= 0 && tmpy-i >= 0 ) {
        if ( table[tmpx-i][tmpy-i] != 0 ) {
          return 0;
        }
      }
      if ( tmpx-i >= 0 && tmpy+i < MAX ) {
        if ( table[tmpx-i][tmpy+i] != 0 ) {
          return 0;
        }
      }
      if ( tmpx+i < MAX && tmpy-i >= 0 ) {
        if ( table[tmpx+i][tmpy-i] != 0 ) {
          return 0;
        }
      }
      if ( tmpx+i < MAX && tmpy+i < MAX ) {
        if ( table[tmpx+i][tmpy+i] != 0 ) {
          return 0;
        }
      }
    }
    break;
    case 9:
    for ( i = 0; i < MAX; i++) {
      if ( tmpx-i >= 0 && tmpy-i >= 0 ) {
        if ( table[tmpx-i][tmpy-i] == 5 ) {
          return 0;
        }
      }
      if ( tmpx-i >= 0 && tmpy+i < MAX ) {
        if ( table[tmpx-i][tmpy+i] == 5 ) {
          return 0;
        }
      }
      if ( tmpx+i < MAX && tmpy-i >= 0 ) {
        if ( table[tmpx+i][tmpy-i] == 5 ) {
          return 0;
        }
      }
      if ( tmpx+i < MAX && tmpy+i < MAX ) {
        if ( table[tmpx+i][tmpy+i] == 5 ) {
          return 0;
        }
      }
    }
    break;
  }

  return 1;
}

int forcastleattact( int x, int y ) {
  int i;
  for ( i = 0; i < totalnum; i++) {
    if ( table[i][y] != 0 ) {
      return 0;
    }
  }
  for ( i = 0; i < totalnum; i++) {
    if ( table[x][i] != 0 ) {
      return 0;
    }
  }
  return 1;
}

void placeable( int row ) {
  int i,j;
  if ( tmpqunum == queennum && tmpcalnum == castlenum ) {
    answer = answer + 1;
  } else if ( row < totalnum && tmpqunum <= queennum && tmpcalnum <= castlenum ) {

      for ( j = 0; j < 2; j++) {

        switch ( j ) {
          case 0:
          for ( i = 0; i < totalnum; i++ ) {
            if ( tmpqunum < queennum && queennum !=0 ) {
              if ( forcastleattact( row, i ) == 1 && forqueenattact( row, i, 5 ) == 1 ) {
                table[row][i]=5;
                tmpqunum++;
                placeable( row+1 );
                table[row][i]=0;
                tmpqunum--;
              }
            }
          }
          break;

          case 1:
          for ( i = 0; i < totalnum; i++ ) {
            if ( tmpcalnum < castlenum && castlenum !=0 ) {
              if ( forcastleattact( row, i ) == 1 && forqueenattact( row, i, 9 ) == 1 ) {
                table[row][i]=9;
                tmpcalnum++;
                placeable( row+1 );
                table[row][i]=0;
                tmpcalnum--;
              }
            }
          }
          break;
        }
      }


  }
}

int main(int argc, const char * argv[]) {

  scanf("%d %d", &queennum, &castlenum);
  totalnum = queennum + castlenum;

  tmpqunum = 0; tmpcalnum = 0;
  placeable( 0 );
  printf("%d\n",answer );
  return 0;
}
