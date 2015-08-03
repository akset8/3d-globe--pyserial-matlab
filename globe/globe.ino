
int latchPin = 8;

int clockPin = 12;

int dataPin = 11;


byte dataRED;
byte dataGREEN;
byte dataBLUE;
byte dataVIOLET ;

byte dataArrayRED[120];

byte dataArrayGREEN[120];

byte dataArrayBLUE[120];

byte dataArrayVIOLET[120];

void setup(){

  pinMode(latchPin, OUTPUT);
  Serial.begin(9600);
  
  int i=0;
  int k=0;
  while(i < 120 ){
  if(Serial.available()){
    int u=Serial.read();
    if(k==0){
    dataArrayVIOLET[i] = u ;
    k=(k+1)%4;
    }
    else if(k==1){
    dataArrayGREEN[i] = u ;
    k=(k+1)%4;
    }
    else if(k==2){
    dataArrayRED[i] = u ;
    k=(k+1)%4;
    }
    else if(k==3){
    dataArrayBLUE[i] = u ;
    k=(k+1)%4;
    }
    i++; }
  } }
    

void loop() {
 


  for (int j = 0; j < 120 ; j++) {

    dataBLUE = dataArrayBLUE[j];
    dataRED = dataArrayRED[j];
    dataGREEN = dataArrayGREEN[j];
    dataVIOLET = dataArrayVIOLET[j];

    
    digitalWrite(latchPin, 0);
    
    shiftOut(dataPin, clockPin, dataBLUE);
    shiftOut(dataPin, clockPin, dataRED);   
    shiftOut(dataPin, clockPin, dataGREEN);
    shiftOut(dataPin, clockPin, dataVIOLET);
    

    
    digitalWrite(latchPin, 1);
    delay(1000);
  }
}



// the heart of the program
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOutï¿½
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {	
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}


//blinks the whole register based on the number of times you want to 
//blink "n" and the pause between them "d"
//starts with a moment of darkness to make sure the first blink
//has its full visual effect.
void blinkAll_3Bytes(int n, int d) {
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, 0);
  shiftOut(dataPin, clockPin, 0);
  shiftOut(dataPin, clockPin, 0);
  digitalWrite(latchPin, 1);
  delay(200);
  for (int x = 0; x < n; x++) {
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, 255);
    shiftOut(dataPin, clockPin, 255);
    shiftOut(dataPin, clockPin, 255);
    digitalWrite(latchPin, 1);
    delay(d);
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, 0);
    shiftOut(dataPin, clockPin, 0);
    shiftOut(dataPin, clockPin, 0);
    digitalWrite(latchPin, 1);
    delay(d);
  }
}

