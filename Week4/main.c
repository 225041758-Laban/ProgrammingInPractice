#include <stdio.h>

int main()
{
    char supplierName[50];
    char preferredName[50] = "None";
    float price;
    float budget;
    float lowestPrice = 0;
    int registered;
    int documentsComplete;
    int foundQualified = 0;
    int i;

    printf("=====================================\n");
    printf("          TENDER EVALUATION\n");
    printf("=====================================\n\n");

    printf("Enter available budget: ");
    scanf("%f", &budget);

    for (i = 1; i <= 4; i++)
    {
        printf("\n--- Supplier %d ---\n", i);

        printf("Enter supplier name: ");
        scanf("%49s", supplierName);

        printf("Enter tender price: ");
        scanf("%f", &price);

        printf("Is supplier registered? (1=Yes, 0=No): ");
        scanf("%d", &registered);

        printf("Are all documents complete? (1=Yes, 0=No): ");
        scanf("%d", &documentsComplete);

        /* Relational and logical operators combined */
        if (registered == 1 && documentsComplete == 1 && price <= budget)
        {
            printf("Supplier: %s\n", supplierName);
            printf("Status: Qualified\n");

            /* Track the lowest qualified price */
            if (foundQualified == 0 || price < lowestPrice)
            {
                lowestPrice = price;
                foundQualified = 1;
                snprintf(preferredName, sizeof(preferredName), "%s", supplierName);
            }
        }
        else
        {
            printf("Supplier: %s\n", supplierName);
            printf("Status: Disqualified\n");
        }
    }

    printf("\n=====================================\n");
    if (foundQualified == 1)
    {
        printf("Preferred Supplier: %s (%.2f)\n", preferredName, lowestPrice);
    }
    else
    {
        printf("No qualified supplier found.\n");
    }
    printf("=====================================\n");

    return 0;
}