#include <mbed.h>

DigitalOut blue(LED_BLUE);

//Create Ticker called pit.
Ticker  pit;

/* Flash function will flash blue led on and off depending
On the phase. */
void flash(void) {
  // Set phase to 0
  static unsigned int phase=0;


  // Seminar 2 exercise
  if(phase==0) blue.write(0); // on
  if(phase==1) blue.write(1); // off
  if(phase==2) blue.write(0);
  if(phase==5) blue.write(1);
  if(phase==12) blue.write(0);
  phase++;
  if(phase==12) phase=0;

/*
  // Messing around with the timer
  if(phase==0) blue.write(0);
  if(phase==5) blue.write(1);
  if(phase==10) blue.write(0);
  if(phase==13) blue.write(1);
  if(phase==15) blue.write(0);
  if(phase==16) blue.write(0);
  if(phase==17) blue.write(1);
  phase++;
  if(phase==18) phase = 0;
*/

}

int main(void) {
  // Attach flash function with speed.
  pit.attach(flash,0.1);

  while(1);
}
