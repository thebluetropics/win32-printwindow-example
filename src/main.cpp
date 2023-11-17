#include <windows.h>
#include <iostream>

int main() {
  HWND hwnd = FindWindowW(L"GLFW30", NULL);
  RECT rect;
  GetClientRect(hwnd, &rect);
  HDC hdc = GetDC(hwnd);
  HDC hdcMem = CreateCompatibleDC(hdc);
  int width = rect.right;
  int height = rect.bottom;
  HBITMAP bitmap = CreateCompatibleBitmap(hdc, width, height);
  SelectObject(hdcMem, bitmap);
  PrintWindow(hwnd, hdcMem, PW_CLIENTONLY);

  BITMAPINFOHEADER info = {};
  ZeroMemory(&info, sizeof(BITMAPINFOHEADER));
  info.biSize = sizeof(BITMAPINFOHEADER);
  info.biWidth = width;
  info.biHeight = -height;
  info.biPlanes = 1;
  info.biBitCount = 24;
  info.biCompression = BI_RGB;

  BYTE* rgbArray = new BYTE[width * height * 3];
  GetDIBits(hdcMem, bitmap, 0, height, rgbArray, (BITMAPINFO*) &info, DIB_RGB_COLORS);

  DeleteDC(hdcMem);
  ReleaseDC(hwnd, hdc);
  DeleteObject(bitmap);
  return 0;
}
