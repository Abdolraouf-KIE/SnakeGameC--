# 2nd October

- Compeleted the Snake project (there are few TODOs).
- Used linux compiler for compiling and linking
- Vscode: configure the vscode for building (using the tasks.json). the use of lauch.json was not explored.

## what I learned:

1. how to config the tasks files for vscode to get compilation only, or to get linking only etc.
2. how to use the g++ compiler and the common flags such as `-S -c -o -g` and `pkg-config gtkmm-3.0 -cflags` or `pkg-config gtkmm-3.0 -libs`
3. the `pkg-config` is used in bash to access link or compile libraries. full list can be accessed via the `--list-all` flag. 
4. linux bash can save the output of a command into a file using `history > log.txt`
5. The flags required for the compiler and the linker are always the same: `--cflags` and `--libs` respectively.

# 3rd October

- Using gdb to debug the snakegameC++ codes.
- Using mkaing multiple `tasks` array in `tasks.json` will allow easy alternation for linking and compiling.
-  

6. VScode's `tasks.json` can be use to store the configurations for both compiler and linker. you will have `tasks` and `tasks1` array and when u build the file you will use the configuration in `tasks` array.
7. We can use gdb for basic debuging in the bash terminal. There are many useful commands such as calling function, setting variables and etc.
8. 

# 4th October

## what i learned

1. used bash scripting to modify the output of `pkg-config gtkmm-3.0 --libs` so that the spaces are replaced with ",\n". This was done using seb instead of tr command as a character was to be replaced with multiple characters.
2. Vscode has some sort of cache system for the run-build task as despite changing tasks.json, there was no change in the build parameters.
3. debugging using vscode debugger instead of gdb in terminal. vscode can allow easy adding of breakpoints, including conditional breakpoints. I still dont know how the fuck the hitcount works.
4. the purpose of flags for compilation and linking (-l -L and -I flags).
5. locations where the g++ looks for libraries can be found by using a command or by finding the PATH of the g++. `g++ -E -x c++ - -v < /dev/null `
6. what is the pkg-config and what are the .pc files. They are used to store informations about packages such as flags and other meta data.
7. After installing a libarary such as C++ (or any packages from apt install), we can use `dpkg -L <package_name>` to list all the directories created when installing the package. dpkg stands for debian packages and they are used for installation and information provision of debian packages. Using the afformentioned command the directories and .pc (for pkg-config) was identified.

5. Making the make and cmake files for the project.




## Interesting things not done.
1. nautilus scripts: how to use them
2. using gdb commands in vscode
3. compiler options for different cpus (i downlaod a redhat.pdf that talks about it).
4. playing around with static and dynamic libraries.
5. Learn more about the compilation process (use the low level language book-chapter 5).
6. 






