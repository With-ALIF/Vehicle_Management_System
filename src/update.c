#include <stdio.h>
#include <string.h>
#include "vehicle.h"

void updateVehicle()
{
    int i, mainChoice, choice;
    char key[20];
    int found = 0;

    if (count == 0)
    {
        printf("\nNo vehicles available.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("           UPDATE VEHICLE INFO\n");
    printf("=====================================\n");
    printf("1. Update by Vehicle ID\n");
    printf("2. Partial Update (by condition)\n");
    printf("0. Cancel\n");
    printf("Enter your choice: ");
    scanf("%d", &mainChoice);

    if (mainChoice == 0)
        return;

    if (mainChoice == 1)
    {
        printf("\nEnter Vehicle ID to update : ");
        scanf("%s", key);

        for (i = 0; i < count; i++)
        {
            if (strcmp(vehicles[i].id, key) == 0)
            {
                printf("\n------------------------------------\n");
                printf("       Current Vehicle Details\n");
                printf("------------------------------------\n");
                printf("Vehicle ID        : %s\n", vehicles[i].id);
                printf("Vehicle Type      : %s\n", vehicles[i].type);
                printf("Model Name        : %s\n", vehicles[i].model);
                printf("Brand             : %s\n", vehicles[i].brand);
                printf("Manufacture Year  : %d\n", vehicles[i].year);
                printf("Engine Capacity   : %d cc\n", vehicles[i].engineCapacity);
                printf("Color             : %s\n", vehicles[i].color);
                printf("Fuel Type         : %s\n", vehicles[i].fuelType);
                printf("Gear / Seat / Route No / Battery Value: %d\n", vehicles[i].seatCount);
                printf("------------------------------------\n");

                printf("\nWhich information do you want to update?\n");
                printf("1. Model Name\n");
                printf("2. Brand\n");
                printf("3. Manufacture Year\n");
                printf("4. Engine Capacity\n");
                printf("5. Color\n");
                printf("6. Fuel Type\n");
                printf("7. Gear / Seat / Route No / Battery Value / Charge Time\n");
                printf("8. Update All Fields\n");
                printf("0. Cancel\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 0)
                    return;

                undoVehicle = vehicles[i];
                undoIndex = i;
                lastOperation = UNDO_UPDATE;

              if (choice == 1) {
                    printf("Enter New Model Name: ");
                    scanf("%s", vehicles[i].model);
                }

                else if (choice == 2) {
                    printf("Enter New Brand: ");
                    scanf("%s", vehicles[i].brand);
                }

                else if (choice == 3) {
                    printf("Enter New Manufacture Year: ");
                    scanf("%d", &vehicles[i].year);
                }

                else if (choice == 4) {
                    printf("Enter New Engine Capacity (cc): ");
                    scanf("%d", &vehicles[i].engineCapacity);
                }

                else if (choice == 5) {
                    printf("Enter New Color: ");
                    scanf("%s", vehicles[i].color);
                }

                else if (choice == 6) {
                    printf("Enter New Fuel Type: ");
                    scanf(" %[^\n]", vehicles[i].fuelType);
                }

                else if (choice == 7) {
                    if (strcmp(vehicles[i].type, "Bike") == 0) {
                        printf("Enter New Gear Count: ");
                        scanf("%d", &vehicles[i].gearCount);
                    }
                    else if (strcmp(vehicles[i].type, "Car") == 0) {
                        printf("Enter New Seat Count: ");
                        scanf("%d", &vehicles[i].seatCount);
                    }
                    else if (strcmp(vehicles[i].type, "Bus") == 0) {
                        printf("Enter New Seat Count: ");
                        scanf("%d", &vehicles[i].seatCount);
                    }
                    else if (strcmp(vehicles[i].type, "Truck") == 0) {
                        printf("Enter New Route Number: ");
                        scanf("%s", vehicles[i].routeNumber);
                    }
                    else if (strcmp(vehicles[i].type, "Electric Vehicle") == 0) {
                        printf("1. Update Battery Capacity\n");
                        printf("2. Update Charge Time\n");
                        printf("Enter choice: ");
                        int evChoice;
                        scanf("%d", &evChoice);
                        if (evChoice == 1) {
                            printf("Enter New Battery Capacity (kWh): ");
                            scanf("%d", &vehicles[i].batteryCapacity);
                        } else if (evChoice == 2) {
                            printf("Enter New Charge Time (hours): ");
                            scanf("%d", &vehicles[i].chargeTime);
                        }
                    }
                }

                else if (choice == 8) {
                    printf("Enter New Model Name       : ");
                    scanf("%s", vehicles[i].model); 

                    printf("Enter New Brand Name       : ");
                    scanf("%s", vehicles[i].brand);

                    printf("Enter New Manufacture Year : ");
                    scanf("%d", &vehicles[i].year);

                    printf("Enter New Engine Capacity (cc): ");
                    scanf("%d", &vehicles[i].engineCapacity);

                    printf("Enter New Color            : ");
                    scanf("%s", vehicles[i].color);

                    printf("Enter New Fuel Type        : ");
                    scanf(" %[^\n]", vehicles[i].fuelType);

                    if (strcmp(vehicles[i].type, "Bike") == 0) {
                        printf("Enter New Gear Count: ");
                        scanf("%d", &vehicles[i].gearCount);
                    }
                    else if (strcmp(vehicles[i].type, "Car") == 0) {
                        printf("Enter New Seat Count: ");
                        scanf("%d", &vehicles[i].seatCount);
                    }
                    else if (strcmp(vehicles[i].type, "Bus") == 0) {
                        printf("Enter New Seat Count: ");
                        scanf("%d", &vehicles[i].seatCount);
                    }
                    else if (strcmp(vehicles[i].type, "Truck") == 0) {
                        printf("Enter New Route Number: ");
                        scanf("%s", vehicles[i].routeNumber);
                    }
                    else if (strcmp(vehicles[i].type, "Electric Vehicle") == 0) {
                        printf("Enter New Battery Capacity (kWh): ");
                        scanf("%d", &vehicles[i].batteryCapacity);
                        printf("Enter New Charge Time (hours): ");
                        scanf("%d", &vehicles[i].chargeTime);
                    }

                    else {
                        printf("Invalid choice!\n");
                        return;
                    }
                }

                printf("\n------------------------------------\n");
                printf(" Vehicle Updated Successfully!\n");
                printf("------------------------------------\n");
                return;
            }
        }

        printf("\nVehicle not found!\n");
    }

    else if (mainChoice == 2)
    {
        int cond, upd, cc;
        char brand[30], type[20];
        char newText[50];
        int newValue;

        printf("\n------------------------------------\n");
        printf("        PARTIAL UPDATE MODE\n");
        printf("------------------------------------\n");
        printf("Match vehicles by:\n");
        printf("1. Brand Name\n");
        printf("2. Vehicle Type\n");
        printf("3. Engine Capacity greater than\n");
        printf("4. Battery Capacity (EV only)\n");
        printf("0. Cancel\n");
        printf("Enter choice: ");
        scanf("%d", &cond);

        if (cond == 0)
            return;

        if (cond == 1)
        {
            printf("Enter Brand Name: ");
            scanf(" %[^\n]", brand);
        }
        else if (cond == 2)
        {
            printf("Enter Vehicle Type: ");
            scanf(" %[^\n]", type);
        }
        else if (cond == 3)
        {
            printf("Enter Engine Capacity: ");
            scanf("%d", &cc);
        }
        else if (cond == 4)
        {
            printf("Enter Battery Capacity: ");
            scanf("%d", &cc);
        }

        printf("\nUpdate which field update?\n");
        printf("1. Brand Name\n");
        printf("2. Vehicle Type\n");
        printf("3. Engine Capacity\n");
        printf("4. Color\n");   
        printf("5. Fuel Type\n");
        printf("6. Battery Capacity (EV only)\n");
        printf("0. Cancel\n");
        printf("Enter choice: ");
        scanf("%d", &upd);

        if (found) 
            return;
    
        if (upd == 1 || upd == 2 || upd == 4 || upd == 5) {
            printf("Enter New Value: ");
            scanf(" %[^\n]", newText);
        }
        else if (upd == 3 || upd == 6) {
            printf("Enter New Value: ");
            scanf("%d", &newValue);
        }
        
        for (i = 0; i < count; i++)
        {
            int match = 0;

            if (cond == 1 && strcmp(vehicles[i].brand, brand) == 0)
                match = 1;

            else if (cond == 2 && strcmp(vehicles[i].type, type) == 0)
                match = 1;

            else if (cond == 3 && vehicles[i].engineCapacity > cc)
                match = 1;

            else if (cond == 4 && strcmp(vehicles[i].type, "Electric Vehicle") == 0 &&
                     vehicles[i].batteryCapacity == cc)
                match = 1;

            if (match)
            {

                undoVehicle = vehicles[i];
                undoIndex = i;
                lastOperation = UNDO_UPDATE;

                
                if (upd == 1)
                    strcpy(vehicles[i].brand, newText);

                else if (upd == 2)
                    strcpy(vehicles[i].type, newText);

                else if (upd == 3)
                    vehicles[i].engineCapacity = newValue;

                else if (upd == 4)
                    strcpy(vehicles[i].color, newText);

                else if (upd == 5)
                    strcpy(vehicles[i].fuelType, newText);

                else if (upd == 6)
                    vehicles[i].batteryCapacity = newValue;

                found = 1;
            }
        }

    if (found)
        {
            printf("\n------------------------------------\n");
            printf(" Vehicles Updated Successfully!\n");
            printf("------------------------------------\n");
        }
    else
    {
        printf("\nNo matching vehicles found.\n");
    }
}
}