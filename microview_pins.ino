#include <MicroView.h>

const int BOX_HEIGHT = 8;
const int BOX_WIDTH  = 8;

const int ROW_TOP = 0;
const int ROW_CTR = 23;
const int ROW_BTM = 47-BOX_HEIGHT;
const int COL_CTR = 32;

const int PIN_CNT=12;
const int ANALOG_OFFSET=14;

/*     MV PIN                       09       10       11       12       13       14       07       06       05       04       03       02    */
const int pins_ar[PIN_CNT] = {       0,       1,       2,       3,       5,       6,      A0,      A1,      A2,      A3,      A4,      A5 }; // arduino pin nr
const int boxes_x[PIN_CNT] = {      56,      48,      40,      32,      24,      16,      48,      40,      32,      24,      16,       8 }; // x coordinate for box
const int boxes_y[PIN_CNT] = { ROW_TOP, ROW_TOP, ROW_TOP, ROW_TOP, ROW_TOP, ROW_TOP, ROW_BTM, ROW_BTM, ROW_BTM, ROW_BTM, ROW_BTM, ROW_BTM }; // y coordinate for box

const int TXT_PAD_L=2;

void setup() {
    // set all pins to input
  for(int i=0; i<PIN_CNT; i++) {
      pinMode(pins_ar[i], INPUT);
  }  
  
  uView.begin();
  uView.clear(PAGE);
  
  // draw static pins
  uView.drawChar(0*BOX_WIDTH, ROW_TOP, 'V');
  uView.drawChar(1*BOX_WIDTH, ROW_TOP, '+');
  uView.drawChar(0*BOX_WIDTH, ROW_BTM, 'R');
  uView.drawChar(0*BOX_WIDTH, ROW_BTM-BOX_HEIGHT-2, 'A');
  uView.drawChar(7*BOX_WIDTH+2, ROW_BTM, '-');
  uView.display();
}

void loop() {
  delay(50);
  for(int i=0; i<PIN_CNT; i++) {
     // access above arrays to read and draw here 
     if(boxes_y[i] == ROW_TOP) {
       uView.setCursor(boxes_x[i]+TXT_PAD_L, boxes_y[i]+BOX_HEIGHT+2);       
       uView.print(pins_ar[i]);
     } else {
       uView.setCursor(boxes_x[i]+TXT_PAD_L, boxes_y[i]-BOX_HEIGHT-2);
       uView.print(pins_ar[i]-ANALOG_OFFSET);
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

