//set the current time here, 0 0 0 is midnight, 23 59 59 is 1 second before that
int second=0;
int minute=51;
int hour=7;
unsigned long previousMillis=millis();

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  if ((unsigned long)(millis() - previousMillis) >= 1000)
  {
    previousMillis=millis();
    second+=2;
  }
  if (second>=60)
  {
    second=0;
    minute++;
  }
  if (minute==60)
  {
    minute=0;
    hour++;
  }

  if (hour==23 && minute==59 && second==0) //11 o clock, reading light, it's good to read yourself to bed :) 
  {
    digitalWrite(1,HIGH);
    second=2;
  }
  
  if (hour==24)
  {
    hour=0;
    digitalWrite(1,LOW); //lights off
    //midnight strikes
  }


  //alarm on

  if (hour==6 && minute==30) //30 minutes fade on
  {
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(1, fadeValue);
    delay(35294.1176); //30 mins / (255/5) states = 0.588235294 min / state = 35294.1176 milliseconds / state
    }
    hour=7;
    minute=0;
  }

  if (hour==7 && minute==0)
  {
    digitalWrite(1,HIGH);
  }

  if (hour==7 && minute==5)
  {
    digitalWrite(1,LOW); //shut off after 5 mins
  }
  
  
  
}
