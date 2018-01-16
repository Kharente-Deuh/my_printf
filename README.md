# my_printf
You must recode the printf function from the C library according to the C99 standard. Your
function should be prototyped like the printf function.
You do not have to implement the C library printf buffer handling.

You must process all printf formating flags except the following (which are optional):
• float or double types management,
• %n flag management,
• " * " , " ’ " and " I " (capital i) flags management

You must add a %S formating flag, which prints a character string (like %s). However,
non-printable characters (ASCII value strictly smaller than 32 or greater or equal than 127)
must be represented by a backslash to be followed by the character’s value in octal base.
