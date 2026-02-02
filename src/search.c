#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "vehicle.h"

void searchVehicle()
{
    int i, choice;
    char text[50];
    char temp[50];
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
        printf("6. Search by Battery Capacity (EV)\n");
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

            for (i = 0; text[i]; i++)
                text[i] = tolower(text[i]);
        }
        else if (choice >= 4 && choice <= 6)
        {
            printf("Enter value: ");
            scanf("%d", &value);
        }

        printf("\n-------------------------------------\n");

        for (i = 0; i < count; i++)
        {
            int match = 0;

            if (choice == 1)
            {
                strcpy(temp, vehicles[i].id);
                for (int j = 0; temp[j]; j++)
                    temp[j] = tolower(temp[j]);

                if (strcmp(temp, text) == 0)
                    match = 1;
            }
            else if (choice == 2)
            {
                strcpy(temp, vehicles[i].type);
                for (int j = 0; temp[j]; j++)
                    temp[j] = tolower(temp[j]);

                if (strcmp(temp, text) == 0)
                    match = 1;
            }
            else if (choice == 3)
            {
                strcpy(temp, vehicles[i].model);
                for (int j = 0; temp[j]; j++)
                    temp[j] = tolower(temp[j]);

                if (strstr(temp, text))
                    match = 1;
            }
            else if (choice == 4 && vehicles[i].year == value)
                match = 1;
            else if (choice == 5 && vehicles[i].engineCapacity == value)
                match = 1;
            else if (choice == 6 && strcmp(vehicles[i].type, "Electric Vehicle") == 0 && vehicles[i].batteryCapacity == value)
                match = 1;

            if (match)
            {
                found = 1;
                printf("Vehicle ID        : %s\n", vehicles[i].id);
                printf("Vehicle Type      : %s\n", vehicles[i].type);
                printf("Model Name        : %s\n", vehicles[i].model);
                printf("Brand             : %s\n", vehicles[i].brand);
                printf("Manufacture Year  : %d\n", vehicles[i].year);

                if (strcmp(vehicles[i].type, "Electric Vehicle") != 0)
                    printf("Engine Capacity   : %d cc\n", vehicles[i].engineCapacity);

                if (strcmp(vehicles[i].type, "Bike") == 0)
                {
                    printf("Gear Count        : %d\n", vehicles[i].gearCount);
                    printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                }
                else if (strcmp(vehicles[i].type, "Car") == 0)
                {
                    printf("Seat Count        : %d\n", vehicles[i].seatCount);
                    printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                }
                else if (strcmp(vehicles[i].type, "Bus") == 0)
                {
                    printf("Seat Count        : %d\n", vehicles[i].seatCount);
                    printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                }
                else if (strcmp(vehicles[i].type, "Truck") == 0)
                {
                    printf("Route Number      : %s\n", vehicles[i].routeNumber);
                    printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                }
                else if (strcmp(vehicles[i].type, "Electric Vehicle") == 0)
                {
                    printf("Battery Capacity  : %d kWh\n", vehicles[i].batteryCapacity);
                    printf("Charge Time       : %d hours\n", vehicles[i].chargeTime);
                }

                printf("Color             : %s\n", vehicles[i].color);
                printf("-------------------------------------\n");

                if (choice == 1)
                    return;
            }
        }

        if (!found)
            printf("No matching vehicle found.\n");
    }
}