For g++ on windows use -municode for compilation.

Windows compilation to include windows entry point
 g++ src\appmain.cpp src\main.cpp src\WindowManager.cpp src\Input.cpp -o main -I"include/" -municod