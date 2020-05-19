void setup() {
  // put your setup code here, to run once:
   for(int i =0 ;i<8 ;i++)pinMode(i ,OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
     
	  digitalWrite(7 ,1 );
      for(int i = 0 ;i<100 ;i++)
	  	selectLED(i), delay(100);		
      
}
void selectLED(int num){
 for(int  i =0 ;i<7 ;i++) digitalWrite(i , (1<<i)&num); 
}
