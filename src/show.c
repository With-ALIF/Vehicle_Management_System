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
        printf("3. Show Electric Vehicles Only\n");
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

                if (strcmp(vehicles[i].type, "Electric Vehicle") != 0)
                    printf("Engine Capacity   : %d cc\n", vehicles[i].engineCapacity);

                if (strcmp(vehicles[i].type, "Bike") == 0) {
                    printf("Gear Count        : %d\n", vehicles[i].gearCount);
                    printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                }
                else if (strcmp(vehicles[i].type, "Car") == 0) {
                    printf("Seat Count        : %d\n", vehicles[i].seatCount);
                    printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                }
                else if (strcmp(vehicles[i].type, "Bus") == 0) {
                    printf("Seat Count        : %d\n", vehicles[i].seatCount);
                    printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                }
                else if (strcmp(vehicles[i].type, "Truck") == 0) {
                    printf("Route Number      : %s\n", vehicles[i].routeNumber);
                    printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                }
                else if (strcmp(vehicles[i].type, "Electric Vehicle") == 0) {
                    printf("Battery Capacity  : %d kWh\n", vehicles[i].batteryCapacity);
                    printf("Charge Time       : %d hours\n", vehicles[i].chargeTime);
                }

                printf("Color             : %s\n", vehicles[i].color);
                printf("-------------------------------------\n");
            }
        }

        else if (choice == 3)
        {
            printf("\n=====================================\n");
            printf("      ELECTRIC VEHICLES (FULL DETAILS)\n");
            printf("=====================================\n");

            int ev_count = 0;
            for (i = 0; i < count; i++)
            {
                if (strcmp(vehicles[i].type, "Electric Vehicle") == 0)
                {
                    ev_count++;
                    printf("\n-------------------------------------\n");
                    printf("Vehicle No        : %d\n", ev_count);
                    printf("Vehicle ID        : %s\n", vehicles[i].id);
                    printf("Vehicle Type      : %s\n", vehicles[i].type);
                    printf("Model Name        : %s\n", vehicles[i].model);
                    printf("Brand             : %s\n", vehicles[i].brand);
                    printf("Manufacture Year  : %d\n", vehicles[i].year);
                    printf("Battery Capacity  : %d kWh\n", vehicles[i].batteryCapacity);
                    printf("Charge Time       : %d hours\n", vehicles[i].chargeTime);
                    printf("Color             : %s\n", vehicles[i].color);
                    printf("-------------------------------------\n");
                }
            }
            if (ev_count == 0)
                printf("\nNo Electric Vehicles available.\n");
        }

        else if (choice == 2)
        {
            printf("\n=====================================\n");
            printf("       VEHICLES GROUPED BY TYPE\n");
            printf("=====================================\n");

            printf("\n----------- BIKES -----------\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Bike") == 0)
                    printf("%s | %s | %s | %dcc | %d gears\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].engineCapacity,
                           vehicles[i].gearCount);

            printf("\n----------- CARS ------------\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Car") == 0)
                    printf("%s | %s | %s | %dcc | %d seats\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].engineCapacity,
                           vehicles[i].seatCount);

            printf("\n----------- BUSES -----------\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Bus") == 0)
                    printf("%s | %s | %s | %dcc | %d seats\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].engineCapacity,
                           vehicles[i].seatCount);

            printf("\n----------- TRUCKS ----------\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Truck") == 0)
                    printf("%s | %s | %s | %dcc | Route %s\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].engineCapacity,
                           vehicles[i].routeNumber);

            printf("\n----- ELECTRIC VEHICLES -----\n");
            for (i = 0; i < count; i++)
                if (strcmp(vehicles[i].type, "Electric Vehicle") == 0)
                    printf("%s | %s | %s | %dkWh | %d hrs\n",
                           vehicles[i].id,
                           vehicles[i].model,
                           vehicles[i].brand,
                           vehicles[i].batteryCapacity,
                           vehicles[i].chargeTime);
        }

        else
        {
            printf("\nInvalid choice. Try again.\n");
        }
    }
}