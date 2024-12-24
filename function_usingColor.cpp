#include <iostream>
#include <windows.h>
using namespace std;
//function setColor
typedef enum{
    BLACK = 0, BLUE = 1, GREEN = 2, AQUA = 3, RED = 4, PURPLE = 5, YELLOW = 6, WHITE = 7, GRAY = 8, LIGHT_BLUE = 9, LIGHT_GREEN = 10, LIGHT_AQUA = 11, LIGHT_RED = 12, LIGHT_PUURPLE = 13, LIGHT_YELLOW = 14, LIGHT_WHITE = 15
}
ConsoleColors;
typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;
short setTextColor(const ConsoleColors foreground){
    Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    BufferInfo bufferInfo;
    if(!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
       return 0;
    Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
    SetConsoleTextAttribute(consoleHandle, color);
    return 1;
}
int main(){
    //using Color for (A Line) in App with Code
    setTextColor(RED);
    cout << "Hello";
    setTextColor(BLUE);
    cout << endl << "Wellcome" << endl;
    setTextColor(WHITE);
    cout << "GoodBye" << endl;
    return 0;
}