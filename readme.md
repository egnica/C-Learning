## Basic Compile Command

cc filename.c -o outputName

if your file is: variables.c
Then compile with: cc variables.c -o variables
To run it: ./variables

| Part           | Meaning                                                                                                |
| -------------- | ------------------------------------------------------------------------------------------------------ |
| `cc`           | The C compiler - cc (Clang on macOS) \n Clang is part of the Xcode Command Line Tools package for mac. |
| `variables.c`  | Your source code                                                                                       |
| `-o variables` | “Output the compiled program with this name”.                                                          |
| `./variables`  | Run the program                                                                                        |

### C Format Specifiers (stdio.h)

| Specifier | Meaning / Description                 | C Data Type(s) Used With | Example Value    |
| --------- | ------------------------------------- | ------------------------ | ---------------- |
| `%d`      | Signed decimal integer                | `int`                    | `42`             |
| `%i`      | Signed integer (same as %d in printf) | `int`                    | `42`             |
| `%u`      | Unsigned decimal integer              | `unsigned int`           | `42`             |
| `%f`      | Floating point number                 | `float`, `double`        | `3.14`           |
| `%lf`     | Double-precision floating point       | `double`                 | `3.14159`        |
| `%c`      | Single character                      | `char`                   | `'A'`            |
| `%s`      | String (char array / char pointer)    | `char *`                 | `"Hello"`        |
| `%ld`     | Signed long integer                   | `long`                   | `2000000000`     |
| `%lu`     | Unsigned long integer                 | `unsigned long`          | `4000000000`     |
| `%x`      | Unsigned hexadecimal (lowercase)      | `unsigned int`           | `7fa`            |
| `%X`      | Unsigned hexadecimal (uppercase)      | `unsigned int`           | `7FA`            |
| `%p`      | Pointer address                       | any pointer type         | `0x7ffee4c3a988` |
| `%%`      | Literal percent sign                  | _(none)_                 | `%`              |
