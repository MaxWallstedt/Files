MaxHex
======

1. About
--------

MaxHex is a curses based command-line hex editor/viewer inspired by vim.

2. Usage
--------

To open a file with MaxHex, type:
```bash
$ MaxHex [options] <file>
```

Valid options are:
```
-h / --help     Print help message
-v / --version  Print version and copyright information
-a / --address  Specify address to open the file at
```

MaxHex can at the moment only open files for reading.

3. Building
-----------

MaxHex includes a build script `build.sh` that outputs object files to
`obj/` and the executable file to `bin/MaxHex`. If you wish to change to
other folders, you need to edit the script.

MaxHex requires a curses library to build. Ncurses is recommended for unix
like systems, and PDCurses should work well for Windows.

I only test my code to compile with `gcc` and `nasm`, and it's likely that it won't compile with other compilers/assemblers.

4. Installing
-------------

To install MaxHex to your system, simply copy `bin/MaxHex` to a folder in
your `$PATH`. You might need root access for this.

5. Contact
----------

You can contact me regarding MaxHex by sending an e-mail to
<max.wallstedt@gmail.com>.
