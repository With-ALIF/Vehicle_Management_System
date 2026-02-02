#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "vehicle.h"

void filterVehicle()
{
    int i, choice;
    int year, cc;
    char type[30];
    int found;

    if (count == 0)
    {
        printf("\nNo vehicles available.\n");
        return;
    }

    while (1)
    {
        printf("\n=====================================\n");
        printf("            FILTER VEHICLE\n");
        printf("=====================================\n");
        printf("1. Below year AND greater engine capacity\n");
        printf("2. Below year AND less engine capacity\n");
        printf("3. After year AND less engine capacity\n");
        printf("4. Vehicle type AND greater engine capacity\n");
        printf("5. Electric Vehicle by battery capacity\n");
        printf("0. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            return;

        found = 0;

        if (choice >= 1 && choice <= 3)
        {
            printf("Enter year: ");
            scanf("%d", &year);
            printf("Enter engine capacity: ");
            scanf("%d", &cc);
        }
        else if (choice == 4)
        {
            printf("Enter vehicle type: ");
            scanf(" %[^\n]", type);
            printf("Enter engine capacity: ");
            scanf("%d", &cc);
        }
        else if (choice == 5)
        {
            printf("Enter minimum battery capacity (kWh): ");
            scanf("%d", &cc);
        }
        else
        {
            printf("\nInvalid choice\n");
            continue;
        }

        for (i = 0; i < count; i++)
        {
            int match = 0;

            if (choice == 5)
            {
                if (strcmp(vehicles[i].type, "Electric Vehicle") == 0 &&
                    vehicles[i].batteryCapacity >= cc)
                    match = 1;
            }
            else if (strcmp(vehicles[i].type, "Electric Vehicle") == 0)
            {
                if (choice == 4 && strcmp(vehicles[i].type, type) == 0)
                    match = 1;
            }
            else
            {
                if (choice == 1 &&
                    vehicles[i].year < year &&
                    vehicles[i].engineCapacity > cc)
                    match = 1;

                else if (choice == 2 &&
                         vehicles[i].year < year &&
                         vehicles[i].engineCapacity < cc)
                    match = 1;

                else if (choice == 3 &&
                         vehicles[i].year > year &&
                         vehicles[i].engineCapacity < cc)
                    match = 1;

                else if (choice == 4 &&
                         strcmp(vehicles[i].type, type) == 0 &&
                         vehicles[i].engineCapacity > cc)
                    match = 1;
            }

            if (match)
            {
                found = 1;

                printf("\n-------------------------------------\n");
                printf("Vehicle ID        : %s\n", vehicles[i].id);
                printf("Vehicle Type      : %s\n", vehicles[i].type);
                printf("Model Name        : %s\n", vehicles[i].model);
                printf("Brand             : %s\n", vehicles[i].brand);
                printf("Manufacture Year  : %d\n", vehicles[i].year);

                if (strcmp(vehicles[i].type, "Electric Vehicle") != 0)
                    printf("Engine Capacity   : %d cc\n", vehicles[i].engineCapacity);

                if (strcmp(vehicles[i].type, "Bike") == 0)
                    printf("Gear Count        : %d\n", vehicles[i].gearCount);

                else if (strcmp(vehicles[i].type, "Car") == 0 ||
                         strcmp(vehicles[i].type, "Bus") == 0)
                    printf("Seat Count        : %d\n", vehicles[i].seatCount);

                else if (strcmp(vehicles[i].type, "Truck") == 0)
                    printf("Route Number      : %s\n", vehicles[i].routeNumber);
                
                else if (strcmp(vehicles[i].type, "Electric Vehicle") == 0) {
                    printf("Battery Capacity  : %d kWh\n", vehicles[i].batteryCapacity);
                    printf("Charge Time       : %d hours\n", vehicles[i].chargeTime);
                }

                printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                printf("Color             : %s\n", vehicles[i].color);
                printf("-------------------------------------\n");
            }
        }

        if (!found)
            printf("\nNo matching vehicles found.\n");
    }
}
