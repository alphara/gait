/*
You need libraries:
l3g-arduino-3.0.0
lsm-arduino-3.0.1
*/

#include <Wire.h>
#include <L3G.h>
#include <LSM303.h>

L3G gyro;
LSM303 compass;

char report[80];

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();

  compass.init();
  compass.enableDefault();
}

void loop() {
  gyro.read();
  compass.read();
  
  snprintf(report, sizeof(report),
    "{Gx: %d, Gy: %d, Gz: %d, Ax: %d, Ay: %d, Az: %d},",
    gyro.g.x, gyro.g.y, gyro.g.z,
    compass.a.x, compass.a.y, compass.a.z);
    
  Serial.println(report);
  delay(50);
}
