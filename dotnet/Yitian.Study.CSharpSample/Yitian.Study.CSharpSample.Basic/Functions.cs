using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Yitian.Study.CSharpSample.Basic
{
    class Functions
    {
        internal static void Show()
        {
            PlainFun();
            GetSum();
            GetSum(10, 20);
            DefaultParamFun();
            VarargFun(1, 2, 3);
            //命名方式传递实参
            ManyParamsFun(a: 10, b: "555", c: 23D, d: 150M);

            Console.WriteLine($"5的阶乘是{GetFactorial(5)}");
        }

        static void PlainFun()
        {
        }

        static int GetSum()
        {
            return 100;
        }

        static int GetSum(int a, int b)
        {
            return a + b;
        }

        static int DefaultParamFun(int a = 10, int b = 20)
        {
            return a + b;
        }

        static int VarargFun(params int[] integers)
        {
            return integers.Sum();
        }

        static void ManyParamsFun(int a, string b, double c, decimal d)
        {
            Console.WriteLine($"a={a},b={b},c={c},d={d}");
        }

        static int GetFactorial(int n)
        {
            if (n == 1 || n == 0)
            {
                return 1;
            }
            else
            {
                return n * GetFactorial(n - 1);
            }
        }
    }
}