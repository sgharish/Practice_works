using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model_prac8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome leute! this is a simple code to check your gender.\n How does it work? \n Choose the best answer for the following questions question");
            Console.Write("Enter your Name:");
            string name = Console.ReadLine();
            Console.Write("I like to play cricket(y/n)(use only small letter):");
            char resp1 = Convert.ToChar(Console.ReadLine());
            Console.Write("I would like to drink tea/ coffee(t/c)(use only small letter):");
            char resp2 = Convert.ToChar(Console.ReadLine());
            Console.Write("I would like to play mobile games/ PS4(m/p) :");
            char resp3 = Convert.ToChar(Console.ReadLine());
            gender(resp1, resp2, resp3, name);
            Console.ReadLine();

        }
        static void gender(char a, char b, char c, string name)
        {
            char y = 'y'; 
            char n = 'n';
            char t = 't';
            char cof = 'c';
            char m = 'm';
            char p = 'p';

            if (a == y && b == t && c == p)
            {
                Console.WriteLine(name + " is a male");

            }else if(a == n && b==cof && c == m ) 
            {
                Console.WriteLine(name + " is a female");
            }
            else
            {
                Console.WriteLine(name + " is a person with unique taste");
            }

        }
    }
}
