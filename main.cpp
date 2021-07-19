#include <windows.h>
#include <iostream>


int StartKey = VK_F3;
int StopKey = VK_END;

INPUT inputs[3] = {0};
void MouseClick() {
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    inputs[2].type = INPUT_MOUSE;
    inputs[2].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(3, inputs, sizeof(INPUT));
}


int main() {
    int MilliSeconds;
    const int MaximumSeconds = 50;
    std::string string1 = "För att använda programmet så ska du ange millisekunder, sedan skall du peka på vart du vill autoclicka sedan trycka på F3 knappen i tangetbordet. För att stoppa programmet ska du trycka på END knappen på tangetbordet."
                       "För att minska användningen av datorns CPU och unvika överhettning så måste du sätta paustid mellan klickarna i millisekunder, minimum 50ms"
                       "Däremot, desto mindre millisekunder, desto snabbare klicks. Du måste dock vara försiktig med hastigheten för att undvika bli detectad och bannad, så testa allt från en halvsekund (500ms) till mindre (50ms till 400ms)";

    std::cout << string1 << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Ange millisekunder: ";
    std::cin >> MilliSeconds;
    if(MilliSeconds < MaximumSeconds) {
        std::cout << "Minimum millisekunder var 50ms, du kan inte gå ner mer än detta." << std::endl;
    } else {
        while(!(GetAsyncKeyState(StopKey))) {
            if(GetAsyncKeyState(StartKey)) {
                while(!(GetAsyncKeyState(StopKey))) {
                    MouseClick();
                    Sleep(MilliSeconds);
                }
            }
        }
    }
}



