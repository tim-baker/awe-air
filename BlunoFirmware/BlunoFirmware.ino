// Title:
//   IoT Mote Firmware v1.0 - Pink
// Target:
//   DFRobot Bluno V2.0
// Descripton:
//   Continually publish analog values in raw format over the serial
//     monitor from MQ-4 and MQ-7 gas sensors
//   A debug AT command set on the BLE chip sends all serial commands
//     over Bluetooth for interfacing with the RPi 2.
// Author(s):
//  Timothy Baker (11380666)

void setup()
{
  Serial.begin(115200); //Set serial baud rate to 115200 bps to match CC2540 baud rate
}
void loop()
{
int CO_val, CH4_val;

CO_val  = analogRead(0);     // Read carbon monoxide sensor from analog 0
CH4_val = analogRead(1);     // Read methane gas sensor from analog 1

// Transmit raw format
Serial.print("C");
Serial.println(CO_val, DEC);
Serial.print("M");
Serial.println(CH4_val, DEC);

delay(1000); // Poll the sensor every second
}