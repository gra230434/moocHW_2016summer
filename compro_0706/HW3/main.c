//
//  main.c
//  compro_HW3_0706
//
//  Created by WeiKevin on 2016/7/6.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float inputfloat=0, neednum=0;
    
    scanf("%f%f",&inputfloat,&neednum);
    
    if(neednum == 1){
        printf("%.0f.0000",inputfloat);
    } else if ( 0.05 < neednum && neednum < 0.5){
        printf("%.1f000",inputfloat);
    } else if ( 0.005< neednum && neednum < 0.05){
        printf("%.2f00",inputfloat);
    } else {
        printf("%.3f0",inputfloat);
    }
    

    printf("\n");
    
    return 0;
}
