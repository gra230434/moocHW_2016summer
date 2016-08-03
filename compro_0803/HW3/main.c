#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N_WORDS 60
char dictionary[N_WORDS][30]={
"a",
"all",
"an",
"and",
"are",
"as",
"at",
"ate",
"be",
"but",
"by",
"can",
"each",
"eat",
"era",
"ew",
"for",
"from",
"had",
"have",
"he",
"his",
"hot",
"how",
"I",
"in",
"is",
"it",
"Neo",
"No",
"of",
"on",
"one",
"or",
"other",
"out",
"said",
"she",
"some",
"tea",
"that",
"The",
"theory",
"there",
"they",
"this",
"To",
"tub",
"up",
"use",
"was",
"we",
"were",
"what",
"when",
"Who",
"with",
"word",
"you",
"your"
};
/* #define ONLINE_JUDGE */

void count_letters(char *input_str, int *counts);
int equal_counts(int *counts1, int *counts2);
void find_words(char *input);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("ps5_3_test.txt", "r", stdin);
#endif

    char input[30];

    while (scanf("%29s", input)!=EOF) {
        find_words(input);
    }

    return 0;
}

void find_words(char *input)
{
    int counts1[26] = {0}, counts2[26] = {0};
    int found = 0;
    int i;

    /* your code here */
    count_letters(input, counts1);
    for ( i = 0; i < N_WORDS; i++) {
      /* code */
      count_letters(dictionary[i], counts2);

      if (equal_counts(counts1, counts2)){
        if (found!=0) {
          printf(",");
        }
        printf("%s", dictionary[i]);
        found = 1;
      }
    }

    if (found) {
        printf("\n");
    } else {
        printf("None.\n");
    }
}
/*
Count the number of occurrences of each letter from 'a' to 'z'.
Store the counts in the integer array counts[].
The integer array counts[] has 26 elements. Each element should
record the number of occurrences of the corresponding letter.
counts[0] for 'a', counts[1] for 'b', ..., etc.
*/
void count_letters(char *input_str, int *counts)
{
    /* your code */
    int i, reset;
    int len = strlen(input_str);
    char lower;
    for ( reset = 0; reset < 26; reset++){
      counts[reset]=0;
    }
    for ( i = 0; i < len; i++) {
      lower = tolower(input_str[i]);
      counts[(int)lower-97] ++;
    }
}

/*
Return 1 if the two arrays counts1[] and counts2[] contain
exactly the same values.
Otherwise, return 0.
*/
int equal_counts(int *counts1, int *counts2)
{
    /* your code */
    int i, count=0;
    for ( i = 0; i < 26; i++) {
      if ( counts1[i]==counts2[i] ) {
        count ++;
      }
    }
    if (count==26) {
      return 1;
    } else {
      return 0;
    }
}
