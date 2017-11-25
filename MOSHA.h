#pragma once
#include "wx\wx.h"

class MOSHA : public wxWindow
{
public:
	MOSHA(wxFrame *parent);
	~MOSHA();
	void OnPaint(wxPaintEvent &event);
private:
	wxBitmap *menu = nullptr;
	wxBitmap *buttonWindow = nullptr;
	wxBitmap *start = nullptr;
	DECLARE_EVENT_TABLE()
	void LoadMenuBitmap();
	void LoadbuttonWindowBitmap();
	void LoadStartButton();
};

