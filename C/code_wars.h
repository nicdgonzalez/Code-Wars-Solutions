/// Helper functions, macros, etc. for quickly running Code Wars
/// solutions outside of Code Wars' online-built-in code editor.

#ifndef CODE_WARS_H_
# define CODE_WARS_H_

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

# define BOOL_TO_STR(expression) (expression? "true": "false")

# define fn_main_args int32_t argc, const char **argv

# define fn_main(str_brief, int_expected_args, str_usage, fn_test) \
int32_t main(fn_main_args) { \
  if (argc != (int_expected_args + 1)) { \
    printf("Usage: %s %s\n", *argv, str_usage); \
    return EXIT_FAILURE; \
  } \
  argv += 1;  /* argv[0] is not needed beyond the usage check. */ \
  printf("%s:\n", str_brief); \
  return fn_test(argc, argv); \
}

#endif  // !CODE_WARS_H_
