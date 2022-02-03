#define Audio A0
#define Envelope A1

const float dBAnalogModerate = 12;
float maximum;
float calculateDecibels(float x){
  float decibelsCalculated = 20 * log10(x/dBAnalogModerate);
  return decibelsCalculated;
  
  }

void setup() {
  Serial.begin(9600);
}

void loop() {

 float envelopeNormalyze = 64;
 float normalValueDB = 59; //Normal sound in DB
  
 float audioValue = analogRead(Audio);
 float envelopeValue = analogRead(Envelope);
 envelopeNormalyze += calculateDecibels(envelopeValue);

 if(envelopeNormalyze>maximum){
  maximum = envelopeNormalyze;
  }
  else if(envelopeNormalyze<maximum){
    maximum == maximum;
    }
 
  Serial.print(normalValueDB);
  Serial.print(" "); 
  Serial.print(envelopeNormalyze);
  Serial.print(" ");
  Serial.println(maximum);

 delay(100);
}
