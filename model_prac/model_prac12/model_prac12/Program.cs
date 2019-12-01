using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace model_prac12
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(GetPow(2, 5));
            Console.ReadLine();
        }
        static int GetPow(int bnum,int pnum)
        {
            int result = 1;
            for (int i =0; i<pnum;i++ )
            {
                result = result * bnum;
            }

            return result;
        }
    }
}
