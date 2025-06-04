#include <stdio.h>
#include <stdlib.h>
#include "sensor_manager.h"

struct SensorManager {
    int sensor_count;
};

static SensorManager* instance = NULL;

SensorManager* sensor_manager_get_instance(void) {
    if (!instance) {
        instance = (SensorManager*)malloc(sizeof(SensorManager));
        if (instance) {
            instance->sensor_count = 0;
            printf("[INIT] SensorManager created.\n");
        }
    }
    return instance;
}

void sensor_manager_collect_data(SensorManager* mgr) {
    if (!mgr) return;
    mgr->sensor_count++;
    printf("[COLLECT] Data collected from sensor #%d.\n", mgr->sensor_count);
}

void sensor_manager_push_to_db(SensorManager* mgr) {
    if (!mgr) return;
    printf("[DB] Pushing %d records to database.\n", mgr->sensor_count);
}

void sensor_manager_destroy(void) {
    if (instance) {
        printf("[DESTROY] SensorManager destroyed.\n");
        free(instance);
        instance = NULL;
    }
}
