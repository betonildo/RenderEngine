#include "WindowManager.h"

//avoid lengthy processing inside window procedure, it is blocking other things
LRESULT WindowManager::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Input::clearLastInputs();
    // always update mouse position
    Input::m_instance->m_pointers[0].x = GET_X_LPARAM(lParam);
    Input::m_instance->m_pointers[0].y = GET_Y_LPARAM(lParam);

    switch (uMsg)
    {
        case WM_CLOSE:
            if (MessageBox(m_hwnd, L"Are you sure?", m_lpWindowName, MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(m_hwnd);
            }
            // Else: User canceled. Do nothing.
            return 0;

    case WM_DESTROY: {
            wglDeleteContext(m_openGLRenderingContext);
            PostQuitMessage(0);
        }
        return 0;

    case WM_PAINT: {

            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(m_hwnd, &ps);
            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
            EndPaint(m_hwnd, &ps);
        }
        return 0;

    case WM_SIZE: {

            int width = LOWORD(lParam);  // Macro to get the low-order word.
            int height = HIWORD(lParam); // Macro to get the high-order word.

            // Respond to the message:
            OnSize(m_hwnd, (UINT)wParam, width, height);
        }
        break;
    
    case WM_LBUTTONDOWN:
        Input::m_instance->m_leftWasPressed = true;
        break;
    case WM_RBUTTONDOWN:
        Input::m_instance->m_rightWasPressed = true;
        break;

    default:
        return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }

    return TRUE;
}

void WindowManager::OnSize(HWND hwnd, UINT flag, int width, int height) {

}