# ft_printf
Recreation of standard libc printf function

## General information:

ft_printf is an openning project in algorithm branch, in project trees of 42ecole and 21school;
Main purpose of this - to give the deep knowledge of printf implementation and mainly, to give complex skills of using this function with the most popular flags and constructions;

## Functional

This implementation have all functions from Mandatory part, such as:
* Supply size, precision;
* Supply flags: ' ', '-', '+', '#', '0';
* Supply conversions:
  * 'c' - for chars;
  * 'diouxX' - for decimal numbers;
  * 'f' - for floating-point numbers;
  * 'p' - for pointers;
  * 's' - for strings;
  * 'n' - for placing data about printed characters into variable via address (bonus);

And some extra features (mostly for ft_ls)
* wildcard supply on size field;
* wildcard supply on precision field;

## Quality

This project passed:
* [This](https://github.com/jgigault/42FileChecker) checker (100/100, except for speed rate (*in developing*));
* [This](https://github.com/gavinfielder/pft) checker (2400/2409, except for some timeouts(*in developing*))
* Moulinette for 125/100;
* 3 frendly peers for average score 123/100;

### The Hardest Thing Of Project:

Work with float numbers and getting them from memory. Cutting of mantissa, exponenta and using number string representation to handle long math sum, sub and div.

### Features

Thanks to extracting long math part into isolated directory in libft, main part of project contatains only 3 .c files and total 14 normed (25 length, 80 width) functions (readabily R.I.P)

## TODO:

- [ ] Add an %e, %g, and binary flags, extra numeric bases for user's choice (1-16)
- [ ] Add file descryptor supply, to put infomation in files, not only in standart output
- [ ] Add color supply for text and background
- [ ] Add unicode
- [ ] Update code for more readability
- [ ] Add updated project to libft
