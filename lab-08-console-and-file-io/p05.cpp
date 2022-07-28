/*
    Lab 8
    Understanding the Concept of Console and File Input/Output
    5.  Write a program for transaction processing that write and read object randomly to and from
        a random access file so that user can add, update, delete and display the account information
        (account-number, last-name, first-name, total-balance).
*/

#include <iostream>
#include <fstream>

class Transaction
{
private:
    std::string _first_name, _last_name, _account_number;
    float _total_balance;

public:
    void readData()
    {
        std::cout << "First name: ";
        std::cin >> _first_name;

        std::cout << "Last name: ";
        std::cin >> _last_name;

        std::cout << "Account number: ";
        std::cin >> _account_number;

        std::cout << "Total balance: ";
        std::cin >> _total_balance;
    }

    void showData()
    {
        std::cout << "\n\nFirst name: " << _first_name;
        std::cout << "\nLast name: " << _last_name;
        std::cout << "\nAccount number: " << _account_number;
        std::cout << "\nTotal balance: " << _total_balance;
    }
};

bool writeToFile(std::string filename)
{
    std::ofstream outfile(filename, std::ios::app | std::ios::binary);
    if (!outfile)
    {
        std::cerr << filename << " could not be opened!\n";
        return false;
    }

    Transaction t;
    t.readData();

    outfile.write(reinterpret_cast<char *>(&t), sizeof(t));
    outfile.close();

    return true;
}

bool readFromFile(std::string filename)
{
    std::ifstream infile(filename, std::ios::in | std::ios::binary);

    if (!infile)
    {
        std::cerr << filename << " could not be opened!\n";
        return false;
    }

    Transaction t;
    while (!infile.eof())
    {
        infile.read(reinterpret_cast<char *>(&t), sizeof(t));
        t.showData();
    }

    infile.close();

    return true;
}

bool deleteFromFile(std::string filename)
{
    std::ofstream outfile(filename, std::ios::out | std::ios::binary);

    if (!outfile)
    {
        std::cerr << filename << " could not be opened!\n";
        return false;
    }

    int n;
    std::cout << "Enter index of transaction to delete: ";
    std::cin >> n;

    outfile.seekp((n - 1) * sizeof(Transaction));

    int transaction_size = sizeof(Transaction);
    while (transaction_size--)
    {
        outfile << ' ';
    }

    outfile.close();

    return true;
}

bool updateFile(std::string filename)
{
    std::ofstream outfile(filename, std::ios::out | std::ios::binary);

    if (!outfile)
    {
        std::cerr << filename << " could not be opened!\n";
        return false;
    }

    int n;
    std::cout << "Enter index of transaction to update: ";
    std::cin >> n;

    outfile.seekp((n - 1) * sizeof(Transaction));

    Transaction t;
    t.readData();

    outfile.write(reinterpret_cast<char *>(&t), sizeof(t));
    outfile.close();

    return true;
}

int main()
{
    int choice;
    std::string filename = "transactions.dat";

    std::cout << "*** Transaction processing system ***\n";
    std::cout << "Choose an option:\n";
    std::cout << "1 --> Add transaction\n";
    std::cout << "2 --> Display all transactions\n";
    std::cout << "3 --> Update transaction\n";
    std::cout << "4 --> Delete transaction\n";
    std::cout << "5 --> Exit\n";

    while (true)
    {
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            if (!writeToFile(filename))
            {
                std::cout << "Failed to write to file\n";
                return 1;
            }

            break;
        case 2:
            if (!readFromFile(filename))
            {
                std::cout << "Failed to read from file\n";
                return 1;
            }

            break;

        case 3:
            if (!updateFile(filename))
            {
                std::cout << "Failed to update file\n";
                return 1;
            }

            break;
        case 4:
            if (!deleteFromFile(filename))
            {
                std::cout << "Failed to delete from file\n";
                return 1;
            }

            break;

        case 5:
            return 0;

        default:
            std::cout << "Invalid choice!\n";
            break;
        }
    }

    return 0;
}
