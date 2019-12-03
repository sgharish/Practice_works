using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace model_prac15
{
    class Program
    {
        static void Main(string[] args)
        {
            Books book1 = new Books("Art of physics in engineering", "Harish", "engineering");
            Books book2 = new Books("Medicen for life", "Harish", "Medicen");
            Books book3 = new Books("Engineering is more than anything", "Harish", "engineering");
            Books book4 = new Books("Quantam physics", "Harish", "science");
            Books book5 = new Books("Differential kienamatics", "Harish", "engineering");

            book4.suggestion();
            Console.ReadLine();
        }
    }
}
