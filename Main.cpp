#pragma once

#include "MainWindow.h"

/* Ivo Carlos Pereira Goncalves 2006125068 Nuno António Marques Lourenço 2006131888 */

using namespace System;
using namespace Game_of_Life;


void initializeWindow();
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{	
	initializeWindow();





	return 0;
}


void initializeWindow() {
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	// Create the main window and run it
	Application::Run(gcnew MainWindow());
}
