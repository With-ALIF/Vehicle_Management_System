#include <stdio.h>
#include <string.h>
#include "vehicle.h"

void showVehicles()
{
    int i, choice;

    if (count == 0)
    {
        printf("\nNo vehicles available.\n");
        return;
    }

    while (1)
    {
        printf("\n=====================================\n");
        printf("           VEHICLE DISPLAY MENU\n");
        printf("=====================================\n");
        printf("1. Show All Vehicles (Full Details)\n");
        printf("2. Show Vehicles Grouped by Type\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            return;

        else if (choice == 1)
        {
            printf("\n=====================================\n");
            printf("           VEHICLE LIST\n");
            printf("=====================================\n");

            for (i = 0; i < count; i++)
            {
                printf("\n-------------------------------------\n");
                printf("Vehicle No        : %d\n", i + 1);
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

        else if (choice == 2)
        {
            printf("\n=====================================\n");
            printf("       VEHICLES GROUPED BY TYPE\n");
            printf("=====================================\n");

            printf("\n----------- BIKES -----------\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Bike") == 0)
                    printf("%s | %s | %s | %dcc\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].engineCapacity);

            printf("\n----------- CARS ------------\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Car") == 0)
                    printf("%s | %s | %s | %dcc\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].engineCapacity);

            printf("\n----------- BUSES -----------\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Bus") == 0)
                    printf("%s | %s | %s | %dcc\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].engineCapacity);

            printf("\n----------- TRUCKS ----------\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Truck") == 0)
                    printf("%s | %s | %s | %dcc\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].engineCapacity);

            printf("\n----------- OTHERS ----------\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Bike") != 0 &&
                    strcmp(vehicles[i].type, "Car") != 0 &&
                    strcmp(vehicles[i].type, "Bus") != 0 &&
                    strcmp(vehicles[i].type, "Truck") != 0)
                    printf("%s | %s | %s | %dcc\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].engineCapacity);
        }

        else
        {
            printf("\nInvalid choice! Try again.\n");
        }
    }
}
