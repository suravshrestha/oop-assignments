/*
    Lab 8
    Understanding the Concept of Console and File Input/Output
    4.  Write a program that stores the information about students (name, student id, department, and address)
        in a structure and then transfers the information to a file in your directory. Finally, retrieve the
        information from your file and print it in the proper format on your output screen.
*/

#include <iostream>
#include <fstream>

struct Student
{
    std::string name, id, department, address;
};

int main()
{
    std::string filename = "db.bin";
    std::fstream iofile(filename, std::ios::in | std::ios::out | std::ios::app | std::ios::binary);

    if (!iofile)
    {
        std::cerr << filename << " could not be opened!\n";
        return 1;
    }

    int num_of_students;
    std::cout << "Enter the number of students: ";
    std::cin >> num_of_students;
    std::cin.ignore();

    Student students[num_of_students];

    for (int i = 0; i < num_of_students; i++)
    {
        std::cout << "\nEnter the info for student " << i + 1 << ":\n";

        std::cout << "Name: ";
        getline(std::cin, students[i].name);

        std::cout << "ID: ";
        getline(std::cin, students[i].id);

        std::cout << "Department: ";
        getline(std::cin, students[i].department);

        std::cout << "Address: ";
        getline(std::cin, students[i].address);

        iofile.write(reinterpret_cast<char *>(&students[i]), sizeof(students[i]));
    }

    std::cout << filename << " updated\n";

    // Since we have reached (and attempted to read past) the end of the file,
    // the eof and fail flags will be set. We need to clear them first using .clear()
    iofile.clear();
    iofile.seekg(0);

    std::cout << "\n*** Student Database ***";

    Student s;

    // Read file line by line
    while (!iofile.eof())
    {
        iofile.read(reinterpret_cast<char *>(&s), sizeof(s));

        std::cout << "\n\nName: " << s.name;
        std::cout << "\nID: " << s.id;
        std::cout << "\nDepartment: " << s.department;
        std::cout << "\nAddress: " << s.address;
    }

    iofile.close();

    return 0;
}
