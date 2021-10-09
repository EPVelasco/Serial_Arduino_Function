
void setup() {
Serial.begin(115200);
}

void loop() {
   wait_init(&Serial,10);
  Serial.println("1.1,1.2,1.3,1.4,1.5,1.6");
  //Serial.println("2.1,2.2,2.3,2.4,2.5,2.6");  
  //Serial.println("3.1,3.2,3.3,3.4,3.5,3.6");
  delay(1);
}

void wait_init(HardwareSerial *port , int data_init){
  int inChar = data_init-1;
  while(inChar != data_init) inChar = port->read(); 
}
