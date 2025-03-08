#pragma once

namespace LR18 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Task1
	/// </summary>
	public ref class Task1 : public System::Windows::Forms::Form
	{
	public:
		Task1(void)
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
		~Task1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ TranslateTypeLabel;
	private: System::Windows::Forms::Label^ TranslateTimeLabel;
	private: System::Windows::Forms::TextBox^ TranslateTimeTextBox;
	protected:

	protected:


	private: System::Windows::Forms::ComboBox^ TranslateTypeComboBox;
	private: System::Windows::Forms::Button^ CalculateButton;


	private: System::Windows::Forms::TextBox^ TranslatePriceTextBox;

	private: System::Windows::Forms::Label^ TranslatePriceLabel;


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
			this->TranslateTypeLabel = (gcnew System::Windows::Forms::Label());
			this->TranslateTimeLabel = (gcnew System::Windows::Forms::Label());
			this->TranslateTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TranslateTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CalculateButton = (gcnew System::Windows::Forms::Button());
			this->TranslatePriceTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TranslatePriceLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// TranslateTypeLabel
			// 
			this->TranslateTypeLabel->AutoSize = true;
			this->TranslateTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TranslateTypeLabel->Location = System::Drawing::Point(21, 21);
			this->TranslateTypeLabel->Name = L"TranslateTypeLabel";
			this->TranslateTypeLabel->Size = System::Drawing::Size(91, 15);
			this->TranslateTypeLabel->TabIndex = 0;
			this->TranslateTypeLabel->Text = L"Вид перевода:";
			// 
			// TranslateTimeLabel
			// 
			this->TranslateTimeLabel->AutoSize = true;
			this->TranslateTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TranslateTimeLabel->Location = System::Drawing::Point(21, 57);
			this->TranslateTimeLabel->Name = L"TranslateTimeLabel";
			this->TranslateTimeLabel->Size = System::Drawing::Size(107, 15);
			this->TranslateTimeLabel->TabIndex = 1;
			this->TranslateTimeLabel->Text = L"Время перевода:";
			// 
			// TranslateTimeTextBox
			// 
			this->TranslateTimeTextBox->Location = System::Drawing::Point(131, 57);
			this->TranslateTimeTextBox->Name = L"TranslateTimeTextBox";
			this->TranslateTimeTextBox->Size = System::Drawing::Size(121, 20);
			this->TranslateTimeTextBox->TabIndex = 2;
			// 
			// TranslateTypeComboBox
			// 
			this->TranslateTypeComboBox->FormattingEnabled = true;
			this->TranslateTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"E", L"K", L"R" });
			this->TranslateTypeComboBox->Location = System::Drawing::Point(131, 20);
			this->TranslateTypeComboBox->Name = L"TranslateTypeComboBox";
			this->TranslateTypeComboBox->Size = System::Drawing::Size(121, 21);
			this->TranslateTypeComboBox->TabIndex = 3;
			// 
			// CalculateButton
			// 
			this->CalculateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CalculateButton->Location = System::Drawing::Point(24, 180);
			this->CalculateButton->Name = L"CalculateButton";
			this->CalculateButton->Size = System::Drawing::Size(104, 23);
			this->CalculateButton->TabIndex = 4;
			this->CalculateButton->Text = L"Рассчитать ";
			this->CalculateButton->UseVisualStyleBackColor = true;
			this->CalculateButton->Click += gcnew System::EventHandler(this, &Task1::CalculateButton_Click);
			// 
			// TranslatePriceTextBox
			// 
			this->TranslatePriceTextBox->Location = System::Drawing::Point(24, 130);
			this->TranslatePriceTextBox->Name = L"TranslatePriceTextBox";
			this->TranslatePriceTextBox->ReadOnly = true;
			this->TranslatePriceTextBox->Size = System::Drawing::Size(196, 20);
			this->TranslatePriceTextBox->TabIndex = 5;
			// 
			// TranslatePriceLabel
			// 
			this->TranslatePriceLabel->AutoSize = true;
			this->TranslatePriceLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TranslatePriceLabel->Location = System::Drawing::Point(21, 112);
			this->TranslatePriceLabel->Name = L"TranslatePriceLabel";
			this->TranslatePriceLabel->Size = System::Drawing::Size(99, 15);
			this->TranslatePriceLabel->TabIndex = 6;
			this->TranslatePriceLabel->Text = L"Цена перевода:";
			// 
			// Task1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(276, 239);
			this->Controls->Add(this->TranslatePriceLabel);
			this->Controls->Add(this->TranslatePriceTextBox);
			this->Controls->Add(this->CalculateButton);
			this->Controls->Add(this->TranslateTypeComboBox);
			this->Controls->Add(this->TranslateTimeTextBox);
			this->Controls->Add(this->TranslateTimeLabel);
			this->Controls->Add(this->TranslateTypeLabel);
			this->Name = L"Task1";
			this->Text = L"Task1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void CalculateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		char type;
		int time = 0, price = 0;

		type = Convert::ToChar(TranslateTypeComboBox->SelectedItem);

		if (!Int32::TryParse(TranslateTimeTextBox->Text, time)) {
			MessageBox::Show(
				"Введите корректное значение времени", 
				"Ошибка", 
				MessageBoxButtons::OK, 
				MessageBoxIcon::Error
			);
			return;
		}

		if (type == 'E' && time <= 270)
			price = 1700;
		else if (type == 'K' && time <= 390)
			price = 3500;
		else if (type == 'R' && time <= 540)
			price = 5000;
		else {
			MessageBox::Show(
				"Неправильный вид или время перевода", 
				"Ошибка", 
				MessageBoxButtons::OK, 
				MessageBoxIcon::Error
			);
			return;
		}

		TranslatePriceTextBox->Text = price.ToString();
	}
};
}
