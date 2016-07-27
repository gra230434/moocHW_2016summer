//
//  main.c
//  compro_HW3_0713
//
//  Created by WeiKevin on 2016/7/11.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int inputnum=0;
    int odd[7]={0}, even[7]={0};
    int times=1,count=0,tempnum=0, minquotient=10000000, tempquotient=0;
    
    scanf("%d", &inputnum);
    
    tempnum=pow(10,times);
    while (inputnum/tempnum!=0) {
        odd[count]=inputnum/tempnum;
        even[count]=inputnum%tempnum;
        count++;
        times++;
        tempnum=pow(10,times);
    }
    
    for (int i=0; i<count; i++) {
        if (i<(times/2)) {
            if (even[i]!=0 && odd[i]%even[i]==0) {
                tempquotient = odd[i]/even[i];
                if (tempquotient<minquotient) {
                    minquotient=tempquotient;

                }
            }
        } else {
            if (even[i]!=0 && even[i]%odd[i]==0) {
                tempquotient = even[i]/odd[i];
                if (tempquotient<minquotient) {
                    minquotient=tempquotient;

                }
            }
        }
    }
    if (minquotient==10000000) {
        printf("0");
    }else{
        printf("%d",minquotient);
    }
    printf("\n");
    return 0;
}
