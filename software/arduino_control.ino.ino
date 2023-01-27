
#include <SerialCommand.h>

int temp = 0;
int main1 = 16;
int main2 = 21;
int trigger1 = 22;
int trigger2 = 23;
int incoming = 0;
#define shockV 25
int shockonoff = 26;

SerialCommand sCmd;     // The demo SerialCommand object

void setup() {
  Serial.begin(115200);
  pinMode(main1,OUTPUT);
  pinMode(main2,OUTPUT);
  pinMode(trigger1,OUTPUT);
  pinMode(trigger2,OUTPUT);
  pinMode(shockV,OUTPUT);
  pinMode(shockonoff,OUTPUT);
  
  sCmd.addCommand("1",    main_on);
  sCmd.addCommand("2",    main_off);
  sCmd.addCommand("s", shock);
  }

void loop() {
  //if (Serial.available() > 0) {
  //  // read the incoming byte:
  //  incoming = Serial.read();
  //  temp = incoming - '0';
  // Serial.println(temp==1);
  //  Serial.println(atoi(incoming));
  //  }// end if

  //if (temp == 1){
  //  temp=0;
  sCmd.readSerial();     // We don't do much, just process serial commands
}

//callbacks
 void main_on(){
  Serial.println("odour on");  
  digitalWrite(main1,HIGH);
  digitalWrite(main2,HIGH);
  }

 void main_off(){
  Serial.println("odour off");  
  digitalWrite(main1,LOW);
  digitalWrite(main2,LOW);
  }

    void shock(){
  Serial.println("shock");  
  digitalWrite(shockonoff,HIGH);
  dacWrite(shockV, 180);
  delay(500);
  digitalWrite(shockonoff,LOW);
  }
