#include "FreqMeasure.h"

void setup() {
  Serial.begin(9600);
  FreqMeasure.begin();
}

double sum = 0;
int count = 0;
int total_sum = 30;

void loop() {
  if (FreqMeasure.available()) {
    sum = sum + FreqMeasure.read();
    count += 1;
    if (sum > total_sum) {
      float frekans = FreqMeasure.countToFrequency(sum / count);
      float hiz = (frekans / 19.49);
      //Serial.println("hız");
      Serial.println(hiz);
      sum = 0;
      count = 0;
    }
  }
}
