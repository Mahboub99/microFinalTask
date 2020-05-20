void setup() {
  // put your setup code here, to run once:
   for(int i =0 ;i<9 ;i++)pinMode(i ,OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
     
	  digitalWrite(8 ,1 );
      
	  selectLED(99);	
      
}
void selectLED(int num){
 digitalWrite(7 , 1);
 for(int  i =0 ;i<7 ;i++) digitalWrite(i , (1<<i)&num); 
 digitalWrite(7 ,0);
}
