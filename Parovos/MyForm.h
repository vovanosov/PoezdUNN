#pragma once
#include "Classes.h"

namespace Parovos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::TextBox^ textX;
	private: System::Windows::Forms::TextBox^ textY;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

	public:
		Graphics^ g;
	private: System::Windows::Forms::TextBox^ textH;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textN;
	private: System::Windows::Forms::Label^ label4;
	public:
		train* w;
		int X = 0, Y = 0, H = 0, N = 0;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_start;
	private: System::Windows::Forms::Button^ btn_go;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->btn_go = (gcnew System::Windows::Forms::Button());
			this->textX = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textY = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textH = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textN = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_start
			// 
			this->btn_start->Location = System::Drawing::Point(774, 84);
			this->btn_start->Margin = System::Windows::Forms::Padding(2);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(85, 35);
			this->btn_start->TabIndex = 0;
			this->btn_start->Text = L"Start";
			this->btn_start->UseVisualStyleBackColor = true;
			this->btn_start->Click += gcnew System::EventHandler(this, &MyForm::btn_start_Click);
			// 
			// btn_go
			// 
			this->btn_go->Location = System::Drawing::Point(774, 156);
			this->btn_go->Margin = System::Windows::Forms::Padding(2);
			this->btn_go->Name = L"btn_go";
			this->btn_go->Size = System::Drawing::Size(85, 40);
			this->btn_go->TabIndex = 1;
			this->btn_go->Text = L"Go";
			this->btn_go->UseVisualStyleBackColor = true;
			this->btn_go->Click += gcnew System::EventHandler(this, &MyForm::btn_go_Click);
			// 
			// textX
			// 
			this->textX->Location = System::Drawing::Point(112, 26);
			this->textX->Name = L"textX";
			this->textX->Size = System::Drawing::Size(68, 20);
			this->textX->TabIndex = 2;
			this->textX->TextChanged += gcnew System::EventHandler(this, &MyForm::textX_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(92, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"X";
			// 
			// textY
			// 
			this->textY->Location = System::Drawing::Point(272, 29);
			this->textY->Name = L"textY";
			this->textY->Size = System::Drawing::Size(68, 20);
			this->textY->TabIndex = 4;
			this->textY->TextChanged += gcnew System::EventHandler(this, &MyForm::textY_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(252, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Y";
			// 
			// textH
			// 
			this->textH->Location = System::Drawing::Point(430, 30);
			this->textH->Name = L"textH";
			this->textH->Size = System::Drawing::Size(68, 20);
			this->textH->TabIndex = 6;
			this->textH->TextChanged += gcnew System::EventHandler(this, &MyForm::textH_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(410, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(15, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"H";
			// 
			// textN
			// 
			this->textN->Location = System::Drawing::Point(600, 33);
			this->textN->Name = L"textN";
			this->textN->Size = System::Drawing::Size(68, 20);
			this->textN->TabIndex = 8;
			this->textN->TextChanged += gcnew System::EventHandler(this, &MyForm::textN_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(579, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"N";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(882, 453);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textN);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textH);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textY);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textX);
			this->Controls->Add(this->btn_go);
			this->Controls->Add(this->btn_start);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	public: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e) {
		X = 0, Y = 0, H = 0, N = 0;
		String^ tX = this->textX->Text;
		String^ tY = this->textY->Text;
		String^ tH = this->textH->Text;
		String^ tN = this->textN->Text;

		for (int i = 0; i < tX->Length; i++)
			X += (tX[tX->Length - 1 - i] - '0') * pow(10, i);
		for (int i = 0; i < tY->Length; i++)
			Y += (tY[tY->Length - 1 - i] - '0') * pow(10, i);
		for (int i = 0; i < tH->Length; i++)
			H += (tH[tH->Length - 1 - i] - '0') * pow(10, i);
		for (int i = 0; i < tN->Length; i++)
			N += (tN[tN->Length - 1 - i] - '0') * pow(10, i);

		g = this->CreateGraphics();
		g->Clear(Color::Azure);
		w = new train(X, Y, H, N);
		w->draw(g);
	}
	private: System::Void btn_go_Click(System::Object^ sender, System::EventArgs^ e) {
		g = this->CreateGraphics();
		g->Clear(Color::Azure);
		w->move(H/4);
		w->draw(g);
	}
	private: System::Void textX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textY_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textH_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textN_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}