#include <SoftwareServo.h> 
 
SoftwareServo myservo;  // create servo object to control a servo 
 
int aperto = 0;   //variabile per switch case per aprire o chiudere i cassetti
int sn = 0;    //porte sono già aperte o chiuse? 0 = chiuse / 1 = perla / 2 = tigre
int motore = 90;  //giro del servo che all'inizio viene impostato a neutro
const int limite = 600;
int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int peso;     // the analog reading from the FSR resistor divider
int pos = 0;
int posizione = 0;

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
 peso = analogRead(fsrPin);

//scelta della gatta in base al peso
  if (peso <= 100) {
    aperto = 0;    //nessuna gatta sulla bilancia
  } else if (peso <= limite) {
    aperto = 1;    //perla sulla bilancia 
  } else {
    aperto = 2;    //tigre sulla bilancia
  }
  
//in base alla gatta apro o chiudo o non faccio nulla se già aperto
  switch (aperto) {
  case 0:    //nessuna gatta sulla bilancia
    myservo.write(90);
    //delay(15);
    SoftwareServo::refresh();
    break;  
  
  case 1:    //parte perla
    myservo.write(135);   
    //delay(15);
    SoftwareServo::refresh();
    break;
  
  case 2:    //parte tigre
    myservo.write(45);   
    //delay(15);
    SoftwareServo::refresh();
    break;
  } 
  
  delay(150);
}
