
void setup() {
  // put your setup code here, to run once:
   for(int i =0 ;i<14 ;i++)pinMode(i ,OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:      
	  digitalWrite(8 ,1 );
	  digitalWrite(9 ,1);
      if(millis()<2000)welcomeMode();

	
     /* selectRow(9);	
      delay(500);
      resetGrid();
      delay(500);*/
}
void selectLED(int num){
 digitalWrite(7 , 1);
 for(int  i =0 ;i<7 ;i++) digitalWrite(i , (1<<i)&num); 
 digitalWrite(7 ,0);
}
void resetGrid(){
  digitalWrite(9 ,0);
  for(int i=1 ;i<= 101 ;i++) selectLED(i);
  digitalWrite(9 ,1);
}
void selectRow(int num){
 for(int i = (num-1)*10+1 ; i<= num*10 ;i++) selectLED(i);
}
void selectCol(int num){
 for(int i = num ; i<=100 ;i+=10) selectLED(i);   
}
void welcomeMode(){

	for(int i = 1 ;i<=10 ;i++){
	      selectRow(i);	
	      delay(200);
	      resetGrid();
	}
	for(int i = 1 ;i<=10 ;i++){
	      selectCol(i);	
	      delay(200);
	      resetGrid();
	}
	
}