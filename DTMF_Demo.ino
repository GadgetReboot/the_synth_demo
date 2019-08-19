// Arduino synth library modulation example
// Library by DZL:  https://github.com/dzlonline/the_synth
//
// Arduino Uno Hardware Connections:
//
//                        +10µF
// PIN 11 ---[ 1kohm ]--+---||--->> Audio out
//                      |
//                     === 10nF
//                      |
//                     GND
//
// This demo uses the_synth library to generate two simultaneous tones
// in frequency pairs that represent various DTMF combinations including
// North American touch tone keypad tones and other call progress tones.
//
//     DTMF keypad frequencies
//             1209Hz 1336Hz 1477Hz 1633Hz
//      697Hz    1      2      3      A
//      770Hz    4      5      6      B
//      852Hz    7      8      9      C
//      941Hz    *      0      #      D
//
//  Gadget Reboot



#include <synth.h>

synth edgar;    //-Make a synth

int keypressDelay   = 200;  // delay in mS to hold down a touch tone key
int keyReleaseDelay = 500;  // delay in mS to remain silent after a key has been released

void setup() {

  edgar.begin();                                   //-Start it up
  edgar.setupVoice(0, TRIANGLE, 60, ENVELOPE1, 127, 64); //-Set up voice 0
  edgar.setupVoice(1, TRIANGLE, 60, ENVELOPE1, 127, 64); //-Set up voice 1
  edgar.setupVoice(2, TRIANGLE, 60, ENVELOPE1, 127, 64); //-Set up voice 2
  edgar.setupVoice(3, TRIANGLE, 60, ENVELOPE1, 127, 64); //-Set up voice 3
}

void loop()
{
  // dial tone 350Hz + 440Hz
  dialTone(1500);  // play dial tone for 1.5 seconds
  delay(500);

  // call Jenny
  callJenny();
  delay(500);

  // busy tone 480Hz + 620Hz, 0.5s on, 0.5s off
  busyTone(4);  // play four busy tone cycles
  delay(200);

  // dial tone 350Hz + 440Hz
  dialTone(1500);  // play dial tone for 1.5 seconds
  delay(500);

  // call Jenny
  callJenny();
  delay(500);

  // ring tone 440Hz + 480Hz, 2s on, 4s off
  ringTone(2);  // play two ring tone cycles

  // off-hook tone 1400Hz + 2060Hz + 2450Hz + 2600Hz, 0.1s on, 0.1s off
  offHookTone(18);  // play twelve off hook tone cycles


  /*

    // cycle through touch tone keypad
    keypressDelay   = 200;  // delay in mS to hold down a touch tone key
    keyReleaseDelay = 200;  // delay in mS to remain silent after a key has been released
    oneTone(keypressDelay);
    delay(keyReleaseDelay);
    twoTone(keypressDelay);
    delay(keyReleaseDelay);
    threeTone(keypressDelay);
    delay(keyReleaseDelay);
    aTone(keypressDelay);
    delay(keyReleaseDelay);
    fourTone(keypressDelay);
    delay(keyReleaseDelay);
    fiveTone(keypressDelay);
    delay(keyReleaseDelay);
    sixTone(keypressDelay);
    delay(keyReleaseDelay);
    bTone(keypressDelay);
    delay(keyReleaseDelay);
    sevenTone(keypressDelay);
    delay(keyReleaseDelay);
    eightTone(keypressDelay);
    delay(keyReleaseDelay);
    nineTone(keypressDelay);
    delay(keyReleaseDelay);
    cTone(keypressDelay);
    delay(keyReleaseDelay);
    starTone(keypressDelay);
    delay(keyReleaseDelay);
    zeroTone(keypressDelay);
    delay(keyReleaseDelay);
    poundTone(keypressDelay);
    delay(keyReleaseDelay);
    dTone(keypressDelay);
    delay(keyReleaseDelay);
  */

}

// "1" tone 1209Hz + 697Hz
void oneTone(int onTime) {

  edgar.setFrequency(0, 1209.0);
  edgar.setFrequency(1, 697.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "2" tone 1336Hz + 697Hz
void twoTone(int onTime) {

  edgar.setFrequency(0, 1336.0);
  edgar.setFrequency(1, 697.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "3" tone 1477Hz + 697Hz
void threeTone(int onTime) {

  edgar.setFrequency(0, 1477.0);
  edgar.setFrequency(1, 697.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "4" tone 1209Hz + 770Hz
void fourTone(int onTime) {

  edgar.setFrequency(0, 1209.0);
  edgar.setFrequency(1, 770.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "5" tone 1336Hz + 770Hz
void fiveTone(int onTime) {

  edgar.setFrequency(0, 1336.0);
  edgar.setFrequency(1, 770.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "6" tone 1477Hz + 770Hz
void sixTone(int onTime) {

  edgar.setFrequency(0, 1477.0);
  edgar.setFrequency(1, 770.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "7" tone 1209Hz + 852Hz
void sevenTone(int onTime) {

  edgar.setFrequency(0, 1209.0);
  edgar.setFrequency(1, 852.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "8" tone 1336Hz + 852Hz
void eightTone(int onTime) {

  edgar.setFrequency(0, 1336.0);
  edgar.setFrequency(1, 852.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "9" tone 1477Hz + 852Hz
void nineTone(int onTime) {

  edgar.setFrequency(0, 1477.0);
  edgar.setFrequency(1, 852.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "0" tone 1336Hz + 941Hz
void zeroTone(int onTime) {

  edgar.setFrequency(0, 1336.0);
  edgar.setFrequency(1, 941.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "Star" tone 1209Hz + 941Hz
void starTone(int onTime) {

  edgar.setFrequency(0, 1209.0);
  edgar.setFrequency(1, 941.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "#" tone 1477Hz + 941Hz
void poundTone(int onTime) {

  edgar.setFrequency(0, 1477.0);
  edgar.setFrequency(1, 941.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "A" tone 1633Hz + 697Hz
void aTone(int onTime) {

  edgar.setFrequency(0, 1633.0);
  edgar.setFrequency(1, 697.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "B" tone 1633Hz + 770Hz
void bTone(int onTime) {

  edgar.setFrequency(0, 1633.0);
  edgar.setFrequency(1, 770.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "C" tone 1633Hz + 852Hz
void cTone(int onTime) {

  edgar.setFrequency(0, 1633.0);
  edgar.setFrequency(1, 852.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// "D" tone 1633Hz + 941Hz
void dTone(int onTime) {

  edgar.setFrequency(0, 1633.0);
  edgar.setFrequency(1, 941.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// dial tone 350Hz + 440Hz
void dialTone(int onTime) {

  edgar.setFrequency(0, 440.0);
  edgar.setFrequency(1, 350.0);
  edgar.trigger(0);
  edgar.trigger(1);

  // if onTime=0 the sound continuously plays until another sound is commanded elsewhere
  // if onTime>0 the sound plays for the duration in mS
  if (onTime > 0) {
    delay(onTime);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
  }
}

// ring tone 440Hz + 480Hz, 2s on, 4s off
void ringTone(int cycles) {

  for (int i = 0; i < cycles; i++) {
    edgar.setFrequency(0, 440.0);
    edgar.setFrequency(1, 480.0);
    edgar.trigger(0);
    edgar.trigger(1);
    delay(2000);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
    delay(4000);
  }
}

// busy tone 480Hz + 620Hz, 0.5s on, 0.5s off
void busyTone(int cycles) {

  for (int i = 0; i < cycles; i++) {
    edgar.setFrequency(0, 480.0);
    edgar.setFrequency(1, 620.0);
    edgar.trigger(0);
    edgar.trigger(1);
    delay(500);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
    delay(500);
  }
}

// off-hook tone 1400Hz + 2060Hz + 2450Hz + 2600Hz, 0.1s on, 0.1s off
void offHookTone(int cycles) {

  for (int i = 0; i < cycles; i++) {
    edgar.setFrequency(0, 1400.0);
    edgar.setFrequency(1, 2060.0);
    edgar.setFrequency(2, 2450.0);
    edgar.setFrequency(3, 2600.0);
    edgar.trigger(0);
    edgar.trigger(1);
    edgar.trigger(2);
    edgar.trigger(3);
    delay(100);
    edgar.setFrequency(0, 0);
    edgar.setFrequency(1, 0);
    edgar.setFrequency(2, 0);
    edgar.setFrequency(3, 0);
    delay(100);
  }
}

// call Jenny
void callJenny() {
  keypressDelay = 100;    // delay in mS to hold down a touch tone key
  keyReleaseDelay = 100;  // delay in mS to remain silent after a key has been released

  eightTone(keypressDelay);
  delay(keyReleaseDelay);
  sixTone(keypressDelay);
  delay(keyReleaseDelay);
  sevenTone(keypressDelay);
  delay(keyReleaseDelay);

  fiveTone(keypressDelay);
  delay(keyReleaseDelay);
  threeTone(keypressDelay);
  delay(keyReleaseDelay);
  zeroTone(keypressDelay);
  delay(keyReleaseDelay);
  nineTone(keypressDelay);
  delay(keyReleaseDelay);
}
