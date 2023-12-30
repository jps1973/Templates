// TemplateWindow.cpp

#include "TemplateWindow.h"

// Global variables
HWND g_hWndTemplate;

BOOL IsTemplateWindow( HWND hWnd )
{
	// See if supplied window is template window
	return( hWnd == g_hWndTemplate );

} // End of function IsTemplateWindow

BOOL TemplateWindowCreate( HWND hWndParent, HINSTANCE hInstance )
{
	BOOL bResult = FALSE;

	// Create template window
	g_hWndTemplate = ::CreateWindowEx( TEMPLATE_WINDOW_EXTENDED_STYLE, TEMPLATE_WINDOW_CLASS_NAME, TEMPLATE_WINDOW_TEXT, TEMPLATE_WINDOW_STYLE, 0, 0, 0, 0, hWndParent, ( HMENU )NULL, hInstance, NULL );

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
	return ::GetWindowRect( g_hWndTemplate, lpRect );

} // End of function TemplateWindowGetRect

BOOL TemplateWindowHandleCommandMessage( WPARAM wParam, LPARAM, void( *lpDoubleClickFunction )( LPCTSTR lpszItemText ), void( *lpSelectionChangedFunction )( LPCTSTR lpszItemText ) )
{
	BOOL bResult = FALSE;

	// Select template window notification code
	switch( HIWORD( wParam ) )
	{
		case LBN_DBLCLK:
		{
			// A template window double click notification code
			int nSelectedItem;

			// Allocate string memory
			LPTSTR lpszSelectedItemText = new char[ STRING_LENGTH ];

			// Get selected item
			nSelectedItem = TemplateWindowGetCurrentSelection();

			// Get selected item text
			if( TemplateWindowGetItemText( nSelectedItem, lpszSelectedItemText ) )
			{
				// Successfully got selected item text

				// Call double click function
				( *lpDoubleClickFunction )( lpszSelectedItemText );

				// Update return value
				bResult = TRUE;

			} // End of successfully got selected item text

			// Free string memory
			delete [] lpszSelectedItemText;

			// Break out of switch
			break;

		} // End of a template window double click notification code
		case LBN_SELCHANGE:
		{
			// A template window selection change notification code
			int nSelectedItem;

			// Allocate string memory
			LPTSTR lpszSelectedItemText = new char[ STRING_LENGTH ];

			// Get selected item
			nSelectedItem = TemplateWindowGetCurrentSelection();

			// Get selected item text
			if( TemplateWindowGetItemText( nSelectedItem, lpszSelectedItemText ) )
			{
				// Successfully got selected item text

				// Call selection changed function
				( *lpSelectionChangedFunction )( lpszSelectedItemText );

				// Update return value
				bResult = TRUE;

			} // End of successfully got selected item text

			// Free string memory
			delete [] lpszSelectedItemText;

			// Break out of switch
			break;

		} // End of a template window selection change notification code

	}; // End of selection for template window notification code

	return bResult;

} // End of function TemplateWindowHandleCommandMessage

BOOL TemplateWindowMove( int nX, int nY, int nWidth, int nHeight, BOOL bRepaint )
{
	// Move template window
	return ::MoveWindow( g_hWndTemplate, nX, nY, nWidth, nHeight, bRepaint );

} // End of function TemplateWindowMove

HWND TemplateWindowSetFocus()
{
	// Focus on template window
	return ::SetFocus( g_hWndTemplate );

} // End of function TemplateWindowSetFocus

void TemplateWindowSetFont( HFONT hFont )
{
	// Set template window font
	::SendMessage( g_hWndTemplate, WM_SETFONT, ( WPARAM )hFont, ( LPARAM )TRUE );

} // End of function TemplateWindowSetFont
