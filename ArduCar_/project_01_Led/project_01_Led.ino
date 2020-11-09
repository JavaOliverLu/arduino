

void setup()
{
        pinMode(8,OUTPUT);
        pinMode(7,OUTPUT);
        
  for(int i=0;i<10;i++)
    {
        digitalWrite(8,LOW);
        digitalWrite(7,1);
        delay(300);
        digitalWrite(8,1);
        digitalWrite(7,0);
        delay(300);
    }

}

void loop()
{

}
