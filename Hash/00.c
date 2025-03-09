// Hashing
#include<stdio.h>
#include<string.h>
#define HASH_TABLE_SIZE 256

void count_character(char *s) {
    int freq[HASH_TABLE_SIZE] = {0};

    for(int i=0; s[i] != '\0'; i++) {
        freq[(int)s[i]]++;      // (int)s[i] converts the character to its ASCII integer value.
    }

    for(int i=0; i < HASH_TABLE_SIZE; i++) {
        if(freq[i] > 0) {
            printf("%c occured %d times\n", (char)i, freq[i]);      // (char)i converts the integer back into a character.
        }
    }
}

int main() {
    char s[] = "oceanoRsea";
    count_character(s);

    return 0;
}