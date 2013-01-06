#define BUFFER_STRING_SIZE 50
String inputString = "";         // a string to hold incoming data
String oldString = "";
char rxbuffer[BUFFER_STRING_SIZE];

void setup() {
  UCSR0A = 1<<U2X0; // async
  UCSR0B = (1<<RXCIE0) | (1<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0); // enable RXTX, register interrupts
  UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); // 8 data bits
  UBRR0L = 103; // 19.2k baud

  DDRB |= (1<<PORTB0); // status LED output
  DDRB |= (0<<PORTB1); // split switch input  
  if((PINB & (1<<PORTB1))) {
    flash_status_led(4, 80);
    RUN_TEST_MODE();
    while(1) {}; // enter infinite loop
  }
  inputString.reserve(BUFFER_STRING_SIZE);
  oldString.reserve(BUFFER_STRING_SIZE);
}

void loop() {
  while(1) {
    while (Serial.available()) {
      if(Serial.read() == 2 && Serial.readBytesUntil((char)4, rxbuffer, BUFFER_STRING_SIZE)) {
          for(int x = 0; x < BUFFER_STRING_SIZE; x++) { // add chars to string
            if((int)rxbuffer[x] != 0) inputString += rxbuffer[x]; // skip null values; add to string
          }
          inputString.trim(); // remove leading and trailing whitespace
          if(inputString.indexOf(".") != -1) { // if string does not include time, skip
            if(inputString.length() <= 7) {
              Serial.print("t"); // t for time
              Serial.println(inputString);
            }
            else if((PINB & (1<<PORTB1)) == 0 && oldString != inputString) { // if split is different from last split transmission
              PORTB = (1<<PORTB0);
              Serial.print("s"); // s for split
              Serial.println(inputString.substring(0,4) + ' ' + inputString.substring(4));
              oldString = inputString;
              PORTB = (0<<PORTB0);
            }
          }
          inputString = "";
          memset(rxbuffer,0, BUFFER_STRING_SIZE); 
      }
    }
  }
}


void RUN_TEST_MODE(void) {
  for(unsigned int x=0; x<5000; x++) {
    Serial.print("t");
    Serial.println(x*0.1, 1);
    if(x == 33) Serial.println("s5 1 3.36 2"); 
    if(x == 45) Serial.println("s3 2 4.52 2"); 
    if(x == 65) Serial.println("s7 3 6.50 2"); 
    if(x == 150) Serial.println("s3 1 15.05 4"); 
    if(x == 165) Serial.println("s5 2 16.54 4"); 
    if(x == 166) Serial.println("s7 3 16.60 4");        
    delay(100);
  }
}

void flash_status_led(byte number_of_flashes, unsigned int milliseconds) {
  for(byte x = 0; x<number_of_flashes; x++) {
    PORTB = (1<<PORTB0);
    delay(milliseconds);
    PORTB = (0<<PORTB0);
    delay(milliseconds); 
  }
}



