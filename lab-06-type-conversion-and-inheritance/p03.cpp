/*
    Lab 6
    Understanding the Concept of Type Conversion and Inheritance
    3.  Create a class called Musicians to contain three methods string(), wind(), and perc().
        Each of these methods should initialize a string array to contain the following instruments
        -  veena, guitar, sitar, sarod and mandolin under string()
        -  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()
        -  tabla, mridangam, bangos, drums and tambour under perc()
        It should also display the contents of the arrays that are initialized.

        Create a derived class called TypeIns to contain a method called get() and show().
        The get() method must display a menu as follows
        Type of instruments to be displayed
        a.  String instruments
        b.  Wind instruments
        c.  Percussion instruments
        The show() method should display the relevant detail according to our choice.
        The base class variables must be accessible only to their derived classes.
*/

#include <iostream>
#include <cstring>

class Musicians
{
private:
    char _string_instruments[5][20];
    char _wind_instruments[5][20];
    char _perc_instruments[5][20];

public:
    void string()
    {
        strcpy(_string_instruments[0], "Veena");
        strcpy(_string_instruments[1], "Guitar");
        strcpy(_string_instruments[2], "Sitar");
        strcpy(_string_instruments[3], "Sarod");
        strcpy(_string_instruments[4], "Mandolin");

        std::cout << "String instruments:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << _string_instruments[i] << '\n';
        }
    }

    void wind()
    {
        strcpy(_wind_instruments[0], "Flute");
        strcpy(_wind_instruments[1], "Clarinet");
        strcpy(_wind_instruments[2], "Nadhaswaram");
        strcpy(_wind_instruments[3], "Piccolo");
        strcpy(_wind_instruments[4], "Saxophone");

        std::cout << "\nWind instruments:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << _wind_instruments[i] << '\n';
        }
    }

    void perc()
    {
        strcpy(_perc_instruments[0], "Tabla");
        strcpy(_perc_instruments[1], "Mridangam");
        strcpy(_perc_instruments[2], "Bangos");
        strcpy(_perc_instruments[3], "Drums");
        strcpy(_perc_instruments[4], "Tambour");

        std::cout << "\nPercussion instruments:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << _perc_instruments[i] << '\n';
        }
    }
};

class TypeIns : public Musicians
{
private:
public:
    char get()
    {
        char choice;
        std::cout << "\nType of instruments to be displayed\n";
        std::cout << "a. String instruments\n";
        std::cout << "b. Wind instruments\n";
        std::cout << "c. Percussion instruments\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        return choice;
    }

    char show()
    {
        char choice = get();
        switch (choice)
        {
        case 'a':
        case 'A':
            std::cout << '\n';
            string();
            break;
        case 'b':
        case 'B':
            wind();
            break;
        case 'c':
        case 'C':
            perc();
            break;
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    }
};

int main()
{
    Musicians m;

    m.string();
    m.wind();
    m.perc();

    TypeIns t;
    t.show();

    return 0;
}
