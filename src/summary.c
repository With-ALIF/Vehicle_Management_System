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
        printf("5. Electric Vehicle Report\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            return;

        if (choice == 1)
        {
            int bike = 0, car = 0, bus = 0, truck = 0, electric = 0;
            int yearSum = 0;

            for (i = 0; i < count; i++)
            {
                if (strcmp(vehicles[i].type, "Bike") == 0) bike++;
                else if (strcmp(vehicles[i].type, "Car") == 0) car++;
                else if (strcmp(vehicles[i].type, "Bus") == 0) bus++;
                else if (strcmp(vehicles[i].type, "Truck") == 0) truck++;
                else if (strcmp(vehicles[i].type, "Electric Vehicle") == 0) electric++;

                yearSum += vehicles[i].year;
            }

            printf("\n-------------------------------------\n");
            printf("          OVERALL SUMMARY\n");
            printf("-------------------------------------\n");
            printf("Total Vehicles : %d\n", count);
            printf("Bike                        : %d\n", bike);
            printf("Car                         : %d\n", car);
            printf("Bus                         : %d\n", bus);
            printf("Truck                       : %d\n", truck);
            printf("Electric Vehicle            : %d\n", electric);
            printf("Average Manufacturing Year  : %.2f\n",
                   (float)yearSum / count);
        }

        else if (choice == 2)
        {
            int maxCC = -1, minCC = -1;
            int ccSum = 0, ccCount = 0;

            for (i = 0; i < count; i++)
            {
                if (strcmp(vehicles[i].type, "Electric Vehicle") == 0)
                    continue;

                if (ccCount == 0)
                {
                    maxCC = vehicles[i].engineCapacity;
                    minCC = vehicles[i].engineCapacity;
                }
                else
                {
                    if (vehicles[i].engineCapacity > maxCC)
                        maxCC = vehicles[i].engineCapacity;
                    if (vehicles[i].engineCapacity < minCC)
                        minCC = vehicles[i].engineCapacity;
                }

                ccSum += vehicles[i].engineCapacity;
                ccCount++;
            }

            printf("\n-------------------------------------\n");
            printf("       ENGINE CAPACITY REPORT\n");
            printf("-------------------------------------\n");
           
            if(ccCount == 0) {
                printf("No vehicles with engine capacity available.\n");
            } else {
                printf("Maximum Engine Capacity : %d cc\n", maxCC);
                printf("Minimum Engine Capacity : %d cc\n", minCC);
                printf("Average Engine Capacity : %.2f cc\n",
                       (float)ccSum / ccCount);
            }
        }

        else if (choice == 3)
        {
            int oldest = vehicles[0].year;
            int newest = vehicles[0].year;

            for (i = 1; i < count; i++)
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

                for (j = 0; j < i; j++) {
                    if (strcmp(vehicles[j].brand, vehicles[i].brand) == 0)
                      {  
                        printed = 1;
                        break;
                      }
                }
                
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

        else if (choice == 5)
        {
            int evCount = 0;
            int maxBattery = -1, minBattery = -1;
            int batterySum = 0;
            int maxChargeTime = -1, minChargeTime = -1;
            int chargeTimeSum = 0;

            for (i = 0; i < count; i++)
            {
                if (strcmp(vehicles[i].type, "Electric Vehicle") == 0)
                {
                    evCount++;

                    if (evCount == 1)
                    {
                        maxBattery = vehicles[i].batteryCapacity;
                        minBattery = vehicles[i].batteryCapacity;
                        maxChargeTime = vehicles[i].chargeTime;
                        minChargeTime = vehicles[i].chargeTime;
                    }
                    else
                    {
                        if (vehicles[i].batteryCapacity > maxBattery)
                            maxBattery = vehicles[i].batteryCapacity;

                        if (vehicles[i].batteryCapacity < minBattery)
                            minBattery = vehicles[i].batteryCapacity;

                        if (vehicles[i].chargeTime > maxChargeTime)
                            maxChargeTime = vehicles[i].chargeTime;

                        if (vehicles[i].chargeTime < minChargeTime)
                            minChargeTime = vehicles[i].chargeTime;
                    }

                    batterySum += vehicles[i].batteryCapacity;
                    chargeTimeSum += vehicles[i].chargeTime;
                }
            }

            printf("\n-------------------------------------\n");
            printf("    ELECTRIC VEHICLE REPORT\n");
            printf("-------------------------------------\n");

            if (evCount == 0)
            {
                printf("No Electric Vehicles available.\n");
            }
            else
            {
                printf("Total Electric Vehicles    : %d (%.2f%%)\n",
                       evCount, (evCount * 100.0) / count);
                printf("Maximum Battery Capacity   : %d kWh\n", maxBattery);
                printf("Minimum Battery Capacity   : %d kWh\n", minBattery);
                printf("Average Battery Capacity   : %.2f kWh\n",
                       (float)batterySum / evCount);
                printf("Maximum Charge Time        : %d hours\n", maxChargeTime);
                printf("Minimum Charge Time        : %d hours\n", minChargeTime);
                printf("Average Charge Time        : %.2f hours\n",
                       (float)chargeTimeSum / evCount);
            }
        }

        else
        {
            printf("\nInvalid choice. Try again.\n");
        }
    }
}