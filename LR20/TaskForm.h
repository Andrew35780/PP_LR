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
	/// Сводка для TaskForm
	/// </summary>
	public ref class TaskForm : public System::Windows::Forms::Form
	{
	public:
		TaskForm(void)
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
		~TaskForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ResultsDataGridView;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ XColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ YColumn;
	private: System::Windows::Forms::Button^ CalculateButton;
	private: System::Windows::Forms::TextBox^ StepTextBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ bTextBox;
	private: System::Windows::Forms::TextBox^ aTextBox;
	private: System::Windows::Forms::Label^ bLabel;
	private: System::Windows::Forms::Label^ aLabel;
	private: System::Windows::Forms::TextBox^ mTextBox;
	private: System::Windows::Forms::Label^ mLabel;
	private: System::Windows::Forms::TextBox^ cTextBox;
	private: System::Windows::Forms::Label^ cLabel;

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
			this->ResultsDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->XColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->YColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CalculateButton = (gcnew System::Windows::Forms::Button());
			this->StepTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bTextBox = (gcnew System::Windows::Forms::TextBox());
			this->aTextBox = (gcnew System::Windows::Forms::TextBox());
			this->bLabel = (gcnew System::Windows::Forms::Label());
			this->aLabel = (gcnew System::Windows::Forms::Label());
			this->mTextBox = (gcnew System::Windows::Forms::TextBox());
			this->mLabel = (gcnew System::Windows::Forms::Label());
			this->cTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultsDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// ResultsDataGridView
			// 
			this->ResultsDataGridView->AllowUserToAddRows = false;
			this->ResultsDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ResultsDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->XColumn,
					this->YColumn
			});
			this->ResultsDataGridView->Location = System::Drawing::Point(155, 140);
			this->ResultsDataGridView->Name = L"ResultsDataGridView";
			this->ResultsDataGridView->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ResultsDataGridView->Size = System::Drawing::Size(240, 192);
			this->ResultsDataGridView->TabIndex = 15;
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
			// CalculateButton
			// 
			this->CalculateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CalculateButton->Location = System::Drawing::Point(24, 339);
			this->CalculateButton->Name = L"CalculateButton";
			this->CalculateButton->Size = System::Drawing::Size(86, 23);
			this->CalculateButton->TabIndex = 14;
			this->CalculateButton->Text = L"Рассчитать";
			this->CalculateButton->UseVisualStyleBackColor = true;
			this->CalculateButton->Click += gcnew System::EventHandler(this, &TaskForm::CalculateButton_Click);
			// 
			// StepTextBox
			// 
			this->StepTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StepTextBox->Location = System::Drawing::Point(295, 60);
			this->StepTextBox->Name = L"StepTextBox";
			this->StepTextBox->Size = System::Drawing::Size(100, 21);
			this->StepTextBox->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(259, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 15);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Шаг";
			// 
			// bTextBox
			// 
			this->bTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bTextBox->Location = System::Drawing::Point(40, 46);
			this->bTextBox->Name = L"bTextBox";
			this->bTextBox->Size = System::Drawing::Size(100, 21);
			this->bTextBox->TabIndex = 11;
			// 
			// aTextBox
			// 
			this->aTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->aTextBox->Location = System::Drawing::Point(41, 17);
			this->aTextBox->Name = L"aTextBox";
			this->aTextBox->Size = System::Drawing::Size(100, 21);
			this->aTextBox->TabIndex = 10;
			// 
			// bLabel
			// 
			this->bLabel->AutoSize = true;
			this->bLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bLabel->Location = System::Drawing::Point(20, 46);
			this->bLabel->Name = L"bLabel";
			this->bLabel->Size = System::Drawing::Size(14, 15);
			this->bLabel->TabIndex = 9;
			this->bLabel->Text = L"b";
			// 
			// aLabel
			// 
			this->aLabel->AutoSize = true;
			this->aLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->aLabel->Location = System::Drawing::Point(20, 17);
			this->aLabel->Name = L"aLabel";
			this->aLabel->Size = System::Drawing::Size(14, 15);
			this->aLabel->TabIndex = 8;
			this->aLabel->Text = L"a";
			// 
			// mTextBox
			// 
			this->mTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mTextBox->Location = System::Drawing::Point(40, 82);
			this->mTextBox->Name = L"mTextBox";
			this->mTextBox->Size = System::Drawing::Size(100, 21);
			this->mTextBox->TabIndex = 17;
			// 
			// mLabel
			// 
			this->mLabel->AutoSize = true;
			this->mLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mLabel->Location = System::Drawing::Point(20, 82);
			this->mLabel->Name = L"mLabel";
			this->mLabel->Size = System::Drawing::Size(18, 15);
			this->mLabel->TabIndex = 16;
			this->mLabel->Text = L"m";
			// 
			// cTextBox
			// 
			this->cTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cTextBox->Location = System::Drawing::Point(41, 112);
			this->cTextBox->Name = L"cTextBox";
			this->cTextBox->Size = System::Drawing::Size(100, 21);
			this->cTextBox->TabIndex = 19;
			// 
			// cLabel
			// 
			this->cLabel->AutoSize = true;
			this->cLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cLabel->Location = System::Drawing::Point(21, 112);
			this->cLabel->Name = L"cLabel";
			this->cLabel->Size = System::Drawing::Size(13, 15);
			this->cLabel->TabIndex = 18;
			this->cLabel->Text = L"c";
			// 
			// TaskForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(414, 374);
			this->Controls->Add(this->cTextBox);
			this->Controls->Add(this->cLabel);
			this->Controls->Add(this->mTextBox);
			this->Controls->Add(this->mLabel);
			this->Controls->Add(this->ResultsDataGridView);
			this->Controls->Add(this->CalculateButton);
			this->Controls->Add(this->StepTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bTextBox);
			this->Controls->Add(this->aTextBox);
			this->Controls->Add(this->bLabel);
			this->Controls->Add(this->aLabel);
			this->Name = L"TaskForm";
			this->Text = L"TaskForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultsDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: double Func(double m, double x, double c) {
		return cbrt(m * tan(x) + fabs(c * sin(x)));
	}

	private: Void CalculateButton_Click(Object^ sender, EventArgs^ e) {
		double a, b, m, c, delta, y;

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

		if (!Double::TryParse(mTextBox->Text, m)) {
			MessageBox::Show(
				"Некорректное значение m",
				"Ошибка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		if (!Double::TryParse(cTextBox->Text, c)) {
			MessageBox::Show(
				"Некорректное значение c",
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

		for (double x = a; x <= b; x += delta) {
			y = Func(m, x, c);

			ResultsDataGridView->Rows->Add(x, Math::Round(y, 4));
		}
	}
};
}
