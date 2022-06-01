#include <Servo.h>
#define potBase A5
#define potGrip A4
#define potShoulder A3
#define potWrist A2
#define buttRec A1
#define buttPlay A0
Servo servoBase;
Servo servoShoulder;
Servo servoWrist;
Servo servoGrip;
int coBase = 0; 
int coGrip = 0; // 25 - 80 
int coShoulder = 0; 
int coWrist = 0; 
int coRec = 0; 
int coPlay = 0; 
void setup() {
 Serial.begin( 115200 );
 
 pinMode( potBase,INPUT );
 pinMode( potGrip,INPUT );
 pinMode( potShoulder,INPUT );
 pinMode( potWrist,INPUT );
 pinMode( buttRec,INPUT );
 pinMode( buttPlay,INPUT );
 servoBase.attach(9);
 servoShoulder.attach(6);
 servoWrist.attach(5);
 servoGrip.attach(3);
 coBase = 512;
 coShoulder = 85;
 coWrist = 52;
 coGrip = 25;
 moveServos();
 delay( 1000 );
}
void loop() {
 mapping();
 writeSerial();
 
 moveServos();
 delay( 15 );
}
void mapping() {
 coBase = map(analogRead( potBase ), 0, 1023, 0, 180);
 coShoulder = map(analogRead( potShoulder ), 0, 1023, 0, 180);
 coWrist = map(analogRead( potWrist ), 0, 1023, 0, 180);
 coGrip = map(analogRead( potGrip ), 0, 1023, 0, 180);
 if (coGrip <=25) coGrip = 25;
 if (coGrip >=80) coGrip = 80;
 
 if (analogRead( buttRec ) == 0 ) coRec = 0; else coRec = 1;
 if (analogRead( buttPlay ) == 0 ) coPlay = 0; else coPlay = 1;
}
void moveServos() {
 servoBase.write( coBase ); 
 servoShoulder.write( coShoulder ); 
 servoWrist.write( coWrist );
 servoGrip.write( coGrip ); 
}
void writeSerial() {
 Serial.print("\tB: "); Serial.print( coBase ); 
 Serial.print("\tG: "); Serial.print( coGrip ); 
 Serial.print("\tS: "); Serial.print( coShoulder ); 
 Serial.print("\tW: "); Serial.print( coWrist ); 
 Serial.print("\tR: "); Serial.print( coRec ); 
 Serial.print("\tP: "); Serial.print( coPlay );
 Serial.println();
}
