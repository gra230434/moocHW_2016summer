//
//  main.c
//  compro_0727_HW2
//
//  Created by WeiKevin on 2016/7/26.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAXBIT 8

char bottle[3][MAXBIT+1];

void HanoiTower(int no, int src, int tmp, int end, int count){
    
    if(no==1){
        int endbits=0, srcbits=0;
        endbits = (int)strlen(bottle[end]);
        srcbits = (int)strlen(bottle[src]);
        bottle[end][endbits] = bottle[src][srcbits-1];
        printf("%c:%d->%d\n",bottle[end][endbits],src,end);
        bottle[src][srcbits-1] = '\0';
        
    } else {
        HanoiTower(no-1, src, end, tmp, count);
        HanoiTower(1, src, tmp, end, count);
        HanoiTower(no-1, tmp, src, end, count);
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int count=0;
    
    scanf("%8s",bottle[0]);
    count = (int)strlen(bottle[0]);
    
    /* HanoiTower(count, 起始, 暫存, 目標) */
    HanoiTower(count, 0, 2, 1,count);
    
    return 0;
}
