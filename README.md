# School-Programming
ECCP problems with explanations. Written in Python and CPP

Please read and follow Cood Coding Practices

https://google.github.io/styleguide/pyguide.html

https://google.github.io/styleguide/cppguide.html

In short, for other's ease of reading follow next rules at a bare minimum:
1. Pick suggestive names for variables (e.g. instead of 'int n, k' use 'int numberOfDogs, numberOfCats)
2. Pick a naming convention and stick with it:
- for variables pick camelCase or snake_case but make sure they start with a small letter
- functions and classes should follow camelCase and start with capital letters
- global defines should be all capitals in snake_case
3. Indent all code with 4 spaces for each inner-scope
4. Separate functions by 2 whitelines and scopes with a whiteline in between

CPP specific practices:
1. Quit 'using namespace std'; if needed, stick to a namespace you wrote. 
https://www.youtube.com/watch?v=4NYC-VU-svE
2. Whereas Python inherently needs indenting for each scope, CPP does not. However, sticking to an indenting style improves code readability significantly
3. Use 'auto' whenever possible
4. Quit writing 'char word[]', this is C-style writing for strings. CPP has 'string' header that has 'std::string' inside it, as well as many useful methods
5. Understand when arrays are needed and how to make efficient use of their smaller over overhead compared to vectors. Also, remember that C-style arrays are different from C++ arrays(that you find in 'array' header). 
6. Learn the difference between 'std::endl' and '\n' and then stop using 'std::endl'. https://www.youtube.com/watch?v=GMqQOEZYVJQ
7. Make use of C++11's introduction of 'range-based for'. In combination with 'auto', it makes itarations through iterable data structures as easy as Python's 'for'
8. If sorted containers are needed, consider use of 'std::map' first
9. When writing C++ code use C++ headers. If a header has .h extension, it is a C header and you should use C++ version. (e.g. 'cmath' instead of 'math.h', 'cctype' instead of 'ctype.h')
