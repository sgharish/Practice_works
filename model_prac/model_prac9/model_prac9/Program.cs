using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace model_prac9
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(GetDay(10));
            Console.ReadLine();
        }
        static string GetDay(int daynum)
        {
            string dayname;
            switch (daynum )
            {
                case 0:
                    dayname = "sunday";
                    break;

                case 1:
                    dayname = "monday";
                    break;

                case 2:
                    dayname = "Tuesday";
                    break;


                case 3:
                    dayname = "Wednesday";
                    break;


                case 4:
                    dayname = "thursday";
                    break;


                case 5:
                    dayname = "Friday";
                    break;


                case 6:
                    dayname = "Saturday";
                    break;

                default:
                    dayname = " not a day in earth";
                    break;

            }
            return dayname;

        }
    }
}
