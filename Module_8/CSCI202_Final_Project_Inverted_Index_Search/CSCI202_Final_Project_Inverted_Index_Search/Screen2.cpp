/* Program Name: Screen2.cpp
*  Author: Generated by ChatGPT using prompts by Kyle Ingersoll
*  Date last updated: 12/2/2024
*  Purpose: To create method definitions for Screen 2.
*/

#include "Screen2.h"
#include <fstream>
#include <sstream>
#include <CommCtrl.h> // For common controls

#define IDC_TEXTBOX_SEARCH 201
#define IDC_BUTTON_SEARCH  202
#define IDC_LISTBOX_EXACT  203
#define IDC_LISTBOX_FUZZY  204

void Screen2::createScreen(HINSTANCE hInstance, const std::string& filePath) {
    this->filePath = filePath;

    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = Screen2::WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"Screen2Class";

    if (!RegisterClassEx(&wc)) {
        MessageBox(nullptr, L"Failed to register Screen2 class!", L"Error", MB_ICONERROR);
        return;
    }

    HWND hwnd = CreateWindowW(
        L"Screen2Class", L"M08 Final Project - Screen 2",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 600, 400,
        nullptr, nullptr, hInstance, this);

    if (!hwnd) {
        MessageBox(nullptr, L"Failed to create Screen2 window!", L"Error", MB_ICONERROR);
        return;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);
}

LRESULT CALLBACK Screen2::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static HWND hwndLabelSearch, hwndTextBoxSearch, hwndButtonSearch;
    static HWND hwndExactResults, hwndFuzzyResults;

    switch (message) {
    case WM_CREATE: {
        // Create UI components
        hwndLabelSearch = CreateWindowW(L"STATIC", L"Input word(s) you want to search for:",
            WS_VISIBLE | WS_CHILD, 50, 50, 300, 20, hwnd, nullptr, nullptr, nullptr);

        hwndTextBoxSearch = CreateWindowW(L"EDIT", L"",
            WS_VISIBLE | WS_CHILD | WS_BORDER, 250, 50, 300, 20, hwnd, (HMENU)IDC_TEXTBOX_SEARCH, nullptr, nullptr);

        hwndButtonSearch = CreateWindowW(L"BUTTON", L"Search",
            WS_VISIBLE | WS_CHILD, 250, 100, 100, 30, hwnd, (HMENU)IDC_BUTTON_SEARCH, nullptr, nullptr);

        hwndExactResults = CreateWindowW(L"EDIT", L"Exact Results:",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
            50, 150, 200, 200, hwnd, (HMENU)IDC_LISTBOX_EXACT, nullptr, nullptr);

        hwndFuzzyResults = CreateWindowW(L"EDIT", L"Fuzzy Results:",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
            350, 150, 200, 200, hwnd, (HMENU)IDC_LISTBOX_FUZZY, nullptr, nullptr);
        break;
    }

    case WM_COMMAND: {
        if (LOWORD(wParam) == IDC_BUTTON_SEARCH) {
            // Retrieve search term
            wchar_t buffer[256];
            GetWindowTextW(hwndTextBoxSearch, buffer, 256);

            // Convert wchar_t to std::string
            std::wstring ws(buffer);
            std::string searchTerm(ws.begin(), ws.end());

            // Load file content and perform search
            // This will be integrated with the InvertedIndex class for actual logic.
            MessageBox(hwnd, L"Search functionality coming soon!", L"Info", MB_ICONINFORMATION);
        }
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
