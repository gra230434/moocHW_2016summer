//
//  main.c
//  compro_HW1_0706
//
//  Created by WeiKevin on 2016/7/3.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>

int changchar(int number){
    int anschar;
    if ( number == 0 ) {
        anschar = number+74;
    } else {
        anschar = number+64;
    }
    
    return anschar;
}

int main(int argc, const char * argv[]) {
    char answer[3];
    int inputnum;
    int funcnum;
    
    scanf("%3d", &inputnum);
    for (int i=0; i < 3; i++){
        funcnum = inputnum%10;
        inputnum = inputnum/10;
        answer[2-i] = changchar( funcnum );
    }
    
    printf("%.3s\n", answer);
    
    return 0;
}
