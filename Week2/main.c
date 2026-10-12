/*
 * PAP521S - Programming In Practice
 * Week 1 Lab: Municipal Financial Management System
 *
 * Displays the system title and a welcome message, captures basic
 * municipality details from the user and prints a formatted report.
 */

#include <stdio.h>

const double VAT_RATE = 0.15;
const int MAX_DEPARTMENTS = 50;

int main()
{
    char municipality[50];
    char mayor[50];
    int population;

        double revenue = 0.0;
    double expenses = 0.0;
    double balance = 0.0;
    int departments = 0;
    double payroll = 0.0;
    double procurement = 0.0;
    double assets = 0.0;
    char budgetCategory = 'A';

    /* 1 & 2: Title and welcome message */
    printf("=====================================\n");
    printf("  Municipal Financial Management System\n");
    printf("=====================================\n");
    printf("Welcome to Windhoek Municipality\n\n");

    /* 3: Capture input
       " %49[^\n]" reads a full line (including spaces) up to 49 characters.
       The leading space skips any leftover newline from the previous input. */
    printf("Enter Municipality Name: ");
    scanf(" %49[^\n]", municipality);

    printf("Enter Mayor's Name: ");
    scanf(" %49[^\n]", mayor);

    printf("Enter Population: ");
    scanf("%d", &population);

    /* 4: Formatted report */
    printf("\n---------------------------------\n");
    printf("        MUNICIPALITY REPORT\n");
    printf("---------------------------------\n");
    printf("Municipality : %s\n", municipality);
    printf("Mayor        : %s\n", mayor);
    printf("Population   : %d\n", population);
    printf("---------------------------------\n");

        printf("\nMUNICIPAL BUDGET CALCULATOR\n");
    printf("---------------------------\n");

    printf("Enter Total Revenue: ");
    scanf("%lf", &revenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &expenses);

    balance = revenue - expenses;

    printf("\nRevenue  : %.2f\n", revenue);
    printf("Expenses : %.2f\n", expenses);
    printf("Balance  : %.2f\n", balance);

    if (balance > 0) {
        printf("Result   : Surplus of %.2f\n", balance);
    }
    else if (balance < 0) {
        printf("Result   : Deficit of %.2f\n", -balance);
    }
    else {
        printf("Result   : The budget is balanced.\n");
    }

    printf("\nEXTENSION: MUNICIPAL FINANCIAL SUMMARY\n");
    printf("--------------------------------------\n");

    printf("Enter Number of Departments (max %d): ", MAX_DEPARTMENTS);
    scanf("%d", &departments);

    printf("Enter Payroll: ");
    scanf("%lf", &payroll);

    printf("Enter Procurement: ");
    scanf("%lf", &procurement);

    printf("Enter Assets Value: ");
    scanf("%lf", &assets);

    printf("Enter Budget Category (A/B/C): ");
    scanf(" %c", &budgetCategory);

    printf("\n=====================================\n");
    printf("   MUNICIPAL FINANCIAL SUMMARY\n");
    printf("=====================================\n");
    printf("Municipality  : %s\n", municipality);
    printf("Mayor         : %s\n", mayor);
    printf("Population    : %d\n", population);
    printf("Departments   : %d\n", departments);
    printf("Category      : %c\n", budgetCategory);
    printf("-------------------------------------\n");
    printf("Revenue       : %.2f\n", revenue);
    printf("Expenses      : %.2f\n", expenses);
    printf("Balance       : %.2f\n", balance);
    printf("Payroll       : %.2f\n", payroll);
    printf("Procurement   : %.2f\n", procurement);
    printf("Assets        : %.2f\n", assets);
    printf("VAT (%.0f%%)     : %.2f\n", VAT_RATE * 100, revenue * VAT_RATE);
    printf("=====================================\n");
    return 0;
}