#define Audio A0
#define Envelope A1

const double dBAnalogModerate = 12;
float calculateDecibels(float x){
  float decibelsCalculated = 20 * log10(x/dBAnalogModerate);
  return decibelsCalculated;
  
  }

void setup() {
  Serial.begin(9600);
}

void loop() {

 float envelopeNormalyze = 58;
  
 float audioValue = analogRead(Audio);
 float envelopeValue = analogRead(Envelope);
 envelopeNormalyze += calculateDecibels(envelopeValue);
 Serial.print("Envelope: ");
 Serial.println(envelopeNormalyze);
 delay(50);
}
