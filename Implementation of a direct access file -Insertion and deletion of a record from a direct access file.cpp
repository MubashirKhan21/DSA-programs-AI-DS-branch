#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_RECORDS = 100;
const int RECORD_SIZE = 50;

struct Record
{
    int id;
    char name[20];
};

void insertRecord(Record records[], int& count)
{
    if (count >= MAX_RECORDS)
    {
        cout << "Cannot insert record. Maximum capacity reached.\n";
        return;
    }

    Record newRecord;

    cout << "Enter ID: ";
    cin >> newRecord.id;

    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(newRecord.name, sizeof(newRecord.name));

    int index = newRecord.id - 1;

    if (index < 0 || index >= MAX_RECORDS)
    {
        cout << "Invalid ID. Record not inserted.\n";
        return;
    }

    records[index] = newRecord;
    count++;

    cout << "Record inserted successfully.\n";
}

void deleteRecord(Record records[], int& count)
{
    int id;

    cout << "Enter the ID of the record to delete: ";
    cin >> id;

    int index = id - 1;

    if (index < 0 || index >= MAX_RECORDS)
    {
        cout << "Invalid ID. Record not found.\n";
        return;
    }

    if (records[index].id == 0)
    {
        cout << "Record not found.\n";
        return;
    }

    records[index].id = 0;
    records[index].name[0] = '\0';
    count--;

    cout << "Record deleted successfully.\n";
}

void displayRecords(const Record records[], int count)
{
    cout << "\nID\tName\n";

    for (int i = 0; i < MAX_RECORDS; i++)
    {
        if (records[i].id != 0)
        {
            cout << records[i].id << "\t" << records[i].name << endl;
        }
    }
}

int main()
{
    Record records[MAX_RECORDS] = { 0 };
    int count = 0;

    while (true)
    {
        cout << "\n--------------- Direct Access File Operations ---------------\n";
        cout << "1. Insert Record\n";
        cout << "2. Delete Record\n";
        cout << "3. Display Records\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertRecord(records, count);
                break;
            case 2:
                deleteRecord(records, count);
                break;
            case 3:
                displayRecords(records, count);
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
