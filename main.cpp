#include <iostream>
#include <windows.h>

/* TRASH CODE FOR NOW UNTIL MAYBE FUTURE USE
void mouseClick() {
    inputs[0].type = INPUT_MOUSE;
    // X coordinate
    inputs[0].mi.dy = ;
    // Y coordinate
    inputs[0].mi.dy;
}*/

INPUT inputs[2] = {0};
int main() {

    typedef struct tagMOUSEINPUT {
        LONG      dx;
        LONG      dy;
        DWORD     dwFlags;
    };

    /* THIS IS IF YOU WANT THE MOUSE TO CHANGE TO A SPECIFIC COORDINATE.
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dx;
    inputs[0].mi.dy;
    */
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    inputs[2].type = INPUT_MOUSE;
    inputs[2].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(3, inputs, sizeof(INPUT));

    std::cout << "Hello, World!" << std::endl;
    return 0;
    // SendInput()
}
