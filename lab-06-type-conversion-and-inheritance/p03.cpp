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

class Musicians
{
public:
    void string()
    {
        std::string _string_instruments[5] = {"Veena", "Guitar", "Sitar", "Sarod", "Mandolin"};

        std::cout << "String instruments:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << _string_instruments[i] << '\n';
        }
    }

    void wind()
    {
        std::string _wind_instruments[5] = {"Flute", "Clarinet", "Nadhaswaram", "Piccolo", "Saxophone"};

        std::cout << "\nWind instruments:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << _wind_instruments[i] << '\n';
        }
    }

    void perc()
    {
        std::string _perc_instruments[5] = {"Tabla", "Mridangam", "Bangos", "Drums", "Tambour"};

        std::cout << "\nPercussion instruments:\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << _perc_instruments[i] << '\n';
        }
    }
};

class TypeIns : public Musicians
{
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

    void show()
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
