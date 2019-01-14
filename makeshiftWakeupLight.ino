//set the current time here, 0 0 0 is midnight, 23 59 59 is 1 second before that
int second=0;
int minute=0;
int hour=0;
unsigned long previousMillis=millis();

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  if ((unsigned long)(millis() - previousMillis) >= 1000)
  {
    previousMillis=millis();
    second++;
  }
  if (second==60)
  {
    second=0;
    minute++;
  }
  if (minute==60)
  {
    minute=0;
    hour++;
  }

  if (hour==23 && minute==0) //11 o clock, reading light, it's good to read yourself to bed :) 
  {
    //fade it on
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) 
    {
    analogWrite(1, fadeValue);
    delay(30);
    }
  }
  
  if (hour==24)
  {
    hour=0;
    analogWrite(1,0); //lights off
    //midnight strikes
  }


  //alarm on

  if (hour==6 && minute==30) //30 minutes fade on
  {
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(1, fadeValue);
    delay(7058.8235); //30 mins / 255 states = 0.117647059 min / state = 7058.8235 milliseconds / state
    }
    hour=7;
    minute=0;
  }

  if (hour==7 && minute==0)
  {
    analogWrite(1, 255);
  }

  if (hour==7 && minute==5)
  {
    analogWrite(1, 0); //shut off after 5 mins
  }

  
  
}
