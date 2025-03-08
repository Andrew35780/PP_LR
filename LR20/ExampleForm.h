#pragma once

#include <cmath>

namespace LR20 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ExampleForm
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
	private: System::Windows::Forms::Label^ aLabel;
	private: System::Windows::Forms::Label^ bLabel;
	private: System::Windows::Forms::TextBox^ aTextBox;
	private: System::Windows::Forms::TextBox^ bTextBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ StepTextBox;
	private: System::Windows::Forms::Button^ CalculateButton;
	private: System::Windows::Forms::DataGridView^ ResultsDataGridView;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ XColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ YColumn;

	protected:

	protected:

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
			this->aLabel = (gcnew System::Windows::Forms::Label());
			this->bLabel = (gcnew System::Windows::Forms::Label());
			this->aTextBox = (gcnew System::Windows::Forms::TextBox());
			this->bTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->StepTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CalculateButton = (gcnew System::Windows::Forms::Button());
			this->ResultsDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->XColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->YColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultsDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// aLabel
			// 
			this->aLabel->AutoSize = true;
			this->aLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->aLabel->Location = System::Drawing::Point(22, 23);
			this->aLabel->Name = L"aLabel";
			this->aLabel->Size = System::Drawing::Size(14, 15);
			this->aLabel->TabIndex = 0;
			this->aLabel->Text = L"a";
			// 
			// bLabel
			// 
			this->bLabel->AutoSize = true;
			this->bLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bLabel->Location = System::Drawing::Point(22, 52);
			this->bLabel->Name = L"bLabel";
			this->bLabel->Size = System::Drawing::Size(14, 15);
			this->bLabel->TabIndex = 1;
			this->bLabel->Text = L"b";
			// 
			// aTextBox
			// 
			this->aTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->aTextBox->Location = System::Drawing::Point(43, 23);
			this->aTextBox->Name = L"aTextBox";
			this->aTextBox->Size = System::Drawing::Size(100, 21);
			this->aTextBox->TabIndex = 2;
			// 
			// bTextBox
			// 
			this->bTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bTextBox->Location = System::Drawing::Point(42, 52);
			this->bTextBox->Name = L"bTextBox";
			this->bTextBox->Size = System::Drawing::Size(100, 21);
			this->bTextBox->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(192, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 15);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Шаг";
			// 
			// StepTextBox
			// 
			this->StepTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StepTextBox->Location = System::Drawing::Point(228, 23);
			this->StepTextBox->Name = L"StepTextBox";
			this->StepTextBox->Size = System::Drawing::Size(100, 21);
			this->StepTextBox->TabIndex = 5;
			// 
			// CalculateButton
			// 
			this->CalculateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CalculateButton->Location = System::Drawing::Point(25, 266);
			this->CalculateButton->Name = L"CalculateButton";
			this->CalculateButton->Size = System::Drawing::Size(86, 23);
			this->CalculateButton->TabIndex = 6;
			this->CalculateButton->Text = L"Рассчитать";
			this->CalculateButton->UseVisualStyleBackColor = true;
			this->CalculateButton->Click += gcnew System::EventHandler(this, &ExampleForm::CalculateButton_Click);
			// 
			// ResultsDataGridView
			// 
			this->ResultsDataGridView->AllowUserToAddRows = false;
			this->ResultsDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ResultsDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->XColumn,
					this->YColumn
			});
			this->ResultsDataGridView->Location = System::Drawing::Point(148, 95);
			this->ResultsDataGridView->Name = L"ResultsDataGridView";
			this->ResultsDataGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ResultsDataGridView->Size = System::Drawing::Size(240, 150);
			this->ResultsDataGridView->TabIndex = 7;
			// 
			// XColumn
			// 
			this->XColumn->HeaderText = L"X";
			this->XColumn->Name = L"XColumn";
			// 
			// YColumn
			// 
			this->YColumn->HeaderText = L"Y";
			this->YColumn->Name = L"YColumn";
			// 
			// ExampleForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 301);
			this->Controls->Add(this->ResultsDataGridView);
			this->Controls->Add(this->CalculateButton);
			this->Controls->Add(this->StepTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bTextBox);
			this->Controls->Add(this->aTextBox);
			this->Controls->Add(this->bLabel);
			this->Controls->Add(this->aLabel);
			this->Name = L"ExampleForm";
			this->Text = L"ExampleForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultsDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Void CalculateButton_Click(Object^ sender, EventArgs^ e) {
		double a, b, delta, y;
		int lastRow;

		ResultsDataGridView->Rows->Clear();

		if (!Double::TryParse(aTextBox->Text, a)) {
			MessageBox::Show(
				"Некорректное значение a",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		if (!Double::TryParse(bTextBox->Text, b)) {
			MessageBox::Show(
				"Некорректное значение b",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		if (!Double::TryParse(StepTextBox->Text, delta)) {
			MessageBox::Show(
				"Некорректное значение шага",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		for (double i = a; i <= b; i += delta) {

			y = pow(i, 2);

			ResultsDataGridView->Rows->Add(); // добавляем строку в dataGridView

			lastRow = ResultsDataGridView->Rows->Count; // узнаем кол-во ячеек

			ResultsDataGridView->Rows[lastRow - 1]->Cells[0]->Value = i;
			ResultsDataGridView->Rows[lastRow - 1]->Cells[1]->Value = y;
		}
	}
};
}
