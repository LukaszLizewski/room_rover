
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int analog_pin_IR = 0; // analog read IR detevtor 
int digital_pin_motor_L = 2; // output pin for motor LEFT
int digital_pin_motor_R = 4; // output pin for motor RIGHT
int digital_pin_motor_S = 3; // PWM for motor (speed)
int digital_pin_servo = 5; // serwo output pin 

int Pin_A=13;   // led pin for screen multiplekser A
int Pin_B=12;   // led pin for screen multiplekser B
int Pin_C=11;   // led pin for screen multiplekser C
int Seg_1=10;   // segment no 1 output
int Seg_2=9;    // segment no 2 output
int Seg_3=8;    // segment no 3 output
int Seg_4=7;    // segment no 4 output

int led_time=2;                     // delay for particular led 

int a []={0, 0, 1};                 // tablice diod wyswietlacza multiplekser ABC
int b []={1, 1, 1};
int c []={1, 0, 0};
int d []={1, 1, 0};
int e []={1, 0, 1};
int f []={0, 1, 1};
int g []={0, 1, 0};
int DP []={0, 0, 0};


void wyswietlacz(float liczba){       //program for screen
    String count = (String)liczba

    
    int i=0, j=0, k=0, l=0;
    float m=1;
    
      while (m >=0){              //hundrets - program for screen
      m = liczba - i*100;
      i++;
      }
      
    i=i-2;
    m=liczba-i*100;
  
      while (m >=0){              //tens - program for screen
      m=liczba-i*100-j*10;
      j++;
      }
      
    j=j-2;
    m=liczba-i*100-j*10; 
   
      while (m >=0){                //units - program for screen
      m=liczba-i*100-j*10-k*1;
      k++;
      }
      
    k=k-2;
    m=liczba-i*100-j*10-k*1;
  
      while (m >=-0.05){               //
      m=liczba-i*100-j*10-k*1-l*0.1;
      l++;
      }
      
    l=l-2;
  
  if ((i==0) && (j!=0) && (k==0) && (l!=0)){          //special cases, we dont want zeros before (for example 001.9) - program for screen
    i=11;
  }
  if ((i==0) && (j!=0) && (k!=0) && (l!=0)){
    i=11;
  }
  if ((i==0) && (j==0) && (k!=0) && (l!=0)){
    i=11;
    j=11;
  }
   if ((i==0) && (j!=0) && (k!=0) && (l==0)){
    i=11;
  }
  if ((i==0) && (j==0) && (k!=0) && (l==0)){
    i=11;
    j=11;
  }
  if ((i==0) && (j!=0) && (k==0) && (l==0)){
    i=11;
  }
   if ((i==0) && (j==0) && (k==0) && (l!=0)){
    i=11;
    j=11;
  }
  if (l==10){
    l=9;
  }

  swiecenie (i, j, k, l);

}

   void swiecenie (int x, int y, int w, int z){

      digitalWrite(Seg_1, 0);          //segments - program for screen 
      digitalWrite(Seg_2, 0);
      digitalWrite(Seg_3, 0);
      digitalWrite(Seg_4, 0);

    aAa (x,y,w,z);
    bBb (x,y,w,z);
    cCc (x,y,w,z);
    dDd (x,y,w,z);
    eEe (x,y,w,z);
    fFf (x,y,w,z);
    gGg (x,y,w,z);
    dot ();                             //dot in third segment - program for screen
}


 void aAa (int x,int y,int w,int z){    // program for screen A's parts

  digitalWrite(Pin_A, a[0]);
  digitalWrite(Pin_B, a[1]);
  digitalWrite(Pin_C, a[2]);
  
  if ((x==0)||(x==2)||(x==3)||(x==5)||(x==6)||(x==7)||(x==8)||(x==9)){
  digitalWrite(Seg_1, 1);
  }
  if ((y==0)||(y==2)||(y==3)||(y==5)||(y==6)||(y==7)||(y==8)||(y==9)){
  digitalWrite(Seg_2, 1);
  }
  if ((w==0)||(w==2)||(w==3)||(w==5)||(w==6)||(w==7)||(w==8)||(w==9)){
  digitalWrite(Seg_3, 1);
  }
  if ((z==0)||(z==2)||(z==3)||(z==5)||(z==6)||(z==7)||(z==8)||(z==9)){
  digitalWrite(Seg_4, 1);
  }
  delay(led_time);
  digitalWrite(Seg_1, 0);          //segments - program for screen
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
}
 void bBb (int x,int y,int w,int z){  // program for screen B's parts

  digitalWrite(Pin_A, b[0]);
  digitalWrite(Pin_B, b[1]);
  digitalWrite(Pin_C, b[2]);
  
  if ((x==0)||(x==1)||(x==2)||(x==3)||(x==4)||(x==7)||(x==8)||(x==9)){
  digitalWrite(Seg_1, 1);
  }
  if ((y==0)||(y==1)||(y==2)||(y==3)||(y==4)||(y==7)||(y==8)||(y==9)){
  digitalWrite(Seg_2, 1);
  }
  if ((w==0)||(w==1)||(w==2)||(w==3)||(w==4)||(w==7)||(w==8)||(w==9)){
  digitalWrite(Seg_3, 1);
  }
  if ((z==0)||(z==1)||(z==2)||(z==3)||(z==4)||(z==7)||(z==8)||(z==9)){
  digitalWrite(Seg_4, 1);
  }
  delay(led_time);
  digitalWrite(Seg_1, 0);       
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
}
void cCc (int x,int y,int w,int z){     // program for screen C's parts

  digitalWrite(Pin_A, c[0]);
  digitalWrite(Pin_B, c[1]);
  digitalWrite(Pin_C, c[2]);
  
  if ((x==0)||(x==1)||(x==3)||(x==4)||(x==5)||(x==6)||(x==7)||(x==8)||(x==9)){
  digitalWrite(Seg_1, 1);
  }
  if ((y==0)||(y==1)||(y==3)||(y==4)||(y==5)||(y==6)||(y==7)||(y==8)||(y==9)){
  digitalWrite(Seg_2, 1);
  }
  if ((w==0)||(w==1)||(w==3)||(w==4)||(w==5)||(w==6)||(w==7)||(w==8)||(w==9)){
  digitalWrite(Seg_3, 1);
  }
  if ((z==0)||(z==1)||(z==3)||(z==4)||(z==5)||(z==6)||(z==7)||(z==8)||(z==9)){
  digitalWrite(Seg_4, 1);
  }
  delay(led_time);
  digitalWrite(Seg_1, 0);         
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
}

void dDd (int x,int y,int w,int z){   // program for screen D's parts

  digitalWrite(Pin_A, d[0]);
  digitalWrite(Pin_B, d[1]);
  digitalWrite(Pin_C, d[2]);
  
  if ((x==0)||(x==2)||(x==3)||(x==5)||(x==6)||(x==8)||(x==9)){
  digitalWrite(Seg_1, 1);
  }
  if ((y==0)||(y==2)||(y==3)||(y==5)||(y==6)||(y==8)||(y==9)){
  digitalWrite(Seg_2, 1);
  }
  if ((w==0)||(w==2)||(w==3)||(w==5)||(w==6)||(w==8)||(w==9)){
  digitalWrite(Seg_3, 1);
  }
  if ((z==0)||(z==2)||(z==3)||(z==5)||(z==6)||(z==8)||(z==9)){
  digitalWrite(Seg_4, 1);
  }
  delay(led_time);
  digitalWrite(Seg_1, 0);       
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
}
void eEe (int x,int y,int w,int z){   // program for screen E's parts

  digitalWrite(Pin_A, e[0]);
  digitalWrite(Pin_B, e[1]);
  digitalWrite(Pin_C, e[2]);
  
  if ((x==0)||(x==2)||(x==6)||(x==8)){
  digitalWrite(Seg_1, 1);
  }
  if ((y==0)||(y==2)||(y==6)||(y==8)){
  digitalWrite(Seg_2, 1);
  }
  if ((w==0)||(w==2)||(w==6)||(w==8)){
  digitalWrite(Seg_3, 1);
  }
  if ((z==0)||(z==2)||(z==6)||(z==8)){
  digitalWrite(Seg_4, 1);
  }
  delay(led_time);
  digitalWrite(Seg_1, 0);         
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
}
void fFf (int x,int y,int w,int z){     // program for screen F's parts

  digitalWrite(Pin_A, f[0]);
  digitalWrite(Pin_B, f[1]);
  digitalWrite(Pin_C, f[2]);
  
  if ((x==0)||(x==4)||(x==5)||(x==6)||(x==8)||(x==9)){
  digitalWrite(Seg_1, 1);
  }
  if ((y==0)||(y==4)||(y==5)||(y==6)||(y==8)||(y==9)){
  digitalWrite(Seg_2, 1);
  }
  if ((w==0)||(w==4)||(w==5)||(w==6)||(w==8)||(w==9)){
  digitalWrite(Seg_3, 1);
  }
  if ((z==0)||(z==4)||(z==5)||(z==6)||(z==8)||(z==9)){
  digitalWrite(Seg_4, 1);
  }
  delay(led_time);
  digitalWrite(Seg_1, 0);        
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
}
void gGg (int x,int y,int w,int z){     // program for screen G's parts

  digitalWrite(Pin_A, g[0]);
  digitalWrite(Pin_B, g[1]);
  digitalWrite(Pin_C, g[2]);
  
  if ((x==2)||(x==3)||(x==4)||(x==5)||(x==6)||(x==8)||(x==9)){
  digitalWrite(Seg_1, 1);
  }
  if ((y==2)||(y==3)||(y==4)||(y==5)||(y==6)||(y==8)||(y==9)){
  digitalWrite(Seg_2, 1);
  }
  if ((w==2)||(w==3)||(w==4)||(w==5)||(w==6)||(w==8)||(w==9)){
  digitalWrite(Seg_3, 1);
  }
  if ((z==2)||(z==3)||(z==4)||(z==5)||(z==6)||(z==8)||(z==9)){
  digitalWrite(Seg_4, 1);
  }
  delay(led_time);
  digitalWrite(Seg_1, 0);         
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
}
void dot (){                        // program for screen dot's parts
  digitalWrite(Pin_A, DP[0]);
  digitalWrite(Pin_B, DP[1]);
  digitalWrite(Pin_C, DP[2]);
  digitalWrite(Seg_3, 1);
  delay(led_time);
  digitalWrite(Seg_3, 0);
}

void right (int x){                                     //turning right screen - program for screen

  for (int k=1; k<=x; k++){ 
  digitalWrite(Pin_A, g[0]);
  digitalWrite(Pin_B, g[1]);
  digitalWrite(Pin_C, g[2]);
                                                             
  digitalWrite(Seg_1, 1); 
  delay (400);          
  digitalWrite(Seg_2, 1);
  delay (100); 
  digitalWrite(Seg_3, 1);
  delay (100); 
  digitalWrite(Seg_4, 1);
  delay (100);

  digitalWrite(Seg_1, 0);           
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
  }
}
void left (int x){                                     //turning left screen - program for screen

  for (int k=1; k<=x; k++){ 
  digitalWrite(Pin_A, g[0]);
  digitalWrite(Pin_B, g[1]);
  digitalWrite(Pin_C, g[2]);
                                                             
  digitalWrite(Seg_4, 1); 
  delay (400);          
  digitalWrite(Seg_3, 1);
  delay (100); 
  digitalWrite(Seg_2, 1);
  delay (100); 
  digitalWrite(Seg_1, 1);
  delay (100);

  digitalWrite(Seg_1, 0);           
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
  }
}
 


void servo (int val){                        // program for servo
 myservo.write(val);                  // sets the servo position according to the scaled value
 delay(15);  
}
void motor_L(int pwm, int on_off){                                   //program for motor which one is moving LEFT
 digitalWrite (digital_pin_motor_L, on_off);
 analogWrite(digital_pin_motor_S, pwm); 
}
void motor_R(int pwm, int on_off){                                   //program for motor which one is moving RIGHT
 digitalWrite (digital_pin_motor_R, on_off);
 analogWrite(digital_pin_motor_S, pwm); 
}
void turning_right (){                                                 //program for turning RIGHT
  
  int delay_for_servo = 1000;
  int servo_right = 120;
  int servo_left = 60;
 right(3);
// Serial.println("turning right");
 servo(90);
 delay (delay_for_servo);
 motor_R(255,1);
 delay (1000);
 motor_R(0,0);
 servo(servo_right);
 delay(delay_for_servo);
 motor_L(255,1);
 delay (1000);
 servo(90);
 delay(delay_for_servo);
}
void turning_left (){                                                 //program for turning LEFT
  
  int delay_for_servo = 1000;
  int servo_right = 120;
  int servo_left = 60;
 left(3); 
// Serial.println("turning left");
 servo(90);
 delay (delay_for_servo);
 motor_R(255,1);
 delay (1000);
 motor_R(0,0);
 servo(servo_left);
 delay(delay_for_servo);
 motor_L(255,1);
 delay (1000);
 servo(90);
 delay(delay_for_servo);
}
void look (){                                                        //program for looking around 
  int delay_for_servo = 1000;
  int servo_right = 120;
  int servo_left = 60;

  
   delay (1000);
//   Serial.println("backwords");
   motor_R(255,1);
   delay (1000);
   motor_R(0,0);
//   Serial.println("stop");
   servo(servo_right);
//   Serial.println("right");
   delay(delay_for_servo);
   float reading1 = analogRead(analog_pin_IR);
//   Serial.println(reading1);
   servo(servo_left);
//   Serial.println("left");
   delay(delay_for_servo);
   float reading2 = analogRead(analog_pin_IR);
//   Serial.println(reading2);
        if (reading1>reading2){
            turning_right();
            
       }
        else if (reading1<reading2){
            turning_left();
      } 
    }

void test (){                                 //program for motor, servo and screen test 
//  Serial.println("testing");                  //motor and servo testing 
/*  servo(90);
  delay(1000);
  servo(160);
  delay(2000);
  servo(20);
  delay(2000);
  servo(90);
  delay(2000);
  motor_R(255,1);
  delay(500);
  motor_R(0,0);
  delay(500);
  motor_L(255,1);
  delay(500);
  motor_L(0,0);
  delay(500);*/

  int tDelay=150;                               //screen testing 
  digitalWrite(Seg_4, 1);   
  digitalWrite(Seg_3, 1); 
  digitalWrite(Seg_2, 1);
  digitalWrite(Seg_1, 1);
  
  digitalWrite(Pin_A, a[0]);
  digitalWrite(Pin_B, a[1]);
  digitalWrite(Pin_C, a[2]);
  delay(tDelay);
  digitalWrite(Pin_A, b[0]);
  digitalWrite(Pin_B, b[1]);
  digitalWrite(Pin_C, b[2]);
  delay(tDelay);
  digitalWrite(Pin_A, c[0]);
  digitalWrite(Pin_B, c[1]);
  digitalWrite(Pin_C, c[2]);
  delay(tDelay);
  digitalWrite(Pin_A, d[0]);
  digitalWrite(Pin_B, d[1]);
  digitalWrite(Pin_C, d[2]);
  delay(tDelay);
  digitalWrite(Pin_A, e[0]);
  digitalWrite(Pin_B, e[1]);
  digitalWrite(Pin_C, e[2]);
  delay(tDelay);
  digitalWrite(Pin_A, f[0]);
  digitalWrite(Pin_B, f[1]);
  digitalWrite(Pin_C, f[2]);
  delay(tDelay);
  digitalWrite(Pin_A, g[0]);
  digitalWrite(Pin_B, g[1]);
  digitalWrite(Pin_C, g[2]);
  delay(tDelay);
  digitalWrite(Pin_A, DP[0]);
  digitalWrite(Pin_B, DP[1]);
  digitalWrite(Pin_C, DP[2]);
  delay(tDelay+800);
                                                             
  digitalWrite(Seg_1, 0);           
  digitalWrite(Seg_2, 0);
  digitalWrite(Seg_3, 0);
  digitalWrite(Seg_4, 0);
}
int metoda () {
  
}

void setup() {
//  Serial.begin(9600);
  myservo.attach(digital_pin_servo);      // attaches the servo on pin 9 to the servo object
  pinMode ( digital_pin_motor_L, OUTPUT); // attaches the motor_L on pin 10
  pinMode ( digital_pin_motor_R, OUTPUT); // attaches the motor_R on pin 12
  pinMode ( digital_pin_motor_S, OUTPUT); // attaches the motor(PWM) on pin 11
  pinMode (Pin_A, OUTPUT);                //pin for screen
  pinMode (Pin_B, OUTPUT);
  pinMode (Pin_C, OUTPUT);
  pinMode (Seg_1, OUTPUT);
  pinMode (Seg_2, OUTPUT);
  pinMode (Seg_3, OUTPUT);
  pinMode (Seg_4, OUTPUT);
  test ();
  
}

void loop() {
  
int reading = analogRead(analog_pin_IR);      //turn on IR detector
float vol = reading / 204.6;                  //concversion read to Volts
//Serial.println (vol);

// float i =reading ;                       // number from 0.0 to 999.9
  for (int T=0; T<10; T++){         //turn on program for led screen (time is equal to number of loops 
  wyswietlacz(vol);                     //program for led screen
  }

if (vol>=1){
//  Serial.println("POWER");
  motor_L(255,1);
}

  else if (vol<=1 && vol>=0){
//  Serial.println("I'm slowing down");
  motor_L(150,1);
}
  else if (vol<=0){
  Serial.println("I'm looking around ");
  motor_L(0,0);
  look();
}

}
