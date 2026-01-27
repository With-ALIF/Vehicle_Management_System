#include <stdio.h>
#include "vehicle.h"

int lastOperation = UNDO_NONE;
struct Vehicle undoVehicle;
int undoIndex = -1;

int main()
{
    int choice;

    while (1)
    {
        printf("\n=====================================\n");
        printf("       VEHICLE MANAGEMENT SYSTEM\n");
        printf("=====================================\n");
        printf(" 1. Add Vehicle\n");
        printf(" 2. Show Vehicles\n");
        printf(" 3. Update Vehicle\n");
        printf(" 4. Delete Vehicle\n");
        printf(" 5. Search Vehicle\n");
        printf(" 6. Filter Vehicle\n");
        printf(" 7. Summary Vehicle\n");
        printf(" 8. Billing Vehicle\n");
        printf(" 9. Undo Last Operation\n");
        printf(" 0. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            addVehicle();
            break;

        case 2:
            showVehicles();
            break;

        case 3:
            updateVehicle();
            break;
        
        case 4: 
            deleteVehicle();
            break;
        
        case 5:
            searchVehicle();
            break;
        
        case 6:
            filterVehicle();
            break;
        
        case 7:
            summaryVehicle();
            break;
        
        case 8:
            billingVehicle();
            break;
        
        case 9:
            undoLastOperation();
            break;
            
        case 0:
            printf("\n=====================================\n");
            printf("     Exiting Vehicle Management...\n");
            printf("     Goodbye!\n");
            printf("=====================================\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
}