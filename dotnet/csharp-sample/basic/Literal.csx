// 整数
sbyte sb = 127;
byte b = 255;
short s = 30000;
ushort us = 65535;
int i;
uint ui = 6000u;
long l = 10000l;
ulong ul = 1000UL;

// depends on platforms
nint ni;
nuint nui;

int hex = 0xcafe;
int octal = 012345;
int binary = 0b1010_1010;

// initializing with default values
int defaultInt = default;
var defaultDouble = default(double);

// 布尔型
bool isChecked = true;

// 小数
float f = 3.1f;
double d = 3.14156d;

// 高精度数字
decimal decimalNumber = 123475m;

// 字符类型
char c = 'c';
string text = "abc";

System.Console.WriteLine(c);
System.Console.WriteLine(text);
