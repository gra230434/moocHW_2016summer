//
//  main.c
//  compro_HW2_0706
//
//  Created by WeiKevin on 2016/7/3.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>

int totwonumber(int check){
    int ans = 0;
    if (check%2==0) {
        ans = check/2;
    } else {
        ans = check;
    }
    return ans;
    
}

int main(int argc, const char * argv[]) {
    int inputnumber=0;
    int checknum=0, returnnum = 0, answerlong=0;
    int answernum[4];
    
    scanf("%d",&inputnumber);
    
    while (inputnumber/10 > 0) {
        checknum = inputnumber%10;
        
        returnnum = totwonumber(checknum);
        
        answernum[answerlong]=returnnum;
        inputnumber = inputnumber/10;
        answerlong++;
    }
    returnnum = totwonumber(inputnumber);
    answernum[answerlong]=returnnum;
    
    for (int i=answerlong; i>=0 ; i--) {
        printf("%d", answernum[i]);
    }
    printf("\n");
    
    return 0;
}
