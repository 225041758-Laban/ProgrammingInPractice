#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5

int main()
{
    char names[MAX_SUPPLIERS][100];
    char emails[MAX_SUPPLIERS][100];
    char phones[MAX_SUPPLIERS][30];
    char towns[MAX_SUPPLIERS][50];

    char searchName[100];
    char backup[100];
    char description[300];
    char input[20];

    int count = 0;
    int choice = 0;
    int found;
    int i;

    do
    {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1)
        {
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                if (count >= MAX_SUPPLIERS)
                {
                    printf("Supplier list is full (%d suppliers).\n", MAX_SUPPLIERS);
                    break;
                }

                printf("Enter supplier name: ");
                fgets(names[count], sizeof(names[count]), stdin);
                names[count][strcspn(names[count], "\n")] = '\0';

                printf("Enter email: ");
                fgets(emails[count], sizeof(emails[count]), stdin);
                emails[count][strcspn(emails[count], "\n")] = '\0';

                printf("Enter phone: ");
                fgets(phones[count], sizeof(phones[count]), stdin);
                phones[count][strcspn(phones[count], "\n")] = '\0';

                printf("Enter town: ");
                fgets(towns[count], sizeof(towns[count]), stdin);
                towns[count][strcspn(towns[count], "\n")] = '\0';

                count++;
                printf("Supplier added.\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No suppliers captured yet.\n");
                    break;
                }
                for (i = 0; i < count; i++)
                {
                    printf("\n--- SUPPLIER %d ---\n", i + 1);
                    printf("Name : %s\n", names[i]);
                    printf("Email: %s\n", emails[i]);
                    printf("Phone: %s\n", phones[i]);
                    printf("Town : %s\n", towns[i]);
                }
                break;

            case 3:
                printf("Enter supplier name to search: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                found = 0;
                for (i = 0; i < count; i++)
                {
                    if (strcmp(names[i], searchName) == 0)
                    {
                        found = 1;
                        printf("Supplier found.\n");
                        printf("Email: %s\n", emails[i]);
                        printf("Phone: %s\n", phones[i]);
                        printf("Town : %s\n", towns[i]);

                        /* strcpy: make a backup copy of the name */
                        strcpy(backup, names[i]);
                        printf("Original: %s\n", names[i]);
                        printf("Backup  : %s\n", backup);

                        /* strcpy + strcat: build a sentence */
                        strcpy(description, names[i]);
                        strcat(description, " operates in ");
                        strcat(description, towns[i]);
                        strcat(description, ".");
                        printf("%s\n", description);
                        break;
                    }
                }
                if (!found)
                {
                    printf("Supplier not found.\n");
                }
                break;

            case 4:
                if (count == 0)
                {
                    printf("No suppliers captured yet.\n");
                    break;
                }
                for (i = 0; i < count; i++)
                {
                    printf("Supplier %d name length: %zu\n", i + 1, strlen(names[i]));
                    printf("Supplier %d email length: %zu\n", i + 1, strlen(emails[i]));
                    printf("Supplier %d town length: %zu\n", i + 1, strlen(towns[i]));
                }
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}