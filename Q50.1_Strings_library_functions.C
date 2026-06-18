
// String library functions in C
// <string.h> - String manipulation functions

1) strlen() - Counts no of char excluding null terminator ('\0');

2) strcpy() - Copies a string to another string.

    #Syntax: 
    char strcpy(destString, srcString);

    Example:
    char oldStr[] = "oldStr";
    char newStr[] = "newStr";
    strcpy(newStr, oldStr);
    printf("New string: %s\n", newStr);
    //Or we can use puts(newStr);

3) strcat() - Concatenates first string with second string, Joining 2 strings wihtout any space between them.

    #Syntax: 
    strcat(destString, srcString);

    Example:
    char str1[] = "Hello";
    char str2[] = "World";
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    //Or we can use puts(str1);

4) strcmp() - Compares two strings and returns an integer value based on the comparison.

    #Syntax: 
    strcmp(str1, str2);

    0 -> Both strings are equal.
    +ve value -> First string is greater than the second string.
    -ve value -> First string is less than the second string.

    This function returns on integer value.
    Banana                      Apple
    |                             |
    66                            65         (ASCII values)

    Banana is greater than Apple in terms of ASCII values.
    66-65 => +1, positive value returned.

    Example:
    char str1[] = "Banana";
    char str2[] = "Apple";
    int result = strcmp(str1, str2);
    printf("Result: %d\n", result);

    Output: 1












