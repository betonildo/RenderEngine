#include "WindowManager.h"

LRESULT WindowManager::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(m_hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
            EndPaint(m_hwnd, &ps);
        }
        return 0;

    case WM_SIZE:
        break;
    
    case WM_LBUTTONDOWN:
        Input::m_instance->m_leftWasPressed = true;
        break;
    case WM_RBUTTONDOWN:
        Input::m_instance->m_rightWasPressed = true;
        break;

    default:
        Input::m_instance->m_pointers[0].x = GET_X_LPARAM(lParam);
        Input::m_instance->m_pointers[0].y = GET_Y_LPARAM(lParam);

        printf("{%f, %f}\n", Input::m_instance->m_pointers[0].x, Input::m_instance->m_pointers[0].y);

        return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }

    return TRUE;
}