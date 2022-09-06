int relay = 10;  
int sensor = 9; 
int flag = 0; // this is a flag and it is changed from 0 to 1 and from 1 to 0 each time sensor is activated 
int sflag = 0; // sensor flag which is used to monitor the state of the sensor when there is nothing infront of it. 
 
void setup()
{
  pinMode(relay, OUTPUT); 
  digitalWrite(relay, LOW); 
  
  pinMode(sensor, INPUT); 
  digitalWrite(sensor, HIGH); 
 
}
 
void loop()
{
  
  if( (digitalRead(sensor) == LOW) && (flag == 0) && (sflag == 0) )
  { 
    flag = 1; 
    digitalWrite(relay, LOW); 
    sflag = 1; 
   
  }
  
    if( (digitalRead(sensor) == LOW) && (flag == 1) && (sflag == 0) )
  { 
    flag = 0; 
    digitalWrite(relay, LOW); 
    sflag = 1; 
   
  }
     if( (digitalRead(sensor) == HIGH)) // if there is nothing in front of the sensor
  { 
    sflag = 0;
    delay(1000);
    digitalWrite(relay, HIGH);  
   
  }
}
