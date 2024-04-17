// SYNTHUX ACADEMY /////////////////////////////////////////
// TEMPLATE PROJECT FOR SIMPLE FIX BOARD AND DAISY SEED ////

////////////////////////////////////////////////////////////
//////////////////////// TESTING ///////////////////////////
// To test knobs uncomment:
// #define TEST_KNOBS

#include "simple-fix-daisy.h"

////////////////////////////////////////////////////////////
///////////////////// KNOBS & SWITCHES /////////////////////
static const int knob_a = A(S30);
static const int knob_b = A(S31);
static const int knob_c = A(S32);
static const int knob_d = A(S33);

///////////////////////////////////////////////////////////////
///////////////////// AUDIO CALLBACK //////////////////////////
void AudioCallback(float **in, float **out, size_t size) {
  for (size_t i = 0; i < size; i++) {
    out[0][i] = in[0][i];
    out[1][i] = in[1][i];
  }
}

///////////////////////////////////////////////////////////////
///////////////////// SETUP ///////////////////////////////////
void setup() {
  // SETUP DAISY
  DAISY.init(DAISY_SEED, AUDIO_SR_48K);
  auto sample_rate = DAISY.get_samplerate();

  // Testing code. Can be removed /////////////////////////////
  #if defined(TEST_KNOBS)
  Serial.begin(9600);
  #endif
  /////////////////////////////////////////////////////////////

  // initialize other modules here

  // BEGIN CALLBACK
  DAISY.begin(AudioCallback);
}

void loop() {
  //Process knob values 
  // auto knob_a_value = analogRead(knob_a);

  auto d = 4; //ms
  //Testing code. Can be renmoved //////////////////////////////////////////
  #ifdef TEST_KNOBS
  testKnobs();
  #endif
  #if defined(TEST_KNOBS)
  d = 100;
  #endif
  /////////////////////////////////////////////////////////////////////////
  delay(d);
}

#ifdef TEST_KNOBS
void testKnobs() {
  Serial.print("S30: ");
  Serial.print(analogRead(knob_a));
  Serial.print(" S31: ");
  Serial.print(analogRead(knob_b));
  Serial.print(" S32: ");
  Serial.print(analogRead(knob_c));
  Serial.print(" S33: ");
  Serial.print(analogRead(knob_d));
  Serial.println("");
}
#endif
