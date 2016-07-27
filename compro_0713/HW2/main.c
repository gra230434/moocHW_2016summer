//
//  main.c
//  compro_HW2_0713
//
//  Created by WeiKevin on 2016/7/11.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int numN=1;
    scanf("%d",&numN);
    
    for (int y=0; y<numN; y++) {
        for (int x=0; x<numN; x++) {
            if (x==0 && x==y) {
                printf("  2");
            }else if (x==y-1){
                printf(" -1");
            }else if (x==y){
                printf("  2");
            }else if (x==y+1){
                printf(" -1");
            }else{
                printf("  0");
            }
        }
        printf("\n");
    }
    
    return 0;
}
