#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[100], str2[100], str_rem[100];
    int count[256] = {0}; 
    int i = 0, j = 0, k = 0;

    printf("Enter the characters to delete (First string):\n");
    gets(str1);

    printf("Enter the target string (Second string):\n");
    gets(str2);

    for (i = 0; str1[i] != '\0'; i++) {
        k = 0;
        int found_this_char = 0;
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                count[(unsigned char)str1[i]]++;
                found_this_char = 1;
            } else {
                str_rem[k] = str2[j];
                k++;
            }
        }
        str_rem[k] = '\0';
        strcpy(str2, str_rem);
    }

    printf("\nResulting string: %s\n", str2);
    printf("\nSummary\n");

    for (i = 0; str1[i] != '\0'; i++) {
        int duplicate = 0;
        for (int prev = 0; prev < i; prev++) {
            if (str1[prev] == str1[i]) duplicate = 1;
        }

        if (!duplicate) {
            if (count[(unsigned char)str1[i]] > 0) {
                printf("Character '%c' removed: %d\n", str1[i], count[(unsigned char)str1[i]]);
            } else {
                printf("Character '%c' not found\n", str1[i]);
            }
        }
    }

    return 0;}
