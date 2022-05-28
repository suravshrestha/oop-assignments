/*
    Lab 1
    Revisiting C
    3.  Write a program to store and retrieve the name of the students and obtained marks in C programming in 1st semester
        using structure
*/

#include <stdio.h>
#include <conio.h>

struct Student
{
    char name[100];
    int marks; // Marks in C programming
};

int main()
{
    char *db_filename = "student-db.bin";

    int num_of_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_of_students);

    struct Student students[num_of_students];

    for (int i = 0; i < num_of_students; ++i)
    {
        printf("\nEnter the data for student %d:\n", i + 1);

        printf("Name: ");
        getchar();
        gets(students[i].name);

        printf("Marks: ");
        scanf("%d", &students[i].marks);
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

    struct Student s;

    // Retrieve and print the data
    printf("\nStudent database:");
    for (int i = 0; i < num_of_students; ++i)
    {
        fread(&s, sizeof(struct Student), 1, fp);

        printf("\nStudent %d:", i + 1);
        printf("\nName: %s", s.name);
        printf("\nMarks in C programming: %d\n", s.marks);
    }

    fclose(fp);

    getch();
    return 0;
}
