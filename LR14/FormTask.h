#pragma once
#include <cmath>

namespace LR14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormTask
	/// </summary>
	public ref class FormTask : public System::Windows::Forms::Form
	{
	public:
		FormTask(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormTask()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ resultTextBox;
	protected:

	private: System::Windows::Forms::Label^ result;
	protected:

	private: System::Windows::Forms::Button^ calculateButton;
	private: System::Windows::Forms::TextBox^ ZTextBox;


	private: System::Windows::Forms::Label^ Z;
	private: System::Windows::Forms::TextBox^ YTextBox;


	private: System::Windows::Forms::Label^ Y;

	private: System::Windows::Forms::Label^ X;
	private: System::Windows::Forms::TextBox^ XTextBox;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->resultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->result = (gcnew System::Windows::Forms::Label());
			this->calculateButton = (gcnew System::Windows::Forms::Button());
			this->ZTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Z = (gcnew System::Windows::Forms::Label());
			this->YTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Y = (gcnew System::Windows::Forms::Label());
			this->X = (gcnew System::Windows::Forms::Label());
			this->XTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// resultTextBox
			// 
			this->resultTextBox->Location = System::Drawing::Point(15, 205);
			this->resultTextBox->Multiline = true;
			this->resultTextBox->Name = L"resultTextBox";
			this->resultTextBox->Size = System::Drawing::Size(257, 37);
			this->resultTextBox->TabIndex = 17;
			// 
			// result
			// 
			this->result->AutoSize = true;
			this->result->Location = System::Drawing::Point(12, 189);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(62, 13);
			this->result->TabIndex = 16;
			this->result->Text = L"Результат:";
			// 
			// calculateButton
			// 
			this->calculateButton->Location = System::Drawing::Point(105, 122);
			this->calculateButton->Name = L"calculateButton";
			this->calculateButton->Size = System::Drawing::Size(75, 23);
			this->calculateButton->TabIndex = 15;
			this->calculateButton->Text = L"Рассчитать";
			this->calculateButton->UseVisualStyleBackColor = true;
			this->calculateButton->Click += gcnew System::EventHandler(this, &FormTask::CalculateButton_Click);
			// 
			// ZTextBox
			// 
			this->ZTextBox->Location = System::Drawing::Point(53, 75);
			this->ZTextBox->Name = L"ZTextBox";
			this->ZTextBox->Size = System::Drawing::Size(219, 20);
			this->ZTextBox->TabIndex = 14;
			// 
			// Z
			// 
			this->Z->AutoSize = true;
			this->Z->Location = System::Drawing::Point(12, 78);
			this->Z->Name = L"Z";
			this->Z->Size = System::Drawing::Size(17, 13);
			this->Z->TabIndex = 13;
			this->Z->Text = L"Z:";
			// 
			// YTextBox
			// 
			this->YTextBox->Location = System::Drawing::Point(53, 46);
			this->YTextBox->Name = L"YTextBox";
			this->YTextBox->Size = System::Drawing::Size(219, 20);
			this->YTextBox->TabIndex = 12;
			// 
			// Y
			// 
			this->Y->AutoSize = true;
			this->Y->Location = System::Drawing::Point(12, 49);
			this->Y->Name = L"Y";
			this->Y->Size = System::Drawing::Size(17, 13);
			this->Y->TabIndex = 11;
			this->Y->Text = L"Y:";
			// 
			// X
			// 
			this->X->AutoSize = true;
			this->X->Location = System::Drawing::Point(12, 21);
			this->X->Name = L"X";
			this->X->Size = System::Drawing::Size(17, 13);
			this->X->TabIndex = 10;
			this->X->Text = L"X:";
			// 
			// XTextBox
			// 
			this->XTextBox->Location = System::Drawing::Point(53, 18);
			this->XTextBox->Name = L"XTextBox";
			this->XTextBox->Size = System::Drawing::Size(219, 20);
			this->XTextBox->TabIndex = 9;
			// 
			// FormTask
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->resultTextBox);
			this->Controls->Add(this->result);
			this->Controls->Add(this->calculateButton);
			this->Controls->Add(this->ZTextBox);
			this->Controls->Add(this->Z);
			this->Controls->Add(this->YTextBox);
			this->Controls->Add(this->Y);
			this->Controls->Add(this->X);
			this->Controls->Add(this->XTextBox);
			this->Name = L"FormTask";
			this->Text = L"FormTask";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		Void CalculateButton_Click(Object^ sender, EventArgs^ e) {
			Double x, y, z, result;

			x = Convert::ToDouble(XTextBox->Text);
			y = Convert::ToDouble(YTextBox->Text);
			z = Convert::ToDouble(ZTextBox->Text);

			result = Function(x, y, z);

			resultTextBox->Text += "При х = " + Convert::ToString(x) + "; y = "
				+ Convert::ToString(y) + "; z = " + Convert::ToString(z)
				+ "\r\n" + "Результат = " + Convert::ToString(result) + "\r\n";
		}

		Double Function(const Double% x, const Double% y, const Double% z) {
			return 5 * atan(x) - 1 / 4.0 * acos(x) * ((x + 3 * fabs(x - y) + pow(x, 2)) / (fabs(x - y) * z + pow(x, 2)));
		}
};
}
