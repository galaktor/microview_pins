#include <MicroView.h>

const int BOX_HEIGHT = 8;
const int BOX_WIDTH  = 8;

const int TOP = 0;
const int BOT = 47-BOX_HEIGHT;

/*     MV PIN           09  10  11  12  13  14  07  06  05  04  03  02    */
const int pins_ar[] = {  0,  1,  2,  3,  5,  6,  7,  8,  9, 10, 11, 12 }; // arduino pin nr
const int boxes_x[] = { 56, 48, 40, 32, 24, 16, 48, 40, 32, 24, 16,  8 }; // x coordinate for box
const int boxes_y[] = {  TOP,  TOP,  TOP,  TOP,  TOP,  TOP, BOT, BOT, BOT, BOT, BOT, BOT }; // y coordinate for box

void setup() {
    // set all pins to input
  for(int i=0; i<12; i++) {
      pinMode(pins_ar[i], INPUT);
  }  
  
  uView.begin();
  uView.clear(PAGE);
  
  // draw static pins
  uView.drawChar(0*BOX_WIDTH, TOP, 'V');
  uView.drawChar(1*BOX_WIDTH, TOP, '+');
  uView.drawChar(0*BOX_WIDTH, BOT, 'R');
  uView.drawChar(0*BOX_WIDTH, BOT-BOX_HEIGHT-2, 'A');
  uView.drawChar(7*BOX_WIDTH, BOT, '-');
  uView.display();
}

void loop() {
  delay(50);
  for(int i=0; i<12; i++) {
     // access above arrays to read and draw here 
     if(boxes_y[i] == TOP) {
       uView.setCursor(boxes_x[i], boxes_y[i]+BOX_HEIGHT+2);       
       uView.print(pins_ar[i]);
     } else {
       uView.setCursor(boxes_x[i], boxes_y[i]-BOX_HEIGHT-2);
       uView.print(pins_ar[i]-7);
     }
     if(digitalRead(pins_ar[i])) {
        // >0, therefore fill
        uView.rectFill(boxes_x[i], boxes_y[i], BOX_WIDTH, BOX_HEIGHT);
      } else {
        // 0, therefore empty
        uView.rect(boxes_x[i], boxes_y[i], BOX_WIDTH, BOX_HEIGHT);  
      }
  }   
   uView.display();
}

