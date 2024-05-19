#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

int rs = 3, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // 初始化几个LCD需要使用的引脚，这里面的“rs”“en”等应换成你所连的引脚

void setup()
{
    lcd.begin(16, 2);          //   初始化lcd ，并定义LCD1602的规格
    lcd.setCursor(0, 0);       //   设置指针 在x=0，y=0的位置
    lcd.print("Hello World!"); //   lcd 显示字符串
    lcd.setCursor(0, 1);
    lcd.print("lwq");
}
void loop()
{
    lcd.setCursor(4, 1);        // 把光标设置在0列1行(第2行开头)上
    lcd.print(millis() / 1000); // 把系统运行的时间打到屏幕上
}