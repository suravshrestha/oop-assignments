/*
    Lab 1
    Revisiting C
    2.  Write a program to find the position of character 'c' in the sequence "idea without execution is worthless"
        using pointer and string
*/

#include <stdio.h>
#include <conio.h>

int get_index(char *str, char search_char)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) == search_char)
        {
            return i;
        }

        ++i;
    }

    return -1;
}

int main()
{
    char *str = "idea without execution is worthless";

    printf("Index of the character 'c' in the string is %d", get_index(str, 'c'));

    getch();
    return 0;
}
