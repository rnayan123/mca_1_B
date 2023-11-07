#include <stdio.h>

// Function prototypes
void readAndDisplayString(char *str);
int calculateStringLength(const char *str);
void reverseString(char *str);
void copyString(char *dest, const char *src);
int countCharacter(const char *str, char ch);

int main()
{
    char inputString[100];
    char targetString[100];
    char searchChar;

    printf("Enter a string: ");
    readAndDisplayString(inputString);

    
    printf("Length of the string: %d\n", calculateStringLength(inputString));

    
    reverseString(inputString);
    printf("Reversed string: %s\n", inputString);

    copyString(targetString, inputString);
    printf("Copied string: %s\n", targetString);
    printf("Enter a character to search: ");
    scanf(" %c", &searchChar);

    int count = countCharacter(inputString, searchChar);
    printf("Character '%c' is present %d times in the string.\n", searchChar, count);

    return 0;
}

void readAndDisplayString(char *str)
{
    scanf("%s", str);
    printf("Entered string: %s\n", str);
}

int calculateStringLength(const char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}

void reverseString(char *str)
{
    char *start = str;
    char *end = str + calculateStringLength(str) - 1;

    while (start < end)
    {
    
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void copyString(char *dest, const char *src)
{
    while ((*dest++ = *src++) != '\0')
        ;
}

int countCharacter(const char *str, char ch)
{
    int count = 0;
    while (*str != '\0')
    {
        if (*str == ch)
        {
            count++;
        }
        str++;
    }
    return count;
}
