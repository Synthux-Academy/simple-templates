// SYNTHUX ACADEMY 
// TEMPLATE PROJECT FOR SIMPLE BOARD AND DAISY SEED

///////////////////////////////////////////////////////////////
///////////////////// LIBRARIES & HARDWARE ////////////////////
#include "simple-daisy.h"

///////////////////////////////////////////////////////////////
//////////////////////// PINS NOTE ////////////////////////////
// In order to get automatic suggestions of the pins compile 
// the project once after opening please. If you've soldered 
// the Daisy on the back of the board, please open simple-daisy.h 
// and uncomment '#define DAISY_IS_ON_THE_BACK'.

// To grab a pin capable of ADC, type A( and  press Ctr + Space 
// to bring the list of ADC capable pins.   
// To grab a digital pin type D( and press Ctr + Space to bring 
// the list of digital pins.

///////////////////////////////////////////////////////////////
///////////////////// AUDIO CALLBACK (PATCH) //////////////////
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

  // initialize modules here

  // BEGIN CALLBACK
  DAISY.begin(AudioCallback);
}

void loop() {
  // put your main code here, to run repeatedly:
}
