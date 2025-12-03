// Header for safe input handling utilities

#ifndef INPUT_H
#define INPUT_H

// Read string with spaces, buffer overflow protection
void readString(char *buffer, int size);

// Read integer with validation, handles invalid input
int readInt();

// Read float with validation, handles invalid input
float readFloat();

#endif
