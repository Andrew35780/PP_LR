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
	/// Сводка для Task2
	/// </summary>
	public ref class Task2 : public System::Windows::Forms::Form
	{
	public:
		Task2(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Task2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ ALabel;
	protected:
	private: System::Windows::Forms::Label^ XLabel;
	private: System::Windows::Forms::TextBox^ ATextBox;
	private: System::Windows::Forms::TextBox^ XTextBox;
	private: System::Windows::Forms::TextBox^ ResultTextBox;
	private: System::Windows::Forms::Button^ CalculateButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ PhiComboBox;

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
			this->ALabel = (gcnew System::Windows::Forms::Label());
			this->XLabel = (gcnew System::Windows::Forms::Label());
			this->ATextBox = (gcnew System::Windows::Forms::TextBox());
			this->XTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ResultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CalculateButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PhiComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// ALabel
			// 
			this->ALabel->AutoSize = true;
			this->ALabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ALabel->Location = System::Drawing::Point(29, 27);
			this->ALabel->Name = L"ALabel";
			this->ALabel->Size = System::Drawing::Size(14, 15);
			this->ALabel->TabIndex = 0;
			this->ALabel->Text = L"A";
			// 
			// XLabel
			// 
			this->XLabel->AutoSize = true;
			this->XLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->XLabel->Location = System::Drawing::Point(29, 59);
			this->XLabel->Name = L"XLabel";
			this->XLabel->Size = System::Drawing::Size(15, 15);
			this->XLabel->TabIndex = 1;
			this->XLabel->Text = L"X";
			// 
			// ATextBox
			// 
			this->ATextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ATextBox->Location = System::Drawing::Point(49, 26);
			this->ATextBox->Name = L"ATextBox";
			this->ATextBox->Size = System::Drawing::Size(100, 21);
			this->ATextBox->TabIndex = 2;
			// 
			// XTextBox
			// 
			this->XTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->XTextBox->Location = System::Drawing::Point(50, 59);
			this->XTextBox->Name = L"XTextBox";
			this->XTextBox->Size = System::Drawing::Size(100, 21);
			this->XTextBox->TabIndex = 3;
			// 
			// ResultTextBox
			// 
			this->ResultTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResultTextBox->Location = System::Drawing::Point(29, 125);
			this->ResultTextBox->Multiline = true;
			this->ResultTextBox->Name = L"ResultTextBox";
			this->ResultTextBox->ReadOnly = true;
			this->ResultTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ResultTextBox->Size = System::Drawing::Size(321, 131);
			this->ResultTextBox->TabIndex = 4;
			// 
			// CalculateButton
			// 
			this->CalculateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CalculateButton->Location = System::Drawing::Point(29, 281);
			this->CalculateButton->Name = L"CalculateButton";
			this->CalculateButton->Size = System::Drawing::Size(85, 23);
			this->CalculateButton->TabIndex = 5;
			this->CalculateButton->Text = L"Вычислить";
			this->CalculateButton->UseVisualStyleBackColor = true;
			this->CalculateButton->Click += gcnew System::EventHandler(this, &Task2::CalculateButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(226, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Функция";
			// 
			// PhiComboBox
			// 
			this->PhiComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PhiComboBox->FormattingEnabled = true;
			this->PhiComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"2x", L"x^2", L"x/3" });
			this->PhiComboBox->Location = System::Drawing::Point(229, 51);
			this->PhiComboBox->Name = L"PhiComboBox";
			this->PhiComboBox->Size = System::Drawing::Size(121, 23);
			this->PhiComboBox->TabIndex = 7;
			// 
			// Task2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(377, 328);
			this->Controls->Add(this->PhiComboBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CalculateButton);
			this->Controls->Add(this->ResultTextBox);
			this->Controls->Add(this->XTextBox);
			this->Controls->Add(this->ATextBox);
			this->Controls->Add(this->XLabel);
			this->Controls->Add(this->ALabel);
			this->Name = L"Task2";
			this->Text = L"Task2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: double CalculatePhi(double x) {
		String^ selected = PhiComboBox->SelectedItem != nullptr ? PhiComboBox->SelectedItem->ToString() : "";

		if (selected == "2x") 
			return 2 * x;
		if (selected == "x^2") 
			return x * x;
		if (selected == "x/3") 
			return x / 3.0;

		return 0;
	}

	private: double CalculateFunc(double x, double y, double a, double phi) {
		return x - 0.75 * phi * log2(y + a);
	}

	private: Void CalculateButton_Click(Object^ sender, EventArgs^ e) {
		ResultTextBox->Clear();
		
		double x, a;

		if (!Double::TryParse(XTextBox->Text, x) || !Double::TryParse(ATextBox->Text, a)) {  
			MessageBox::Show(
				"Ошибка ввода. Введите числа.",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		double phi = CalculatePhi(x);
		if (phi == 0) {
			MessageBox::Show(
				"Выберите функцию или замените x.",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		for (double y = -2; y <= 2; y += 0.4) {
			if (y + a <= 0) {
				ResultTextBox->Text += Environment::NewLine + "Ошибка: log2(" + (y + a) + ") недопустимо\n";
				continue;
			}

			double result = CalculateFunc(x, y, a, phi);
			if (y == -2)
				ResultTextBox->Text += String::Format("z = {0:F4}, при x = {1}, y = {2}, a = {3}, phi = {4}", 
					result, x, y, a, PhiComboBox->SelectedItem);
			else
				ResultTextBox->Text += Environment::NewLine + String::Format("z = {0:F4}, при x = {1}, y = {2:F1}, a = {3}, phi = {4}", 
					result, x, y, a, PhiComboBox->SelectedItem);
		}
	}
};
}
