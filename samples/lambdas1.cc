#include <functional>
#include <vector>
#include <iostream>
  
int main() {
  std::function<bool(int)> isEven = [](int i)->bool 
    { return (i % 2) == 0; };

  std::function<int(int)> successor = [](int n)->int 
    { return n+1; };

  std::function<void(void)> print5 = [](void)->void 
    { std::cout << 5 << std::endl; };

  std::function<void(int)> print3x = [](int n)->void {
    std::cout << n << std::endl;
    std::cout << n << std::endl;
    std::cout << n << std::endl;
  };

  std::cout << isEven(10) << std::endl;
  std::cout << successor(10) << std::endl;
  print5();
  print3x(54321);

  int tens_digit = 5;
  std::function<int(int)> make_fifty_something =
    [tens_digit](int ones_digit) -> int {
    return tens_digit * 10 + ones_digit;
  };
  tens_digit--;
  std::cout << make_fifty_something(8) << std::endl;
  tens_digit--;
  std::cout << make_fifty_something(7) << std::endl;

  int tens_varies = 5;
  std::function<int(int)> make_umpty_something =
    [&tens_varies](int ones_digit) -> int {
    return tens_varies * 10 + ones_digit;
  };
  tens_varies--;
  std::cout << make_umpty_something(8) << std::endl;
  tens_varies--;
  std::cout << make_umpty_something(7) << std::endl;

  int count = 0;
  std::function<void(void)> increment = 
    [&count](void) -> void { count++; };
  int x = 10;
  int y = 11;
  std::function<void(void)> swap = 
    [&x,&y](void) -> void { 
    int tmp = x;
    x = y;
    y = tmp;
  };
  increment();
  std::cout << count << " " << x << " " << y << std::endl;
  increment();
  swap();
  std::cout << count << " " << x << " " << y << std::endl;
  increment();
  swap();
  std::cout << count << " " << x << " " << y << std::endl;

  std::vector<int> v = {12, 8, 17};
  std::function<void(void)> output = 
    [&v](void) -> void {
    for (int e : v) {
      std::cout << e << " ";
    }
    std::cout << std::endl; 
  };
  std::function<void(int,int)> change = 
    [&v](int index, int value) -> void { v.at(index) = value; };

  output();
  change(2,37);
  output();
  change(0,32);
  output();
  change(1,3);
  output();
}



