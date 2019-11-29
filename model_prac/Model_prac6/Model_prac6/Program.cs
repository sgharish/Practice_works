using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace model_prac7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("enter the number to be cubes:");
            double a = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter the number to be added");
            double b = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine(cube(a));
            Console.WriteLine(add(a,b));
            Console.ReadLine();
        }
        static double cube(double num)
        {
            double result;
            result = num * num * num;
            return result;
        }

        static double add(double num1, double num2)
        {
            double cubed =cube(num1);
            double result = cubed + num2;
            return result;
        }
    }

}
