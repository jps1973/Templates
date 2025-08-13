// TemplateClass.h

#pragma once

#include <windows.h>

#include "Ascii.h"
#include "Common.h"

class Template
{
public:
	Template();
	~Template();

	Template& operator = ( HWND hWnd );

	BOOL operator == ( HWND hWnd );

	BOOL operator != ( HWND hWnd );

	operator HWND();

protected:
	HWND m_hWnd;

}; // End of class Template
