define BUTTON 2
#define LED 13

int ledPins[8] = {3,4,5,6,7,8,9,10};
double tempo = 300;
int score = 0;
boolean blueLed = false;

void interrupt();
void endFunction();

void setup(){
  for( int i = 0 ; i < 8 ; i++ ){
    pinMode( ledPins[i] , OUTPUT ); 
  }
  pinMode( LED , OUTPUT );
  pinMode( BUTTON , INPUT );
  attachInterrupt( 0 , interrupt , FALLING ); 
}

void loop(){
  for( int i = 0 ; i < 7 ; i++ ){
    digitalWrite( ledPins[i] , HIGH );
    delay( tempo );
    digitalWrite( ledPins[i] , LOW );
  }
  digitalWrite( ledPins[7] , HIGH);
  blueLed = true;
  delay( tempo );
  digitalWrite( ledPins[7] , LOW);
  blueLed = false;
  for( int i = 6 ; i > 0 ; i-- ){
    digitalWrite( ledPins[i] , HIGH );
    delay( tempo );
    digitalWrite( ledPins[i] , LOW );
  }
}

void endFunction(){
  Serial.begin(9600);
  Serial.print( "Your score: " );
  Serial.println( score );
  digitalWrite( LED , HIGH );
  while(1){
    //game over
  } 
}

void interrupt(){
  delayMicroseconds(20000);
  if( digitalRead( BUTTON ) == HIGH ){
    return; 
  }
  tempo = tempo * 9 / 10;
  if( blueLed ){
    score++; 
  }
  else{
    endFunction(); 
  }
}
