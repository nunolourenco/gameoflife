#pragma once

/* Ivo Carlos Pereira Goncalves 2006125068 Nuno António Marques Lourenço 2006131888 */

#include "Vector.h"
#include "MyMatrix.h"
#include "GameOfLife.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;


namespace Game_of_Life {

	/// <summary>
	/// Summary for MainWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			this->whiteBrush = gcnew SolidBrush(Color::White);
			this->blackBrush = gcnew SolidBrush(Color::Black);
			// TODO create game of life instance and init to false
			gameOfLife = gcnew GameOfLife();
			numberOfElementsX = numberOfElementsY = 0;
			menuSize = optionsMenuStrip->Size.Height;
			cellDimensions = 20;
			//this->Update();
			this->defineWorld(this->defaultWindowWidth, this->defaultWindowHeight);
		}
		void CheckStatus() {
			Vector<Cell>* v = gameOfLife->evolve();
			for(unsigned i = 0; i < v->length(); i++) {
				Rectangle rect;
				rect.X = v->get(i).getCol() * this->cellDimensions;
				rect.Y = v->get(i).getRow() * this->cellDimensions + menuSize;
				rect.Width = this->cellDimensions;
				rect.Height = this->cellDimensions;
				this->Invalidate(rect);
			}


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

			
	protected:
		static const unsigned defaultWindowWidth = 640;
		static const unsigned defaultWindowHeight = 480;
		//TODO Change this variable to be set by the user
		unsigned cellDimensions;
		MyMatrix<bool>* activeCells;
	private: System::ComponentModel::IContainer^  components;
	protected: 
		ArrayList^ rectangles;
		
		

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::MenuStrip^  optionsMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  simulationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  startToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preferencesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  changeNeighborhoodToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mooreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  vonNeumannToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  changeCellSizeToolStripMenuItem;
		
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::Timer^  myTimer;
	private: System::Windows::Forms::ToolStripMenuItem^  stopToolStripMenuItem;
			 
		SolidBrush^ whiteBrush;
		SolidBrush^ blackBrush;
		unsigned menuSize;
		unsigned numberOfElementsX, numberOfElementsY;
		GameOfLife^ gameOfLife;
	private: System::Windows::Forms::ToolStripMenuItem^  increaseSpeedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  decreaseSpeedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem5;



			 static const unsigned timerIncrements = 100;





	private: System::Windows::Forms::ToolStripMenuItem^  menuOptionTool;

	private: System::Windows::Forms::ToolStripMenuItem^  setCellSizeToolStripMenuItem;
			 


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->optionsMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->simulationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stopToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preferencesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeNeighborhoodToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mooreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vonNeumannToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeCellSizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->increaseSpeedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->decreaseSpeedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->myTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->optionsMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// optionsMenuStrip
			// 
			this->optionsMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->simulationToolStripMenuItem, 
				this->preferencesToolStripMenuItem, this->increaseSpeedToolStripMenuItem, this->decreaseSpeedToolStripMenuItem});
			this->optionsMenuStrip->Location = System::Drawing::Point(0, 0);
			this->optionsMenuStrip->Name = L"optionsMenuStrip";
			this->optionsMenuStrip->Size = System::Drawing::Size(632, 24);
			this->optionsMenuStrip->TabIndex = 1;
			this->optionsMenuStrip->Text = L"menuStrip1";
			// 
			// simulationToolStripMenuItem
			// 
			this->simulationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->startToolStripMenuItem, 
				this->stopToolStripMenuItem});
			this->simulationToolStripMenuItem->Name = L"simulationToolStripMenuItem";
			this->simulationToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->simulationToolStripMenuItem->Text = L"Simulation";
			// 
			// startToolStripMenuItem
			// 
			this->startToolStripMenuItem->Name = L"startToolStripMenuItem";
			this->startToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->startToolStripMenuItem->Text = L"Start";
			this->startToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::startToolStripMenuItem_Click);
			// 
			// stopToolStripMenuItem
			// 
			this->stopToolStripMenuItem->Enabled = false;
			this->stopToolStripMenuItem->Name = L"stopToolStripMenuItem";
			this->stopToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->stopToolStripMenuItem->Text = L"Stop";
			this->stopToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::stopToolStripMenuItem_Click);
			// 
			// preferencesToolStripMenuItem
			// 
			this->preferencesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->changeNeighborhoodToolStripMenuItem, 
				this->changeCellSizeToolStripMenuItem});
			this->preferencesToolStripMenuItem->Name = L"preferencesToolStripMenuItem";
			this->preferencesToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			this->preferencesToolStripMenuItem->Text = L"Preferences";
			// 
			// changeNeighborhoodToolStripMenuItem
			// 
			this->changeNeighborhoodToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->mooreToolStripMenuItem, 
				this->vonNeumannToolStripMenuItem});
			this->changeNeighborhoodToolStripMenuItem->Name = L"changeNeighborhoodToolStripMenuItem";
			this->changeNeighborhoodToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->changeNeighborhoodToolStripMenuItem->Text = L"Change Neighborhood";
			// 
			// mooreToolStripMenuItem
			// 
			this->mooreToolStripMenuItem->Enabled = false;
			this->mooreToolStripMenuItem->Name = L"mooreToolStripMenuItem";
			this->mooreToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->mooreToolStripMenuItem->Text = L"Moore";
			this->mooreToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::mooreToolStripMenuItem_Click);
			// 
			// vonNeumannToolStripMenuItem
			// 
			this->vonNeumannToolStripMenuItem->Name = L"vonNeumannToolStripMenuItem";
			this->vonNeumannToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->vonNeumannToolStripMenuItem->Text = L"Von Neumann";
			this->vonNeumannToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::vonNeumannToolStripMenuItem_Click);
			// 
			// changeCellSizeToolStripMenuItem
			// 
			this->changeCellSizeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItem2, 
				this->toolStripMenuItem5, this->toolStripMenuItem3, this->toolStripMenuItem4});
			this->changeCellSizeToolStripMenuItem->Name = L"changeCellSizeToolStripMenuItem";
			this->changeCellSizeToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->changeCellSizeToolStripMenuItem->Text = L"Change Cell Size";
			this->changeCellSizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::changeCellSizeToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItem2->Text = L"10";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainWindow::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItem5->Text = L"20";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &MainWindow::toolStripMenuItem5_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItem3->Text = L"50";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MainWindow::toolStripMenuItem3_Click);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItem4->Text = L"100";
			this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &MainWindow::toolStripMenuItem4_Click);
			// 
			// increaseSpeedToolStripMenuItem
			// 
			this->increaseSpeedToolStripMenuItem->Enabled = false;
			this->increaseSpeedToolStripMenuItem->Name = L"increaseSpeedToolStripMenuItem";
			this->increaseSpeedToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->increaseSpeedToolStripMenuItem->Text = L"Increase Speed";
			this->increaseSpeedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::increaseSpeedToolStripMenuItem_Click);
			// 
			// decreaseSpeedToolStripMenuItem
			// 
			this->decreaseSpeedToolStripMenuItem->Enabled = false;
			this->decreaseSpeedToolStripMenuItem->Name = L"decreaseSpeedToolStripMenuItem";
			this->decreaseSpeedToolStripMenuItem->Size = System::Drawing::Size(97, 20);
			this->decreaseSpeedToolStripMenuItem->Text = L"Decrease Speed";
			this->decreaseSpeedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::decreaseSpeedToolStripMenuItem_Click);
			// 
			// myTimer
			// 
			this->myTimer->Interval = 500;
			this->myTimer->Tick += gcnew System::EventHandler(this, &MainWindow::myTimer_Tick);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(632, 446);
			this->Controls->Add(this->optionsMenuStrip);
			this->MainMenuStrip = this->optionsMenuStrip;
			this->Name = L"MainWindow";
			this->Text = L"Game Of Life";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::MainWindow_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::MainWindow_MouseClick);
			this->Resize += gcnew System::EventHandler(this, &MainWindow::MainWindow_Resize);
			this->optionsMenuStrip->ResumeLayout(false);
			this->optionsMenuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MainWindow_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				Point mousePosition = e->Location;
				Rectangle rect;
				if((unsigned)mousePosition.Y >= menuSize) {
					unsigned xCell = (unsigned) Math::Floor(mousePosition.X / (double) this->cellDimensions);
					unsigned yCell = (unsigned) Math::Floor((mousePosition.Y - menuSize) / (double) this->cellDimensions);
					rect.X = xCell * this->cellDimensions;
					rect.Y = yCell * this->cellDimensions + menuSize;
					rect.Width = this->cellDimensions;
					rect.Height = this->cellDimensions;
					gameOfLife->flipCellState(yCell, xCell);
					this->Invalidate(rect);
					this->Update();
				}
				
			 }
	private: System::Void MainWindow_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				array<Rectangle>^ temp = reinterpret_cast<array<Rectangle>^>(this->rectangles->ToArray(Rectangle::typeid));
				
				for(unsigned i = 0; i < this->numberOfElementsY; i++) {
					for(unsigned k = 0; k < this->numberOfElementsX; k++) {
						if(gameOfLife->getCellState(i, k)) {
							e->Graphics->FillRectangle(blackBrush, temp[i * this->numberOfElementsX + k]);
						}
						else {
							e->Graphics->FillRectangle(whiteBrush, temp[i * this->numberOfElementsX + k]);
						}
					}
				}
					
				e->Graphics->DrawRectangles(gcnew Pen(Color::Gray), temp);
			 }
	
private: System::Void MainWindow_Resize(System::Object^  sender, System::EventArgs^  e) {
			Form^ window = safe_cast<Form^>(sender);
			defineWorld(window->Width, window->Height);
			gameOfLife->changeWorld(numberOfElementsY, numberOfElementsX);
			
			
		 }

	void defineWorld(int width, int height) {
			  this->numberOfElementsX = (unsigned) Math::Ceiling(width / (double) this->cellDimensions);
			  this->numberOfElementsY = (unsigned) Math::Ceiling(height / (double) this->cellDimensions);

			  this->rectangles = gcnew ArrayList();
		
			  for(unsigned yElements = 0; yElements < this->numberOfElementsY; yElements++) {
				  for (unsigned xElements = 0; xElements < this->numberOfElementsX; xElements++) {
					  Rectangle rect;
					  rect.X = xElements * this->cellDimensions;
					  rect.Y = yElements * this->cellDimensions + menuSize;
					  rect.Width = this->cellDimensions;
					  rect.Height = this->cellDimensions;
					  this->rectangles->Add(rect);				  
				  }
			  }
	}
private: System::Void MainWindow_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void startToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->myTimer->Start();
			startToolStripMenuItem->Enabled = false;
			stopToolStripMenuItem->Enabled = true;
			increaseSpeedToolStripMenuItem->Enabled = true;
			decreaseSpeedToolStripMenuItem->Enabled = true;
			 
		 }
private: System::Void mooreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 gameOfLife->setNeighborhood(GameOfLife::neighborhoodType::MOORE);
			 mooreToolStripMenuItem->Enabled = false;
			 vonNeumannToolStripMenuItem->Enabled = true;
		 }
private: System::Void vonNeumannToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			gameOfLife->setNeighborhood(GameOfLife::neighborhoodType::VON_NEUMANN);
			vonNeumannToolStripMenuItem->Enabled = false;
			mooreToolStripMenuItem->Enabled = true;
			
		 }
private: System::Void changeCellSizeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 

		 }

private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->cellDimensions = 10;
			 defineWorld(this->Width, this->Height);
			 gameOfLife->changeWorld(numberOfElementsY, numberOfElementsX);
			 this->Invalidate();
		 }
private: System::Void toolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->cellDimensions = 50;
			 defineWorld(this->Width, this->Height);
			 gameOfLife->changeWorld(numberOfElementsY, numberOfElementsX);
			 this->Invalidate();
		 }
private: System::Void toolStripMenuItem4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->cellDimensions = 100;
			 defineWorld(this->Width, this->Height);
			 gameOfLife->changeWorld(numberOfElementsY, numberOfElementsX);
			 this->Invalidate();
		 }
		 
private: System::Void myTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 this->CheckStatus();
		 }
private: System::Void stopToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->myTimer->Stop();
			 startToolStripMenuItem->Enabled = true;
			 stopToolStripMenuItem->Enabled = false;
			 increaseSpeedToolStripMenuItem->Enabled = false;
			 decreaseSpeedToolStripMenuItem->Enabled = false;
			 
			
		 }



private: System::Void increaseSpeedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->myTimer->Interval > this->timerIncrements)
				this->myTimer->Interval -=this->timerIncrements;

		 }
private: System::Void decreaseSpeedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->myTimer->Interval += this->timerIncrements;
		 }
private: System::Void toolStripMenuItem5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->cellDimensions = 20;
			 defineWorld(this->Width, this->Height);
			 gameOfLife->changeWorld(numberOfElementsY, numberOfElementsX);
			 this->Invalidate();
		 }
};
}
