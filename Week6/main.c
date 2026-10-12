#include <stdio.h>
#include <string.h>

#define NUM_SALARIES 50
#define NUM_BUDGETS  10
#define NUM_REGS     20

int main()
{
    /* Part A: salaries */
    float salaries[NUM_SALARIES];
    float salaryTotal = 0;
    float salaryAverage;
    float highest;
    float lowest;
    float searchSalary;
    int found;

    /* Part B: budgets */
    float budgets[NUM_BUDGETS];
    float budgetTotal = 0;
    float budgetAverage;
    float temp;

    /* Part C: registrations */
    char registrations[NUM_REGS][20];
    char searchReg[20];

    int i;
    int j;

    printf("=====================================\n");
    printf("  MUNICIPAL INFORMATION MANAGEMENT\n");
    printf("=====================================\n");

    /* ---------- PART A: EMPLOYEE SALARIES ---------- */
    printf("\n--- PART A: EMPLOYEE SALARIES ---\n");

    for (i = 0; i < NUM_SALARIES; i++)
    {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("\nAll salaries:\n");
    for (i = 0; i < NUM_SALARIES; i++)
    {
        printf("%d. %.2f\n", i + 1, salaries[i]);
    }

    highest = salaries[0];
    lowest = salaries[0];

    for (i = 0; i < NUM_SALARIES; i++)
    {
        salaryTotal = salaryTotal + salaries[i];

        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
        if (salaries[i] < lowest)
        {
            lowest = salaries[i];
        }
    }

    salaryAverage = salaryTotal / NUM_SALARIES;

    printf("\nTotal salary:   %.2f\n", salaryTotal);
    printf("Average salary: %.2f\n", salaryAverage);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary:  %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);

    found = 0;
    for (i = 0; i < NUM_SALARIES; i++)
    {
        if (salaries[i] == searchSalary)
        {
            printf("Salary found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Salary not found.\n");
    }

    /* ---------- PART B: DEPARTMENT BUDGETS ---------- */
    printf("\n--- PART B: DEPARTMENT BUDGETS ---\n");

    for (i = 0; i < NUM_BUDGETS; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
        budgetTotal = budgetTotal + budgets[i];
    }

    printf("\nBudgets entered:\n");
    for (i = 0; i < NUM_BUDGETS; i++)
    {
        printf("%d. %.2f\n", i + 1, budgets[i]);
    }

    budgetAverage = budgetTotal / NUM_BUDGETS;
    printf("\nTotal budget:   %.2f\n", budgetTotal);
    printf("Average budget: %.2f\n", budgetAverage);

    /* Bubble sort: lowest to highest */
    for (i = 0; i < NUM_BUDGETS - 1; i++)
    {
        for (j = 0; j < NUM_BUDGETS - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets sorted (lowest to highest):\n");
    for (i = 0; i < NUM_BUDGETS; i++)
    {
        printf("%d. %.2f\n", i + 1, budgets[i]);
    }

    /* ---------- PART C: VEHICLE REGISTRATIONS ---------- */
    printf("\n--- PART C: VEHICLE REGISTRATIONS ---\n");

    for (i = 0; i < NUM_REGS; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nVehicle registrations:\n");
    for (i = 0; i < NUM_REGS; i++)
    {
        printf("%d. %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchReg);

    found = 0;
    for (i = 0; i < NUM_REGS; i++)
    {
        if (strcmp(registrations[i], searchReg) == 0)
        {
            printf("Registration found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Registration not found.\n");
    }

    return 0;
}