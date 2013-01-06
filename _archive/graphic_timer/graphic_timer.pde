import processing.serial.*;

PImage img;  // Declare variable "a" of type PImage
Serial myPort;    // The serial port
String inString = "";  // Input string from serial port
int lf = 02;      // ASCII linefeed
String oldString = "";
PFont font;

int _FONT_SIZE = 40; // font size in px
float _TEXT_X = 640;
float _TEXT_Y = 446;

void setup() {
  size(900,700);
  println(Serial.list());
  myPort = new Serial(this, "COM18", 19200);
  myPort.bufferUntil(lf); // newline at 0x02
  
  font = createFont("arialnbi.ttf", _FONT_SIZE);
  textFont(font, _FONT_SIZE);
  img = loadImage("swimming_timer_outer_small.png");  // Load the image into the program  


  textAlign(RIGHT, BOTTOM);
  textSize(_FONT_SIZE);
  background(0, 255, 33);
  text("0.0", _TEXT_X, _TEXT_Y); // placeholder text
  fill(0, 0, 0); // fill text black
  image(img, 500, 400);
}

void draw() {
  background(0, 255, 33);
  while(myPort.available() == 0) {
  }
  image(img, 500, 400);
  if(inString.length() < 9 && inString.indexOf(".") != -1) {
    text(inString, _TEXT_X, _TEXT_Y);
    oldString = inString;
    println(inString);
  } else { // FAILSAFE
    text(oldString, _TEXT_X, _TEXT_Y);
  }
 
  
}

void serialEvent(Serial p) {
  inString = (myPort.readString());
  if(inString.indexOf(".") != -1) {
      println(inString);
      inString = inString.substring(0, 8); // cut out first 8
      inString = inString.replace(" ", "");
      println("TIME: " + inString);
  }
}
