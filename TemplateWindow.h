// TemplateWindow.h

#pragma once

#include <windows.h>
#include <commctrl.h>

#include "Ascii.h"
#include "Common.h"

#define TEMPLATE_WINDOW_CLASS_NAME												WC_LISTBOX

#define TEMPLATE_WINDOW_EXTENDED_STYLE											0
#define TEMPLATE_WINDOW_STYLE													( WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | WS_BORDER | LBS_NOINTEGRALHEIGHT | LBS_NOTIFY )
#define TEMPLATE_WINDOW_TEXT													NULL

BOOL IsTemplateWindow( HWND hWnd );

BOOL TemplateWindowCreate( HWND hWndParent, HINSTANCE hInstance );

BOOL TemplateWindowGetRect( LPRECT lpRect );

BOOL TemplateWindowHandleCommandMessage( WPARAM wParam, LPARAM lParam, BOOL( *lpStatusFunction )( LPCTSTR lpszItemText ) );

BOOL TemplateWindowHandleNotifyMessage( WPARAM wParam, LPARAM lParam, BOOL( *lpStatusFunction )( LPCTSTR lpszItemText ) );

BOOL TemplateWindowMove( int nX, int nY, int nWidth, int nHeight, BOOL bRepaint = TRUE );

HWND TemplateWindowSetFocus();

void TemplateWindowSetFont( HFONT hFont );
