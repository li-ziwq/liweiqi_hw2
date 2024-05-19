/* 使用串口助手和串口通信方式控制LED灯的亮灭，同时每次发送控制指令并被正确接受时，在串口助手的控制台上进行显示。
内容如下：
1. 在串口助手的发送栏输入相应的指令，并进行发送给单片机。比如'1'对应亮LED1
2. arduino接受到相应的串口的字符串，并进行解码，同时和预设的指令进行对比，比如说解析到字符串'1'，LED1灯亮，解析到字符串'2'，LED2亮。其中特别注意这里说的是字符串，而不是整数，因为传输的是字符串，解析的也是字符串，整数会先转换成字符串再传（大概，我有点忘记了，你们自己踩踩坑）
3. 当解析到字符串后，执行相应的操作，比如说如果现在LED1是灭的，接受到'1'的指令，LED1亮起。如果现在LED1是亮的，接受到'1'的指令，LED1亮。如果接受到指令'4'，没有相应的指令，则不执行动作。
4. 完成动作后，使用串口通讯给电脑发一个反馈，比如说执行了LED1开灯指令后，发送'LED1亮'。该过程可以使用自带的print函数（还是printf我忘记了） */
#include <Arduino.h>

int led_1 = 2;

int led_2 = 3;

String myString = ""; // 接收串口发送过来的值

String short_String = ""; // 存储myString截取后的字符串

String Control_LED[] = {"led_on(1)", "led_off(1)", "led_on(2)", "led_off(2)"}; // 定义字符串数组

void setup()
{
    pinMode(led_1, OUTPUT);
    pinMode(led_2, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0) // 如果串口有数据
    {
        myString = Serial.readStringUntil('\n');         // 读取字符串
        short_String = myString.substring(0, 9);         // 截取输入字符串myString的前9位字符
        Control_LED[0] = Control_LED[0].substring(0, 9); // 截取字符串Control_LED[0]的前9位字符
        Control_LED[1] = Control_LED[1].substring(0, 9); // 截取字符串Control_LED[1]的前9位字符
        Control_LED[2] = Control_LED[2].substring(0, 9); // 截取字符串Control_LED[2]的前9位字符
        Control_LED[3] = Control_LED[3].substring(0, 9); // 截取字符串Control_LED[3]的前9位字符

        if (short_String.compareTo(Control_LED[0]) == 0) // 比较short_String和截取后led_on(1)是否相同
        {
            Serial.println("LED1_ON");
            digitalWrite(led_1, HIGH);
        }
        else if (short_String.compareTo(Control_LED[1]) == 0)
        {
            Serial.println("LED1_OFF");
            digitalWrite(led_1, LOW);
        }
        else if (short_String.compareTo(Control_LED[2]) == 0)
        {
            Serial.println("LED2_ON");
            digitalWrite(led_2, HIGH);
        }
        else if (short_String.compareTo(Control_LED[3]) == 0)
        {
            Serial.println("LED2_OFF");
            digitalWrite(led_2, LOW);
        }
    }
}