#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "vehicle.h"

void searchVehicle()
{
    int i, choice;
    char text[50];
    int value;
    int found;

    if (count == 0)
    {
        printf("\nNo vehicles available.\n");
        return;
    }

    while (1)
    {
        printf("\n=====================================\n");
        printf("          SEARCH VEHICLE\n");
        printf("=====================================\n");
        printf("1. Search by Vehicle ID\n");
        printf("2. Search by Vehicle Type\n");
        printf("3. Search by Model Name\n");
        printf("4. Search by Manufacturing Year\n");
        printf("5. Search by Engine Capacity\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            return;

        found = 0;

        if (choice >= 1 && choice <= 3)
        {
            printf("Enter search value: ");
            scanf(" %[^\n]", text);
        }
        else if (choice == 4 || choice == 5)
        {
            printf("Enter value: ");
            scanf("%d", &value);
        }

        printf("\n-------------------------------------\n");

        for (i = 0; i < count; i++)
        {
            int match = 0;

            if (choice == 1 && strcmp(vehicles[i].id, text) == 0)
                match = 1;
            else if (choice == 2 && strcmp(vehicles[i].type, text) == 0)
                match = 1;
            else if (choice == 3 && strcmp(vehicles[i].model, text) == 0)
                match = 1;
            else if (choice == 4 && vehicles[i].year == value)
                match = 1;
            else if (choice == 5 && vehicles[i].engineCapacity == value)
                match = 1;

            if (match)
            {
                found = 1;
                printf("Vehicle ID        : %s\n", vehicles[i].id);
                printf("Vehicle Type      : %s\n", vehicles[i].type);
                printf("Model Name        : %s\n", vehicles[i].model);
                printf("Brand             : %s\n", vehicles[i].brand);
                printf("Manufacture Year  : %d\n", vehicles[i].year);
                printf("Engine Capacity   : %d cc\n", vehicles[i].engineCapacity);
                printf("Color             : %s\n", vehicles[i].color);
                printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                printf("Seat Count        : %d\n", vehicles[i].seatCount);
                printf("-------------------------------------\n");
            }
        }

        if (!found)
            printf("No matching vehicle found.\n");
    }
}