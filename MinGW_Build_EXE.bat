call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -std=c++11 -Wall -Wextra -pedantic -O2 -o Arcanum_MinGW.exe -static -s    ^
source\*.cpp             ^
source\Core\*.cpp        ^
source\Formats\*.cpp     ^
source\Forms\*.cpp       ^
source\Game\*.cpp        ^
source\Gameplay\*.cpp    ^
source\Graphics\*.cpp    ^
source\Loaders\*.cpp     ^
source\Managers\*.cpp    ^
source\Objects\*.cpp     ^
source\Painters\*.cpp    ^
source\Readers\*.cpp     ^
source\Scripts\*.cpp     ^
source\Widgets\*.cpp     ^
-Iinclude\ -Idependencies\LDL\include\ -L. -ldependencies\LDL\lib\LDL_MinGW

pause