//#include <stdint.h>

static unsigned int c = 10;
unsigned int &c_ref = c;
bool my_bool_array[] = {false, true, true, false, true};

const bool isFalse = true;

typedef unsigned int uin32;

enum TestEnum
{
  Pass = 0,
  Fail = 1
};

class Base
{
  public:
    Base() = default;
  private:
    bool a_{ true };
};

class Derived: public Base
{
  public:
    Derived() = default;
  private:
    bool b_{ false };
};

namespace abc
{
  unsigned int d = 20;
  namespace def {
      unsigned int e = 30;
  }
}

unsigned int add_decimals(unsigned int a, unsigned int b)
{
  return a + b + c + abc::d + abc::def::e;
}

Base base1{};
Base * base2 = new Base{};

