int motorNum[4] = {9 , 3 , 6 , 12};
unsigned long prevDownServo = 0;  
unsigned long prevUpServo = 0;  
unsigned long prevStepper[13] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 0, 0, 0, 0 ,0};
unsigned long prevValve[4] ={0 , 0 , 0 ,0}; 
unsigned long prevLED[3]={0 , 0 , 0};
unsigned long int ledState[3] ={0 ,0 , 0};
unsigned long int servoTime = 0  , backingTime =0 ,decorateTime = 0;
int servoPins[6] = {9 , 10 , 5 , 6 , 6 , 6};
int servoDelays[6]={500 , 400 ,100 ,200 ,200 ,200 };
int bakingDelay[4] = {1000 , 1000 , 1000 , 1000};
int decorateDelay[20] = {100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100 ,100  };
int cnt = 3 , mixerSpeed = 10 , backingCnt = 0 ,decorateCnt = 0 , mode = 0;
int keys[4] ={227 , 127 , 88 ,68 };

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
   for(int i=0 ;i<14 ;i++) pinMode(i ,OUTPUT);
   pinMode(A0 , OUTPUT);
   pinMode(A1 , OUTPUT);
   pinMode(A2 , OUTPUT);
   pinMode(A3 , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   
    moveMotor(0, mixerSpeed , 1); // mixer
    
    if(millis()- servoTime >= servoDelays[cnt]+100){
         servo(servoPins[cnt] , 2300 );
         cnt++, cnt%=6;
         if(cnt >= 3) mixerSpeed = 5 ,delay(50);
         if(cnt == 0) mixerSpeed =10 ;
         servo(servoPins[cnt] , 1450 );
         servoTime = millis();
    }
   
    moveMotor(2 , 1 , ledState[0]==0||ledState[0] == 2);//prduction line
    heater(); //oven
  
     moveMotor(12 , 1 , 1); // decorate stepper


     setMode(); 
     if(millis()- decorateTime >= decorateDelay[decorateCnt]+100){
       
      decorateCnt++,decorateCnt%=20;
      if(mode == 1){
          if(decorateCnt >=0 && decorateCnt <=9){
             digitalWrite(A1 , 1) , digitalWrite(A2 , 0);
             servo(11 ,2300);
          }else { 
             digitalWrite(A1 , 0) , digitalWrite(A2 , 1);
             servo(11 ,1450);
          }
      }else if(mode == 2 ) {
            if(decorateCnt >=0 && decorateCnt <=9){
              if(decorateCnt==0||decorateCnt==2 ||decorateCnt==4||decorateCnt==6 )         
                 digitalWrite(A1 , 1);
              else  digitalWrite(A1 , 0);
             digitalWrite(A2 , 0);
             servo(11 ,2300);
          }else { 
             if(decorateCnt==10||decorateCnt==12 ||decorateCnt==14||decorateCnt==16 )         
                 digitalWrite(A2 , 1);
              else  digitalWrite(A2 , 0);
             digitalWrite(A1 , 0);
             servo(11 ,1450);
          }
       
      }else if(mode == 3 ) {
         if(decorateCnt >=0 && decorateCnt <16){
              if(decorateCnt%2 == 0)         
                 digitalWrite(A1 , 1);
              else  digitalWrite(A1 , 0);
             digitalWrite(A2 , 0);
             servo(11 ,2300);
          }else { 
                  
             digitalWrite(A2 , 1);
             digitalWrite(A1 , 0);
             servo(11 ,600);
          }
       
      }else if(mode == 4 ) {
          if(decorateCnt >=0 && decorateCnt <16){
              if(decorateCnt%2 == 0)         
                 digitalWrite(A1 , 1),  digitalWrite(A2 , 0);
              else  digitalWrite(A1 , 0) , digitalWrite(A2 , 1);
             servo(11 ,2300);
          }else { 
                  
             digitalWrite(A2 ,0);
             digitalWrite(A1 , 1);
             if(decorateCnt==16)
               servo(11 ,600);
            else if(decorateCnt==17)
               servo(11 ,800);
            else if(decorateCnt==18)
               servo(11 ,1200);
            else if(decorateCnt==19)
               servo(11 ,1450);
          }
      }
      decorateTime = millis();
    }
   
}

void moveMotor(int num ,int speed ,int enable){
 unsigned long currStepper = millis();
 if (currStepper - prevStepper[num] >= 1000.0/(8.0*speed)) {	
     prevStepper[num] = currStepper;
	for(int i =0 ;i<4 && enable ;i++){
	 	for(int j =0 ;j<4 ;j++){
		  digitalWrite(i%2+num , 1<<j&motorNum[i%4]);
		  
	   }
	}	
  }	
}

void servo(int num ,int angle){

    digitalWrite(num, HIGH);
    delayMicroseconds(angle); // Duration of the pusle in microseconds
    digitalWrite(num, LOW);
   
}

void heater(){
  unsigned long currentMillis = millis();

  if (currentMillis - prevLED[0] >= 1000 ) {
    // save the last time you blinked the LED
    prevLED[0] = currentMillis;

    // if the LED is off turn it on and vice-versa:
    ledState[0]++, ledState[0]%=4;
    // set the LED with the ledState of the variable:
    digitalWrite(A0, ledState[0] == 1);
   }
}
void setMode(){
  int a = analogRead(A3);
  for(int i =0 ;i<4 ;i++){
    if(a == keys[i]) mode = i+1;
  }
}