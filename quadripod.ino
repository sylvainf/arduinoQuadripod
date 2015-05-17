#include <NewPing.h>
#include <Servo.h> 

Servo waist,front,back,radar;

#define TRIGGER_PIN 7
#define ECHO_PIN 8
#define ledPin 2

NewPing sonar(TRIGGER_PIN, ECHO_PIN, 100);

// adjust values here to center your servos
#define wCenter 87
#define fCenter 90
#define bCenter 105
#define rCenter 90
#define rSwing 40
#define wSwing 17
#define fSwing 27
#define bSwing 27
#define FORWARD 0
#define BACKWARD 1
#define LEFT 2
#define RIGHT 3
#define STOP 4
int wPos,fPos,bPos,cycle,dir,rPos, superCycle;
boolean evitement;



void setup() 
{ 
  pinMode(ledPin, OUTPUT);
  waist.attach(13);
  front.attach(10);
  back.attach(11);
  radar.attach(9);
  wPos=wCenter;
  fPos=fCenter;
  bPos=bCenter;
  rPos=rCenter;
  waist.write(wPos);
  front.write(fPos);
  back.write(bPos);
  radar.write(rPos);
  delay(5000);
  
  dir=FORWARD;
  cycle=0;
  superCycle=0;
  evitement = 0;
} 




long readDist(){
  long  distance, newdist;  
    radar.write(rCenter-rSwing);
    delay(170);
    distance = sonar.ping_cm();
    if (distance== 0) { distance=200; }
    delay(20);
   
    radar.write(rCenter);
    delay(170);
    newdist = sonar.ping_cm();
    if (newdist == 0) { newdist=200; }
    delay(20);
    if (newdist<distance){distance = newdist;}
  
    radar.write(rCenter+rSwing);
    delay(170);
    newdist = sonar.ping_cm();
    if (newdist == 0) { newdist=200; }
    delay(20);
    if (newdist<distance){distance = newdist;}
    if (!distance) { distance=200; } 
    
    radar.write(rCenter); 
    return distance;
}


void doBackward(int cycle) {
  if (cycle<12) wPos=wCenter+wSwing;
  else if (cycle<37) wPos=wCenter-wSwing;
  else if (cycle<62) wPos=wCenter+wSwing;
  else if (cycle<87) wPos=wCenter-wSwing;
  else          wPos=wCenter+wSwing;
  if (cycle<25) fPos=fCenter+fSwing;
  else if (cycle<50) fPos=fCenter-fSwing; 
  else if (cycle<75) fPos=fCenter+fSwing;
  else fPos=fCenter-fSwing; 
  if (cycle<25) bPos=bCenter-bSwing;
  else if (cycle<50) bPos=bCenter+bSwing; 
  else if (cycle<75) bPos=bCenter-bSwing;
  else bPos=bCenter+bSwing; 
}

void doForward(int cycle) {
  doBackward(100-cycle);
}

void doLeft(int cycle) {
  doBackward(100-cycle);
  if (wPos>wCenter) wPos=wCenter;
}

void doRight(int cycle) {
  doBackward(100-cycle);
  if (wPos<wCenter) wPos=wCenter;
 
}

void doStop(){
  wPos=wCenter;
  fPos=fCenter;
  bPos=bCenter;
}

void posUpdate() {
  cycle=(cycle+1)%100;
  switch(dir) {
    case FORWARD: doForward(cycle);  break;
    case BACKWARD: doBackward(cycle); break;
    case LEFT: doLeft(cycle); break;
    case RIGHT: doRight(cycle); break;
    case STOP: doStop(); break;
  }
}

void loop() 
{ 
  long distance;
  posUpdate();
  waist.write(wPos);
  front.write(fPos);
  back.write(bPos);

  if (cycle==5){
      // No delay  
  } else {
    if(dir==LEFT or dir==RIGHT){ 
        delay(8);
    }
    else {
     delay(15);
    } 
  }
  
 
 if (evitement){
   digitalWrite(ledPin, HIGH);
   if (superCycle < 200) {
     dir = BACKWARD;
   } else {
     dir = LEFT;
   }
   
   superCycle++;
   if (superCycle >800){
     evitement = 0;
     superCycle=0;
     dir= FORWARD;
     digitalWrite(ledPin, LOW);
   }
 }
 
 if (cycle==5) {
   if (dir==FORWARD) { 
     distance = readDist();
   } 
 }
 
  if (distance < 40){
     digitalWrite(ledPin, HIGH);
     evitement = 1;
  }  
}
