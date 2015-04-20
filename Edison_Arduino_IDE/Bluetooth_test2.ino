#define izq 4
#define der 5
#define up 6
#define dwn 7
#define TON 600
#define LIMITE 8

int derc=0;
int izqc=0;
int upc=0;
int dwnc=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  //pinMode(13, OUTPUT);
  pinMode(izq, OUTPUT);
  pinMode(der, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(dwn, OUTPUT);
  digitalWrite(izq, LOW); 
  digitalWrite(der, LOW); 
  digitalWrite(up, LOW); 
  digitalWrite(dwn, LOW); 

}

void loop() {
  // put your main code here, to run repeatedly:
// put your main code here, to run repeatedly:
   while(Serial.available())
    {
      char data=Serial.read();
      Serial.println(data);
      switch(data)
      {
 
        case 'R':{
          if (error_control (LIMITE, derc)== true){
            Serial.println("Right");
            digitalWrite(der, HIGH); 
            delay(TON); 
            digitalWrite(der, LOW); 
            derc++;
            izqc--;
          }
           break;
        }
        case 'L':{
          if (error_control (LIMITE, izqc)== true){
            Serial.println("Left");
            digitalWrite(izq, HIGH); 
            delay(TON); 
            digitalWrite(izq, LOW); 
            izqc++;
            derc--;
          }
          break;
        }
        case 'U':{
          if (error_control (LIMITE, upc)== true){
            Serial.println("Up");
            digitalWrite(up, HIGH); 
            delay(TON); 
            digitalWrite(up, LOW);
            upc++;
            dwnc--;
          }
          break;
        }
        case 'D':{
          if (error_control (LIMITE, dwnc)== true){
            Serial.println("Down");
            digitalWrite(dwn, HIGH);
            delay(TON); 
            digitalWrite(dwn, LOW);
            dwnc++;
            upc--;
          }
          break;
        }
        case 'S':{
          Serial.println("STOP");
          digitalWrite(up, LOW); 
          digitalWrite(dwn, LOW); 
          digitalWrite(der, LOW); 
          digitalWrite(izq, LOW); 
          break;
        }       
 
      }
   }
   delay(100);
   
}

bool error_control (int Limit, int conta){
  if (conta<Limit){return true;}
  else {return false;}
}
