#include <windows.h>
#include <iostream>
int startKey = VK_F3;
int stopKey = VK_END;

INPUT inputs[3] = {0};

void mouseClick() {
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    inputs[2].type = INPUT_MOUSE;
    inputs[2].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(3, inputs, sizeof(INPUT));
}

int main() {
    int milliSecond;
    const int minimumSeconds = 50;
    std::cout << "För att använda programmet så skall du ange millisekunder, sedan skall du peka på vart du vill autoclicka sedan trycka på F3 knappen i tangetbordet. " << std::endl;

    std::cout << "" << std::endl;
    std::cout << "Ange millisekunder: ";
    std::cin >> milliSecond;
    if(milliSecond < minimumSeconds) {
        std::cout << "Minimum millisekunder var 50ms, du kan inte gå ner mer än detta. Försök igen." << std::endl;
    } else {
      while(!(GetAsyncKeyState(stopKey))) {
          execution: if(GetAsyncKeyState(startKey)) {
                while(!(GetAsyncKeyState(stopKey))) {
                    mouseClick();
                    Sleep(minimumSeconds);
                }
            }
        }
        if(GetAsyncKeyState(stopKey)) {
            std::cout << "Programmet är pausat" << std::endl;
            goto execution;
        }

        }
    }




