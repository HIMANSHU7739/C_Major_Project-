#include <stdio.h>
#include <string.h>

// Read string
void readString(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t ln = strlen(buffer);
        if (ln > 0 && buffer[ln-1] == '\n') 
            buffer[ln-1] = '\0'; // Remove newline
    } else {
        buffer[0] = '\0'; // Handle error
    }
}

// Read integer with validation and error 
int readInt() {
    int x;
    // Loop until valid integer is entered
    while (scanf("%d", &x) != 1) {
        // Clear's invalid input from buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Please enter a valid integer: ");
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return x;
}

// Read float with validation and error recovery
float readFloat() {
    float f;
    // Loop until valid number is entered
    while (scanf("%f", &f) != 1) {
        // Clear invalid input from buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Please enter a valid number: ");
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return f;
}
