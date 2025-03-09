#include<stdio.h>
#include<string.h>
#define TABLE_SIZE 10   // hash table

int hashFunction(char *key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash + (int)key[i]) % TABLE_SIZE;   // ensures that the computed hash value remains within the valid range of the hash table indices.
    }
    return hash;
}

int main() {
    char name1[] = "Amen";
    char name2[] = "Beyonce";

    printf("Hash index for %s: %d\n", name1, hashFunction(name1));
    printf("Hash index for %s: %d\n", name2, hashFunction(name2));

    return 0;
}