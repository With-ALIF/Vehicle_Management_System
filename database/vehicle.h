#ifndef VEHICLE_H
#define VEHICLE_H

#define MAX 200

struct Vehicle
{
    char id[10];
    char type[20];
    char model[30];
    char brand[30];
    int year;
    int engineCapacity;
    char color[20];
    char fuelType[20];
    int seatCount;
};

extern struct Vehicle vehicles[];
extern int count;
extern int vehicleCounter;

void loadVehiclesFromFile();
void saveVehiclesToFile();

void addVehicle();
void deleteVehicle();
void updateVehicle();
void showVehicles();
void searchVehicle();
void summaryVehicle();
void filterVehicle();
void billingVehicle();

#endif