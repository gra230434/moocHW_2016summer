//
//  main.c
//  compro_HW1_0720
//
//  Created by WeiKevin on 2016/7/19.
//  Copyright © 2016年 WeiKevin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char HW_str1[10];
char HW_str2[10];
char HW_str3[10];
int mapping[10]={-1};
int num1=0, num2=0, num3=0;
char input_first, input_sec;


void readfirststr(void){
    int i=0;
    char inputchar;
    
    while ((inputchar=getchar()) != '+') {
        HW_str1[i]=inputchar;
        i++;
    }
    HW_str1[i+1]='\0';
    i=0;
    while ((inputchar=getchar()) != '=') {
        HW_str2[i]=inputchar;
        i++;
    }
    HW_str2[i+1]='\0';
    i=0;
    while ((inputchar=getchar()) != '\n') {
        HW_str3[i]=inputchar;
        i++;
    }
    HW_str3[i+1]='\0';
};

void read_mapping(void){
    int mappingid=-1, Noinput=1;
    char inputchar;
    
    while ((inputchar=getchar()) != '#') {
        if ( isupper(inputchar) ) {
            if (Noinput==1 ) {
                input_first = inputchar;
            } else if (Noinput==2){
                input_sec = inputchar;
            }
            switch (inputchar) {
                case 'A':
                    mappingid=0;
                    break;
                case 'B':
                    mappingid=1;
                    break;
                case 'C':
                    mappingid=2;
                    break;
                case 'D':
                    mappingid=3;
                    break;
                case 'E':
                    mappingid=4;
                    break;
                case 'F':
                    mappingid=5;
                    break;
                case 'G':
                    mappingid=6;
                    break;
                case 'H':
                    mappingid=7;
                    break;
                case 'I':
                    mappingid=8;
                    break;
                case 'J':
                    mappingid=9;
                    break;
                default:
                    break;
            }
            
            Noinput++;
        } else if ( isdigit(inputchar) ) {
            mapping[mappingid]= ((int)inputchar)-48;
            
        } else if ( inputchar == (char)10 ) {
            mappingid=-1;
        }
        
    }
};

void compiletonum(void){
    int i=0;
    num1=num2=num3=0;
    while (HW_str1[i] != '\0') {
        num1 = mapping[(int)HW_str1[i]-65] + ( num1 * 10 );
        i++;
    }
    i=0;
    while (HW_str2[i] != '\0') {
        num2 = mapping[(int)HW_str2[i]-65] + ( num2 * 10 );
        i++;
    }
    i=0;
    while (HW_str3[i] != '\0') {
        num3 = mapping[(int)HW_str3[i]-65] + ( num3 * 10 );
        i++;
    }
};
void print_num(void){
    printf("%d\n",num1);
    printf("%d\n",num2);
    printf("%d\n",num3);

    if (num1 + num2 == num3) {
        printf("Right\n");
    } else {
        printf("Wrong\n");
    }
};
bool tryanother(void){
    for (int a=0; a<10; a++) {
        mapping[(int)input_first-65] = a;
        for (int b=0; b<10; b++) {
            mapping[(int)input_sec-65] = b;
            compiletonum();
            if (num1+num2==num3) {
                return true;
            }
        }
    }
    return false;
};

void print_str(void){
    
    printf("%s %s %s\n",HW_str1,HW_str2,HW_str3);
    
    for (int i=0; i<10; i++) {
        printf("%3d",mapping[i]);
    }
    printf("\n");
};



void print_ans(void){
    for (int i=0; i<10; i++) {
        printf("%3d",mapping[i]);
    }
    printf("\n");
};

int main(int argc, const char * argv[]) {
    // insert code here...
    memset(mapping,-1,sizeof(mapping));
    
    readfirststr();
    read_mapping();
    
    /*print_str();*/
    if (tryanother()) {
        print_ans();
    }
    
    return 0;
}
