#include "sensors/door_sensor.h"
#include "sensors/smoke_sensor.h"
#include "subscribers/mobile_app_notifier.h"
#include "subscribers/alarm_system_controller.h"

#include <stdio.h>

int main() {
    // Initialize sensors (publishers)
    DoorSensor doorSensor;
    doorSensorInit(&doorSensor);

    SmokeSensor smokeSensor;
    smokeSensorInit(&smokeSensor);

    // Initialize subscribers
    MobileAppNotifier mobileApp;
    mobileAppNotifierInit(&mobileApp);

    AlarmSystemController alarmSystem;
    alarmSystemControllerInit(&alarmSystem);

    // Register subscribers to door sensor (publisher)
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&mobileApp);
    doorSensor.base.subscribe(&doorSensor.base, (Subscriber*)&alarmSystem);

    // Register subscribers to smoke sensor (publisher)
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&mobileApp);
    smokeSensor.base.subscribe(&smokeSensor.base, (Subscriber*)&alarmSystem);

    // Simulate events
    printf("== Simulate Door Open Event ==\n");
    doorSensorTrigger(&doorSensor, 1);

    // printf("\n== Simulate Smoke Detected Event ==\n");
    // smokeSensorTrigger(&smokeSensor, 1);

    return 0;
}
