/// Given two integers a and b, which can be positive or negative, find
/// the sum of all the integers between and including them and return
/// it. If the two numbers are equal return a or b.
/// 
/// Note: a and b are not ordered!
/// 
/// Examples (a, b) --> output (explanation)
/// -----------------------------------------
/// (1, 0) --> 1 (1 + 0 = 1)
/// (1, 2) --> 3 (1 + 2 = 3)
/// (0, 1) --> 1 (0 + 1 = 1)
/// (1, 1) --> 1 (1 since both are same)
/// (-1, 0) --> -1 (-1 + 0 = -1)
/// (-1, 2) --> 2 (-1 + 0 + 1 + 2 = 2)

#include <stdint.h>  // int64_t

#define CODE_WARS
// #undef CODE_WARS  // If running outside of Code Wars, uncomment this line.

#ifdef CODE_WARS
// Not sure if it's a bug or not, but using the `(u)int_t` typedefs
// from `stdint.h` breaks the code on Code Wars.
# define int64_t long long int
#endif  // !CODE_WARS

int64_t get_sum(int64_t a, int64_t b) {
  if (a == b) {
    return a;
  }
  int64_t smallest = a < b? a: b;
  int64_t largest = a == smallest? b: a;
  int64_t total = smallest;
  while (smallest < largest) {
    total += (smallest += 1);
  }
  return total;
}

#ifndef CODE_WARS
# include <string.h>  // atoi

# include "code_wars.h"

int32_t test_get_sum(fn_main_args) {
  int64_t a = (int64_t) atoi(*(argv + 0));
  int64_t b = (int64_t) atoi(*(argv + 1));
  printf("%lld -> %lld = %lld\n", a < b? a: b, !(a < b)? a: b, get_sum(a, b));
  return EXIT_SUCCESS;
}

fn_main(
    "Calculates the sum of all values in range 'A' and 'B' inclusive",
    2,
    "<start> <end>",
    test_get_sum
)
#endif  // !CODE_WARS
