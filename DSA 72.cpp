#include <stdio.h>
#include <string.h>

char findFirstRepeated(char *s) {
 
    int count[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char val = s[i];
        
      
        if (count[val] == 1) {
            return s[i];
        }
        
        count[val]++;
    }

    return '\0';
}

int main() {
    char s[1000];
    
    if (scanf("%s", s) == 1) {
        char result = findFirstRepeated(s);
        
        if (result != '\0') {
            printf("%c\n", result);
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}
