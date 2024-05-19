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
	public:
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
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->btn_go = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_start
			// 
			this->btn_start->Location = System::Drawing::Point(556, 121);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(128, 54);
			this->btn_start->TabIndex = 0;
			this->btn_start->Text = L"Start";
			this->btn_start->UseVisualStyleBackColor = true;
			this->btn_start->Click += gcnew System::EventHandler(this, &MyForm::btn_start_Click);
			// 
			// btn_go
			// 
			this->btn_go->Location = System::Drawing::Point(556, 243);
			this->btn_go->Name = L"btn_go";
			this->btn_go->Size = System::Drawing::Size(128, 62);
			this->btn_go->TabIndex = 1;
			this->btn_go->Text = L"Go";
			this->btn_go->UseVisualStyleBackColor = true;
			this->btn_go->Click += gcnew System::EventHandler(this, &MyForm::btn_go_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1220, 497);
			this->Controls->Add(this->btn_go);
			this->Controls->Add(this->btn_start);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
		}
	
#pragma endregion

	public: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		train w(500, 200, 10,1);
		train v(w);
		v.draw(g);
	}
	private: System::Void btn_go_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}