#include <Adafruit_NeoPixel.h>
#define NUM_PIXELS 43
//my lightstrip is 43 leds long, yours may vary
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, 6, NEO_GRB + NEO_KHZ800);
void setup() { 
  strip.begin();
  strip.show();
  randomSeed(analogRead(0));
}

void loop() {
  theaterMarquee(); //go through all light patterns
  colourMulti();
  thump();
  lump();
}
void colourMulti(){//affect that appears to spread 5 colours from the middle and then collapse in the same order.
  strip.clear();
  uint32_t colour1, colour2, colour3, colour4, colour5, colour6, colour7, colour8;
//make 8 random colours
colour1= randomColour();
colour2= randomColour();
colour2=colourCheck(colour1,colour2);
colour3= randomColour();
colour3=colourCheck(colour2,colour3);
colour4= randomColour();
colour4=colourCheck(colour3,colour4);
colour5= randomColour();
colour5=colourCheck(colour4,colour5);
colour6= randomColour();
colour6=colourCheck(colour5,colour6);
colour7= randomColour();
colour7=colourCheck(colour6,colour7);
colour8= 0;

int wait = 50;
strip.clear();
int nextDelay = (NUM_PIXELS/2)-10;

  for (int i=0; i<NUM_PIXELS+5*nextDelay;i++){
    if (i<=NUM_PIXELS){
    strip.setPixelColor((NUM_PIXELS/2)+i,colour1);
     strip.setPixelColor((NUM_PIXELS/2)-i,colour1);
     
    }
    if (i>=nextDelay&&i<=NUM_PIXELS+nextDelay){
      strip.setPixelColor((NUM_PIXELS/2)+(i-nextDelay),colour2);
     strip.setPixelColor((NUM_PIXELS/2)-(i-nextDelay),colour2);
     
      }
       if (i>=nextDelay*2&&i<=NUM_PIXELS+nextDelay*2){
      strip.setPixelColor((NUM_PIXELS/2)+(i-nextDelay*2),colour3);
     strip.setPixelColor((NUM_PIXELS/2)-(i-nextDelay*2),colour3);
     
      }
      if (i>=nextDelay*3&&i<=NUM_PIXELS+nextDelay*3){
      strip.setPixelColor((NUM_PIXELS/2)+(i-nextDelay*3),colour4);
     strip.setPixelColor((NUM_PIXELS/2)-(i-nextDelay*3),colour4);
     
      }
      if (i>=nextDelay*4&&i<=NUM_PIXELS+nextDelay*4){
      strip.setPixelColor((NUM_PIXELS/2)+(i-nextDelay*4),colour5);
     strip.setPixelColor((NUM_PIXELS/2)-(i-nextDelay*4),colour5);
     
      }
      
      if (i>=nextDelay*5&&i<=NUM_PIXELS+nextDelay*5){
      strip.setPixelColor((NUM_PIXELS/2)+(i-nextDelay*5),colour6);
     strip.setPixelColor((NUM_PIXELS/2)-(i-nextDelay*5),colour6);
     
      }
      if (i>=nextDelay*6&&i<=NUM_PIXELS+nextDelay*6){
      strip.setPixelColor((NUM_PIXELS/2)+(i-nextDelay*6),colour7);
     strip.setPixelColor((NUM_PIXELS/2)-(i-nextDelay*6),colour7);
     
      }
      if (i>=nextDelay*7&&i<=NUM_PIXELS+nextDelay*7){
      strip.setPixelColor((NUM_PIXELS/2)+(i-nextDelay*7),colour8);
     strip.setPixelColor((NUM_PIXELS/2)-(i-nextDelay*7),colour8);
     
      }
      strip.show();
     delay(wait);
  }
  }
void theaterMarquee() {//theatre marquee effect
  strip.clear();
uint32_t colour = randomColour();
int wait = 125;
for (int i = 0;i<30;i++){
  for (int a = 0; a<NUM_PIXELS;a+=3){
    if (a%2==0){
      strip.setPixelColor(a,colour);
      strip.setPixelColor(a+1,colour);
      strip.setPixelColor(a+2,colour);
      }
  }
      strip.show();
      delay(wait);
      strip.clear();

      for (int a = 0; a<NUM_PIXELS;a+=3){
    if (a%2>0){
      strip.setPixelColor(a,colour);
      strip.setPixelColor(a+1,colour);
      strip.setPixelColor(a+2,colour);
      }
    
    }
    strip.show();
    delay(wait);
    strip.clear();
  }
  
  
}

void thump(){//pulses the whole strip with 3 different colours in a row
  strip.clear();
  int mask =255;
 uint32_t colour1, colour2, colour3;
 int wait = 25;
 colour1=randomColour();
 colour2=randomColour();
 colour2=colourCheck(colour1,colour2);
 colour3=randomColour();
 colour3=colourCheck(colour2,colour3);
 int steps = 75;
 for (int i=0;i<NUM_PIXELS;i++){
  strip.setPixelColor(i,colour1);
  }
  strip.show();

  for (int i=0; i<steps;i++){
   
    for (int a =0;a<NUM_PIXELS;a++){
       strip.setPixelColor(a,map(i,steps,0,0,(colour1 >> 16)),map(i,steps,0,0,(mask&(colour1 >> 8))),map(i,steps,0,0,(mask&colour1))); 
      }
      strip.show();
 
    }
    for (int i=0;i<NUM_PIXELS;i++){
  strip.setPixelColor(i,colour2);
  }
  strip.show();

  for (int i=0; i<steps;i++){
   
    for (int a =0;a<NUM_PIXELS;a++){
       strip.setPixelColor(a,map(i,steps,0,0,(colour2 >> 16)),map(i,steps,0,0,(mask&(colour2 >> 8))),map(i,steps,0,0,(mask&colour2))); 
      }
      strip.show();
  }
 for (int i=0;i<NUM_PIXELS;i++){
  strip.setPixelColor(i,colour3);
  }
  strip.show();
  
  for (int i=0; i<steps;i++){
   
    for (int a =0;a<NUM_PIXELS;a++){
       strip.setPixelColor(a,map(i,steps,0,0,(colour3 >> 16)),map(i,steps,0,0,(mask&(colour3 >> 8))),map(i,steps,0,0,(mask&colour3))); 
      }
      strip.show();
 
    }
 
    
 
 
}
void lump(){//moves a "lump" of colour across the strip, a bit reminiscient of Kitt
  uint32_t colour;
  uint32_t colourAr[11];
  int mask = 255;
  
  for (int a =0;a<3;a++){
    colour = randomColour();
    colourAr[5]=colour;
  colourAr[4]=((map(5,0,6,0,(colour >> 16)))<<16)+((map(5,0,6,0,((colour >> 8)&mask)))<<8)+(map(5,0,6,0,(colour)&mask));
  colourAr[6]=((map(5,0,6,0,(colour >> 16)))<<16)+((map(5,0,6,0,((colour >> 8)&mask)))<<8)+(map(5,0,6,0,(colour)&mask));
  colourAr[3]=((map(4,0,6,0,(colour >> 16)))<<16)+((map(4,0,6,0,((colour >> 8)&mask)))<<8)+(map(4,0,6,0,(colour)&mask));
  colourAr[7]=((map(4,0,6,0,(colour >> 16)))<<16)+((map(4,0,6,0,((colour >> 8)&mask)))<<8)+(map(4,0,6,0,(colour)&mask));
  colourAr[2]=((map(3,0,6,0,(colour >> 16)))<<16)+((map(3,0,6,0,((colour >> 8)&mask)))<<8)+(map(3,0,6,0,(colour)&mask));
  colourAr[8]=((map(3,0,6,0,(colour >> 16)))<<16)+((map(3,0,6,0,((colour >> 8)&mask)))<<8)+(map(3,0,6,0,(colour)&mask));
  colourAr[1]=((map(2,0,6,0,(colour >> 16)))<<16)+((map(2,0,6,0,((colour >> 8)&mask)))<<8)+(map(2,0,6,0,(colour)&mask));
  colourAr[9]=((map(2,0,6,0,(colour >> 16)))<<16)+((map(2,0,6,0,((colour >> 8)&mask)))<<8)+(map(2,0,6,0,(colour)&mask));
  colourAr[0]=((map(1,0,6,0,(colour >> 16)))<<16)+((map(1,0,6,0,((colour >> 8)&mask)))<<8)+(map(1,0,6,0,(colour)&mask));
  colourAr[10]=((map(1,0,6,0,(colour >> 16)))<<16)+((map(1,0,6,0,((colour >> 8)&mask)))<<8)+(map(1,0,6,0,(colour)&mask));
  for (int i=0;i<NUM_PIXELS+20;i++){
    strip.clear();
    strip.setPixelColor(i-5,colourAr[5]);
    strip.setPixelColor(i-4,colourAr[4]);
    strip.setPixelColor(i-3,colourAr[3]);
    strip.setPixelColor(i-2,colourAr[2]);
    strip.setPixelColor(i-1,colourAr[1]);
    strip.setPixelColor(i,colourAr[0]);
    strip.setPixelColor(i-6,colourAr[6]);
    strip.setPixelColor(i-7,colourAr[7]);
    strip.setPixelColor(i-8,colourAr[8]);
    strip.setPixelColor(i-9,colourAr[9]);
    strip.setPixelColor(i-10,colourAr[10]);
    
    
      strip.show();
      delay(25);
    }
    
    for (int i=0;i<NUM_PIXELS+20;i++){
    strip.clear();
    strip.setPixelColor(NUM_PIXELS-i+5,colourAr[5]);
    strip.setPixelColor(NUM_PIXELS-i+4,colourAr[4]);
    strip.setPixelColor(NUM_PIXELS-i+3,colourAr[3]);
    strip.setPixelColor(NUM_PIXELS-i+2,colourAr[2]);
    strip.setPixelColor(NUM_PIXELS-i+1,colourAr[1]);
    strip.setPixelColor(NUM_PIXELS-i,colourAr[0]);
    strip.setPixelColor(NUM_PIXELS-i+6,colourAr[6]);
    strip.setPixelColor(NUM_PIXELS-i+7,colourAr[7]);
    strip.setPixelColor(NUM_PIXELS-i+8,colourAr[8]);
    strip.setPixelColor(NUM_PIXELS-i+9,colourAr[9]);
    strip.setPixelColor(NUM_PIXELS-i+10,colourAr[10]);
    
    
      strip.show();
      delay(25);
    }
    
  }
  }
uint32_t randomColour(){//picks a random colour
  uint32_t colour = Wheel(random(1,17)*15);
  return colour;
 }    

  uint32_t colourCheck(uint32_t colour1,uint32_t colour2){
    //checks if 2 colours are the same, if they are, gets a new random colour and checks again, and so forth
    //returns the second colour
    if (colour1 == colour2){
      colour2 = randomColour();
      colour2 = colourCheck(colour1,colour2);
      }
      return colour2;
    }
 uint32_t Wheel(byte WheelPos) {//takes position on a colour wheel and returns an RGB value (taken from Adafruit example code)
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}





