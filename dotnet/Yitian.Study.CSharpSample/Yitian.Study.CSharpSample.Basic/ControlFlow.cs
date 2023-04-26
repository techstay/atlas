using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Yitian.Study.CSharpSample.Basic
{
    class ControlFlow
    {
        internal static void Show()
        {
            ConditionStmt();
            LoopStmt();
        }

        static void ConditionStmt()
        {
            //if语句
            bool condition = 1 == 2 - 1;
            if (condition)
            {
                Console.WriteLine("条件为真");
            }
            else
            {
                Console.WriteLine("条件为假");
            }

            //switch语句
            //在C#中，每个标签之后的break是必须的，否则编译通不过
            int x = 5;
            switch (x)
            {
                case 1:
                    Console.WriteLine("x是1");
                    break;
                case 2:
                case 3:
                    Console.WriteLine("x是2或3");
                    break;
                default:
                    Console.WriteLine("x是其他值");
                    break;
            }
        }

        static void LoopStmt()
        {
            //for循环
            for (int i = 0; i < 9; ++i)
            {
                Console.Write(i);
            }
            Console.WriteLine();

            //while循环
            int sum = 0, it = 0;
            while (it <= 10)
            {
                sum += it;
                it++;
            }
            Console.WriteLine($"sum={sum}");

            //do-while循环
            sum = 0;
            it = 0;
            do
            {
                sum += it;
                it++;
            } while (it <= 10);
            Console.WriteLine($"sum={sum}");

        }
    }
}