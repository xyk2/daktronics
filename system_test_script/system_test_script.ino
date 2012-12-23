void setup() {
  Serial.begin(19200);
}

void loop() {
  for(int x=0; x<5000; x++) {
	Serial.print("t");
        Serial.println(x*0.1);
        if(x == 33) Serial.println("s5 1 3.36 2"); 
        if(x == 45) Serial.println("s3 2 4.52 2"); 
        if(x == 65) Serial.println("s7 3 6.50 2"); 
        
        if(x == 150) Serial.println("s3 1 15.05 4"); 
        if(x == 165) Serial.println("s5 2 16.54 4"); 
        if(x == 166) Serial.println("s7 3 16.60 4");        
	delay(100);
  }
}
