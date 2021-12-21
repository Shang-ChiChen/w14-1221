#include "pitches.h"

int freq = 2000;
int channel = 0;
int resolution = 8;

int melody[] = {
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_B4, NOTE_D5,
  NOTE_C5, NOTE_A4, 
  NOTE_C4, NOTE_E4, NOTE_A4, NOTE_B4,
  NOTE_E4, NOTE_GS4, NOTE_B4, NOTE_C5, NOTE_E4,
  
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_B4, NOTE_D5,
  NOTE_C5, NOTE_A4, 
  NOTE_C4, NOTE_E4, NOTE_A4, NOTE_B4,
  NOTE_E4, NOTE_C5, NOTE_B4, NOTE_A4, 
  
  
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4,
  4, 8/3,
  4, 4, 4, 8/3,
  4, 4, 4, 8/3, 4, 
  4, 4, 4, 4, 4, 4, 4,
  4, 8/3,
  4, 4, 4, 8/3,
  4, 4, 4, 8/5,
};

void setup() {
  Serial.begin(115200);
  pinMode(14,INPUT);
  pinMode(27,INPUT);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(25, channel);
}
int Mask = 0;
int NoMask = 0;
void loop() {
    for (int thisNote = 0; thisNote < 42; thisNote++) {
        Mask = digitalRead(14);
        NoMask = digitalRead(27);
            while(Mask == 0){
        ledcWriteTone(channel, 0);
        Mask = digitalRead(14);
        NoMask = digitalRead(27);
      }
        int noteDuration = 800 / noteDurations[thisNote];
        
        ledcWriteTone(channel, melody[thisNote]);
        
        delay(noteDuration);
        ledcWriteTone(channel, 0);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
  }
}
