/*
    Lab 1
    Revisiting C
    4.  Write a program to read name, roll number, and address of each student in your class using structure.
        Store the information in file so that you can recover the information later.
        While recovering the information from the file sort the information alphabetically according to the name.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Student
{
    char name[100];
    char roll_no[15];
    char address[50];
};

int main()
{
    int num_of_students;
    char *db_filename = "student-db2.bin";

    printf("Enter the number of students: ");
    scanf("%d", &num_of_students);

    struct Student students[num_of_students];

    // Read the data
    for (int i = 0; i < num_of_students; ++i)
    {
        printf("\nEnter the data for student %d:\n", i + 1);

        printf("Name: ");
        fflush(stdin);
        gets(students[i].name);

        printf("Roll number: ");
        fflush(stdin);
        gets(students[i].roll_no);

        printf("Address: ");
        fflush(stdin);
        gets(students[i].address);
    }

    FILE *fp;

    if ((fp = fopen(db_filename, "wb")) == NULL)
    {
        // Error opening file
        printf("An error occurred while creating the file...");
        return -1;
    }

    // Store the data
    for (int i = 0; i < num_of_students; ++i)
    {
        fwrite(&students[i], sizeof(struct Student), 1, fp);
    }

    fclose(fp);

    if ((fp = fopen(db_filename, "rb")) == NULL)
    {
        // Error opening file
        printf("An error occurred while reading the file...");
        return -1;
    }

    struct Student s[num_of_students];

    // Retrieve the data
    for (int i = 0; i < num_of_students; ++i)
    {
        fread(&s[i], sizeof(struct Student), 1, fp);
    }

    // Sort the students in alphabetical order of name
    for (int i = 0; i < num_of_students; ++i)
    {
        for (int j = i + 1; j < num_of_students; ++j)
        {
            if (strcmp(s[i].name, s[j].name) > 0)
            {
                struct Student temp;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // Print the data
    printf("\nStudent database in alphabetical order:");
    for (int i = 0; i < num_of_students; ++i)
    {
        printf("\nStudent %d:", i + 1);
        printf("\nName: %s", s[i].name);
        printf("\nRoll number: %s", s[i].roll_no);
        printf("\nAddress: %s\n", s[i].address);
    }

    fclose(fp);

    getch();
    return 0;
}
