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
// Demo arranged based on examples from the_synth library
// Gadget Reboot


#include <synth.h>

synth edgar;    //-Make a synth

void setup()
{

  edgar.begin();  //-Start it up

  //Set up a voice:
  //setupVoice( voice[0-3] , waveform[SINE,TRIANGLE,SQUARE,SAW,RAMP,NOISE] , pitch[0-127], envelope[ENVELOPE0-ENVELOPE3], length[0-127], mod[0-127, 64=no mod])

  edgar.setupVoice(0, SINE, 65, ENVELOPE1, 70, 64);
}

void loop()
{

  // voices demo - simple tones with snare or hi-hat hits
  edgar.setupVoice(0, SINE, 60, ENVELOPE1, 60, 64);
  edgar.setupVoice(1, RAMP, 0, ENVELOPE3, 64, 64);
  edgar.setupVoice(2, TRIANGLE, 0, ENVELOPE2 , 70, 64);
  edgar.setupVoice(3, NOISE, 0, ENVELOPE3, 20, 64);

  for (int i = 49; i < 57; i++)
  {
    edgar.mTrigger(0, i);
    edgar.mTrigger(1, i);
    delay(200);

    edgar.setLength(3, 30);
    edgar.mTrigger(3, i);
    delay(100);

    edgar.mTrigger(2, i);
    edgar.setLength(3, 20);
    edgar.mTrigger(3, i);
    delay(100);
  }

  // modulation demo - disco sounds
  edgar.setupVoice(0, SINE, 65, ENVELOPE1, 70, 64);
  for (int i = 30; i < 104; i += 10)
  {
    edgar.setMod(0, i);
    edgar.trigger(0);
    delay(200);
  }

  // random noise/effects/poly voices
  edgar.setupVoice(0, SINE, 60, ENVELOPE0, 90, 64);
  edgar.setupVoice(1, SAW, 62, ENVELOPE3, 90, 64);
  edgar.setupVoice(2, NOISE, 64, ENVELOPE2, 90, 64);
  edgar.setupVoice(3, SQUARE, 70, ENVELOPE0, 90, 64);

  edgar.trigger(2);
  delay(200);
  edgar.trigger(0);
  edgar.trigger(1);
  delay(1000);

  edgar.trigger(3);
  edgar.setupVoice(1, SAW, 58, ENVELOPE2, 90, 64);
  edgar.trigger(1);
  delay(1000);

  edgar.setupVoice(2, NOISE, 65, ENVELOPE1, 90, 64);
  edgar.trigger(2);
  delay(1000);

  edgar.setupVoice(0, NOISE, 57, ENVELOPE1, 90, 64);
  edgar.setupVoice(2, NOISE, 65, ENVELOPE1, 90, 64);
  edgar.trigger(0);
  edgar.trigger(2);
  delay(1000);

  edgar.setupVoice(0, NOISE, 59, ENVELOPE1, 90, 64);
  edgar.setupVoice(2, NOISE, 65, ENVELOPE1, 90, 64);
  edgar.trigger(0);
  edgar.trigger(2);
  delay(1000);

  edgar.setupVoice(0, SQUARE, 57, ENVELOPE2, 90, 64);
  edgar.setupVoice(1, SAW, 60, ENVELOPE3, 90, 64);
  edgar.trigger(0);
  edgar.trigger(1);
  delay(1000);

  edgar.setupVoice(0, NOISE, 71, ENVELOPE1, 90, 64);
  edgar.setupVoice(2, RAMP, 65, ENVELOPE1, 90, 64);
  edgar.trigger(0);
  edgar.trigger(2);
  delay(1000);

}
