#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vehicle.h"

void undoLastOperation() {
    
    int i;

    if (lastOperation == UNDO_NONE) {
        printf("\nNo operation to undo.\n");
        return;
    }

    if (lastOperation == UNDO_ADD) {
        count--;
        printf("\nLast add operation undone successfully.\n");
    }

    else if (lastOperation == UNDO_UPDATE) {
        vehicles[undoIndex] = undoVehicle;
        printf("\nLast update operation undone successfully.\n");
    }

    else if (lastOperation == UNDO_DELETE) {
        for (i = count; i > undoIndex; i--) 
            vehicles[i] = vehicles[i - 1];

        vehicles[undoIndex] = undoVehicle;
        count++;

        printf("\nLast delete operation undone successfully.\n");
        }

        lastOperation = UNDO_NONE;
        undoIndex = -1;
    
}