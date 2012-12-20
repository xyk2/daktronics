String inputString = "";         // a string to hold incoming data
int inByte;


void setup() {
  Serial.begin(19200);
}

char rxbuffer[50];

void loop() {
  while (Serial.available()) {
    if(Serial.read() == 2) {
      if(Serial.readBytesUntil((char)4, rxbuffer, 100)) {
        //Serial.println(rxbuffer);
        for(int x = 0; x < sizeof(rxbuffer); x++) {
          if((int)rxbuffer[x] != 0) inputString += rxbuffer[x];
        }
        inputString.trim();
        
        if(inputString.indexOf(".") != -1) {
          if(inputString.length() <= 7) Serial.print("t"); // t for time
          else Serial.print("s"); // s for split
          
          Serial.println(inputString);
        }
        
        
        inputString = "";
        memset(rxbuffer,0,sizeof(rxbuffer));
      }
    }
  }
}

