using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace model_prac4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("welcome to the matlib theater game.\n what is Matlib theater: We will provide you with a script which is funny and serious so you can have fun with you partner or team \n So lets get Started !! ");
            Console.Write("Enter your Name:"); //this will print on the same line printf
            string name = Console.ReadLine();
            Console.Write("Enter your age:"); //this will print on the same line printf
            string age = Console.ReadLine();

            Console.Write("Enter your friends name:"); //this will print on the same line printf
            string fname = Console.ReadLine();

            Console.Write("Enter your favourite movie:"); //this will print on the same line printf
            string movie = Console.ReadLine();

            Console.Write("Enter your biggest fear:"); //this will print on the same line printf
            string fear = Console.ReadLine();

            Console.WriteLine("Read these lines to have fun:\n Narater: Once upon a time there live two friends who were searching for nothing \n friend 1: You know him \n friend 2 : you know who \n friend 1: He who watchs " + movie + "all the time. He who is friend of " + fname + " . he who has this crazy fear named " + fear + ".");
            Console.WriteLine("friend 2 : you are talking about" + name + "," + age + "old fellow");
            Console.ReadLine();
            //this line waits for the user to enter the text
        }
    }
}
