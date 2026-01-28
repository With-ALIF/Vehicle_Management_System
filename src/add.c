#include <stdio.h>
#include <string.h>
#include "vehicle.h"

struct Vehicle vehicles[MAX];
int count = 0;
int vehicleCounter = 1;

void addVehicle()
{
    int i, choice;
    char cloneId[10];
    int found = 0;
    int attempts = 0;

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
        printf("\n1. Bike\t 2. Car\t 3. Truck 4. Bus 5. Electric Vehicle\n");
        printf("Select Type (1-5)        : ");
        scanf("%d", &choice);

        if(choice == 1) {
            strcpy(vehicles[count].type, "Bike");
        } 
        else if(choice == 2) {
            strcpy(vehicles[count].type, "Car");
        } 
        else if(choice == 3) {
            strcpy(vehicles[count].type, "Truck");
        } 
        else if(choice == 4) {
            strcpy(vehicles[count].type, "Bus");
        } 
        else if(choice == 5) {
            strcpy(vehicles[count].type, "Electric Vehicle");
        } 
        else {
            printf("Invalid vehicle type selected!\n");
            return;
        }

        printf("Enter Vehicle Model       : ");
        scanf("%s", vehicles[count].model); 

        printf("Enter Vehicle Brand Name : ");
        scanf("%s", vehicles[count].brand);

        printf("Vehicle Manufacture Year : ");
        scanf("%d", &vehicles[count].year);


        if(strcmp(vehicles[count].type, "Bike") == 0) {
            printf("Enter Engine Capacity (cc): ");
            scanf("%d", &vehicles[count].engineCapacity);

            if (vehicles[count].engineCapacity < 80 || vehicles[count].engineCapacity > 200) {
                printf("Invalid engine capacity for Bike! Must be between 80 to 200!\n");
                return;
            } 

            printf("Enter Fuel Type           : ");
            scanf(" %[^\n]", vehicles[count].fuelType);

            int attempts = 0;

            while (attempts < 2) {
            
            printf("Enter Gear Count          : ");
    
            scanf("%d", &vehicles[count].gearCount);

            if (vehicles[count].gearCount <= 4) {
            break;
        
        } else {
            
            printf("Invalid gear count for Bike! Must be at least 4.\n");
            attempts++;
            }
        }

        if (attempts == 2) {
            printf("Too many invalid attempts. Aborting vehicle addition.\n");
            return;
        }
 
        }  

        else if (strcmp(vehicles[count].type, "Car") == 0) {
            printf("Enter Engine Capacity (cc): ");
            scanf("%d", &vehicles[count].engineCapacity);

            printf("Enter Fuel Type           : ");
            scanf(" %[^\n]", vehicles[count].fuelType);

            printf("Enter Seat Count (max 12): ");
            scanf("%d", &vehicles[count].seatCount);

            if(vehicles[count].seatCount > 12) {
                printf("Invalid seat count for Car! Must not exceed 12.\n");
                return;
            }
        }

        else if (strcmp(vehicles[count].type, "Bus") == 0) {
            printf("Enter Engine Capacity (cc): ");
            scanf("%d", &vehicles[count].engineCapacity);

            printf("Enter Fuel Type           : ");
            scanf(" %[^\n]", vehicles[count].fuelType);

            printf("Enter Seat Count (min 20 and max 50): ");
            scanf("%d", &vehicles[count].seatCount);

            if(vehicles[count].seatCount < 20 || vehicles[count].seatCount > 50) {
                printf("Invalid seat count for Bus! Must be between 20 and 50.\n");
                return;
            }
        }

        else if (strcmp(vehicles[count].type, "Truck") == 0) {
            printf("Enter Engine Capacity (cc): ");
            scanf("%d", &vehicles[count].engineCapacity); 
            
            printf("Enter Fuel Type           : ");
            scanf(" %[^\n]", vehicles[count].fuelType);

            printf("Enter Route Number      : ");
            scanf("%s", vehicles[count].routeNumber);
        }


        else if (strcmp(vehicles[count].type, "Electric Vehicle") == 0) {
            vehicles[count].engineCapacity = 0;

            printf("Enter Battery Capacity (kWh): ");
            scanf("%d", &vehicles[count].batteryCapacity);

            printf("Enter Charge Time (hours)   : ");
            scanf("%d", &vehicles[count].chargeTime);
        }

    printf("Enter Vehicle Color       : ");
    scanf("%s", vehicles[count].color);
        count++;

    lastOperation = UNDO_ADD;

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