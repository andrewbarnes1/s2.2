#include <mbed.h>

DigitalOut blue(LED_BLUE);

//Create Ticker called pit.
Ticker  pit;

/* Flash function will flash blue led on and off depending
On the phase. */
void flash(void) {
  // Set phase to 0
  static unsigned int phase=0;

  // On and Off pattern in seconds rather than ms
  if(phase==0) blue.write(0); // on
  if(phase==10) blue.write(1); // off
  if(phase==20) blue.write(0);
  if(phase==50) blue.write(1);
  if(phase==120) blue.write(0);
  phase++;

  if(phase==120) phase=0;

}

int main(void) {
  // Attach flash function with speed.
  pit.attach(flash,0.1);

  while(1);
}
