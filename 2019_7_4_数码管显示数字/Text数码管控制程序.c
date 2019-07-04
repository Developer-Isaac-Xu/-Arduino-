void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

int income=0;

void p0()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}

void p1()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
}

void p2()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}

void p3()
{
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
}

void p4()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}

void p5()
{
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
}

void p6()
{
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}

void p7()
{
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
}

void p8()
{
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
}

void p9()
{
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
}


void loop()
{
  if (Serial.available()>0)
  {
	income=Serial.read();
      switch(income)
      {
      	case '0':
      		p0();break;
  		case '1':
      		p1();break;
  		case '2':
      		p2();break;
  		case '3':
      		p3();break;
        case '4':
        	p4();break;
        case '5':
        	p5();break;
        case '6':
        	p6();break;
        case '7':
        	p7();break;
        case '8':
        	p8();break;
        case '9':
        	p9();break;
      }
  }
}
