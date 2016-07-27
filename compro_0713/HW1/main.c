//
//  main.c
//  compro_HW1_0713
//
//  Created by WeiKevin on 2016/7/11.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char inputstring[100] = {(char)0}, outputstring[100] = {(char)0};
    int tempcount=0, maxcount=0;
    int inputcount=0, outputcount=0;
    
    scanf("%[^#]", inputstring);
    
    while (inputstring[inputcount]!=(char)0) {
        if (inputstring[inputcount]>(char)96 && inputstring[inputcount]<(char)123) {
            outputstring[outputcount] = inputstring[inputcount];
            inputcount++;
            outputcount++;
        } else {
            inputcount++;
        }
    }

    for (int i=0; i<outputcount; i++) {
        if (i==0) {
            tempcount++;
            if (tempcount>maxcount) {
                maxcount=tempcount;
            }
        }else{
            if ((int)outputstring[i]>=(int)outputstring[i-1]) {
                tempcount++;
                if (tempcount>maxcount) {
                    maxcount=tempcount;
                }
            }else{
                tempcount = 1;
            }
        }
    }

    printf("%d\n",maxcount);
    return 0;
}
