// Win32ClientRectChecker.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Win32ClientRectChecker.h"

#pragma comment(lib, "shlwapi.lib")

using namespace std;
using namespace Ambiesoft;
using namespace Ambiesoft::stdosd;

void OnTimer(HWND hWnd)
{
    RECT windowRect;
    GetWindowRect(hWnd, &windowRect);

    RECT clientRect;
    GetClientRect(hWnd, &clientRect);

    POINT clientScreenPointLeftTop = { clientRect.left,clientRect.top };
    POINT clientScreenPointRightBottom = { clientRect.right,clientRect.bottom };
    ClientToScreen(hWnd, &clientScreenPointLeftTop);
    ClientToScreen(hWnd, &clientScreenPointRightBottom);
    RECT clientScreenRect = { 
        clientScreenPointLeftTop.x,clientScreenPointLeftTop.y ,
        clientScreenPointRightBottom.x,clientScreenPointRightBottom.y 
    };

    RECT rectAdjustBefore = { 100,100,1000,1000 };
    RECT rectAdjustAfter = rectAdjustBefore;
    DWORD dwStyple = GetWindowLong(hWnd, GWL_STYLE);
    AdjustWindowRect(&rectAdjustAfter, dwStyple, TRUE);

    gtxtOut = stdFormat(STDOSD_WCHARLITERAL(
        R"(GetWindowRect:
windowRect.left=%d
windowRect.right=%d
windowRect.top=%d
windowRect.bottom=%d
windowRect.Width()=%d
windowRect.Height()=%d

GetClientRect:
clientRect.left=%d
clientRect.right=%d
clientRect.top=%d
clientRect.bottom=%d
clientRect.Width()=%d
clientRect.Height()=%d

ClientToScreen:
clientScreenRect.left=%d
clientScreenRect.right=%d
clientScreenRect.top=%d
clientScreenRect.bottom=%d

AdjustWindowRect:
rectAdjustBefore.left=%d
rectAdjustBefore.right=%d
rectAdjustBefore.top=%d
rectAdjustBefore.bottom=%d

rectAdjustAfter.left=%d
rectAdjustAfter.right=%d
rectAdjustAfter.top=%d
rectAdjustAfter.bottom=%d

)"),
windowRect.left,
windowRect.right,
windowRect.top,
windowRect.bottom,
windowRect.right-windowRect.left,
windowRect.bottom-windowRect.top,

clientRect.left,
clientRect.right,
clientRect.top,
clientRect.bottom,
clientRect.right - clientRect.left,
clientRect.bottom - clientRect.top,

clientScreenRect.left,
clientScreenRect.right,
clientScreenRect.top,
clientScreenRect.bottom,

rectAdjustBefore.left,
rectAdjustBefore.right,
rectAdjustBefore.top,
rectAdjustBefore.bottom,

rectAdjustAfter.left,
rectAdjustAfter.right,
rectAdjustAfter.top,
rectAdjustAfter.bottom

);

    gtxtOut = stdStringReplace(gtxtOut, L"\r\n", L"\n");
    gtxtOut = stdStringReplace(gtxtOut, L"\r", L"\n");
    gtxtOut = stdStringReplace(gtxtOut, L"\n", L"\r\n");

    InvalidateRect(hWnd, nullptr, TRUE);
    UpdateWindow(hWnd);
}
