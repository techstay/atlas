using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Yitian.Study.CSharpSample.Basic
{
    class VariableDeclaration
    {
        internal static void DeclareVariables()
        {
            //各种变量声明
            int i;
            i = 5;

            //可以在一行同时声明多个变量
            int j = 5, k = 6;

            //变量在使用前必须初始化
            int m = 6;
            Console.WriteLine(m);

            //声明常量，常量是不可变的
            /*常量必须在编译起就确定值
             */
            const string s = "我是不可变的";
        }
    }
}