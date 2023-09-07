#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame{
    public:
        Mainframe(const wxString& title);

    private:
        void CreateControls();
        wxPanel* panel;
        wxStaticText* headlineText;
        wxTextCtrl* inputField;
        wxButton* addButton;
        wxCheckListBox * checkListBox;
        wxButton * clearButton;
}