int redLed = 12;    //led rosu conectat la pinul 12  
int greenLed = 11;  //led verde conectat la pinul 11
int buzzer = 10;    //buzzer conectat la pin 10
int smokeA0 = A5;   //senzor gaze conectat la A5

int sensorActivation = 90;   //valoarea de la care senzorul se activeaza

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);   //realizeaza conexiunea seriala la 9600 biti/secunda
}

void loop() {
  int analogSensor = analogRead(smokeA0); //initializare citire analog a senzorului de gaze

  Serial.print("Pin A0: ");   //in serial monitor se printeaza
  Serial.println(analogSensor); //tot in serial monitor se printeaza nivelul gazului citit de senzor

 
  if (analogSensor > sensorActivation) //daca valoarea nivelului initial este mai mare decat valoarea minima de la care porneste alarma
  {
    digitalWrite(redLed, HIGH);         //se aprinde led rosu
    digitalWrite(greenLed, LOW);        //se stinge led verde
    alarm();                            //se apeleaza functia alarmei
  }
  else                                  //daca nu:    
  {
    digitalWrite(redLed, LOW);          //se stinge led rosu
    digitalWrite(greenLed, HIGH);       //se aprinde led verde
    
  }
  delay(100);                           
}
void alarm()  {
  tone(buzzer, 1000, 900);
  delay(500);
  tone(buzzer, 1200, 900);
  delay(500);
}
