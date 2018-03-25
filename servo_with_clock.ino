
#include <Wire.h>

#include <DS3231.h>
#include <Servo.h>
Servo servoMain; // Define our Servo
// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
// Init a Time-data structure
Time  t;
void setup()
{
  servoMain.attach(3); // servo on digital pin 3
  servoMain.write(75);  // Turn Servo back to center position (90 degrees)
  delay(1000);          // Wait 1 second
  // Setup Serial connection
  Serial.begin(115200);
  // Initialize the rtc object
  rtc.begin();
  // The following lines can be uncommented to set the date and time
  /*rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(14, 34, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(17, 12, 2017);   // Set the date to DD/MM/YYYY
*/
}
void loop()
{
  t = rtc.getTime();   // Get data from the DS3231
  // Send date over serial connection
  Serial.print("Date: ");
  Serial.print(t.date, DEC);
  Serial.print("/");
  Serial.print(t.mon, DEC);
  Serial.print("/");
  Serial.print(t.year, DEC);
  Serial.println();

  // Send Day-of-Week and time
  Serial.print("Day of Week: ");
  Serial.print(t.dow, DEC);
  Serial.println();
  Serial.print("Time: ");
  Serial.print(t.hour, DEC);
  Serial.print(":");
  Serial.print(t.min, DEC);
  Serial.print(":");
  Serial.print(t.sec, DEC);
  Serial.println();
  Serial.println("--------------------------------");
  delay(1000); //Delay is for displaying the time in 1 second interval.
if (t.hour == 7 && t.min == 0 && t.sec == 0) 
//Setting alarm/timer at every 2:32:53pm, 
//in other words you can insert t.dow for every Thursday?, t.date for specific date?
  { 
    //lampa på
   servoMain.write(120);  // Turn Servo Left to 45 degrees
   delay(1000);          // Wait 1 second; 
   servoMain.write(75);  // Turn Servo back to center position (90 degrees)
   delay(1000);          // Wait 1 second
   delay(5000);
  }
if (t.hour == 23 && t.min == 0 && t.sec == 0) 
  { 
    //lampa av
   servoMain.write(35);  // Turn Servo Left to 45 degrees
   delay(1000);          // Wait 1 second; 
   servoMain.write(75);  // Turn Servo back to center position (90 degrees)
   delay(1000);          // Wait 1 second
   delay(5000);
  }
  

}
