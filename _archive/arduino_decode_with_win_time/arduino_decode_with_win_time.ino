#define BUFFER_STRING_SIZE 40
String inputString = "";         // a string to hold incoming data
String oldString = "";
String winning_time = "";
int TOTAL_LAPS = 0;
boolean completedLapReceive = false;

String inputString_ONE = "";         // a string to hold incoming data
String oldString_ONE = "";
void setup() {
  Serial.begin(19200);
  inputString.reserve(BUFFER_STRING_SIZE);
  oldString.reserve(BUFFER_STRING_SIZE);
}

char rxbuffer[BUFFER_STRING_SIZE];
char checksum[BUFFER_STRING_SIZE];
char rxbuffer_ONE[BUFFER_STRING_SIZE];
String checksumString = "";         // a string to hold incoming data

void loop() {
  while (Serial.available()) {
    if(Serial.read() == 1) {
      if(Serial.readBytesUntil((char)2, checksum, BUFFER_STRING_SIZE)) { // if successful
        for(int x = 0; x < BUFFER_STRING_SIZE; x++) { // add chars to string
            if((int)checksum[x] != 0) checksumString += checksum[x]; // skip null values; add to string
        }
        if(checksumString == "0042100099") {
          memset(checksum,0, BUFFER_STRING_SIZE); 
          Serial.readBytesUntil((char)4, checksum, BUFFER_STRING_SIZE);
          //Serial.println(checksum);
          char *p = checksum;
          char temp[3];
          for(int x = 0; x < 4; x++) {
                String str = strtok_r(p, " ", &p); // delimiter is the space
                str.replace("F", "");
                str.replace("P", "");
                str.toCharArray(temp, 3);
                if((x == 2 || x == 3) && atoi(temp) != 0) { // laps
                  TOTAL_LAPS = atoi(temp);
                  //Serial.println(TOTAL_LAPS);
                }
                memset(temp,0, 3); 
          }
        }
        memset(checksum,0, BUFFER_STRING_SIZE); 
        checksumString = "";
        
        if(Serial.readBytesUntil((char)4, rxbuffer_ONE, BUFFER_STRING_SIZE)) {
          for(int x = 0; x < BUFFER_STRING_SIZE; x++) { // add chars to string
            if((int)rxbuffer_ONE[x] != 0) inputString_ONE += rxbuffer_ONE[x]; // skip null values; add to string
            //if(rxbuffer[x] == ' ') inputString += ' '; // add another space for >10:00.0 times
          }
          inputString_ONE.trim(); // remove leading and trailing whitespace
          
          char *p = rxbuffer_ONE;
  
        if(inputString_ONE.indexOf(".") != -1) { // if string does not include time, skip
          if(inputString_ONE.length() <= 7) {
            Serial.print("t"); // t for time
            Serial.println(inputString_ONE);
          }
          else if(oldString_ONE != inputString_ONE && inputString_ONE.indexOf((char)2) == -1) { // if split is different from last split transmission
            Serial.print("s"); // s for split
            //Serial.println(inputString_ONE.indexOf((char)2));
            Serial.println(inputString_ONE.substring(0,4) + ' ' + inputString_ONE.substring(4));
            for(int x = 0; x < 4; x++) {
              String str = strtok_r(p, " ", &p); // delimiter is the semicolon
              if(x == 3) { // laps
                if(str == String(TOTAL_LAPS)) Serial.println('w' + winning_time); //if matches finish race
              }
              if(x == 2) winning_time = str;
            }
            oldString_ONE = inputString_ONE;
          }
        } 

          //else if(inputString.indexOf(".") != -1) {
          // Serial.println(inputString); 
          //}
          inputString_ONE = "";
          memset(rxbuffer_ONE,0, BUFFER_STRING_SIZE); 
        }
      }
    }
  }
}

