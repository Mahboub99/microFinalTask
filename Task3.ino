int key[10] = {911 , 730 , 719 ,708 , 786 , 773 ,761 , 852 ,837 , 822}; 
unsigned long int Numeric [11][10] = {
                                     {252, 132 ,132, 132 ,132 ,132 ,132 , 132 , 132 , 252},
                                     {48 , 48 , 48 , 48 ,48 , 48 , 48 ,48 ,48 ,48},
								   {0 ,252 , 4 , 4 , 4 ,252 ,128 , 128 ,128 ,252 },
								   {0 ,252 , 4 , 4 , 4 ,252 ,4 , 4 ,4 ,252 },
								   {132 , 132 , 132 , 132 ,252 , 4 , 4 ,4 ,4 ,4},
								   {0 ,252 , 128 , 128 , 128 ,252 ,4 , 4 ,4 ,252 },
								   {0 ,252 , 128 , 128 , 128 ,252 ,132 , 132 ,132 ,252 },
								   {252 , 132 , 132 , 4 ,4 , 4 , 4 ,4 ,4 ,4},
								   {0 ,252 ,132, 132 ,132 ,252 ,132 , 132 , 132 , 252},
								   {0 ,252 , 132 , 132 , 132 ,252 ,4 , 4 ,4 ,252 },
								   {0 , 0 , 0 , 0 ,0 , 0 , 0 ,0 ,0 ,0}
								  };
int currentShap = 10;
int prevShap = 10;
void setup() {
  // put your setup code here, to run once:
   for(int i =0 ;i<14 ;i++)pinMode(i ,OUTPUT);
   pinMode(A0 , INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:      
	  digitalWrite(8 ,1 );
	  digitalWrite(9 ,1);
     // if(millis()<2000)welcomeMode();
      setCurrentShap();
	  Serial.println(currentShap);
	  delay(100);
	  Mode();
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
	      selectCol(i);	
	      delay(200);
	      resetGrid();
	}
	for(int i = 1 ;i<=10 ;i++){
	      selectRow(i);	
	      delay(200);
	      resetGrid();
	}
	
}
void setCurrentShap(){

 int a = analogRead(A0);
 //int b = 10;
 for(int i = 0 ; i<10 ;i++) 
 {
	if(a == key[i]) 
	  currentShap = i;
 }
 if(prevShap != currentShap){
   resetGrid();
   prevShap = currentShap; 
 }
 
}

void Mode(){
 for(int i =0 ;i< 10 ;i++){
  for(int j = 0 ;j< 10 ;j++){
  	if(1<<j&Numeric[currentShap][i]){
	 selectLED(j+1 + 10*i);
	 delay(100);
	 setCurrentShap();
	}
   }
 
 }

}