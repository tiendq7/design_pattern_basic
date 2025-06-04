#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct SensorManager SensorManager;

SensorManager* sensor_manager_get_instance(void);
void sensor_manager_collect_data(SensorManager* mgr);
void sensor_manager_push_to_db(SensorManager* mgr);
void sensor_manager_destroy(void);

#ifdef __cplusplus
}
#endif

#endif // SENSOR_MANAGER_H
