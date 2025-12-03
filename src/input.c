#include <stdio.h>
#include <string.h>

void readString(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t ln = strlen(buffer);
        if (ln > 0 && buffer[ln-1] == '\n') buffer[ln-1] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

int readInt() {
    int x;
    while (scanf("%d", &x) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Please enter a valid integer: ");
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return x;
}

float readFloat() {
    float f;
    while (scanf("%f", &f) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Please enter a valid number: ");
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return f;
}
