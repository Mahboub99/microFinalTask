void setup() {
  // put your setup code here, to run once:
   for(int i =0 ;i<9 ;i++)pinMode(i ,OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
     digitalWrite(8,1);
      
      digitalWrite(0,0);
      digitalWrite(1,0);
      digitalWrite(2,0);
      digitalWrite(3,0);


      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      
     delay(1000);
      
      digitalWrite(0,1);
      digitalWrite(1,0);
      digitalWrite(2,0);
      digitalWrite(3,0);


      digitalWrite(4,1);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      delay(1000);
}

