#pragma once

namespace LR18 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Task1_Part2
	/// </summary>
	public ref class Task1_Part2 : public System::Windows::Forms::Form
	{
	public:
		Task1_Part2(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Task1_Part2()
		{
			if (components)
				delete components;
		}
	private: System::Windows::Forms::Label^ RublesValueLabel;
	private: System::Windows::Forms::Label^ Currencylabel;
	protected:

	private: System::Windows::Forms::TextBox^ RublesValueTextBox;
	private: System::Windows::Forms::ComboBox^ CurrencyComboBox;
	private: System::Windows::Forms::Button^ ConvertButton;
	private: System::Windows::Forms::Label^ ConvertedValueLabel;
	private: System::Windows::Forms::Label^ ConvertedValue;

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
			this->RublesValueLabel = (gcnew System::Windows::Forms::Label());
			this->Currencylabel = (gcnew System::Windows::Forms::Label());
			this->RublesValueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrencyComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ConvertButton = (gcnew System::Windows::Forms::Button());
			this->ConvertedValueLabel = (gcnew System::Windows::Forms::Label());
			this->ConvertedValue = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// RublesValueLabel
			// 
			this->RublesValueLabel->AutoSize = true;
			this->RublesValueLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RublesValueLabel->Location = System::Drawing::Point(21, 23);
			this->RublesValueLabel->Name = L"RublesValueLabel";
			this->RublesValueLabel->Size = System::Drawing::Size(118, 15);
			this->RublesValueLabel->TabIndex = 0;
			this->RublesValueLabel->Text = L"Значение в рублях:";
			// 
			// Currencylabel
			// 
			this->Currencylabel->AutoSize = true;
			this->Currencylabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Currencylabel->Location = System::Drawing::Point(21, 56);
			this->Currencylabel->Name = L"Currencylabel";
			this->Currencylabel->Size = System::Drawing::Size(114, 15);
			this->Currencylabel->TabIndex = 1;
			this->Currencylabel->Text = L"Выберите валюту:";
			// 
			// RublesValueTextBox
			// 
			this->RublesValueTextBox->Location = System::Drawing::Point(145, 22);
			this->RublesValueTextBox->Name = L"RublesValueTextBox";
			this->RublesValueTextBox->Size = System::Drawing::Size(115, 20);
			this->RublesValueTextBox->TabIndex = 2;
			// 
			// CurrencyComboBox
			// 
			this->CurrencyComboBox->FormattingEnabled = true;
			this->CurrencyComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Доллары", L"Евро", L"Юани" });
			this->CurrencyComboBox->Location = System::Drawing::Point(145, 56);
			this->CurrencyComboBox->Name = L"CurrencyComboBox";
			this->CurrencyComboBox->Size = System::Drawing::Size(115, 21);
			this->CurrencyComboBox->TabIndex = 3;
			// 
			// ConvertButton
			// 
			this->ConvertButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ConvertButton->Location = System::Drawing::Point(24, 94);
			this->ConvertButton->Name = L"ConvertButton";
			this->ConvertButton->Size = System::Drawing::Size(115, 23);
			this->ConvertButton->TabIndex = 4;
			this->ConvertButton->Text = L"Конвертировать";
			this->ConvertButton->UseVisualStyleBackColor = true;
			this->ConvertButton->Click += gcnew System::EventHandler(this, &Task1_Part2::ConvertButton_Click);
			// 
			// ConvertedValueLabel
			// 
			this->ConvertedValueLabel->AutoSize = true;
			this->ConvertedValueLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ConvertedValueLabel->Location = System::Drawing::Point(21, 146);
			this->ConvertedValueLabel->Name = L"ConvertedValueLabel";
			this->ConvertedValueLabel->Size = System::Drawing::Size(183, 15);
			this->ConvertedValueLabel->TabIndex = 5;
			this->ConvertedValueLabel->Text = L"Конвертированное значение: ";
			// 
			// ConvertedValue
			// 
			this->ConvertedValue->AutoSize = true;
			this->ConvertedValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ConvertedValue->Location = System::Drawing::Point(210, 146);
			this->ConvertedValue->Name = L"ConvertedValue";
			this->ConvertedValue->Size = System::Drawing::Size(0, 15);
			this->ConvertedValue->TabIndex = 6;
			// 
			// Task1_Part2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(362, 261);
			this->Controls->Add(this->ConvertedValue);
			this->Controls->Add(this->ConvertedValueLabel);
			this->Controls->Add(this->ConvertButton);
			this->Controls->Add(this->CurrencyComboBox);
			this->Controls->Add(this->RublesValueTextBox);
			this->Controls->Add(this->Currencylabel);
			this->Controls->Add(this->RublesValueLabel);
			this->Name = L"Task1_Part2";
			this->Text = L"Конвертер валют";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Void ConvertButton_Click(Object^ sender, EventArgs^ e) {
		double value;

		if (!Double::TryParse(RublesValueTextBox->Text, value)) {
			MessageBox::Show(
				"Введите корректное число в рублях", 
				"Ошибка",
				MessageBoxButtons::OK, 
				MessageBoxIcon::Error
			);
			return;
		}

		String^ currency = CurrencyComboBox->SelectedItem != nullptr ? CurrencyComboBox->SelectedItem->ToString() : "";

		if (currency == "") {
			MessageBox::Show(
				"Выберите вид валюты для конвертации",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		double dollarCourse = 95.03;
		double euroCourse = 104.87;
		double yuanCourse = 13.48;
		double newValue = 0.0;

		if (currency == "Доллары")
			newValue = value / dollarCourse;
		else if (currency == "Евро")
			newValue = value / euroCourse;
		else if (currency == "Юани")
			newValue = value / yuanCourse;
		else {
			MessageBox::Show(
				"Выбран неверный тип валюты", 
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		ConvertedValue->Text = " " + newValue.ToString("F2");
	}
};
}
