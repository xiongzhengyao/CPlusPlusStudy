#include <iostream>


// Lambda 函数计算1+2+3+...+n
class Lambda
{
public:
  int sum(int n)
  {
    return [n](int x)
    {
      int sum = 0;
      for (int i = 1; i <= n; ++i)
      {
        sum += x;
      }
      return sum;
    }(n);
  }
};

int main()
{
    auto lambda = [](){return 42;};
    
}
