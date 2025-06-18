const int relayPin = 4;        
const int soilSensorPin = 12;  
const int ledPin = 7;          
const int ldrSensorPin = A0;  

const int moistureThreshold = 1; 
const int lightThreshold = 500;  

void kontrolPompa(int durasi) {
  digitalWrite(relayPin, HIGH);  
  delay(3000);                
  digitalWrite(relayPin, LOW);   
}

void setup() {
  pinMode(relayPin, OUTPUT);       
  pinMode(soilSensorPin, INPUT);   
  pinMode(ledPin, OUTPUT);        

  digitalWrite(relayPin, LOW);     
  digitalWrite(ledPin, LOW);       

  Serial.begin(9600);
}

void loop() {
  pengecekanSensorKelembapan();

  pengecekanSensorLDR();
}

void pengecekanSensorKelembapan() {
  while (digitalRead(soilSensorPin) == HIGH) { 
    Serial.println("Tanah kering, menyemprot...");
    kontrolPompa(3000); 
    delay(5000);    
  }
  Serial.println("Tanah basah, pompa berhenti.");
}

void pengecekanSensorLDR() {
  int ldrValue = analogRead(ldrSensorPin); 

  Serial.print("Nilai LDR: ");
  Serial.println(ldrValue);

  if (ldrValue > lightThreshold) {        
    digitalWrite(ledPin, HIGH);           
  } else {                                
    digitalWrite(ledPin, LOW);            
  }
}
