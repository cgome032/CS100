# rshell-molle-monarchs

## Summary of project
This project is our RShell assignment that:
1. Prints a command prompt
2. Read in a command on one line.

Commands will the have the form:
cmd		=executable[argumentList][connector cmd]
connector	= || or && or ;

A few examples of the possible commands that can be executed using our RShell
$ ls -a
$ echo hello
$ mkdir test

All three of these commands are equivalent to:
$ ls -a; echo hello; mkdir test

## Known Bugs
1. Test Script files automatically exit, even thought command is not called
2. Unable to delete directory using rm -r command
3. Commands formatted with a space as the second (EG: ls && ' ' || ls) does not work
4. When using brackets "[]" to use symbolized test file, an extra "Binary operator expected" line is outputted.
5. Using parentheses with semicolons within causes undefined behavior.
6. Separating parentheses statements with semicolons causes undefined behavior. 
7. Nested parentheses do not work 100% of the time.
8. Piping does not work correctly

## Future Changes
1. Separate RShell file.
2. Change parse method by using tree data structure to make expansion easier
3. Make parentheses more functional
4. Make piping functional

