#include "FreqMeasure.h"

void setup() {
  Serial.begin(9600);
  FreqMeasure.begin();
  
}

double sum = 0;
int count = 0;
float sinir = 0;

int test = 0;
void loop() {
  Serial.println(test);
  if (test == 1000){
    //Serial.println(test);
    test = 0;
  }
  else{
    test = test + 1;
  }
  //Serial.println("50");
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count += 1;
    if (sum > 100) {
      float frekans = FreqMeasure.countToFrequency(sum / count);
      float hiz = (frekans / 19.49);
      if (hiz > sinir) {
        //Serial.println("frekans");
        //Serial.println(frekans);
        Serial.println("hız");
        Serial.println(hiz);
        //      lcd.print(frekans/19.49);
        sum = 0;
        count = 0;
      }
    }
  }
}
