int key[10] = {911 , 730 , 719 ,708 , 761 , 773 ,786 , 852 ,837 , 822}; 
unsigned long int Data[2][11][10] = { //0 numeric , 1 emotions
								{
                                     {252, 132 ,132, 132 ,132 ,132 ,132 , 132 , 132 , 252},//0
                                     {48 , 48 , 48 , 48 ,48 , 48 , 48 ,48 ,48 ,48},//1
								   {0 ,252 , 4 , 4 , 4 ,252 ,128 , 128 ,128 ,252 },//2
								   {0 ,252 , 4 , 4 , 4 ,252 ,4 , 4 ,4 ,252 },//3
								   {132 , 132 , 132 , 132 ,252 , 4 , 4 ,4 ,4 ,4},//4
								   {0 ,252 , 128 , 128 , 128 ,252 ,4 , 4 ,4 ,252 },//5
								   {0 ,252 , 128 , 128 , 128 ,252 ,132 , 132 ,132 ,252 },//6
								   {252 , 132 , 132 , 4 ,4 , 4 , 4 ,4 ,4 ,4},//7
								   {0 ,252 ,132, 132 ,132 ,252 ,132 , 132 , 132 , 252},//8
								   {0 ,252 , 132 , 132 , 132 ,252 ,4 , 4 ,4 ,252 },//9
								   {0 , 0 , 0 , 0 ,0 , 0 , 0 ,0 ,0 ,0}
								  },
								  {
                                     {252, 132 ,258, 330 ,513 ,513 ,330 , 306 , 132 , 252},
                                     {252, 132 ,258, 330 ,513 ,561 ,330 , 258 , 132 , 252},
								   {1023 ,513 , 645 , 843 , 513 ,513 ,513 , 633 ,513 ,1023 },
								   {1023 ,513 , 645 , 843 , 513 ,513 ,513 , 513 ,513 ,1023 },
								   {1023 ,513 , 645 , 585 , 513 ,513 ,513 , 633 ,513 ,1023 },  
								   {1023 ,513 , 585 , 585 , 513 ,513 ,513 , 633 ,513 ,1023 },
								   {0 ,204 , 306 , 513, 513 ,513 ,258 , 132 ,72 ,48 },
								   {1023 , 819 , 513 , 513 ,513 , 513 , 771 ,903 ,975 ,1023},
								   {48 ,120 ,252, 48 ,48 ,48 ,48 , 48 , 48 , 48},
								   {48 ,48 , 48 , 48 , 48 ,48 ,48, 252 ,120 ,48 },
								   {0 , 0 , 0 , 0 ,0 , 0 , 0 ,0 ,0 ,0}
								  }
								};
int currentShap = 10;
int prevShap = 10;
int password[4] ={1 ,2 ,3 ,4};
int lastFour[4]={10 ,10 ,10 ,10};
int lastEight[8] = {10 , 10 , 10 , 10 , 10 ,10 ,10 ,10};
int changePassword[4] ={1 ,2 ,1 ,2};
int keyPressed = 10;
int cnt = 0;
int displayMode = 0; 

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
    
      if(millis()<2000)welcomeMode();
      setCurrentShap();
	  Mode(displayMode);
	  
    
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
	if(a == key[i]){
	 currentShap = i;
	 updateLast(i);
	}
	   
 }
 if(prevShap != currentShap){
   resetGrid();
   prevShap = currentShap; 
 }
 
}

void Mode(int displayMode){
 for(int i =0 ;i< 10 ;i++){
  for(int j = 0 ;j< 10 ;j++){
  	if(1<<j&Data[displayMode][currentShap][i]){
	 selectLED(j+1 + 10*i);
	 delay(100);
	 
	}
	 setCurrentShap();
	 handleSwitch();
	 handleChangePassword();
   }
 }
}
void handleSwitch(){


	/*for(int i = 0 ;i< 8 ;i++) {
	 Serial.print(lastEight[i]);
	}
	 Serial.println();*/
	 bool ok = 0;
	 for(int i = 0 ;i<4 ;i++){
	  if(password[i]!=lastFour[i]) ok = 1;
	 }
	
	 if(!ok){
	   displayMode = 1;
	   for(int i =0 ;i<4 ;i++) lastFour[i] =10;
	   currentShap = 10;
	 }
	 ok = 0;
	 for(int i = 0 ;i<4 ;i++){
	  if(password[i]!=lastFour[4-i-1]) ok = 1;
	 }
	 if(!ok){
	   displayMode = 0;
	   for(int i =0 ;i<4 ;i++) lastFour[i] =10;
	   currentShap = 10;
	 }

}
void updateLast(int value){
	
	for(int i =0 ;i< 3 ;i++){
	 lastFour[i] =lastFour[i+1];
	}
   lastFour[3] = value ;

   for(int i =0 ;i< 7 ;i++){
	 lastEight[i] =lastEight[i+1];
	}
   lastEight[7] = value ;
}

void handleChangePassword(){
 	 bool ok = 0;
	 for(int i = 0 ;i<4 ;i++){
	  if(changePassword[i]!=lastEight[i]) ok = 1;
	 }
	if(!ok){
	  //Serial.print("Done");
	  for(int i =0 ;i<4 ;i++){
	    password[i]=lastEight[i+4];
	   // Serial.print(password[i]);
	  }
	}
}