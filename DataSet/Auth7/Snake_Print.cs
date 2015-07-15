using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SnakePrint
{
    class Program
    {
        /*int * generateArray(int N)
        {
            return (int*)malloc(N * N * sizeof(int));
        }*/

        static void Main(string[] args)
        {
            int N = 4;
            int [,] a = new int[4,4] {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
            int i, j, len = N, count = 1, step, pattern = 0, rc = 0, start = 0;
            
            while (len>0)
            {
                step = pattern<2?1:-1;
                for (i = start, j = 0; j < len; i = i + step, j++)
                {
                    if (pattern == 0 || pattern == 2)
                        System.Console.Write(a[rc, i] + " , ");
                    else
                        System.Console.Write(a[i, rc] + " , ");
                }
                len = len - count;
                count = (count + 1) % 2;
                if (pattern == 1 || pattern == 2)
                    start = rc - 1;
                else
                    start = rc + 1;
                rc = i - step;
                pattern = (pattern + 1) % 4;
            }
            System.Console.ReadLine();
        }
    }
}
