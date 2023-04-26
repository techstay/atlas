
#pragma warning disable 219

namespace Yitian.Study.CSharpSample.Basic
{
    class DataType
    {
        internal static void Show()
        {
            Integers();
            Floats();
            Booleans();
            Characters();
            ComplexTypes();
        }
        static void Integers()
        {
            //有符号和无符号整数
            byte b = 10;
            short s = -20;
            int i = -30;
            long l = -50L;

            sbyte sb = -10;
            ushort us = 20;
            uint ui = 30;
            ulong ul = 50L;
        }

        static void Floats()
        {
            //单精度和双精度浮点数
            float f = 3.14F;
            double d = 3.1415926;
        }

        static void Booleans()
        {
            //布尔类型
            bool no = false;
            bool yes = true;
        }

        static void Characters()
        {
            //字符类型
            char c = 'A';
        }

        static void ComplexTypes()
        {
            //字符串和decimal，它们其实都是类类型，只不过拥有别名
            string str = "12345";
            decimal salary = 15000.0M;
        }
    }
}

#pragma warning restore 219