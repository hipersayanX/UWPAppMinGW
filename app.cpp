/* Copyright (c) 2021 Gonzalo Exequiel Pedone
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <windows.h>

LRESULT CALLBACK windowProc(HWND hwnd,
                            UINT message,
                            WPARAM wParam,
                            LPARAM lParam);

int WINAPI WinMain(HINSTANCE instance,
                   HINSTANCE prevInstance,
                   LPSTR cmdLine,
                   int showCmd)
{
    const TCHAR className[] = TEXT("UWPApp Class");
    
    WNDCLASS windowClass;
    memset(&windowClass, 0, sizeof(WNDCLASS));
    windowClass.lpfnWndProc = windowProc;
    windowClass.hInstance = instance;
    windowClass.lpszClassName = className;
    RegisterClass(&windowClass);

    auto hwnd = CreateWindowEx(0,
                               className,
                               TEXT("This is an UWP app"),
                               WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT,
                               CW_USEDEFAULT,
                               640,
                               480,
                               nullptr,
                               nullptr,
                               instance,
                               nullptr);

    if (!hwnd)
        return -1;

    ShowWindow(hwnd, showCmd);

    MSG message;
    memset(&message, 0, sizeof(MSG));

    while (GetMessage(&message, nullptr, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}

LRESULT CALLBACK windowProc(HWND hwnd,
                            UINT message,
                            WPARAM wParam,
                            LPARAM lParam)
{
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);

        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        auto hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);

        return 0;
    }

    default:
        break;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}
