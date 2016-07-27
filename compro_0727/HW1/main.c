//
//  main.c
//  compro_0721_HW1
//
//  Created by WeiKevin on 2016/7/26.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>
#include <string.h>


#define MAXBITS 16

char bits[3];
char input[MAXBITS+1];
char answer[MAXBITS+1];
int MBITS;

char changechar (char ch){
    return ((ch==bits[0])?bits[1]:bits[0]);
}

void check_bits(int nowfor, int correct, int befornum){
    char tmp[MBITS+1];
    for (int tmpcount=0; tmpcount<MBITS; tmpcount++){tmp[tmpcount]=answer[tmpcount];}
    for (int b = befornum; b<MBITS; b++) {
        answer[b]=input[b];
        if (nowfor==correct) {
            for (int count=0; count<MBITS; count++) {
                if (answer[count]=='\0') {
                    answer[count]=changechar(input[count]);
                }
            }
            printf("%s\n",answer);
            for (int tmpcount=0; tmpcount<MBITS; tmpcount++){answer[tmpcount]=tmp[tmpcount];}
        } else {
            check_bits(nowfor+1, correct, b+1);
            for (int tmpcount=0; tmpcount<MBITS; tmpcount++){answer[tmpcount]=tmp[tmpcount];}
        }
    }
    
}

void fix_bit(int correct){
    
    int nowfor=0;
    
    check_bits(nowfor+1, correct, 0);
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int  correct;
    
    scanf("%2s", bits);
    scanf("%s", input);
    MBITS = (int)strlen(input);
    answer[MBITS] = '\0';
    
    scanf("%d", &correct);
    
    fix_bit(correct);
    
    return 0;
}

