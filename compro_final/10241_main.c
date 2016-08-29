//
//  main.c
//  compro_Final10241_0828
//
//  Created by WeiKevin on 2016/8/28.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>

int cointype[5]={0};
int coinmax[5]={0};
int answer[5]={0};
int cointypenum, totalmomey;

void printfanswer( void ) {
  int i;
  printf("(");
  for ( i = 0; i < cointypenum; i++) {
    if ( i == 0 ) {
      printf( "%d",answer[i] );
    } else {
      printf( ",%d",answer[i] );
    }
  }
  printf(")\n");
}

void claeranswer( int input ) {
  int i;
  for ( i = input; i < cointypenum; i++) {
    answer[i] = 0;
  }
}

int tmpmoneyfun( void ) {
  int returnnum = totalmomey,i;

  for ( i = 0; i < cointypenum; i++) {
    returnnum = returnnum - ( cointype[i] * answer[i] );
  }

  return returnnum;
}

void changcoin( int input ) {

  int i, tmpmoney;
  if ( input < cointypenum ) {
    for ( i = 0; i <= coinmax[input]; i++ ) {
      answer[input] = i;
      tmpmoney = tmpmoneyfun();

      if ( tmpmoney == 0 ) {
        printfanswer();

      } else if ( tmpmoney > 0 ) {
        changcoin( input+1 );

      } else {
        claeranswer( input );
      }
    }

  }

}

int main(int argc, const char * argv[]) {
    int i=0;

    scanf("%d", &cointypenum);
    for ( i=0; i < cointypenum; i++ ){
      scanf("%d", &cointype[i]);
    }
    scanf("%d", &totalmomey);

    for ( i = 0; i < cointypenum; i++ ){
      coinmax[i] = ( totalmomey/cointype[i] ) + 1;
    }

    changcoin(0);
    return 0;
}
