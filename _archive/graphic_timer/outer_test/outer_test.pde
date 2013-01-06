/*PFont font;
int _FONT_SIZE = 120; // font size in px
float _TEXT_X = 475;
float _TEXT_Y = 190;
PImage img;  // Declare variable "a" of type PImage

void setup() {
  size(800,500);
  
  font = createFont("arialnbi.ttf", _FONT_SIZE);
  textFont(font, _FONT_SIZE);
  img = loadImage("swimming_timer_outer.png");  // Load the image into the program  
  
  textAlign(RIGHT, BOTTOM);
  textSize(_FONT_SIZE);
  fill(0, 0, 0); // fill text black
}

void draw() {
  background(0, 255, 33);
  image(img, 50, 50);
  text("11:34.5", _TEXT_X, _TEXT_Y);
} */

PFont font;
int _FONT_SIZE = 40; // font size in px
float _TEXT_X = 195;
float _TEXT_Y = 97;
PImage img;  // Declare variable "a" of type PImage

void setup() {
  size(1280,800);
  
  font = createFont("arialnbi.ttf", _FONT_SIZE);
  textFont(font, _FONT_SIZE);
  img = loadImage("swimming_timer_outer_small.png");  // Load the image into the program  
  
  textAlign(RIGHT, BOTTOM);
  textSize(_FONT_SIZE);
  fill(0, 0, 0); // fill text black
}

void draw() {
  background(0, 255, 33);
  image(img, 50, 50);
  text("11:34.5", _TEXT_X, _TEXT_Y);
}

