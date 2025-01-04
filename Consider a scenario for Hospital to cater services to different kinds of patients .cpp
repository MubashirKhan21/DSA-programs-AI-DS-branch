#include <iostream>
#include <cstdlib>

void insert();
void delet();
void display();

struct node
{
    int priority;
    int info;
    char name[10];
    struct node* next;
}* front = NULL;

int main()
{
    int choice;

    while (true)
    {
        std::cout << "\n\n--------------------------- HOSPITAL TOKEN MANAGEMENT SYSTEM-------------------------------------\n\n";
        std::cout << "1. ADMISSION BASED ON PRIORITY\n\n";
        std::cout << "2. REMOVE VISITED PATIENT\n\n";
        std::cout << "3. DISPLAY THE LIST ALONG WITH THEIR PRIORITY\n\n";
        std::cout << "4. EXIT.\n\n";
        std::cout << "ENTER YOUR CHOICE: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                std::cout << "INVALID CHOICE. TRY AGAIN.\n";
        }
    }
}

void insert()
{
    struct node* tmp;
    struct node* ptr;
    int token, ip;

    tmp = new struct node;

    std::cout << "\nENTER NAME: ";
    std::cin >> tmp->name;

    std::cout << "\nENTER THE TOKEN NUMBER: ";
    std::cin >> token;

    std::cout << "\n\nENTER THE PRIORITY\n1 for emergency\n2 for visiting\n3 for regular checkup\n4 for medicine\nENTER: ";
    std::cin >> ip;

    tmp->info = token;
    tmp->priority = ip;

    if (front == NULL || ip < front->priority)
    {
        tmp->next = front;
        front = tmp;
    }
    else
    {
        ptr = front;
        while (ptr->next != NULL && ptr->next->priority <= ip)
            ptr = ptr->next;
        tmp->next = ptr->next;
        ptr->next = tmp;
    }
}

void delet()
{
    struct node* tmp;
    if (front == NULL)
    {
        std::cout << "\n\nNO MORE PATIENTS\n";
    }
    else
    {
        tmp = front;
        std::cout << "\n\nDELETED TOKEN NUMBER " << tmp->info << "\n";
        front = front->next;
        delete tmp;
    }
}

void display()
{
    struct node* ptr;
    ptr = front;
    if (front == NULL)
    {
        std::cout << "\n\nLIST IS EMPTY, NO PATIENTS\n";
    }
    else
    {
        std::cout << "PRIORITY\tNAME\tTOKEN NUMBER\n\n";
        while (ptr != NULL)
        {
            std::cout << ptr->priority << "\t\t" << ptr->name << "\t\t" << ptr->info << "\n\n";
            ptr = ptr->next;
        }
    }
}
