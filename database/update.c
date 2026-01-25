#include <stdio.h>
#include <string.h>
#include "vehicle.h"

void updateVehicle()
{
    int i, mainChoice, choice;
    char key[20];
    int found = 0;

    if (count == 0)
    {
        printf("\nNo vehicles available.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("           UPDATE VEHICLE INFO\n");
    printf("=====================================\n");
    printf("1. Update by Vehicle ID\n");
    printf("2. Partial Update (by condition)\n");
    printf("0. Cancel\n");
    printf("Enter your choice: ");
    scanf("%d", &mainChoice);

    if (mainChoice == 0)
        return;

    if (mainChoice == 1)
    {
        printf("\nEnter Vehicle ID to update : ");
        scanf("%s", key);

        for (i = 0; i < count; i++)
        {
            if (strcmp(vehicles[i].id, key) == 0)
            {
                printf("\n------------------------------------\n");
                printf("       Current Vehicle Details\n");
                printf("------------------------------------\n");
                printf("Vehicle ID        : %s\n", vehicles[i].id);
                printf("Vehicle Type      : %s\n", vehicles[i].type);
                printf("Model Name        : %s\n", vehicles[i].model);
                printf("Brand             : %s\n", vehicles[i].brand);
                printf("Manufacture Year  : %d\n", vehicles[i].year);
                printf("Engine Capacity   : %d cc\n", vehicles[i].engineCapacity);
                printf("Color             : %s\n", vehicles[i].color);
                printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                printf("Seat Count        : %d\n", vehicles[i].seatCount);
                printf("------------------------------------\n");

                printf("\nWhich information do you want to update?\n");
                printf("1. Vehicle Type\n");
                printf("2. Model Name\n");
                printf("3. Brand\n");
                printf("4. Manufacture Year\n");
                printf("5. Engine Capacity\n");
                printf("6. Color\n");
                printf("7. Fuel Type\n");
                printf("8. Seat Count\n");
                printf("9. Update All Fields\n");
                printf("0. Cancel\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 0)
                    return;

                switch (choice)
                {
                case 1:
                    printf("Enter New Vehicle Type: ");
                    scanf(" %[^\n]", vehicles[i].type);
                    break;

                case 2:
                    printf("Enter New Model Name: ");
                    scanf(" %[^\n]", vehicles[i].model);
                    break;

                case 3:
                    printf("Enter New Brand: ");
                    scanf(" %[^\n]", vehicles[i].brand);
                    break;

                case 4:
                    printf("Enter New Manufacture Year: ");
                    scanf("%d", &vehicles[i].year);
                    break;

                case 5:
                    printf("Enter New Engine Capacity: ");
                    scanf("%d", &vehicles[i].engineCapacity);
                    break;

                case 6:
                    printf("Enter New Color: ");
                    scanf(" %[^\n]", vehicles[i].color);
                    break;

                case 7:
                    printf("Enter New Fuel Type: ");
                    scanf(" %[^\n]", vehicles[i].fuelType);
                    break;

                case 8:
                    printf("Enter New Seat Count: ");
                    scanf("%d", &vehicles[i].seatCount);
                    break;

                case 9:
                    printf("Enter New Vehicle Type      : ");
                    scanf(" %[^\n]", vehicles[i].type);

                    printf("Enter New Model Name        : ");
                    scanf(" %[^\n]", vehicles[i].model);

                    printf("Enter New Brand             : ");
                    scanf(" %[^\n]", vehicles[i].brand);

                    printf("Enter New Manufacture Year  : ");
                    scanf("%d", &vehicles[i].year);

                    printf("Enter New Engine Capacity   : ");
                    scanf("%d", &vehicles[i].engineCapacity);

                    printf("Enter New Color             : ");
                    scanf(" %[^\n]", vehicles[i].color);

                    printf("Enter New Fuel Type         : ");
                    scanf(" %[^\n]", vehicles[i].fuelType);

                    printf("Enter New Seat Count        : ");
                    scanf("%d", &vehicles[i].seatCount);
                    break;

                default:
                    printf("\nInvalid choice\n");
                    return;
                }

                printf("\n------------------------------------\n");
                printf(" Vehicle Updated Successfully!\n");
                printf("------------------------------------\n");
                return;
            }
        }

        printf("\nVehicle not found!\n");
    }

    else if (mainChoice == 2)
    {
        int cond, upd, cc;
        char brand[30], type[20];

        printf("\n------------------------------------\n");
        printf("        PARTIAL UPDATE MODE\n");
        printf("------------------------------------\n");
        printf("Match vehicles by:\n");
        printf("1. Brand Name\n");
        printf("2. Vehicle Type\n");
        printf("3. Engine Capacity greater than\n");
        printf("0. Cancel\n");
        printf("Enter choice: ");
        scanf("%d", &cond);

        if (cond == 0)
            return;

        if (cond == 1)
        {
            printf("Enter Brand Name: ");
            scanf(" %[^\n]", brand);
        }
        else if (cond == 2)
        {
            printf("Enter Vehicle Type: ");
            scanf(" %[^\n]", type);
        }
        else if (cond == 3)
        {
            printf("Enter Engine Capacity: ");
            scanf("%d", &cc);
        }

        printf("\nUpdate which field update?\n");
        printf("1. Brand Name\n");
        printf("2. Vehicle Type\n");
        printf("3. Engine Capacity\n");
        printf("0. Cancel\n");
        printf("Enter choice: ");
        scanf("%d", &upd);

        if (upd == 0)
            return;

        for (i = 0; i < count; i++)
        {
            int match = 0;

            if (cond == 1 && strcmp(vehicles[i].brand, brand) == 0)
                match = 1;
            if (cond == 2 && strcmp(vehicles[i].type, type) == 0)
                match = 1;
            if (cond == 3 && vehicles[i].engineCapacity > cc)
                match = 1;

            if (match)
            {
                if (upd == 1){
                    printf("Enter New Brand Name: ");
                    scanf(" %[^\n]", vehicles[i].brand);
                }

                else if (upd == 2) {
                    printf("Enter New Vehicle Type: ");
                    scanf(" %[^\n]", vehicles[i].type);
                }

                else if (upd == 3) {
                    printf("Enter New Engine Capacity: ");
                    scanf("%d", &vehicles[i].engineCapacity);
                }
                found = 1;
            }
        }

        if (found)
        {
            printf("\n------------------------------------\n");
            printf(" Vehicle Updated Successfully!\n");
            printf("------------------------------------\n");
        }

        else
            printf("\nNo matching vehicles found.\n");
    }
}