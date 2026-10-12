#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS  5
#define EMPLOYEE_COUNT 5

/* Supplier data shared by the supplier functions */
char supplierNames[MAX_SUPPLIERS][100];
char supplierEmails[MAX_SUPPLIERS][100];
char supplierPhones[MAX_SUPPLIERS][30];
char supplierTowns[MAX_SUPPLIERS][50];
int supplierCount = 0;

/* Function prototypes */
void displayWelcome();
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

void readLine(char text[], int size);
int readInt();
float readFloat();

void salaryOption();
void vatOption();
void budgetOption();
void employeeOption(int ids[], int size);
void supplierMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();

int main()
{
    int employeeIDs[EMPLOYEE_COUNT] = {101, 102, 103, 104, 105};
    int choice;

    displayWelcome();

    do
    {
        displayMenu();
        choice = readInt();

        switch (choice)
        {
            case 1:
                salaryOption();
                break;
            case 2:
                vatOption();
                break;
            case 3:
                budgetOption();
                break;
            case 4:
                employeeOption(employeeIDs, EMPLOYEE_COUNT);
                break;
            case 5:
                supplierMenu();
                break;
            case 6:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

/* ---------- Display functions ---------- */

void displayWelcome()
{
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu()
{
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

/* ---------- Calculation functions ---------- */

float calculateVAT(float amount)
{
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}

/* ---------- Input helpers ---------- */

void readLine(char text[], int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

int readInt()
{
    char input[50];
    int value;

    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &value) != 1)
    {
        return 0;
    }
    return value;
}

float readFloat()
{
    char input[50];
    float value;

    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%f", &value) != 1)
    {
        return 0;
    }
    return value;
}

/* ---------- Menu option functions ---------- */

void salaryOption()
{
    float basic;
    float housing;
    float transport;

    printf("Basic salary: ");
    basic = readFloat();
    printf("Housing allowance: ");
    housing = readFloat();
    printf("Transport allowance: ");
    transport = readFloat();

    printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
}

void vatOption()
{
    float amount;

    printf("Enter amount: ");
    amount = readFloat();

    printf("VAT: %.2f\n", calculateVAT(amount));
}

void budgetOption()
{
    float revenue;
    float expenses;
    float balance;

    printf("Enter revenue: ");
    revenue = readFloat();
    printf("Enter expenses: ");
    expenses = readFloat();

    balance = calculateBudget(revenue, expenses);
    printf("Budget balance: %.2f\n", balance);

    if (balance > 0)
    {
        printf("SURPLUS\n");
    }
    else if (balance < 0)
    {
        printf("DEFICIT\n");
    }
    else
    {
        printf("BALANCED\n");
    }
}

void employeeOption(int ids[], int size)
{
    int id;
    int position;

    printf("Enter employee ID: ");
    id = readInt();

    position = searchEmployee(id, ids, size);
    if (position == -1)
    {
        printf("Employee not found.\n");
    }
    else
    {
        printf("Employee found at position %d.\n", position);
    }
}

/* ---------- Supplier functions ---------- */

void supplierMenu()
{
    int choice;

    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to main menu\n");
        printf("Enter choice: ");
        choice = readInt();

        switch (choice)
        {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Enter supplier name: ");
    readLine(supplierNames[supplierCount], sizeof(supplierNames[supplierCount]));
    printf("Enter email: ");
    readLine(supplierEmails[supplierCount], sizeof(supplierEmails[supplierCount]));
    printf("Enter phone: ");
    readLine(supplierPhones[supplierCount], sizeof(supplierPhones[supplierCount]));
    printf("Enter town: ");
    readLine(supplierTowns[supplierCount], sizeof(supplierTowns[supplierCount]));

    supplierCount++;
    printf("Supplier added.\n");
}

void displaySupplier()
{
    int i;

    if (supplierCount == 0)
    {
        printf("No suppliers captured yet.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        printf("\n--- SUPPLIER %d ---\n", i + 1);
        printf("Name : %s\n", supplierNames[i]);
        printf("Email: %s\n", supplierEmails[i]);
        printf("Phone: %s\n", supplierPhones[i]);
        printf("Town : %s\n", supplierTowns[i]);
    }
}

void searchSupplier()
{
    char searchName[100];
    int i;

    printf("Enter supplier name to search: ");
    readLine(searchName, sizeof(searchName));

    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierNames[i], searchName) == 0)
        {
            printf("Supplier found.\n");
            printf("Email: %s\n", supplierEmails[i]);
            printf("Phone: %s\n", supplierPhones[i]);
            printf("Town : %s\n", supplierTowns[i]);
            return;
        }
    }
    printf("Supplier not found.\n");
}