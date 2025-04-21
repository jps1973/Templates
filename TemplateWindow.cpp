// TemplateWindow.cpp

#include "TemplateWindow.h"

// Global variables
static HWND g_hWndTemplate;

BOOL IsTemplateWindow( HWND hWnd )
{
	// See if supplied window is template window
	return( hWnd == g_hWndTemplate );

} // End of function IsTemplateWindow

BOOL TemplateWindowCreate( HWND hWndParent, HINSTANCE hInstance )
{
	BOOL bResult = FALSE;

	// Create template window
	g_hWndTemplate = CreateWindowEx( TEMPLATE_WINDOW_EXTENDED_STYLE, TEMPLATE_WINDOW_CLASS_NAME, TEMPLATE_WINDOW_TEXT, TEMPLATE_WINDOW_STYLE, 0, 0, 0, 0, hWndParent, ( HMENU )NULL, hInstance, NULL );

	// Ensure that template window was created
	if( g_hWndTemplate )
	{
		// Successfully created template window

		// Update return value
		bResult = TRUE;

	} // End of successfully created template window
	return bResult;

} // End of function TemplateWindowCreate

BOOL TemplateWindowGetRect( LPRECT lpRect )
{
	// Get template window rect
	return GetWindowRect( g_hWndTemplate, lpRect );

} // End of function TemplateWindowGetRect

BOOL TemplateWindowHandleCommandMessage( WPARAM wParam, LPARAM, BOOL( *lpStatusFunction )( LPCTSTR lpszItemText ) )
{
	BOOL bResult = FALSE;

	// Select template window notification code
	switch( HIWORD( wParam ) )
	{
		default:
		{
			// Default notification code

			// No need to do anything here, just continue with default result

			// Break out of switch
			break;

		} // End of default notification code

	}; // End of selection for template window notification code

	return bResult;

} // End of function TemplateWindowHandleCommandMessage

BOOL TemplateWindowHandleNotifyMessage( WPARAM wParam, LPARAM lParam, BOOL( *lpStatusFunction )( LPCTSTR lpszItemText ) )
{
	BOOL bResult = FALSE;

	LPNMHDR lpNmhdr;

	// Get notify message handler
	lpNmhdr = ( ( LPNMHDR )lParam );

	// Select template window notification code
	switch( lpNmhdr->code )
	{
		default:
		{
			// Default notification code

			// No need to do anything here, just continue with default result

			// Break out of switch
			break;

		} // End of default notification code

	}; // End of selection for template window notification code

	return bResult;

} // End of function TemplateWindowHandleNotifyMessage

BOOL TemplateWindowMove( int nX, int nY, int nWidth, int nHeight, BOOL bRepaint )
{
	// Move template window
	return MoveWindow( g_hWndTemplate, nX, nY, nWidth, nHeight, bRepaint );

} // End of function TemplateWindowMove

HWND TemplateWindowSetFocus()
{
	// Focus on template window
	return SetFocus( g_hWndTemplate );

} // End of function TemplateWindowSetFocus

void TemplateWindowSetFont( HFONT hFont )
{
	// Set template window font
	SendMessage( g_hWndTemplate, WM_SETFONT, ( WPARAM )hFont, ( LPARAM )TRUE );

} // End of function TemplateWindowSetFont
