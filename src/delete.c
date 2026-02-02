#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vehicle.h"

void deleteVehicle()
{
    char command[100];
    int i, j;
    int deleted;

    if (count == 0)
    {
        printf("\nNo vehicles available.\n");
        return;
    }

    while (1)
    {
        deleted = 0;

        printf("\n========================================\n");
        printf("         VEHICLE DELETE COMMANDS\n");
        printf("========================================\n");
        printf("Type commands using your own values\n\n");

        printf("delete <ID>\n");
        printf("Example: delete V102\n\n");

        printf("delete older <YEAR>\n");
        printf("Example: delete older 2018\n\n");

        printf("delete engine < <CC>\n");
        printf("Example: delete engine < 1500\n\n");

        printf("delete engine > <CC>\n");
        printf("Example: delete engine > 2000\n\n");

        printf("delete battery > <KWH>\n");
        printf("Example: delete battery > 100\n\n");

        printf("delete battery < <KWH>\n");
        printf("Example: delete battery < 50\n\n");

        printf("delete brand <BRAND_NAME>\n");
        printf("Example: delete brand Toyota\n\n");

        printf("0. Back\n");
        printf("Enter command: ");
        scanf(" %[^\n]", command);

        if (strcmp(command, "0") == 0)
            return;

        if (strncmp(command, "delete ", 7) == 0 &&
            strstr(command, "older") == NULL &&
            strstr(command, "engine") == NULL &&
            strstr(command, "brand") == NULL)
        {
            char id[20];
            strcpy(id, command + 7);

            for (i = 0; i < count; i++)
            {
                if (strcmp(vehicles[i].id, id) == 0)
                {
                    undoVehicle = vehicles[i];
                    undoIndex = i;
                    lastOperation = UNDO_DELETE;

                    for (j = i; j < count - 1; j++)
                        vehicles[j] = vehicles[j + 1];
                    count--;
                    printf("\nVehicle deleted successfully.\n");
                    break;
                }
            }

            if (i == count)
                printf("\nVehicle ID not found.\n");

            continue;
        }

        if (strncmp(command, "delete older ", 13) == 0)
        {
            int year = atoi(command + 13);

            for (i = 0; i < count;)
            {
                if (vehicles[i].year < year)
                {
                    undoVehicle = vehicles[i];
                    undoIndex = i;
                    lastOperation = UNDO_DELETE;

                    for (j = i; j < count - 1; j++)
                        vehicles[j] = vehicles[j + 1];
                    count--;
                    deleted++;
                }
                else
                    i++;
            }
        }

        else if (strncmp(command, "delete engine < ", 16) == 0)
        {
            int cc = atoi(command + 16);

            for (i = 0; i < count;)
            {
                if (vehicles[i].engineCapacity < cc)
                {
                    undoVehicle = vehicles[i];
                    undoIndex = i;
                    lastOperation = UNDO_DELETE;

                    for (j = i; j < count - 1; j++)
                        vehicles[j] = vehicles[j + 1];
                    count--;
                    deleted++;
                }
                else
                    i++;
            }
        }

        else if (strncmp(command, "delete engine > ", 16) == 0)
        {
            int cc = atoi(command + 16);

            for (i = 0; i < count;)
            {
                if (vehicles[i].engineCapacity > cc)
                {
                    undoVehicle = vehicles[i];
                    undoIndex = i;
                    lastOperation = UNDO_DELETE;

                    for (j = i; j < count - 1; j++)
                        vehicles[j] = vehicles[j + 1];
                    count--;
                    deleted++;
                }
                else
                    i++;
            }
        }
        
        else if (strncmp(command, "delete battery > ", 17) == 0)
        {
            int capacity = atoi(command + 17);

            for (i = 0; i < count;)
            {
                if (strcmp(vehicles[i].type, "Electric Vehicle") == 0 &&
                    vehicles[i].batteryCapacity > capacity)
                {
                    undoVehicle = vehicles[i];
                    undoIndex = i;
                    lastOperation = UNDO_DELETE;

                    for (j = i; j < count - 1; j++)
                        vehicles[j] = vehicles[j + 1];
                    count--;
                    deleted++;
                }
                else
                    i++;
            }
        }

        else if (strncmp(command, "delete battery < ", 17) == 0)
        {
            int capacity = atoi(command + 17);

            for (i = 0; i < count;)
            {
                if (strcmp(vehicles[i].type, "Electric Vehicle") == 0 &&
                    vehicles[i].batteryCapacity < capacity)
                {
                    undoVehicle = vehicles[i];
                    undoIndex = i;
                    lastOperation = UNDO_DELETE;

                    for (j = i; j < count - 1; j++)
                        vehicles[j] = vehicles[j + 1];
                    count--;
                    deleted++;
                }
                else
                    i++;
            }
        }
        
        else if (strncmp(command, "delete brand ", 13) == 0)
        {
            char brand[50];
            strcpy(brand, command + 13);

            for (i = 0; i < count;)
            {
                if (strcmp(vehicles[i].brand, brand) == 0)
                {
                    undoVehicle = vehicles[i];
                    undoIndex = i;
                    lastOperation = UNDO_DELETE;

                    for (j = i; j < count - 1; j++)
                        vehicles[j] = vehicles[j + 1];
                    count--;
                    deleted++;
                }
                else
                    i++;
            }
        }
        else
        {
            printf("\nInvalid command.\n");
            continue;
        }

        if (deleted > 0)
        {
            printf("\n%d vehicle(s) deleted successfully.\n", deleted);
        }
        else
        {
            printf("\nNo matching vehicles found.\n");
        }
    }
}