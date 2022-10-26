/// Trolls are attacking your comment section!
///
/// A common way to deal with this situation is to remove all of the
/// vowels from the trolls' comments, neutralizing the threat.
///
/// Your task is to write a function that takes a string and return a
/// new string with all vowels removed.
///
/// For example, the string "This website is for losers LOL!" would
/// become "Ths wbst s fr lsrs LL!".
///
/// Note: for this kata y isn't considered a vowel.

#include <stdint.h>  // int64_t
#include <stdlib.h>  // calloc, realloc
#include <string.h>  // strlen

#define CODE_WARS
// #undef CODE_WARS  // If running outside of Code Wars, uncomment this line.

char * disemvowel(const char *str) {
  int64_t str_len = strlen(str) + 1;  // mutated: subtract by vowel count
  char *str_with_no_vowels = (char *) calloc(str_len, sizeof(char));
  int64_t index = 0;
  while (*str != '\0') {
    switch (*str) {
      case 'A': case 'a':
      case 'E': case 'e':
      case 'I': case 'i':
      case 'O': case 'o':
      case 'U': case 'u':
        str += 1;
        str_len -= 1;
        break;
      default:
        str_with_no_vowels[index++] = *str++;
        break;
    }
  }
  str_with_no_vowels = (char *) realloc(str_with_no_vowels, str_len);
  return str_with_no_vowels;
}

#ifndef CODE_WARS
# include "code_wars.h"

int32_t test_disemvowel(fn_main_args) {
  char *result = disemvowel(*argv);
  printf("old: '%s'\n", *argv);
  printf("new: '%s'\n", result);
  printf("- (%lld) vowels were removed.\n", (strlen(*argv) - strlen(result)));
  free(result);
  return EXIT_SUCCESS;
}


fn_main(
    "Removes all the vowels from the string",
    1,
    "<string>",
    test_disemvowel
)
#endif  // !CODE_WARS
