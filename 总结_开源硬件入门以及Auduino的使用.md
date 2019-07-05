# 开源硬件Auduino开发板的入门使用及实例演示

------

___文档始创于 2019/7/5 晨___

___文档最后修改于 2019/7/5 晨___

------



## Day 1：入门

#### 上课内容：

> 1、创建了Github账号：Developer-Isaac-Xu
>
> 2、了解了版本控制工具：Git工具
>
> 3、安装了Arduino UNO开发平台的IDE：Arduino
>
> 4、安装了Fritzing用于硬件产品开发流程管理
>
> 5、安装了Processing的开发平台，明白Processing作为Java派生语言的优点
>
> 6、了解Linux OS基本操作控制代码，以及操作的便捷性

#### 课后作业：

> 将上述开发平台安装到了本地机，并查看了相关的开发文档，特别是Arduino开发板的Serial串口基本操作



## Day2：Arduino编程

#### 上课内容：

> 1、了解摩尔斯电码：用0/1交替输出信息，在电子硬件上表现为高低电平的不同组合
>
> 2、介绍了老师封装的Morse库
>
> 3、介绍了Github网页版上传文件的基本方法
>
> 4、介绍了Arduino各个接口以及电子硬件相关的功能、相关术语以及缩写的解释

*补充说明：总结出关于Arduino开发相关的一些缩写以及简略的解释，若有错误，敬请指正包涵：*

> MCU		单片机
>
> bus		总线，分为SCL（时钟线）和SDA（数据线）
>
> serial	串行、串行通信口（串口），通常是USB
>
> IC		集成电路=俗称芯片（大约是）
>
> pin		IC的引脚
>
> VCC		供电电压、供电接口
>
> circuit		整个电路
>
> VDD		元器件工作电压、工作接口
>
> device		电子元器件
>
> GND			接地线、接地口
>
> digital			数字信号接口。Digital I/O口，简称D口
>
> analogue		模拟信号接口，Analogue I/O口，简称A口
>
> PCI		外围设备总线，并行
>
> AREF		模拟输入基准电压接口



#### 课后作业：

> **实战项目1：**用LED灯明灭表示摩尔斯电码的dash、dot，从串口输入字母，让LED灯以字母的摩尔斯电码形式闪烁

```c
int led = 5;
void dash()
{
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(250);
}

void spa()
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
      }
    }
    else
    spa();
  }
}
/*
在本次实例开发中，由于不了解接口原理以及串口、和各接口的简称，开发工作进展缓慢。不过在反复尝试后终于成功运行，令人感觉非常快乐。但是由于Morse库使用时一直报错，不得已采用了自行编写代码实现Morse库功能的方案
*/
```



## Day3：认识电子元件及操作

#### 上课内容：

> 1、介绍了本地分布式版本控制工具Git
>
> 2、介绍了Arduino UNO R3、LED、电阻、电机、7段解码器CD4511以及相关的针脚端口详解
>
> 3、连接小车的电路图、以及Arduino UNO驱动电机的方法
>
> 4、Arduino UNO不能直接驱动七段数码管点亮，需利用CD4511转码。介绍了七段数码管以及CD4511的各个pin
>
> 5、仔细讲解了Tinkercad网站提供的Arduino拟真环境的使用

#### 课堂作业：

> **实战项目2：**用Arduino UNO驱动小车前进后退的接线图以及程序

```c
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
int income=0;
void loop()
{
  if (Serial.available()>0)
  {
	income=Serial.read();
      switch(income)
      {
      	case 'f':
      		forward();break;
  		case 'b':
      		back();break;
  		case 'l':
      		left();break;
  		case 'r':
      		right();break;
        case 's':
        	stop();break;
      }
  }
}

void forward()
{
	digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
}

void back()
{
	digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
}

void left()
{
	digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
}

void right()
{
	digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
}

void stop()
{
	digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
}
/*
本次实战中，在控制左右转向时，对左右电机旋转方向出现了错误理解。在思考很久后解决了
*/
```

#### 课后作业：

> **实战项目3：**用Arduino UNO和CD4511驱动七段数码管，使从串口接收一个数字，并在数码管上显示出像相应的数字

```c
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

/*
在本实例项目训练中，一开始由于不太熟悉CD4511的逻辑门，导致七段数码管数字显示异常。在查阅相关技术文档后获得了CD4511的逻辑真值表，于此基础上对七段数码管、CD4511以及Arduino UNO进行接线。

查阅文档知，锁鞘启用的引脚需要为LOW电平时输出数字。一开始并未明白，花费了大量时间

在软件设计方面，采用了统一输入，各个情况分别对应相应的处理函数。这样有助于在开发阶段提升代码的可维护性。不过现在想来，在显示操作中，可能会导致内存占用率高等问题
*/
```





## Day4：总结

#### 上课内容：

> 1、介绍Github客户端用法
>
> 2、介绍了利用ssh密钥解决文件无法上传Github的问题
>
> 3、对Day1的摩尔斯电码进行修改，使之能运行在Tinkercad的虚拟环境中
>
> 4、介绍了利用Markdown语法来构写博客、文档的方法

#### 课后作业：

> **实战训练4：**运用Markdown语法，完成本课程的总结

​	该项目展示如以上文档内容所示。

​	笔者是用开源软件Typora进行Markdown文档的编写。在使用中，笔者发现用Markdown语法进行文档编写能快速方便且美观地展示代码片段，而且在书写公式、编排版面以及转移到网页上显示上相比常用的Office Word或是Notepad++都更有优势



## 结尾与致谢：

​	在本次课程开始时笔者还是一个对开源硬件完全不了解的学生，所以在学习之中遇到了诸多的困难，一开始笔者认为这超出了笔者的能力范围无法解决，不过在与同学朋友交流、协助之后，完成一个个碰到的难题，在这之后的满足感令笔者非常开心。在经过四天的学习之后，笔者虽绝不敢称是由多了解，但是也能明白开源硬件给开发者带来的成就感和满足感是难以言喻的，笔者对开源硬件的学习将会继续进行。

​	最后感谢张老师和助教们的辛勤付出和耐心指导。老师认真负责工作原则和雷厉风行的工作态度体现了开发产品应有的细致和效率，这对还是大学生的笔者深有启发，笔者对此深怀谢意。