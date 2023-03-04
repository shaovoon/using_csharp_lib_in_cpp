using System;
using System.Collections.Generic;

namespace CSharp
{
    public class CSharpMath
    {
        public int Add(int a, int b)
        {
            return a + b;
        }
        public int AddList(List<int> arr)
        {
            int sum = 0;
            foreach(int n in arr)
                sum += n;

            return sum;
        }
    }
}
