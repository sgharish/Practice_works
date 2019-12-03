using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace model_prac15
{
    class Books
    {
        string name, author, gener;
        public Books(string bname, string bauthor, string bgener)
        {
            name = bname;
            author = bauthor;
            gener = bgener;
        }
        public void suggestion()
        {
            if (gener == "medicen")
            {
                Console.WriteLine("suggested for medicen students");
            }
            else if(gener == "engineering")
            {
                Console.WriteLine("suggested for engineering students");
            }
            else
            {
                Console.WriteLine("suggested for all students");
            }
        }
        }
    }

