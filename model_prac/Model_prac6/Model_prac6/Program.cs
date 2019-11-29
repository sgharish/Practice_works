using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model_prac6
{
    class Program
    {
        static void Main(string[] args)
        {
            double num1, num2;
            Console.Write("enter the number:");
            num1 = Convert.ToDouble(Console.ReadLine());
            Console.Write("enter the another number:");
            num2 = Convert.ToDouble(Console.ReadLine());
            calculator(num1,num2);
            Console.ReadLine();

        }


        static void calculator(double a,double b)
        {
            double sum = a + b;
            Console.WriteLine(sum);

        }

    }
}
