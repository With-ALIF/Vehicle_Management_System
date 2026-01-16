#include <stdio.h>
#include <string.h>
#include "vehicle.h"

void addVehicle()
{
    int i, choice;
    char cloneId[10];
    int found = 0;

    printf("\n=====================================\n");
    printf("            ADD VEHICLE\n");
    printf("=====================================\n");
    printf("1. Add New Vehicle (Manual)\n");
    printf("2. Clone Existing Vehicle\n");
    printf("0. Cancel\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 0)
        return;

    if (choice == 1)
    {
        sprintf(vehicles[count].id, "V%03d", vehicleCounter);
        printf("\nGenerated Vehicle ID     : %s\n", vehicles[count].id);
        vehicleCounter++;

        printf("Enter Vehicle Type        : ");
        scanf(" %[^\n]", vehicles[count].type);

        printf("Enter Model Name          : ");
        scanf(" %[^\n]", vehicles[count].model);

        printf("Enter Brand Name          : ");
        scanf(" %[^\n]", vehicles[count].brand);

        printf("Enter Manufacturing Year  : ");
        scanf("%d", &vehicles[count].year);

        printf("Enter Engine Capacity (cc): ");
        scanf("%d", &vehicles[count].engineCapacity);

        printf("Enter Vehicle Color       : ");
        scanf(" %[^\n]", vehicles[count].color);

        printf("Enter Fuel Type           : ");
        scanf(" %[^\n]", vehicles[count].fuelType);

        printf("Enter Seat Count          : ");
        scanf("%d", &vehicles[count].seatCount);

        count++;
        saveVehiclesToFile();

        printf("\n-------------------------------------\n");
        printf(" Vehicle Added Successfully!\n");
        printf("-------------------------------------\n");
    }
    else if (choice == 2)
    {
        printf("\nEnter Vehicle ID to clone : ");
        scanf("%s", cloneId);

        for (i = 0; i < count; i++)
        {
            if (strcmp(vehicles[i].id, cloneId) == 0)
            {
                vehicles[count] = vehicles[i];

                sprintf(vehicles[count].id, "V%03d", vehicleCounter);
                printf("New Generated Vehicle ID  : %s\n", vehicles[count].id);
                vehicleCounter++;

                count++;
                saveVehiclesToFile();
                found = 1;

                printf("\n-------------------------------------\n");
                printf(" Vehicle Cloned Successfully!\n");
                printf("-------------------------------------\n");
                break;
            }
        }

        if (!found)
            printf("\nVehicle ID not found!\n");
    }
    else
    {
        printf("\nInvalid choice!\n");
    }
}