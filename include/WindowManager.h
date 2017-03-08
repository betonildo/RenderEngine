#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "renderer_local_includes.h"
//#include "GL.h"
#include "Input.h"

template <class DERIVED_TYPE> 
class BaseWindow
{
public:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        DERIVED_TYPE *pThis = NULL;

        if (uMsg == WM_NCCREATE)
        {
            CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
            pThis = (DERIVED_TYPE*)pCreate->lpCreateParams;
            SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);

            pThis->m_hwnd = hwnd;

            // Get pixel format of current window
            PIXELFORMATDESCRIPTOR pfd = pThis->GetPixelFormat();
            // create device handle
            pThis->m_windowHandleToDeviceContext = GetDC(pThis->m_hwnd);
		    
            // Try set pixel format
            int letWindowsChooseThisPixelFormat = ChoosePixelFormat(pThis->m_windowHandleToDeviceContext, &pfd); 
            SetPixelFormat(pThis->m_windowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

            // create OpenGL rendering context
            pThis->m_openGLRenderingContext = wglCreateContext(pThis->m_windowHandleToDeviceContext);
            // Set opengl current context
		    wglMakeCurrent (pThis->m_windowHandleToDeviceContext, pThis->m_openGLRenderingContext);
            //MessageBoxA(0,(char*)glGetString(GL_VERSION), "OPENGL VERSION",0);
        }
        else pThis = (DERIVED_TYPE*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

        // this handle messages on window instance i'm working on
        if (pThis) return pThis->HandleMessage(uMsg, wParam, lParam);
        else return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    BaseWindow() : m_hwnd(NULL) { }

    BOOL Create(
        PCWSTR lpWindowName,
        DWORD dwStyle = WS_OVERLAPPEDWINDOW,
        DWORD dwExStyle = 0,
        int x = CW_USEDEFAULT,
        int y = CW_USEDEFAULT,
        int nWidth = CW_USEDEFAULT,
        int nHeight = CW_USEDEFAULT,
        HWND hWndParent = 0,
        HMENU hMenu = 0
        )
    {
        // store window name
        m_lpWindowName = lpWindowName;

        WNDCLASS wc = {0};

        wc.lpfnWndProc   = DERIVED_TYPE::WindowProc;
        wc.hInstance     = GetModuleHandle(NULL);
        wc.lpszClassName = ClassName();
        wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
        wc.style         = CS_OWNDC;

        RegisterClass(&wc);

        m_hwnd = CreateWindowEx(
            dwExStyle, ClassName(), lpWindowName, dwStyle, x, y,
            nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), 
            // window creation data to be reinterpreted on window proc calls of message handling
            this
            );

        return (m_hwnd ? TRUE : FALSE);
    }

    HWND Window() const { return m_hwnd; }

    void Show(int nCmdShow = 10) {
        ShowWindow(m_hwnd, nCmdShow);
    }

    int Watch() {
        
        MSG msg = { };
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    PIXELFORMATDESCRIPTOR GetPixelFormat() {
        
        PIXELFORMATDESCRIPTOR pfd = {
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
			PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
			32,                       //Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                       //Number of bits for the depthbuffer
			8,                        //Number of bits for the stencilbuffer
			0,                        //Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

        return pfd;
    }

protected:

    virtual PCWSTR  ClassName() const = 0;
    virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

    HWND m_hwnd;
    PCWSTR m_lpWindowName;
    HDC m_windowHandleToDeviceContext;
    HGLRC m_openGLRenderingContext;

};

class WindowManager : public BaseWindow<WindowManager>
{
public:
    PCWSTR  ClassName() const { return L"WindowManager Class"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    void OnSize(HWND hwnd, UINT flag, int width, int height);
};

#endif /*WINDOWMANAGER_H*/