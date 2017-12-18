int iMoisture;
int iPump = 13;
int iCounter = 0;

long iWait = 6; //Wartezeit in H 
int const iThreshholdmoisture = 520; //Je niedriger desto Nasser!!

void setup() {
 
 pinMode(iPump,OUTPUT);
 iWait = iWait * 1000* 60 * 60; // Umrechnung ms -> h 
}

void loop() {
  
 iMoisture = analogRead(1);
 if (iMoisture >= iThreshholdmoisture) {
  digitalWrite(iPump, HIGH);
  iCounter++;
  if(iCounter > 600){
    digitalWrite(iPump, LOW);
    iCounter = 0;
    delay(iWait/2);
   } 
 }
 
 else if(iMoisture < iThreshholdmoisture) {
  digitalWrite(iPump, LOW);
  delay(iWait);
 }
 
 delay(1000); 
}
