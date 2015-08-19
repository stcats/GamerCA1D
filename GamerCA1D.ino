#include <Gamer.h>
#define w 8
#define h 8

Gamer gamer;
int response[] =  {0, 1, 1, 1, 0, 1, 1, 0};//rule 110
int row;
int editing = 0;
long now,cnow,cdelay = 100;//current time and delay
int cx,cstate;//cursor x position,cursor state

void setup(){
  gamer.begin();  
  reset();
}
void reset(){
  gamer.setLED(0);
  gamer.allOn();
  gamer.display[0][0] = 0;
  gamer.updateDisplay();
  row = 1;
}
void randomize(){
//  randomSeed(analogRead(A0));
  for(int i = 0 ; i < w; i++) response[i] = (random(1000) > 500);
  reset();
}
void loop(){
  now = millis();
  if(gamer.isPressed(UP)) editing = !editing;//toggle editing
  if(gamer.isPressed(DOWN)) {reset();editing = false;}//reset, force quite editor
  if(editing){//editor
    if(gamer.isPressed(LEFT) && cx > 0)    cx--;//left/right keys to move cursor
    if(gamer.isPressed(RIGHT) && cx < w-1) cx++;
    if(gamer.isPressed(START)) response[cx] = 1-response[cx];//start to toggle the current CA response bit
    gamer.clear();
    if(now - cnow >= cdelay){//blink cursor
      cstate = 1-cstate;
      cnow = now;
    }
    for(int i = 0 ; i < w; i++) {
      gamer.display[i][0] = response[i];//display CA response rule
      gamer.display[cx][0] = cstate;    //overlay cursor
    }
    gamer.setLED(response[cx]);//feedback on current state of bit under the cursor
  }else{
    if(gamer.isPressed(START)) randomize();
    if(row <= h){
      for(int i = 0 ; i < w; i++){
        int a = gamer.display[(i+w-1)%w][row-1];
        int b = gamer.display[i        ][row-1];
        int c = gamer.display[(i+w+1)%w][row-1];
        int number = 0;
        if(a == 0) number++;
        if(b == 0) number+=2;
        if(c == 0) number+=4;
        if(response[number] == 1) gamer.display[i][row] = 0;
      }
      row++;
    }
  }
  gamer.updateDisplay();
  delay(40);
}
