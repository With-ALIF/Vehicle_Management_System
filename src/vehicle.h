#ifndef VEHICLE_H
#define VEHICLE_H

#define MAX 100

#define UNDO_NONE   0
#define UNDO_ADD    1
#define UNDO_UPDATE 2
#define UNDO_DELETE 3

struct Vehicle
{
    char id[10];
    char type[30];
    char model[50];
    char brand[50];
    int year;
    int engineCapacity;

    char color[20];
    char fuelType[20];

    int seatCount;
    int gearCount;

    int batteryCapacity;
    int chargeTime;

    char routeNumber[20];
};

extern struct Vehicle vehicles[MAX];
extern int count;
extern int vehicleCounter;

extern int lastOperation;
extern struct Vehicle undoVehicle;
extern int undoIndex;

void addVehicle();
void showVehicles();
void updateVehicle();
void deleteVehicle();
void searchVehicle();
void filterVehicle();
void summaryVehicle();
void billingVehicle();
void undoLastOperation();

#endif