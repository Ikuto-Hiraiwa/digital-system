
#include "LiquidCrystal.h"
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

const int SW_1 = 5;
int button_1;
int val1;
const int SW_2 = 6;
int button_2;
int val2;
const int SW_3 = 7;
int button_3;
int val3;
const int SW_4 = 4;
int button_4;
int val4=1;
const int LED4 = 3;

const int LED1 = 14;
const int LED2 = 15;
const int LED3 = 16;

int LED_flag=0;

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD
  pinMode(SW_1,INPUT);
  button_1 = digitalRead(SW_1);
  pinMode(SW_2,INPUT);
  button_2 = digitalRead(SW_2);
  pinMode(SW_3,INPUT);
  button_3 = digitalRead(SW_3);
  pinMode(SW_4,INPUT);
  val4 = digitalRead(SW_4);
  pinMode(LED1,OUTPUT);
  digitalWrite(LED1,LOW);
  pinMode(LED2,OUTPUT);
  digitalWrite(LED2,LOW);
  pinMode(LED3,OUTPUT);
  digitalWrite(LED3,LOW);
  pinMode(LED4,OUTPUT);
  digitalWrite(LED4,LOW);
}

int rand1 = 0;
int rand2 =0;
int rand3 = 0;
int i1 = 0;
int j1 =0;
int count1 = 0;
int i2 = 0;
int j2 =0;
int count2 = 1;
int i3 = 0;
int j3 =0;
int count3 = 2;
int tap_i=0;

void Func1(){
   if(rand1 == 0){
    for(i1 =0 ; i1< 2;i1++){
      for(j1=0;j1<3;j1++){
        lcd.setCursor(j1,i1);
        if(count1 ==0){
          lcd.print("*");
        }else if(count1 == 1){
          lcd.print("?");
        }else if(count1 == 2){
          lcd.print("!");
        }else if(count1 == 3){
          lcd.print("$");
        }else if(count1 == 4){
          lcd.print("#");
        }else if(count1 == 5){
          lcd.print("7");
        }else if(count1 == 6){
          lcd.print("1");
        }else if(count1 == 7){
          lcd.print("+");
        } 
      }
    }
    count1++;
    if(count1==8){
      count1 = 0;
    }
  }
}

void Func2(){
   if(rand2 == 0){
    for(i2 =0 ; i2< 2;i2++){
      for(j2=0;j2<3;j2++){
        lcd.setCursor(j2+6,i2);
        if(count2 ==0){
          lcd.print("*");
        }else if(count2 == 1){
          lcd.print("?");
        }else if(count2 == 2){
          lcd.print("!");
        }else if(count2 == 3){
          lcd.print("$");
        }else if(count2 == 4){
          lcd.print("#");
        }else if(count2 == 5){
          lcd.print("7");
        }else if(count2 == 6){
          lcd.print("1");
        }else if(count2 == 7){
          lcd.print("+");
        } 
      }
    }
    count2++;
    if(count2==8){
      count2 = 0;
    }
  }
}

void Func3(){
  if(rand3 == 0){
    for(i3 =0 ; i3< 2;i3++){
      for(j3=0;j3<3;j3++){
        lcd.setCursor(j3+12,i3);
        if(count3 ==0){
          lcd.print("*");
        }else if(count3 == 1){
          lcd.print("?");
        }else if(count3 == 2){
          lcd.print("!");
        }else if(count3 == 3){
          lcd.print("$");
        }else if(count3 == 4){
          lcd.print("#");
        }else if(count3 == 5){
          lcd.print("7");
        }else if(count3 == 6){
          lcd.print("1");
        }else if(count3 == 7){
          lcd.print("+");
        } 
      }
    }
       count3++;
    if(count3==8){
      count3 = 0;
    }
  }
}

void stop1(){
  val1 = digitalRead(SW_1);
  if(val1==LOW){
    rand1=1;
    tap_i++;
    if(tap_i==1){
      digitalWrite(LED1,HIGH);
    }else if(tap_i==2){
      if(rand2==1){
        if(count2==count1){
          digitalWrite(LED1,HIGH);
        }else{
          digitalWrite(LED2,LOW);
        }
      }else if(rand3==1){
        if(count3==count1){
          digitalWrite(LED1,HIGH);
        }else{
          digitalWrite(LED3,LOW);
        }
      }
    }else if(tap_i==3){
      if(count1 == count2 && count1 == count3){
        digitalWrite(LED1,HIGH);
      }else{
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
      }
    }
  }
}

void stop2(){
  val2 = digitalRead(SW_2);
  if(val2==LOW){
    rand2=1;
    tap_i++;
    if(tap_i==1){
      digitalWrite(LED2,HIGH);
    }else if(tap_i==2){
      if(rand1==1){
        if(count1==count2){
          digitalWrite(LED2,HIGH);
        }else{
          digitalWrite(LED1,LOW);
        }
      }else if(rand3==1){
        if(count2==count3){
          digitalWrite(LED2,HIGH);
        }else{
          digitalWrite(LED3,LOW);
        }
      }
    }else if(tap_i==3){
      if(count2 == count1 && count2 == count3){
        digitalWrite(LED2,HIGH);
      }else{
        digitalWrite(LED1,LOW);
        digitalWrite(LED3,LOW);
      }
    }
  }
}

void stop3(){
  val3 = digitalRead(SW_3);
  if(val3==LOW){
    rand3=1;
    tap_i++; 
    if(tap_i==1){
      digitalWrite(LED3,HIGH);
    }else if(tap_i==2){
      if(rand2==1){
        if(count3==count2){
          digitalWrite(LED3,HIGH);
        }else{
          digitalWrite(LED2,LOW);
        }
      }else if(rand1==1){
        if(count1==count3){
          digitalWrite(LED3,HIGH);
        }else{
          digitalWrite(LED1,LOW);
        }
      }
    }else if(tap_i==3){
      if(count3 == count2 && count3 == count1){
        digitalWrite(LED3,HIGH);
      }else{
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
      }
    }
  }
}

void reset(){
  val4 = digitalRead(SW_4);
  if(rand1==1 && rand2==1 && rand3==1){
    if(val4 == LOW){
      rand1=0;
      rand2=0;
      rand3=0;
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      tap_i=0;
    }
  } 
}

void atari(){
  if(rand1==1 && rand2==1 && rand3==1 ){
    if(count1==count2 && count2==count3){
      if(LED_flag==0){
        digitalWrite(LED4,HIGH);
        LED_flag=1;
      }else{
        digitalWrite(LED4,LOW);
        LED_flag=0;
      }  
    }
  }
}

void loop() {
  
  Func1();
  stop1();
  Func2();
  stop2();
  Func3();
  stop3();
  atari();
  reset();
  
  
  delay(30);
}
