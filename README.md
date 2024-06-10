# Goal

Here is a simple example project to replay https://github.com/clangd/clangd/issues/1516
On this branch we use the eclipse clangd fork extension to see how it could resovle some issues

See CMakeLists.txt of app1 is configured to use **pack-div@1.0.0**

# Setup

* Vscode
* Extensions:
  * vscode-clangd-cdtcloud (multiprojects: enabled)
  * CMake tools

# Step to reproduce

* Open the workspace: apps-and-packs.code-workspace
* Configure cmake extension to use Clang 18.1.6 x86_64-pc-windows-msvc kit
* Build both app1 and app2

# OK use cases with official clangd => OK but end-up with .h with eclipse

* 1 (pack-div@**1.0.0**/src/div.c never opened)
  * Close all tabs
  * Command palette (Ctrl +Shift + P) => `Developer: reload window`
  * Open app1/src/main.c
  * Right click on `div(6,3)`
  
=> pack-div@**1.0.0**/src/div.h opens instead of div.c


# NOK use case with official clangd => OK but end-up with .h with eclipse

* Close all tabs
* Command palette (Ctrl +Shift + P) => `Developer: reload window`
* Dbl click to open pack-div@**2.0.0**/div.c
* Dbl click to open app1/src/main.c
* Right click on `div(6,3)`

 => redirection goes to pack-div@**1.0.0**/src/div.h. This is the expected pack but .h instead of .c
