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
	private: System::Windows::Forms::Label^ TypeLabel;
	private: System::Windows::Forms::Label^ ValueLabel;
	private: System::Windows::Forms::TextBox^ ValueTextBox;
	protected:



	private: System::Windows::Forms::ComboBox^ TypeComboBox;
	protected:

	protected:



	private: System::Windows::Forms::Button^ CalculateButton;
	private: System::Windows::Forms::TextBox^ ResultTextBox;



	private: System::Windows::Forms::Label^ ResultLabel;


	private: System::Windows::Forms::CheckBox^ SwitchTaskCheckBox;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TypeLabel = (gcnew System::Windows::Forms::Label());
			this->ValueLabel = (gcnew System::Windows::Forms::Label());
			this->ValueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CalculateButton = (gcnew System::Windows::Forms::Button());
			this->ResultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ResultLabel = (gcnew System::Windows::Forms::Label());
			this->SwitchTaskCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// TypeLabel
			// 
			this->TypeLabel->AutoSize = true;
			this->TypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TypeLabel->Location = System::Drawing::Point(21, 21);
			this->TypeLabel->Name = L"TypeLabel";
			this->TypeLabel->Size = System::Drawing::Size(91, 15);
			this->TypeLabel->TabIndex = 0;
			this->TypeLabel->Text = L"Вид перевода:";
			// 
			// ValueLabel
			// 
			this->ValueLabel->AutoSize = true;
			this->ValueLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ValueLabel->Location = System::Drawing::Point(21, 57);
			this->ValueLabel->Name = L"ValueLabel";
			this->ValueLabel->Size = System::Drawing::Size(107, 15);
			this->ValueLabel->TabIndex = 1;
			this->ValueLabel->Text = L"Время перевода:";
			// 
			// ValueTextBox
			// 
			this->ValueTextBox->Location = System::Drawing::Point(167, 58);
			this->ValueTextBox->Name = L"ValueTextBox";
			this->ValueTextBox->Size = System::Drawing::Size(121, 20);
			this->ValueTextBox->TabIndex = 2;
			// 
			// TypeComboBox
			// 
			this->TypeComboBox->FormattingEnabled = true;
			this->TypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"E", L"K", L"R" });
			this->TypeComboBox->Location = System::Drawing::Point(167, 21);
			this->TypeComboBox->Name = L"TypeComboBox";
			this->TypeComboBox->Size = System::Drawing::Size(121, 21);
			this->TypeComboBox->TabIndex = 3;
			// 
			// CalculateButton
			// 
			this->CalculateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CalculateButton->Location = System::Drawing::Point(24, 154);
			this->CalculateButton->Name = L"CalculateButton";
			this->CalculateButton->Size = System::Drawing::Size(104, 23);
			this->CalculateButton->TabIndex = 4;
			this->CalculateButton->Text = L"Рассчитать ";
			this->CalculateButton->UseVisualStyleBackColor = true;
			this->CalculateButton->Click += gcnew System::EventHandler(this, &Task1::CalculateButton_Click);
			// 
			// ResultTextBox
			// 
			this->ResultTextBox->Location = System::Drawing::Point(24, 219);
			this->ResultTextBox->Name = L"ResultTextBox";
			this->ResultTextBox->ReadOnly = true;
			this->ResultTextBox->Size = System::Drawing::Size(196, 20);
			this->ResultTextBox->TabIndex = 5;
			// 
			// ResultLabel
			// 
			this->ResultLabel->AutoSize = true;
			this->ResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResultLabel->Location = System::Drawing::Point(21, 201);
			this->ResultLabel->Name = L"ResultLabel";
			this->ResultLabel->Size = System::Drawing::Size(99, 15);
			this->ResultLabel->TabIndex = 6;
			this->ResultLabel->Text = L"Цена перевода:";
			// 
			// SwitchTaskCheckBox
			// 
			this->SwitchTaskCheckBox->AutoSize = true;
			this->SwitchTaskCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SwitchTaskCheckBox->Location = System::Drawing::Point(24, 109);
			this->SwitchTaskCheckBox->Name = L"SwitchTaskCheckBox";
			this->SwitchTaskCheckBox->Size = System::Drawing::Size(119, 19);
			this->SwitchTaskCheckBox->TabIndex = 7;
			this->SwitchTaskCheckBox->Text = L"Сменить задачу";
			this->SwitchTaskCheckBox->UseVisualStyleBackColor = true;
			this->SwitchTaskCheckBox->CheckedChanged += gcnew System::EventHandler(this, &Task1::SwitchTaskCheckBox_CheckedChanged);
			// 
			// Task1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(314, 268);
			this->Controls->Add(this->SwitchTaskCheckBox);
			this->Controls->Add(this->ResultLabel);
			this->Controls->Add(this->ResultTextBox);
			this->Controls->Add(this->CalculateButton);
			this->Controls->Add(this->TypeComboBox);
			this->Controls->Add(this->ValueTextBox);
			this->Controls->Add(this->ValueLabel);
			this->Controls->Add(this->TypeLabel);
			this->Name = L"Task1";
			this->Text = L"Task1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void CalculateTranslatePrice() {
		char type;
		int time = 0, price = 0;

		type = Convert::ToChar(TypeComboBox->SelectedItem);

		if (!Int32::TryParse(ValueTextBox->Text, time)) {
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

		ResultTextBox->Text = price.ToString();
	}

	private: void ConvertCurrency() {
		double value;

		if (!Double::TryParse(ValueTextBox->Text, value)) {
			MessageBox::Show(
				"Введите корректное число в рублях",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		String^ currency = TypeComboBox->SelectedItem != nullptr ? TypeComboBox->SelectedItem->ToString() : "";

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

		ResultTextBox->Text = newValue.ToString("F2");
	}


	private: Void CalculateButton_Click(Object^ sender, EventArgs^ e) {
		if (SwitchTaskCheckBox->Checked)
			ConvertCurrency();
		else
			CalculateTranslatePrice();
	}
	private: Void SwitchTaskCheckBox_CheckedChanged(Object^ sender, EventArgs^ e) {
		TypeComboBox->SelectedIndex = -1;
		ValueTextBox->Clear();
		ResultTextBox->Clear();

		if (SwitchTaskCheckBox->Checked) {
			TypeLabel->Text = "Вид валюты: ";
			ValueLabel->Text = "Значение в рублях: ";
			ResultLabel->Text = "Сконвертированное значение: ";

			TypeComboBox->Items->Clear();

			TypeComboBox->Items->Add("Доллары");
			TypeComboBox->Items->Add("Евро");
			TypeComboBox->Items->Add("Юани");
		}
		else {
			TypeLabel->Text = "Вид перевода: ";
			ValueLabel->Text = "Время перевода: ";
			ResultLabel->Text = "Цена перевода: ";

			TypeComboBox->Items->Clear();

			TypeComboBox->Items->Add("E");
			TypeComboBox->Items->Add("K");
			TypeComboBox->Items->Add("R");
		}
	}
};
}
