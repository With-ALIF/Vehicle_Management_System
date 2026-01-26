#include<stdio.h>
#include<string.h>
#include "vehicle.h"

void billingVehicle()
{
    char id[10];
    int i, found = 0;
    int charge = 0;
    int currentYear = 2026;

    if (count == 0)
    {
        printf("\nNo vehicles available for billing.\n");
        return;
    }

    printf("\n=======================================\n");
    printf("          VEHICLE BILLING\n");
    printf("=======================================\n");
    printf("Enter Vehicle ID for billing: ");
    scanf("%s", id);

    for (i = 0; i < count; i++)
    {
        if (strcmp(vehicles[i].id, id) == 0)
        {
            found = 1;

            if (strcmp(vehicles[i].type, "Bike") == 0) {
                charge = 500 + (vehicles[i].gearCount * 100);
            }

            else if (strcmp(vehicles[i].type, "Car") == 0) {
                if (vehicles[i].engineCapacity <= 1500)
                    charge = 1200;
                else if (vehicles[i].engineCapacity <= 2500)
                    charge = 1700;
                else
                    charge = 2200;
            }

            else if (strcmp(vehicles[i].type, "Bus") == 0) {
                if (vehicles[i].seatCount <= 30)
                    charge = 2000;
                else if (vehicles[i].seatCount <= 45)
                    charge = 2500;
                else
                    charge = 3000;
            }

            else if (strcmp(vehicles[i].type, "Truck") == 0) {
                charge = 3500;
            }
            
            else if (strcmp(vehicles[i].type, "Electric Vehicle") == 0) {
                charge = 800;

                if (vehicles[i].batteryCapacity < 40)
                    charge += 700;

                if (vehicles[i].chargeTime > 6)
                    charge += 300;
            }

            if (currentYear - vehicles[i].year > 5)
                charge -= 200;

            if (charge < 0)
                charge = 0;

            printf("\n--------------------------------------\n");
            printf("Vehicle ID          : %s\n", vehicles[i].id);
            printf("Vehicle Type        : %s\n", vehicles[i].type);

            if (strcmp(vehicles[i].type, "Electric Vehicle") != 0)
                printf("Engine Capacity     : %d cc\n", vehicles[i].engineCapacity);

            if (strcmp(vehicles[i].type, "Bike") == 0)
                printf("Gear Count          : %d\n", vehicles[i].gearCount);

            else if (strcmp(vehicles[i].type, "Car") == 0 ||
                     strcmp(vehicles[i].type, "Bus") == 0)
                printf("Seat Count          : %d\n", vehicles[i].seatCount);

            else if (strcmp(vehicles[i].type, "Electric Vehicle") == 0) {
                printf("Battery Capacity    : %d kWh\n", vehicles[i].batteryCapacity);
                printf("Charge Time         : %d hours\n", vehicles[i].chargeTime);
            }

            printf("Manufacturing Year  : %d\n", vehicles[i].year);
            printf("Service Charge      : %d TK\n", charge);
            printf("--------------------------------------\n");

            break;
        }
    }

    if (!found)
        printf("\nVehicle with ID %s not found.\n", id);
}