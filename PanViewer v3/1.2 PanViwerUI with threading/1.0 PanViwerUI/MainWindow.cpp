#include "MainWindow.h"

using namespace My10PanViwerUI;			//            The name of the namespace in MainWindow.h

[STAThreadAttribute]					//            Run this program in STA mode

int main() {
	MainWindow mainWindow;              //            The form to be created and shown
	mainWindow.ShowDialog();			//            Show the form
	return 0;
}