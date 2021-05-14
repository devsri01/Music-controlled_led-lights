int layer[4]={A3,A2,A1,A0}; //initializing and declaring led layers

int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4}; //initializing and declaring led rows

int time = 500;


  
 
void setup()
{
  for(int i=0;i<16;i++)   
  {
    pinMode(column[i], OUTPUT);  //setting rows to output
  }
  
  for(int i=0;i<4;i++)
  {
    pinMode(layer[i], OUTPUT);  //setting layers to output
  }
  //pinMode(A6, INPUT);  //setting analog pin A6 to input for sound sensor detection
}

void loop()
{
    AllOff();
    
    Flicker();
    
    LayerONOFF();
    
    ErraticLED();
    
    GoThroughAllLedsOneAtATime();
}


//turn all off
void AllOff()
 {
   for(int i=0;i<4;i++)
  {
    digitalWrite(layer[i],HIGH);
  }
  for( int i=0;i<16;i++)
  {
    digitalWrite(column[i],LOW);
  }
 }
 
//turn all on
void AllOn()
{
  for(int i=0;i<4;i++)
  {
    digitalWrite(layer[i],LOW);
  }
  for( int i=0;i<16;i++)
  {
    digitalWrite(column[i],HIGH);
  }
  
}   

//flicker pattern
void Flicker()
{
  int i = 500;
  while(i != 0)
  {
    AllOn();
    delay(i);
    AllOff();
    delay(i);
    i-= 50;
  }
}
// switching on and off of LEDs layerwise
void LayerONOFF()
{
  int x = 75;
  for(int i=5;i>0;i--)
  {
    AllOn();
    for(int i=3;i>=0;i--)
    {
      digitalWrite(layer[i], LOW);
      delay(x);
    }
    for(int i=0;i<4;i++)
    {
      digitalWrite(layer[i], HIGH);
      delay(x);
    }
      for(int i=0;i<4;i++)
    {
      digitalWrite(layer[i], LOW);
      delay(x);
    }
    for(int i=3;i>=0;i--)
    {
      digitalWrite(layer[i], HIGH);
      delay(x);
    }
  }
}
//triggering diagonal glowing on LEDs in each layer
void Diagonal()
{
    for(int i=1;i<=5;i++)
    {
        int x=200;
        digitalWrite(column[15],LOW);
        digitalWrite(column[0], HIGH);
        delay(x);
        digitalWrite(column[0], LOW);
        digitalWrite(column[1], HIGH);
        digitalWrite(column[4], HIGH);
        delay(x);
        digitalWrite(column[1], LOW);
        digitalWrite(column[4], LOW);
        digitalWrite(column[2], HIGH);
        digitalWrite(column[5], HIGH);
        digitalWrite(column[8], HIGH);
        delay(x);
        digitalWrite(column[2], LOW);
        digitalWrite(column[5], LOW);
        digitalWrite(column[8], LOW);
        digitalWrite(column[3], HIGH);
        digitalWrite(column[6], HIGH);
        digitalWrite(column[9], HIGH);
        digitalWrite(column[12], HIGH);
        delay(x);
        digitalWrite(column[3], LOW);
        digitalWrite(column[6], LOW);
        digitalWrite(column[9], LOW);
        digitalWrite(column[12], LOW);
        digitalWrite(column[7], HIGH);
        digitalWrite(column[10], HIGH);
        digitalWrite(column[13], HIGH);
        delay(x);
        digitalWrite(column[7], LOW);
        digitalWrite(column[10], LOW);
        digitalWrite(column[13], LOW);
        digitalWrite(column[14], HIGH);
        digitalWrite(column[11], HIGH);
        delay(x);
        digitalWrite(column[14], LOW);
        digitalWrite(column[11], LOW);
        digitalWrite(column[15], HIGH);
        delay(x);
   }
}

//erratic glowing of LEDs
void ErraticLED()
{
  int x = 100;
  for(int i=0;i<60; i+=2)
  {
    int randomColumn = random(0,16);
    digitalWrite(column[randomColumn], HIGH);
    digitalWrite(layer[0], LOW);
    delay(x+50);
    digitalWrite(layer[0], HIGH);
    digitalWrite(layer[1], LOW);
    delay(x);
    digitalWrite(layer[1], HIGH);
    digitalWrite(layer[2], LOW);
    delay(x);
    digitalWrite(layer[2], HIGH);
    digitalWrite(layer[3], LOW);
    delay(x+50);
    digitalWrite(layer[3], HIGH);
    digitalWrite(column[randomColumn], LOW);
  }
}
//spiral in and out
void SpiralInAndOut()
{
  int x = 60;
  for(int i=0;i<6;i++)
  {
    //spiral in clockwise
    digitalWrite(column[0], HIGH);
    delay(x);
    digitalWrite(column[1], HIGH);
    delay(x);
    digitalWrite(column[2], HIGH);
    delay(x);
    digitalWrite(column[3], HIGH);
    delay(x);
    digitalWrite(column[7], HIGH);
    delay(x);
    digitalWrite(column[11], HIGH);
    delay(x);
    digitalWrite(column[15], HIGH);
    delay(x);
    digitalWrite(column[14], HIGH);
    delay(x);
    digitalWrite(column[13], HIGH);
    delay(x);
    digitalWrite(column[12], HIGH);
    delay(x);
    digitalWrite(column[8], HIGH);
    delay(x);
    digitalWrite(column[4], HIGH);
    delay(x);
    digitalWrite(column[5], HIGH);
    delay(x);
    digitalWrite(column[6], HIGH);
    delay(x);
    digitalWrite(column[10], HIGH);
    delay(x);
    digitalWrite(column[9], HIGH);
    delay(x);
//spiral out counter clockwise
    digitalWrite(column[9], LOW);
    delay(x);
    digitalWrite(column[10], LOW);
    delay(x);
    digitalWrite(column[6], LOW);
    delay(x);
    digitalWrite(column[5], LOW);
    delay(x);
    digitalWrite(column[4], LOW);
    delay(x);
    digitalWrite(column[8], LOW);
    delay(x);
    digitalWrite(column[12], LOW);
    delay(x);
    digitalWrite(column[13], LOW);
    delay(x);
    digitalWrite(column[14], LOW);
    delay(x);
    digitalWrite(column[15], LOW);
    delay(x);
    digitalWrite(column[11], LOW);
    delay(x);
    digitalWrite(column[7], LOW);
    delay(x);
    digitalWrite(column[3], LOW);
    delay(x);
    digitalWrite(column[2], LOW);
    delay(x);
    digitalWrite(column[1], LOW);
    delay(x);
    digitalWrite(column[0], LOW);
    delay(x);
//spiral in counter clock wise
    digitalWrite(column[0], HIGH);
    delay(x);
    digitalWrite(column[4], HIGH);
    delay(x);
    digitalWrite(column[8], HIGH);
    delay(x);
    digitalWrite(column[12], HIGH);
    delay(x);
    digitalWrite(column[13], HIGH);
    delay(x);
    digitalWrite(column[14], HIGH);
    delay(x);
    digitalWrite(column[15], HIGH);
    delay(x);
    digitalWrite(column[11], HIGH);
    delay(x);
    digitalWrite(column[7], HIGH);
    delay(x);
    digitalWrite(column[3], HIGH);
    delay(x);
    digitalWrite(column[2], HIGH);
    delay(x);
    digitalWrite(column[1], HIGH);
    delay(x);
    digitalWrite(column[5], HIGH);
    delay(x);
    digitalWrite(column[9], HIGH);
    delay(x);
    digitalWrite(column[10], HIGH);
    delay(x);
    digitalWrite(column[6], HIGH);
    delay(x);
//spiral out clock wise
    digitalWrite(column[6], LOW);
    delay(x);
    digitalWrite(column[10], LOW);
    delay(x);
    digitalWrite(column[9], LOW);
    delay(x);
    digitalWrite(column[5], LOW);
    delay(x);
    digitalWrite(column[1], LOW);
    delay(x);
    digitalWrite(column[2], LOW);
    delay(x);
    digitalWrite(column[3], LOW);
    delay(x);
    digitalWrite(column[7], LOW);
    delay(x);
    digitalWrite(column[11], LOW);
    delay(x);
    digitalWrite(column[15], LOW);
    delay(x);
    digitalWrite(column[14], LOW);
    delay(x);
    digitalWrite(column[13], LOW);
    delay(x);
    digitalWrite(column[12], LOW);
    delay(x);
    digitalWrite(column[8], LOW);
    delay(x);
    digitalWrite(column[4], LOW);
    delay(x);
    digitalWrite(column[0], LOW);
    delay(x);
  }
}
//go through all leds one at a time
void GoThroughAllLedsOneAtATime()
{
  int x = 15;
  for(int y = 0; y<5; y++)
  {
    //0-3
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], LOW);
      for(int i = 0; i<4; i++)
      {
        digitalWrite(column[i], HIGH);
        delay(x);
        digitalWrite(column[i], LOW);
        delay(x);
      }
    digitalWrite(layer[count-1], HIGH);
    }
    //4-7
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], LOW);
      for(int i = 4; i<8; i++)
      {
        digitalWrite(column[i], HIGH);
        delay(x);
        digitalWrite(column[i], LOW);
        delay(x);
      }
    digitalWrite(layer[count], HIGH);
    }
    //8-11
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], LOW);
      for(int i = 8; i<12; i++)
      {
        digitalWrite(column[i], HIGH);
        delay(x);
        digitalWrite(column[i], LOW);
        delay(x);
      }
    digitalWrite(layer[count-1], HIGH);
    }
    //12-15
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], LOW);
      for(int i = 12; i<16; i++)
      {
        digitalWrite(column[i], HIGH);
        delay(x);
        digitalWrite(column[i], LOW);
        delay(x);
      }
    digitalWrite(layer[count], HIGH);
    }
  }
}
