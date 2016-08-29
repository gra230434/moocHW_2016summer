//
//  main.c
//  compro_Final10244_0829
//
//  Created by WeiKevin on 2016/8/29.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define ArrayMAX 20000

int arrayA[ArrayMAX][2]={{0}};
int arrayB[ArrayMAX][2]={{0}};
int numA = 0, numB = 0;

int returnArrayB( int check ){
  int i;
  for ( i = 0; i < numB; i++) {
    if ( arrayB[i][1]==check ) {
      return arrayB[i][2];
    }
  }
  return 0;
}

int main(int argc, const char * argv[]) {
  int answer=0;
  int a=1,b=1;
  int i;

  while ( a != 0 ) {
    scanf("%d:%d",&a,&b);
    arrayA[numA][1]=a;
    arrayA[numA][2]=b;
    numA ++;
  }
  a = 1;
  while ( a != 0 ) {
    scanf("%d:%d",&a,&b);
    arrayB[numB][1]=a;
    arrayB[numB][2]=b;
    numB ++;
  }
  for ( i = 0; i < numA; i++ ) {
    answer = answer + ( arrayA[i][2] * returnArrayB(arrayA[i][1]) );
  }
  printf("%d\n",answer );
  return 0;
}
