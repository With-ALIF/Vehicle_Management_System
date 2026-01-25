#include <stdio.h>
#include <string.h>
#include "vehicle.h"

struct Vehicle vehicles[MAX];
int count = 0;
int vehicleCounter = 1;

void loadVehiclesFromFile()
{
    FILE *fp = fopen("vehicles.txt", "r");
    if (!fp) return;

    count = 0;
    vehicleCounter = 1;

    while (fscanf(fp,
        "%[^,],%[^,],%[^,],%[^,],%d,%d,%[^,],%[^,],%d\n",
        vehicles[count].id,
        vehicles[count].type,
        vehicles[count].model,
        vehicles[count].brand,
        &vehicles[count].year,
        &vehicles[count].engineCapacity,
        vehicles[count].color,
        vehicles[count].fuelType,
        &vehicles[count].seatCount) == 9)
    {
        int n;
        sscanf(vehicles[count].id, "V%d", &n);
        if (n >= vehicleCounter)
            vehicleCounter = n + 1;

        count++;
    }

    fclose(fp);
}

void saveVehiclesToFile()
{
    FILE *fp = fopen("vehicles.txt", "w");
    int i;

    for (i = 0; i < count; i++)
    {
        fprintf(fp, "%s,%s,%s,%s,%d,%d,%s,%s,%d\n",
            vehicles[i].id,
            vehicles[i].type,
            vehicles[i].model,
            vehicles[i].brand,
            vehicles[i].year,
            vehicles[i].engineCapacity,
            vehicles[i].color,
            vehicles[i].fuelType,
            vehicles[i].seatCount);
    }

    fclose(fp);
}