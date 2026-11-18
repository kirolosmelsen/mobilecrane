#define M1r 3
#define M1b 5
#define M2r 10
#define M2b 11
#define M3r 8
#define M3b 9
#define M4r 12
#define M4b 13
#define SONAR_TRIGGER_PIN 6
#define SONAR_ECHO_PIN 7
void setup(){
Serial.begin(9600);
pinMode(SONAR_TRIGGER_PIN,OUTPUT);
pinMode(SONAR_ECHO_PIN,INPUT);
pinMode(M1r,OUTPUT);
pinMode(M1b,OUTPUT);
pinMode(M2r,OUTPUT);
pinMode(M2b,OUTPUT);
pinMode(M3r,OUTPUT);
pinMode(M3b,OUTPUT);
pinMode(M4r,OUTPUT);
pinMode(M4b,OUTPUT);}
void loop(){
solo();}
unsigned int distance(){
digitalWrite(SONAR_TRIGGER_PIN,HIGH);
delayMicroseconds(10);
digitalWrite(SONAR_TRIGGER_PIN,LOW);
unsigned long pulse_len = pulseIn(SONAR_ECHO_PIN,HIGH);
delay(50);
return((unsigned int) (pulse_len/58)); }
void solo(){
unsigned int object = distance();
Serial.println(object,DEC);
if(object>30){
a();}  
else{
stop();
delay(1000);
b();    
delay(1000);
r();
delay(1000);}}
void a(){
digitalWrite(M1r,HIGH);
digitalWrite(M1b,LOW);
digitalWrite(M2r,HIGH);
digitalWrite(M2b,LOW);
digitalWrite(M3r,HIGH);
digitalWrite(M3b,LOW);
digitalWrite(M4r,HIGH);
digitalWrite(M4b,LOW);}
void b(){
digitalWrite(M1r,LOW);
digitalWrite(M1b,HIGH);
digitalWrite(M2r,LOW);
digitalWrite(M2b,HIGH);
digitalWrite(M3r,LOW);
digitalWrite(M3b,HIGH);
digitalWrite(M4r,LOW);
digitalWrite(M4b,HIGH);}
void r(){
digitalWrite(M1r,LOW);
digitalWrite(M1b,LOW);
digitalWrite(M2r,HIGH);
digitalWrite(M2b,LOW);
digitalWrite(M3r,LOW);
digitalWrite(M3b,LOW);
digitalWrite(M4r,HIGH);
digitalWrite(M4b,LOW);}
void l(){
digitalWrite(M1r,HIGH);
digitalWrite(M1b,LOW);
digitalWrite(M2r,LOW);
digitalWrite(M2b,LOW);
digitalWrite(M3r,HIGH);
digitalWrite(M3b,LOW);
digitalWrite(M4r,LOW);
digitalWrite(M4b,LOW);}
void stop(){
digitalWrite(M1r,LOW);
digitalWrite(M1b,LOW);
digitalWrite(M2r,LOW);
digitalWrite(M2b,LOW);
digitalWrite(M3r,LOW);
digitalWrite(M3b,LOW);
digitalWrite(M4r,LOW);
digitalWrite(M4b,LOW);}