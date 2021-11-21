#include <controllers/MenuControllers.h>

const char g_szClassName[] = "myWindowClass";

BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;
        
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDOK:
                    EndDialog(hwnd, IDOK);
                break;
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                break;
            }
        break;

        default:
            return FALSE;
    }
    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){

    using std::cout;

    switch(msg){
        case WM_LBUTTONDOWN:
            ClickWithLeft(msg);
        break;
        case WM_RBUTTONDOWN:
            ClickWithRigth(msg);
        break;
        case WM_KEYDOWN:
            JustAKey("down", msg);
        break; 
        case WM_KEYUP:
            JustAKey("up", msg);
        break;

        case WM_COMMAND:

            cout << "w: "<<wParam<< "\nl:"<< lParam<<"\n";
            ButtonWriter(wParam);
            OpenLocalFile(wParam);

            switch(LOWORD(wParam)){
                case ID_HELP_ABOUT:
                {
                    int ret = DialogBox(GetModuleHandle(NULL), 
                        MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
                    if(ret == IDOK){
                        MessageBox(hwnd, "Dialog exited with IDOK.", "Notice",
                            MB_OK | MB_ICONINFORMATION);
                    }
                    else if(ret == IDCANCEL){
                        MessageBox(hwnd, "Dialog exited with IDCANCEL.", "Notice",
                            MB_OK | MB_ICONINFORMATION);
                    }
                    else if(ret == -1){
                        MessageBox(hwnd, "Dialog failed!", "Error",
                            MB_OK | MB_ICONINFORMATION);
                    }
                }
                break;
            }
        break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow){
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;

    wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MYMENU);
    wc.hIcon  = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
    wc.hIconSm  = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);

    if(!RegisterClassEx(&wc)){
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "c++ code editor",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 480, 240,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL){
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}
