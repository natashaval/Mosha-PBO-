#include "MenuName.h"
#include "Hero.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/font.h>
#include <vector>

BEGIN_EVENT_TABLE(MenuName, wxWindow)
EVT_PAINT(MenuName::OnPaint)
EVT_BUTTON(1001, MenuName::ClickOK)
END_EVENT_TABLE()

//Hero * Hero::instance = 0;

MenuName::MenuName(ImageFrame * parent)
	: wxWindow(parent, wxID_ANY), parentFrame(parent)
{
	Refresh();
	this->SetBackgroundColour(wxColour(*wxWHITE));
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	LoadAllBitmap();

	mirai = Hero::getInstance();

	wxFont font(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	NameEntry = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(79, 550), wxSize(349, 40), wxTE_CENTRE | wxTE_RICH);
	NameEntry->SetBackgroundColour(wxColor(*wxWHITE));
	NameEntry->SetFont(font);
	//	NameEntry->SetDefaultStyle(wxTextAttr(wxColor(*wxGREEN), wxColor(*wxBLUE)));

	wxBitmapButton* OKbutton = new wxBitmapButton(this, 1001, *OK, wxPoint(197,610), wxDefaultSize, wxBU_AUTODRAW);
}

MenuName::~MenuName()
{
	delete menu, buttonWindow, OK, insert;
}

void MenuName::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*menu, wxPoint(0, 0), true);
	pdc.DrawBitmap(*buttonWindow, wxPoint(0, 455), true);
	pdc.DrawBitmap(*insert, wxPoint(82, 490), true);
}

void MenuName::ClickOK(wxCommandEvent & event)
{
	string TempName = NameEntry->GetValue();
	//	mirai->SetName(TempName);
	mirai->name = TempName;
	wxString anu = wxT("Welcome Hero ") + TempName;
	vector<char> mirainama(mirai->name.begin(), mirai->name.end());
	int i, n,o, ok;
	o = mirainama.size();
	if (TempName.empty())
	{
		wxMessageBox(wxT("Username must not empty!"), wxT("Warning!"), wxICON_ERROR);
	}
	else {
		for (i = 0; i < o; i++) {
			n = mirainama[i] - '0';
			n -= 16;
			if ((n <= 0) || (n > 42 && n < 49) || (n >= 75)) { 
				wxMessageBox(wxT("Number and Symbol will not be shown"), wxT("Warning!"), wxICON_ERROR); 
				break;
			}
		}
		wxMessageBox(anu, wxT("Welcome"), wxICON_INFORMATION);
		parentFrame->ShowMap();
		
	}

	//	delete menu, buttonWindow, OK;

}

void MenuName::LoadAllBitmap()
{
	this->LoadMenuBitmap();
	this->LoadbuttonWindowBitmap();
}

void MenuName::LoadMenuBitmap()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	fileLocation = stdPaths.GetExecutablePath();
	wxString loclogo = wxFileName(fileLocation).GetPath() + wxT("\\menu awal.png");
	wxImage image(loclogo, wxBITMAP_TYPE_PNG);
	menu = new wxBitmap(image);
	menu->ConvertToDisabled(150);
}

void MenuName::LoadbuttonWindowBitmap()
{
	wxString locwindow = wxFileName(fileLocation).GetPath() + wxT("\\button window.png");
	wxImage image(locwindow, wxBITMAP_TYPE_PNG);
	buttonWindow = new wxBitmap(image);

	wxString locstart = wxFileName(fileLocation).GetPath() + wxT("\\ok button3.png");
	wxImage image1(locstart, wxBITMAP_TYPE_PNG);
	OK = new wxBitmap(image1);

	wxString locinsert = wxFileName(fileLocation).GetPath() + wxT("\\insert name.png");
	wxImage image2(locinsert, wxBITMAP_TYPE_PNG);
	insert = new wxBitmap(image2);
	//insert your name ver3
}
