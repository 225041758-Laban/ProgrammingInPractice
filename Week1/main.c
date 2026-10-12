/*
 * PAP521S - Programming In Practice
 * Week 1 Lab: Municipal Financial Management System
 *
 * Displays the system title and a welcome message, captures basic
 * municipality details from the user and prints a formatted report.
 */

#include <stdio.h>

int main()
{
    char municipality[50];
    char mayor[50];
    int population;

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

    return 0;
}