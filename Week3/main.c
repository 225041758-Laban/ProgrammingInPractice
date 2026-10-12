#include <stdio.h>

int main()
{
    float basicSalary;
    float housing;
    float transport;
    float tax;
    float grossSalary;
    float netSalary;

    printf("=====================================\n");
    printf("      EMPLOYEE SALARY CALCULATOR\n");
    printf("=====================================\n\n");

    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    /* Arithmetic and assignment operators */
    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    printf("\nGross Salary: %.2f\n", grossSalary);
    printf("Net Salary: %.2f\n", netSalary);

    /* Extension: relational operator with if...else */
    if (netSalary >= 20000)
    {
        printf("Income Category: High Income\n");
    }
    else
    {
        printf("Income Category: Standard Income\n");
    }

    return 0;
}