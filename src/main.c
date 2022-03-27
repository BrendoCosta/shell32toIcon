// x86_64-w64-mingw32-gcc wintest.cpp -o main.exe -Wall -static-libgcc -mwindows -fno-pic -no-pie -lim -L ./d_im -I ./d_im/include
#include <windows.h>
#include <im.h>
#include <im_image.h>
#include <im_dib.h>

int main(void) {

    HMODULE hModDLL = LoadLibrary("shell32.dll");
    
        HRSRC hRSRC = FindResourceA(
            hModDLL,
            MAKEINTRESOURCE(0x000003CA),
            RT_ICON
        );
        
        HGLOBAL hGlobal = LoadResource(hModDLL, hRSRC);
        
        HICON hIcon = CreateIconFromResourceEx(
            (BYTE*)LockResource(hGlobal),
            SizeofResource(hModDLL, hRSRC),
            TRUE,
            0x00030000,
            48, 48,
            LR_DEFAULTCOLOR
        );
        
        ICONINFO iconinfo;
        GetIconInfo(hIcon, &iconinfo);
        
        HBITMAP hBitmap = iconinfo.hbmColor;
        
        /*
        HBITMAP hBitmap = (HBITMAP) LoadImage(
            (HINSTANCE)hModDLL,
            MAKEINTRESOURCE(420),
            IMAGE_BITMAP,
            0, 0,
            LR_DEFAULTCOLOR
        );
        */
        
        imDib* dib = imDibFromHBitmap(hBitmap, NULL);
            
            imImage* image = imDibToImage(dib);
            imFileImageSave("teste.ico", "ICO", image);
            
        imDibDestroy(dib);
    
    FreeLibrary(hModDLL);

    return 0;

}
