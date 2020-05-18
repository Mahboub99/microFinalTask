void setup() {
  // put your setup code here, to run once:
   pinMode(1 ,OUTPUT);
   pinMode(2 ,OUTPUT);
   pinMode(3 ,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    
      digitalWrite(1 , 1);
      digitalWrite(3 , 0);
      delay(500);
 	  digitalWrite(1 , 1);
      digitalWrite(3 , 1);
      delay(500);
	  digitalWrite(1 , 0);
      digitalWrite(3 , 1);
      delay(500);
      digitalWrite(1 , 0);
      digitalWrite(3 , 0);
      delay(500);
      digitalWrite(2,0);
      
      
}

