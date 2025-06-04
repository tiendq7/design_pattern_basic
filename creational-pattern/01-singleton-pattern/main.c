#include <stdio.h>
#include "sensor_manager.h"

int main(void) {
    SensorManager* m1 = sensor_manager_get_instance();
    SensorManager* m2 = sensor_manager_get_instance();

    if (m1 == m2) {
        printf("Singleton works! Same instance.\n");
    }

    sensor_manager_collect_data(m1);
    sensor_manager_collect_data(m2);
    sensor_manager_push_to_db(m1);

    sensor_manager_destroy();
    return 0;
}
