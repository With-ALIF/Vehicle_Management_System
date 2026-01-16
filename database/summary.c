#include <stdio.h>
#include <string.h>
#include "vehicle.h"

void summaryVehicle()
{
    int i, j, choice;

    if (count == 0)
    {
        printf("\nNo vehicles available.\n");
        return;
    }

    while (1)
    {
        printf("\n=====================================\n");
        printf("           VEHICLE REPORT MENU\n");
        printf("=====================================\n");
        printf("1. Overall Vehicle Summary\n");
        printf("2. Engine Capacity Report\n");
        printf("3. Manufacturing Year Report\n");
        printf("4. Brand Distribution Report\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            return;

        if (choice == 1)
        {
            int bike = 0, car = 0, bus = 0, truck = 0, other = 0;
            int yearSum = 0;

            for (i = 0; i < count; i++)
            {
                if (strcmp(vehicles[i].type, "Bike") == 0) bike++;
                else if (strcmp(vehicles[i].type, "Car") == 0) car++;
                else if (strcmp(vehicles[i].type, "Bus") == 0) bus++;
                else if (strcmp(vehicles[i].type, "Truck") == 0) truck++;
                else other++;

                yearSum += vehicles[i].year;
            }

            printf("\n-------------------------------------\n");
            printf("          OVERALL SUMMARY\n");
            printf("-------------------------------------\n");
            printf("Total Vehicles : %d\n", count);
            printf("Bike   : %d\n", bike);
            printf("Car    : %d\n", car);
            printf("Bus    : %d\n", bus);
            printf("Truck : %d\n", truck);
            printf("Other  : %d\n", other);
            printf("Average Manufacturing Year : %.2f\n",
                   (float)yearSum / count);
        }

        else if (choice == 2)
        {
            int maxCC = vehicles[0].engineCapacity;
            int minCC = vehicles[0].engineCapacity;
            int ccSum = 0;

            for (i = 0; i < count; i++)
            {
                if (vehicles[i].engineCapacity > maxCC)
                    maxCC = vehicles[i].engineCapacity;

                if (vehicles[i].engineCapacity < minCC)
                    minCC = vehicles[i].engineCapacity;

                ccSum += vehicles[i].engineCapacity;
            }

            printf("\n-------------------------------------\n");
            printf("       ENGINE CAPACITY REPORT\n");
            printf("-------------------------------------\n");
            printf("Average Engine Capacity : %.2f cc\n",
                   (float)ccSum / count);
            printf("Highest Engine Capacity : %d cc\n", maxCC);
            printf("Lowest Engine Capacity  : %d cc\n", minCC);
        }

        else if (choice == 3)
        {
            int oldest = vehicles[0].year;
            int newest = vehicles[0].year;

            for (i = 0; i < count; i++)
            {
                if (vehicles[i].year < oldest)
                    oldest = vehicles[i].year;

                if (vehicles[i].year > newest)
                    newest = vehicles[i].year;
            }

            printf("\n-------------------------------------\n");
            printf("     MANUFACTURING YEAR REPORT\n");
            printf("-------------------------------------\n");
            printf("Oldest Vehicle Year : %d\n", oldest);
            printf("Newest Vehicle Year : %d\n", newest);
        }

        else if (choice == 4)
        {
            printf("\n-------------------------------------\n");
            printf("       BRAND DISTRIBUTION REPORT\n");
            printf("-------------------------------------\n");

            for (i = 0; i < count; i++)
            {
                int printed = 0;
                int brandCount = 0;

                for (j = 0; j < i; j++)
                    if (strcmp(vehicles[j].brand, vehicles[i].brand) == 0)
                        printed = 1;

                if (printed)
                    continue;

                for (j = 0; j < count; j++)
                    if (strcmp(vehicles[j].brand, vehicles[i].brand) == 0)
                        brandCount++;

                printf("%s : %d (%.2f%%)\n",
                       vehicles[i].brand,
                       brandCount,
                       (brandCount * 100.0) / count);
            }
        }

        else
        {
            printf("\nInvalid choice. Try again.\n");
        }
    }
}