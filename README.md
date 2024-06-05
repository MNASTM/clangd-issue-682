# Goal

Here is a simple example project to replay https://github.com/clangd/clangd/issues/1516

See CMakeLists.txt is configured to use **pack-div@1.1.0**

# Setup

* Vscode
* Extensions:
  * Clangd
  * CMake tools

# Step to reproduce

* Open this repo in Vscode
* Configure cmake extension to use Clang 18.1.6 x86_64-pc-windows-msvc kit
* Build => compile_commands.json should be generated in build dir
* Configure clangd extension to start with the compile_commands.json explicitly:
  * settings -> "Clangd: Arguments"
  * Add item -> --compile-commands-dir
  * Add item -> \<path\>/\<to\>/clang-issue-682/build

# OK use cases

* 1 (pack-div@**1.1.0**/src/div.c never opened)
  * Close all tabs
  * Command palette (Ctrl +Shift + P) => `Developer: reload window`
  * Open src/main.c
  * Right click on `div(6,3)`
  
=> pack-div@**1.1.0**/src/div.c opens as expected

* 2 (pack-div@**1.1.0**/src/div.c opened in tab from the beginning but never active)
  * Close all tabs
  * Dbl click to open pack-div@**1.0.0**/div.c
  * Dbl click to open src/main.c
  * Command palette (Ctrl +Shift + P) => `Developer: reload window`
  * main.c should already be the active editor
  * Right click on `div(6,3)`

 => pack-div@**1.1.0**/src/div.c opens as expected

* 3 (pack-div@**1.1.0**/src/div.c opened before pack-div@**1.0.0**/src/div.c)
  * Close all tabs
  * Command palette (Ctrl +Shift + P) => `Developer: reload window`
  * Dbl click to open pack-div@**1.1.0**/div.c
  * Dbl click to open pack-div@**1.0.0**/div.c
  * Dbl click to open src/main.c
  * Right click on `div(6,3)`

 => pack-div@**1.1.0**/src/div.c opens as expected

* 4 (pack-div@**1.1.0**/src/div.c opened after pack-div@**1.0.0**/src/div.c)
  * Close all tabs
  * Command palette (Ctrl +Shift + P) => `Developer: reload window`
  * Dbl click to open pack-div@**1.0.0**/div.c
  * Dbl click to open pack-div@**1.1.0**/div.c
  * Dbl click to open src/main.c
  * Right click on `div(6,3)`

 => pack-div@**1.1.0**/src/div.c opens as expected


# NOK use case

* Close all tabs
* Command palette (Ctrl +Shift + P) => `Developer: reload window`
* Dbl click to open pack-div@**1.0.0**/div.c
* Dbl click to open src/main.c
* Right click on `div(6,3)`

 => redirection goes to pack-div@**1.0.0**/src/div.c which now becomes the active tab while we were expecting pack-div@**1.1.0**/src/div.c to open
