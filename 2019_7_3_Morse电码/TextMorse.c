int led = 5;

void dash()
{
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(250);
}
void space()
{
  delay(3000);
}

void dot()
{
  digitalWrite(led,HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(250);
}

char MORSE[][5] = {
  {'*', '-'},{'-', '*', '*', '*'},{'-', '*', '-', '*'},{'-', '*', '*'},{'*'},{'*', '*', '-', '*'},{'-', '-', '*'},{'*', '*', '*', '*'},{'*', '*'},{'*', '-', '-', '-'},{'-', '*', '-'},{'*', '-', '*', '*'},{'-', '-'},{'-', '*'},{'-', '-', '-'},{'*', '-', '-', '*'},{'-', '-', '*', '-'},{'*', '-', '*'},{'*', '*', '*'},{'-'},{'*', '*', '-'},{'*', '*', '*', '-'},{'*', '-', '-'},{'-', '*', '*', '-'},{'-', '*', '-', '-'},{'-', '-', '*', '*'}
};
void setup() 
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
int comechar = 0;
void loop() 
{
  String morse = "";
  char sign;
  if (Serial.available() > 0)
  {
    comechar = Serial.read() - 97;
    if (comechar >= 0 && comechar <= 25)
    {
      morse = MORSE[comechar];
      morse += ' ';
      for (int i = 0;i < 5; i++)
      {
        sign = morse[i];
        if (sign == '*')
          dot();
        else if (sign == '-')
          dash();
        Serial.print(sign);
      }
      //Serial.print(morse);
    }
    else
    Serial.println();
    space();
  }
}
