// Title:
//   IoT Mote Firmware v1.1 - Pink
// Target:
//   DFRobot Bluno V2.0
// Descripton:
//   Continually publish analog values in JSON format over the serial
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

// Transmit JSON format for both sensors
Serial.println("{");
Serial.println("    \"AweAirMote 1.0\": {");
Serial.println("        \"CarbonMonoxide\": {");
Serial.println("            \"id\": 0,");
Serial.println("            \"nick\": \"CO\",");
Serial.print("            \"value\": ");
Serial.println(CO_val, DEC);
Serial.println("        },");
Serial.println("        \"Methane\": {");
Serial.println("            \"id\": 1,");
Serial.println("            \"nick\": \"CH4\",");
Serial.print("            \"value\": ");
Serial.println(CH4_val, DEC);
Serial.println("        }");
Serial.println("    }");
Serial.println("}");

delay(1000); // Poll the sensor every second
}
