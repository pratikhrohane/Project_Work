/***Home Automation***/

//MQ6 GAS SENSOR
int gas = 2;
int gasout = 8;

//PIR
int pir = 3;
int pirout = 9;

//LDR
int ldr = A0;
int ldrout = 10;

//Fan
int fan = 11;

//Bulb
int bulb = 12;

void setup()
{
  Serial.begin(9600);
  
  pinMode( gas,INPUT);
  pinMode (gasout,OUTPUT);  
  pinMode(ldr,INPUT);
  pinMode (ldrout,OUTPUT);
  pinMode(pir,INPUT);
  pinMode (pirout,OUTPUT);
  
  pinMode (fan,OUTPUT);
  pinMode (bulb,OUTPUT);
 
}
void ldrAction()
{
  int ldr_val = analogRead(ldr);
  if (ldr_val>500){
    digitalWrite(ldrout,HIGH);   //TURN ON LAMP
  }
  else{
  digitalWrite (ldrout,LOW);
  }
}
void pirAction()
{
  int pir_val = digitalRead(ldr);
  if (pir_val == HIGH){
    digitalWrite(pirout,HIGH);   //TURN ON STARECASE LIGHT
  }
  else{
  digitalWrite (pirout, LOW);
  }
}
void gasAction()
{
  int gas_val = digitalRead(ldr);
  if (gas_val == HIGH){
    digitalWrite(gasout,HIGH);   //TURN ON BUZZER
  }
  else{
  digitalWrite (gasout,LOW);
  }
}
void mobileControl(){
  if (Serial.available() > 1){
    int data = Serial.read();

    if( data == 51){
      digitalWrite(fan, HIGH);
    }
    else{
      digitalWrite(fan, LOW);
    }
    if( data == 53){
      digitalWrite(bulb, HIGH);
    }
    else{
    digitalWrite(bulb, LOW);
    }
    if( data == 55){
      digitalWrite(pirout, HIGH);
    }
    else{
      digitalWrite(pirout, LOW);
    }
    if(data == 57){
      digitalWrite(ldrout, HIGH);
    }
    else{
      digitalWrite(ldrout, LOW);
    }
    
  }
}
void loop()
{
  ldrAction();
  pirAction();
  gasAction();
  mobileControl();
}
  
