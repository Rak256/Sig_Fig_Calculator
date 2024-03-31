#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

// This program performs division with 2 numbers inputted by the user and prints the answer in scientific notation
// with the amount of sig figs defined by the user.
int main();

// Integer power function
int exponentiate( int base, int exponent ){
  int result{1};
  if ( exponent == 0 ){
    return 1;
  }
  else {
  for (int i{0}; i < exponent; i++){
    result *= base;
  }
  }

  
  return result;
}
//Function to determine how much num must be displaced by to get a non-zero starting digit
int exponent(int n, int d){
  int count{0};

  // reduce count if quotient is less than 1 (quotient is always positive), increase count if quotient is greater than 9.
 
// if 0 < n/d < 1
if (n/d == 0){
 
  while (n < d){
    n = n*10;
    count --;
  }
  
}
// if n/d > 9
  else{
    while (n/d > 9){
      n /= 10;
      count++;
    }
   
  }
   return count;
}

void print_significand(int n, int d, int dig, int e){
  int top{};
  int place{exponentiate(10, std::abs(e))};
  
  if (n > d){
    top = n/place;
  }
  
  else{
    top = n*place;
  }
  
  std::cout << top/d << ".";

  int rem {top%d*10};

  for (int i{0}; i < dig-1; i++){
    std::cout << rem/d;
    rem = rem%d*10;
  }
  
  std::cout << "*10^" << e;
  
}

int main() {
  int num{};
  bool neg{false};
  std::cout << "Enter the numerator: ";
  std::cin  >> num;

  int den{};
  std::cout << "Enter the denominator: ";
  std::cin  >> den;

  int digits{};
  std::cout << "Enter the number of significant digits: ";
  std::cin  >> digits;
  

  if ( den == 0 || digits <= 0 ) {
    return 0;
  }
  
  if (num == 0){
  std::cout << "0. x 10^0" << std::endl;
    return 0;
  }

  int exp{exponent(num, den)};
  
   if (num < 0)
  {
    if (den < 0){
    num = -num;
    den = -den;
    }
    else{
    num = -num;
    std::cout << "-";
    neg = true;
    }
  }

  else{
    if (den < 0){
    den = -den;
    neg = true;
      std::cout << "-";
    }
  }
  std::cout << num << "/" << den << " = ";
  
  if (neg){
    std::cout << "-";
  }

  print_significand(num, den, digits, exp);
  
   return 0; 
}