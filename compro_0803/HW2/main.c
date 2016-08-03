#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N_WORDS 50
char dictionary[N_WORDS][30]={
"a",
"all",
"an",
"and",
"are",
"as",
"at",
"be",
"but",
"by",
"can",
"each",
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
"of",
"on",
"one",
"or",
"other",
"out",
"said",
"she",
"some",
"that",
"The",
"there",
"they",
"this",
"To",
"up",
"use",
"was",
"we",
"were",
"what",
"when",
"with",
"word",
"you",
"your"
};

/* #define ONLINE_JUDGE */

void complete(char *input_str);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("ps5_2_test.txt", "r", stdin);
#endif

    char input[30];

    while (scanf("%29s", input)!=EOF) {
        complete(input);
    }

    return 0;
}

/*
Iteratively convert every words in the dictionary into lowercase,
and store the converted word in lower.
Use strncmp to compare the first len characters of input_str and lower.
If the return value of strncmp is 0, then the first len characters
of the two strings are the same.
*/
void complete(char *input_str)
{
    int len = strlen(input_str);
    int i, j, found;
    char lower[30];

    found = 0;

    /* your code here */
    for (int count = 0; count < N_WORDS; count++) {
      for (int lowercount = 0; lowercount < 30; lowercount++) {
        /* code */
        lower[lowercount] = tolower(dictionary[count][lowercount]);
      }
      if ( strncmp( lower, input_str, len ) ) {
        /* code */
        if (found) {
          printf(",");
        }
        printf("%s",dictionary[count]);
        found=1;
      }
    }

    if (!found) {
        printf("None.\n");
    } else {
        printf("\n");
    }
}
