using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SetTopBoxPath
{
    class Program
    {
        int geti(char[,] settopbox, char ch)
        {
            int i, j;
            for (i = 0; i < 6; i++)
                for (j = 0; j < 5; j++)
                    if (settopbox[i, j] == ch)
                        return i;
            return -1;
        }
        int getj(char[,] settopbox, char ch)
        {
            int i, j;
            for (i = 0; i < 6; i++)
                for (j = 0; j < 5; j++)
                    if (settopbox[i, j] == ch)
                        return j;
            return -1;
        }
        static void Main(string[] args)
        {
            int curri = 0, currj = 0, ch, desti, destj, s = 0;
            char[] str = new char[] {'z', 'o', 'z', '\0'};
            //char[,] settopbox = new char[6,5] { { 'a','b','c','d','e'}, {'f','g','h','i','j'}, {'k','l','m','n','o'}, {'p','q','r','s','t' }, {'u','v','w','x','y' }, {'z' } };
            while (str[s] != '\0')
            {
                if (str[s] >= 'A' && str[s] <= 'Z')
                    ch = str[s] - 'A';
                else if (str[s] >= 'a' && str[s] <= 'z')
                    ch = str[s] - 'a';
                else
                    break;
                
                //desti = geti(settopbox,str[s]);
                //destj = getj(settopbox,str[s]);
                desti = ch / 5;
                destj = ch % 5;

                while (desti != curri || destj != currj)
                {
                    if (desti < curri)
                    {
                        System.Console.WriteLine("Up");
                        curri--;
                    }
                    else if (destj < currj)
                    {
                        System.Console.WriteLine("Left");
                        currj--;
                    }
                    else if (destj > currj)
                    {
                        System.Console.WriteLine("Right");
                        currj++;
                    }
                    else if (desti > curri)
                    {
                        System.Console.WriteLine("Down");
                        curri++;
                    }                   
                }
                System.Console.WriteLine("Ok");
                s++;
            }
            System.Console.ReadLine();
        }
    }
}
