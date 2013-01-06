#define BUFFER_STRING_SIZE 50
String inputString = "";         // a string to hold incoming data
String oldString = "";
String winning_time = "";
byte TOTAL_LAPS = 10;

void setup() {
  //Serial.begin(19200);
  inputString.reserve(BUFFER_STRING_SIZE);
  oldString.reserve(BUFFER_STRING_SIZE);
  UCSR0A = 1<<U2X0; // async
  UCSR0B = (1<<RXCIE0) | (1<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0);
  UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); // 8 data bits
  //UBRR0L = 103;
  
  Serial.println("Serial Ports Registers");
  Serial.println("----------------------");
  Serial.print("UCSR0A: ");
  Serial.println(UCSR0A,BIN);
  Serial.print("UCSR0B: ");
  Serial.println(UCSR0B,BIN);
  Serial.print("UCSR0C: ");
  Serial.println(UCSR0C,BIN);
  Serial.print("UBRR0H: ");
  Serial.println(UBRR0H,BIN);
  Serial.print("UBRR0L: ");
  Serial.println(UBRR0L,BIN);
}

char rxbuffer[BUFFER_STRING_SIZE];

void loop() {
      //Serial.println(!(UCSR0A & (1<<RXC0)));
    //  Serial.println(Serial.available());
 // delay(100);
  /*while (Serial.available()) {
    if(Serial.read() == 2) {
      if(Serial.readBytesUntil((char)4, rxbuffer, BUFFER_STRING_SIZE)) { // if successful
        for(int x = 0; x < BUFFER_STRING_SIZE; x++) { // add chars to string
          if((int)rxbuffer[x] != 0) inputString += rxbuffer[x]; // skip null values; add to string
          //if(rxbuffer[x] == ' ') inputString += ' '; // add another space for >10:00.0 times
        }
        inputString.trim(); // remove leading and trailing whitespace
        
        char *p = rxbuffer;

        if(inputString.indexOf(".") != -1) { // if string does not include time, skip
          if(inputString.length() <= 7) {
            Serial.print("t"); // t for time
            Serial.println(inputString);
          }
          else if(oldString != inputString) { // if split is different from last split transmission
            Serial.print("s"); // s for split
            Serial.println(inputString.substring(0,4) + ' ' + inputString.substring(4));
            for(int x = 0; x < 4; x++) {
              String str = strtok_r(p, " ", &p); // delimiter is the semicolon
              if(x == 3) { // laps
                if(str == String(TOTAL_LAPS)) Serial.println('w' + winning_time); //if matches finish race
              }
              if(x == 2) winning_time = str;
            }
            oldString = inputString;
          }
          
          
        }
        
        
        inputString = "";
        memset(rxbuffer,0, BUFFER_STRING_SIZE); 
      }
    }
  }*/
}




