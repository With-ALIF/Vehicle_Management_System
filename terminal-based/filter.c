#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "vehicle.h"

void filterVehicle()
{
    int i, choice;
    int year, cc;
    char type[20];
    int found;

    if (count == 0)
    {
        printf("\nNo vehicles available.\n");
        return;
    }

    while (1)
    {
        printf("\nFilter Menu\n");
        printf("1. Below year AND greater engine capacity\n");
        printf("2. Below year AND less engine capacity\n");
        printf("3. After year AND less engine capacity\n");
        printf("4. Vehicle type AND greater engine capacity\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        found = 0;

        if (choice == 1)
        {
            printf("Enter year: ");
            scanf("%d", &year);
            printf("Enter engine capacity: ");
            scanf("%d", &cc);

            for (i = 0; i < count; i++)
            {
                if (vehicles[i].year < year &&
                    vehicles[i].engineCapacity > cc)
                {
                    found = 1;
                    printf("\n-------------------------------------\n");
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
        }
        else if (choice == 2)
        {
            printf("Enter year: ");
            scanf("%d", &year);
            printf("Enter engine capacity: ");
            scanf("%d", &cc);

            for (i = 0; i < count; i++)
            {
                if (vehicles[i].year < year &&
                    vehicles[i].engineCapacity < cc)
                {
                    found = 1;
                    printf("\n-------------------------------------\n");
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
        }
        else if (choice == 3)
        {
            printf("Enter year: ");
            scanf("%d", &year);
            printf("Enter engine capacity: ");
            scanf("%d", &cc);

            for (i = 0; i < count; i++)
            {
                if (vehicles[i].year > year &&
                    vehicles[i].engineCapacity < cc)
                {
                    found = 1;
                    printf("\n-------------------------------------\n");
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
        }
        else if (choice == 4)
        {
            printf("Enter vehicle type: ");
            scanf("%19s", type);
            printf("Enter engine capacity: ");
            scanf("%d", &cc);

            for (i = 0; i < count; i++)
            {
                if (strcmp(vehicles[i].type, type) == 0 &&
                    vehicles[i].engineCapacity > cc)
                {
                    found = 1;
                    printf("\n-------------------------------------\n");
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
        }
        else
        {
            printf("Invalid choice\n");
        }

        if (!found)
            printf("\nNo matching vehicles found.\n");
    }
}