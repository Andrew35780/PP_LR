#pragma once

#include <cmath>

namespace LR18 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class ExampleForm : public System::Windows::Forms::Form
	{
	public:
		ExampleForm(void)
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
		~ExampleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ XLabel;
	protected:
	private: System::Windows::Forms::Label^ YLabel;
	private: System::Windows::Forms::Label^ ZLabel;
	private: System::Windows::Forms::TextBox^ XTextBox;
	private: System::Windows::Forms::TextBox^ YTextBox;
	private: System::Windows::Forms::TextBox^ ZTextBox;
	private: System::Windows::Forms::ComboBox^ FuncsComboBox;
	private: System::Windows::Forms::CheckBox^ MaxModulesCheckBox;
	private: System::Windows::Forms::TextBox^ ResultTextBox;
	private: System::Windows::Forms::Button^ CalculateButton;






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
			this->XLabel = (gcnew System::Windows::Forms::Label());
			this->YLabel = (gcnew System::Windows::Forms::Label());
			this->ZLabel = (gcnew System::Windows::Forms::Label());
			this->XTextBox = (gcnew System::Windows::Forms::TextBox());
			this->YTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ZTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FuncsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->MaxModulesCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ResultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CalculateButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// XLabel
			// 
			this->XLabel->AutoSize = true;
			this->XLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->XLabel->Location = System::Drawing::Point(22, 33);
			this->XLabel->Name = L"XLabel";
			this->XLabel->Size = System::Drawing::Size(15, 15);
			this->XLabel->TabIndex = 0;
			this->XLabel->Text = L"X";
			// 
			// YLabel
			// 
			this->YLabel->AutoSize = true;
			this->YLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->YLabel->Location = System::Drawing::Point(22, 61);
			this->YLabel->Name = L"YLabel";
			this->YLabel->Size = System::Drawing::Size(14, 15);
			this->YLabel->TabIndex = 1;
			this->YLabel->Text = L"Y";
			// 
			// ZLabel
			// 
			this->ZLabel->AutoSize = true;
			this->ZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ZLabel->Location = System::Drawing::Point(22, 88);
			this->ZLabel->Name = L"ZLabel";
			this->ZLabel->Size = System::Drawing::Size(14, 15);
			this->ZLabel->TabIndex = 2;
			this->ZLabel->Text = L"Z";
			// 
			// XTextBox
			// 
			this->XTextBox->Location = System::Drawing::Point(43, 33);
			this->XTextBox->Name = L"XTextBox";
			this->XTextBox->Size = System::Drawing::Size(121, 20);
			this->XTextBox->TabIndex = 3;
			// 
			// YTextBox
			// 
			this->YTextBox->Location = System::Drawing::Point(43, 61);
			this->YTextBox->Name = L"YTextBox";
			this->YTextBox->Size = System::Drawing::Size(121, 20);
			this->YTextBox->TabIndex = 4;
			// 
			// ZTextBox
			// 
			this->ZTextBox->Location = System::Drawing::Point(43, 88);
			this->ZTextBox->Name = L"ZTextBox";
			this->ZTextBox->Size = System::Drawing::Size(121, 20);
			this->ZTextBox->TabIndex = 5;
			// 
			// FuncsComboBox
			// 
			this->FuncsComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FuncsComboBox->FormattingEnabled = true;
			this->FuncsComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Косинус", L"Синус", L"Тангенс" });
			this->FuncsComboBox->Location = System::Drawing::Point(201, 32);
			this->FuncsComboBox->Name = L"FuncsComboBox";
			this->FuncsComboBox->Size = System::Drawing::Size(133, 23);
			this->FuncsComboBox->TabIndex = 6;
			this->FuncsComboBox->Text = L"Функция";
			// 
			// MaxModulesCheckBox
			// 
			this->MaxModulesCheckBox->AutoSize = true;
			this->MaxModulesCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MaxModulesCheckBox->Location = System::Drawing::Point(201, 63);
			this->MaxModulesCheckBox->Name = L"MaxModulesCheckBox";
			this->MaxModulesCheckBox->Size = System::Drawing::Size(109, 19);
			this->MaxModulesCheckBox->TabIndex = 7;
			this->MaxModulesCheckBox->Text = L"Max модулей\?";
			this->MaxModulesCheckBox->UseVisualStyleBackColor = true;
			// 
			// ResultTextBox
			// 
			this->ResultTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResultTextBox->Location = System::Drawing::Point(43, 157);
			this->ResultTextBox->Multiline = true;
			this->ResultTextBox->Name = L"ResultTextBox";
			this->ResultTextBox->ReadOnly = true;
			this->ResultTextBox->Size = System::Drawing::Size(211, 68);
			this->ResultTextBox->TabIndex = 8;
			// 
			// CalculateButton
			// 
			this->CalculateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CalculateButton->Location = System::Drawing::Point(43, 252);
			this->CalculateButton->Name = L"CalculateButton";
			this->CalculateButton->Size = System::Drawing::Size(75, 23);
			this->CalculateButton->TabIndex = 9;
			this->CalculateButton->Text = L"Решить";
			this->CalculateButton->UseVisualStyleBackColor = true;
			this->CalculateButton->Click += gcnew System::EventHandler(this, &ExampleForm::CalculateButton_Click);
			// 
			// ExampleForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(369, 310);
			this->Controls->Add(this->CalculateButton);
			this->Controls->Add(this->ResultTextBox);
			this->Controls->Add(this->MaxModulesCheckBox);
			this->Controls->Add(this->FuncsComboBox);
			this->Controls->Add(this->ZTextBox);
			this->Controls->Add(this->YTextBox);
			this->Controls->Add(this->XTextBox);
			this->Controls->Add(this->ZLabel);
			this->Controls->Add(this->YLabel);
			this->Controls->Add(this->XLabel);
			this->Name = L"ExampleForm";
			this->Text = L"Пример";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void CalculateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Double x, y, z, result, max;

		x = Convert::ToDouble(XTextBox->Text);
		y = Convert::ToDouble(YTextBox->Text);
		z = Convert::ToDouble(ZTextBox->Text);

		switch (FuncsComboBox->SelectedIndex) {
		case 0:
			result = cos(x);
			ResultTextBox->Text = String::Format("cos(x) равен {0:F4}", result);
			break;
		case 1:
			result = sin(x);
			ResultTextBox->Text = String::Format("sin(x) равен {0:F4}", result);
			break;
		case 2:
			result = tan(x);
			ResultTextBox->Text = String::Format("tan(x) равен {0:F4}", result);
			break;
		}

		if (MaxModulesCheckBox->Checked) {
			x = fabs(x);
			y = fabs(y);
			z = fabs(z);
		}
		if (x > y)
			max = x;
		else
			max = y;
		if (z > max)
			max = z;
		if (MaxModulesCheckBox->Checked)
			ResultTextBox->Text = ResultTextBox->Text + Environment::NewLine + String::Format("Max модулей равен {0:F4}", max);
		else  
			ResultTextBox->Text = ResultTextBox->Text + Environment::NewLine + String::Format("Max равен {0:F4}", max);
	}

};
}
