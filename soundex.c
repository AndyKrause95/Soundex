#include <stdio.h>
#include <ctype.h>
#include <string.h>

void soundex(char s[], char res[]) {
    // Check if array is empty
    if(strlen(s) <= 0) {
        printf("Empty Array! \n");
        return;
    }
    
    // Capitalize first letter
    res[0] = (char)toupper(s[0]);
    s[0] = toupper(s[0]);
    
    // Create Soundex Word
    int r = 1;
    int i = 1;

    for(i; i < strlen(s); i++) {
        s[i] = toupper(s[i]);
        if(s[i] == 'B' || s[i] == 'F' || s[i] == 'P' || s[i] == 'V') {
        //if(strstr("BFPV", toupper(s[i]))) {
            if(res[r-1] != '1') {
                res[r] = '1';
                r++;
            }
        } else if(s[i] == 'C' || s[i] == 'G' || s[i] == 'J' || s[i] == 'K' || s[i] == 'Q' || s[i] == 'S' || s[i] == 'X' || s[i] == 'Z') {
            if(res[r-1] != '2') {
                res[r] = '2';
                r++;
            }
        } else if(s[i] == 'D' || s[i] == 'T') {
            if(res[r-1] != '3') {
                res[r] = '3';
                r++;
            }
        } else if(s[i] == 'L') {
            if(res[r-1] != '4') {
                res[r] = '4';
                r++;
            }
        } else if(s[i] == 'M' || s[i] == 'N') {
            if(res[r-1] != '5') {
                res[r] = '5';
                r++;
            }
        } else if(s[i] == 'R') {
            if(res[r-1] != '6') {  
                res[r] = '6';
                r++;
            }
        } else {
            //printf("Nothing found. Character: %c \n", s[i]);
        }
        // End of Soundex word
        if(r > 5) {
            //printf("End of Word. r: %i \n", r);
            break;
        }
    }
    
    // Fill results array to 6 characters
    if(r < 6) {
        for(r; r < 7; r++) {
            res[r] = '0';
        }
    }
    // Add end of string
    res[6] = '\0';
    printf("====================\n");
    printf("Word: %s \n", s);
    printf("Soundex: %s \n", res);
    printf("====================\n");
}

int main()
{
    int textArraySize = 100;
    char textArray[textArraySize];
    char res[7];
    printf("Enter a name: \n");
    while(fgets(textArray, textArraySize, stdin)) {
        // Remove new line \n
        int len = strlen(textArray);
        if (len && textArray[len-1] == '\n') {
            textArray[len-1] = 0;
        }
        
        soundex(textArray, res);
        printf("Enter a name: \n");
    }
    return 0;
}