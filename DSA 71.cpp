#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    if (scanf("%d %d", &m, &q) != 2) return 0;

    int *hashTable = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    char command[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", command, &key);

        if (strcmp(command, "INSERT") == 0) {
            int hash = key % m;
            int inserted = 0;

            for (int j = 0; j < m; j++) {
                int index = (hash + (j * j)) % m;
                if (hashTable[index] == EMPTY) {
                    hashTable[index] = key;
                    inserted = 1;
                    break;
                }
            }
        } 
        else if (strcmp(command, "SEARCH") == 0) {
            int hash = key % m;
            int found = 0;

            for (int j = 0; j < m; j++) {
                int index = (hash + (j * j)) % m;
                if (hashTable[index] == key) {
                    found = 1;
                    break;
                } else if (hashTable[index] == EMPTY) {
                    break;
                }
            }

            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    free(hashTable);
    return 0;
}
