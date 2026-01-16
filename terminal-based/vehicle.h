#ifndef VEHICLE_H
#define VEHICLE_H

#define MAX 100

struct Vehicle {
    char id[10];
    char type[30];
    char model[50];
    char brand[50];
    int year;
    int engineCapacity;
    char color[20];
    char fuelType[20];
    int seatCount;
};

extern struct Vehicle vehicles[MAX];
extern int count;

void addVehicle();
void showVehicles();
void updateVehicle();
void deleteVehicle();
void searchVehicle();
void filterVehicle();
void summaryVehicle();

#endif
