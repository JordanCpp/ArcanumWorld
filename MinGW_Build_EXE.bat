call "C:\Downloads\codeblocks-20.03mingw-nosetup\MinGW\mingwvars.bat"

g++ -std=c++11 -Wall -Wextra -pedantic -O2 -o Arcanum_MinGW.exe -static -s    ^
source\*.cpp           ^
source\Core\*.cpp           ^
source\Formats\*.cpp           ^
source\Game\*.cpp           ^
source\Graphics\*.cpp           ^
source\Loaders\*.cpp           ^
source\Managers\*.cpp           ^
source\Objects\*.cpp           ^
source\Painters\*.cpp           ^
source\Readers\*.cpp           ^
source\Widgets\*.cpp           ^
source\Forms\*.cpp           ^
-Iinclude\ -Idependencies\LDL\include\ -L. -ldependencies\LDL\lib\LDL_MinGW

pause