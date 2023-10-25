#include "windows.h"
#include <iostream>

#pragma once

namespace ИграСудоку {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Судоку
	/// </summary>
	public ref class Судоку : public System::Windows::Forms::Form
	{
	public:
		Судоку(void)
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
		~Судоку()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button39;
	private: System::Windows::Forms::Button^ button49;
	private: System::Windows::Forms::Button^ button59;
	private: System::Windows::Forms::Button^ button69;
	private: System::Windows::Forms::Button^ button79;
	private: System::Windows::Forms::Button^ button89;
	private: System::Windows::Forms::Button^ button99;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button38;
	private: System::Windows::Forms::Button^ button37;
	private: System::Windows::Forms::Button^ button47;
	private: System::Windows::Forms::Button^ button48;
	private: System::Windows::Forms::Button^ button57;
	private: System::Windows::Forms::Button^ button58;
	private: System::Windows::Forms::Button^ button67;
	private: System::Windows::Forms::Button^ button77;
	private: System::Windows::Forms::Button^ button87;
	private: System::Windows::Forms::Button^ button97;
	private: System::Windows::Forms::Button^ button68;
	private: System::Windows::Forms::Button^ button78;
	private: System::Windows::Forms::Button^ button88;
	private: System::Windows::Forms::Button^ button98;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button36;
	private: System::Windows::Forms::Button^ button46;
	private: System::Windows::Forms::Button^ button56;
	private: System::Windows::Forms::Button^ button66;
	private: System::Windows::Forms::Button^ button76;
	private: System::Windows::Forms::Button^ button86;
	private: System::Windows::Forms::Button^ button96;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button41;
	private: System::Windows::Forms::Button^ button42;
	private: System::Windows::Forms::Button^ button43;
	private: System::Windows::Forms::Button^ button44;
	private: System::Windows::Forms::Button^ button45;
	private: System::Windows::Forms::Button^ button51;
	private: System::Windows::Forms::Button^ button52;
	private: System::Windows::Forms::Button^ button53;
	private: System::Windows::Forms::Button^ button54;
	private: System::Windows::Forms::Button^ button55;
	private: System::Windows::Forms::Button^ button61;
	private: System::Windows::Forms::Button^ button62;
	private: System::Windows::Forms::Button^ button63;
	private: System::Windows::Forms::Button^ button64;
	private: System::Windows::Forms::Button^ button65;
	private: System::Windows::Forms::Button^ button71;
	private: System::Windows::Forms::Button^ button72;
	private: System::Windows::Forms::Button^ button73;
	private: System::Windows::Forms::Button^ button74;
	private: System::Windows::Forms::Button^ button75;
	private: System::Windows::Forms::Button^ button81;
	private: System::Windows::Forms::Button^ button82;
	private: System::Windows::Forms::Button^ button83;
	private: System::Windows::Forms::Button^ button84;
	private: System::Windows::Forms::Button^ button85;
	private: System::Windows::Forms::Button^ button91;
	private: System::Windows::Forms::Button^ button92;
	private: System::Windows::Forms::Button^ button93;
	private: System::Windows::Forms::Button^ button94;
	private: System::Windows::Forms::Button^ button95;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button40;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button50;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ button60;
	private: System::Windows::Forms::Label^ label2;

	const int SIZE = 9;
	private: String^ Changed = L" ";
	private: String^ Difficulty = L"Средний";
	cli::array<int, 2>^ sudokulog = gcnew cli::array<int, 2>(SIZE, SIZE);
	cli::array<int, 2>^ arraylog = gcnew cli::array<int, 2>(SIZE * SIZE, SIZE);
	cli::array<int, 2>^ arraylog_base = gcnew cli::array<int, 2>(SIZE * SIZE, SIZE);
	cli::array<int, 2>^ sudokutest_plus = gcnew cli::array<int, 2>(SIZE, SIZE);
	cli::array<int, 2>^ sudokutest_minus = gcnew cli::array<int, 2>(SIZE, SIZE);

		   bool check_row(int x, int y) {
			   for (int i = 0; i < y; i++) {
				   if (sudokulog[x, i] == sudokulog[x, y]) return false;
			   }
			   return true;
		   }

		   bool check_col(int x, int y) {
			   for (int i = 0; i < x; i++) {
				   if (sudokulog[i, y] == sudokulog[x, y]) return false;
			   }
			   return true;
		   }

		   bool check_sqr(int x, int y) {
			   int i_start = x / 3;	i_start *= 3;
			   int j_start = y / 3;	j_start *= 3;
			   for (int i = i_start; i < i_start + 3; i++) {
				   for (int j = j_start; j < j_start + 3; j++) {
					   if (i == x && j == y) return true;
					   if (sudokulog[i, j] == sudokulog[x, y]) return false;
				   }
			   }
			   return true;
		   }

		   bool check_all(int num, int x, int y) {
			   for (int i = 0; i < 9; i++) {
				   if (sudokulog[x, i] == num && y != i) {
					   return false;
				   }
			   }
			   for (int i = 0; i < 9; i++) {
				   if (sudokulog[i, y] == num && x != i) {
					   return false;
				   }
			   }
			   int i_start = x / 3; i_start *= 3;
			   int j_start = y / 3; j_start *= 3;
			   for (int i = i_start; i < i_start + 3; i++) {
				   for (int j = j_start; j < j_start + 3; j++) {
					   if (sudokulog[i, j] == num && i != x && j != y) return false;
				   }
			   }
			   return true;
		   }

		   bool test(int i, int j) {
			   int current = i * 9 + j;

			   for (int x = 0; x < 9; x++)
				   if (arraylog[current, x] == 0)
					   return true;

			   return false;
		   }

		   bool check_repeated(int i, int j) {
			   int value = sudokulog[i, j] - 1;
			   int current = i * 9 + j;

			   if (arraylog[current, value] == 1) return true;
			   else return false;
		   }

		   void move_back(int& i, int& j) {
			   int current = i * 9 + j;

			   for (int x = 0; x < 9; x++) {
				   arraylog[current, x] = 0;
			   }
			   if (j < 1)
			   {
				   i--;    j = 8;
			   }
			   else
				   j--;
		   }

		   void write(int i, int j) {
			   int current = i * 9 + j;
			   int value = sudokulog[i, j] - 1;

			   arraylog[current, value] = 1;
		   }

		   void write_to_base(int i, int j) {
			   int current = i * 9 + j;
			   int value = sudokulog[i, j] - 1;
			   for (int x = 0; x < 9; x++) {
				   arraylog_base[current, x] = 0;
			   }
			   arraylog_base[current, value] = 1;
		   }

		   bool blank(int& x, int& y) {
			   for (x = 0; x < 9; x++) {
				   for (y = 0; y < 9; y++) {
					   if (sudokulog[x, y] == 0) return true;
				   }
			   }
			   return false;
		   }

		   bool solver_plus() {
			   int row = 0; int col = 0;
			   if (!blank(row, col)) return true;
			   for (int i = 1; i <= 9; i++) {
				   if (check_all(i, row, col)) {
					   sudokulog[row, col] = i;
					   if (solver_plus()) return true;
					   sudokulog[row, col] = 0;
				   }
			   }
			   return false;
		   }

		   bool solver_minus() {
			   int row = 0; int col = 0;
			   if (!blank(row, col)) return true;
			   for (int i = 9; i >= 1; i--) {
				   if (check_all(i, row, col)) {
					   sudokulog[row, col] = i;
					   if (solver_minus()) return true;
					   sudokulog[row, col] = 0;
				   }
			   }
			   return false;
		   }

		   bool check_the_correctness() {
			   for (int i = 0; i < 9; i++) {
				   for (int j = 0; j < 9; j++) {
					   if (sudokutest_plus[i, j] != sudokutest_minus[i, j]) return false;
				   }
			   }
			   return true;
		   }

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Судоку::typeid));
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->button49 = (gcnew System::Windows::Forms::Button());
			this->button59 = (gcnew System::Windows::Forms::Button());
			this->button69 = (gcnew System::Windows::Forms::Button());
			this->button79 = (gcnew System::Windows::Forms::Button());
			this->button89 = (gcnew System::Windows::Forms::Button());
			this->button99 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->button47 = (gcnew System::Windows::Forms::Button());
			this->button48 = (gcnew System::Windows::Forms::Button());
			this->button57 = (gcnew System::Windows::Forms::Button());
			this->button58 = (gcnew System::Windows::Forms::Button());
			this->button67 = (gcnew System::Windows::Forms::Button());
			this->button77 = (gcnew System::Windows::Forms::Button());
			this->button87 = (gcnew System::Windows::Forms::Button());
			this->button97 = (gcnew System::Windows::Forms::Button());
			this->button68 = (gcnew System::Windows::Forms::Button());
			this->button78 = (gcnew System::Windows::Forms::Button());
			this->button88 = (gcnew System::Windows::Forms::Button());
			this->button98 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button46 = (gcnew System::Windows::Forms::Button());
			this->button56 = (gcnew System::Windows::Forms::Button());
			this->button66 = (gcnew System::Windows::Forms::Button());
			this->button76 = (gcnew System::Windows::Forms::Button());
			this->button86 = (gcnew System::Windows::Forms::Button());
			this->button96 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->button44 = (gcnew System::Windows::Forms::Button());
			this->button45 = (gcnew System::Windows::Forms::Button());
			this->button51 = (gcnew System::Windows::Forms::Button());
			this->button52 = (gcnew System::Windows::Forms::Button());
			this->button53 = (gcnew System::Windows::Forms::Button());
			this->button54 = (gcnew System::Windows::Forms::Button());
			this->button55 = (gcnew System::Windows::Forms::Button());
			this->button61 = (gcnew System::Windows::Forms::Button());
			this->button62 = (gcnew System::Windows::Forms::Button());
			this->button63 = (gcnew System::Windows::Forms::Button());
			this->button64 = (gcnew System::Windows::Forms::Button());
			this->button65 = (gcnew System::Windows::Forms::Button());
			this->button71 = (gcnew System::Windows::Forms::Button());
			this->button72 = (gcnew System::Windows::Forms::Button());
			this->button73 = (gcnew System::Windows::Forms::Button());
			this->button74 = (gcnew System::Windows::Forms::Button());
			this->button75 = (gcnew System::Windows::Forms::Button());
			this->button81 = (gcnew System::Windows::Forms::Button());
			this->button82 = (gcnew System::Windows::Forms::Button());
			this->button83 = (gcnew System::Windows::Forms::Button());
			this->button84 = (gcnew System::Windows::Forms::Button());
			this->button85 = (gcnew System::Windows::Forms::Button());
			this->button91 = (gcnew System::Windows::Forms::Button());
			this->button92 = (gcnew System::Windows::Forms::Button());
			this->button93 = (gcnew System::Windows::Forms::Button());
			this->button94 = (gcnew System::Windows::Forms::Button());
			this->button95 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button50 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button60 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// button19
			// 
			this->button19->Cursor = System::Windows::Forms::Cursors::Default;
			this->button19->FlatAppearance->BorderSize = 0;
			this->button19->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button19->ForeColor = System::Drawing::Color::Black;
			this->button19->Location = System::Drawing::Point(812, 73);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(55, 55);
			this->button19->TabIndex = 0;
			this->button19->Text = L" ";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button18
			// 
			this->button18->Cursor = System::Windows::Forms::Cursors::Default;
			this->button18->FlatAppearance->BorderSize = 0;
			this->button18->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button18->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button18->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button18->ForeColor = System::Drawing::Color::Black;
			this->button18->Location = System::Drawing::Point(751, 73);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(55, 55);
			this->button18->TabIndex = 1;
			this->button18->Text = L" ";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button29
			// 
			this->button29->Cursor = System::Windows::Forms::Cursors::Default;
			this->button29->FlatAppearance->BorderSize = 0;
			this->button29->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button29->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button29->ForeColor = System::Drawing::Color::Black;
			this->button29->Location = System::Drawing::Point(812, 134);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(55, 55);
			this->button29->TabIndex = 2;
			this->button29->Text = L" ";
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button39
			// 
			this->button39->Cursor = System::Windows::Forms::Cursors::Default;
			this->button39->FlatAppearance->BorderSize = 0;
			this->button39->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button39->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button39->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button39->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button39->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button39->ForeColor = System::Drawing::Color::Black;
			this->button39->Location = System::Drawing::Point(812, 195);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(55, 55);
			this->button39->TabIndex = 3;
			this->button39->Text = L" ";
			this->button39->UseVisualStyleBackColor = true;
			this->button39->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button49
			// 
			this->button49->Cursor = System::Windows::Forms::Cursors::Default;
			this->button49->FlatAppearance->BorderSize = 0;
			this->button49->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button49->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button49->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button49->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button49->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button49->ForeColor = System::Drawing::Color::Black;
			this->button49->Location = System::Drawing::Point(812, 256);
			this->button49->Name = L"button49";
			this->button49->Size = System::Drawing::Size(55, 55);
			this->button49->TabIndex = 4;
			this->button49->Text = L" ";
			this->button49->UseVisualStyleBackColor = true;
			this->button49->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button59
			// 
			this->button59->Cursor = System::Windows::Forms::Cursors::Default;
			this->button59->FlatAppearance->BorderSize = 0;
			this->button59->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button59->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button59->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button59->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button59->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button59->ForeColor = System::Drawing::Color::Black;
			this->button59->Location = System::Drawing::Point(812, 317);
			this->button59->Name = L"button59";
			this->button59->Size = System::Drawing::Size(55, 55);
			this->button59->TabIndex = 5;
			this->button59->Text = L" ";
			this->button59->UseVisualStyleBackColor = true;
			this->button59->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button69
			// 
			this->button69->Cursor = System::Windows::Forms::Cursors::Default;
			this->button69->FlatAppearance->BorderSize = 0;
			this->button69->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button69->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button69->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button69->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button69->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button69->ForeColor = System::Drawing::Color::Black;
			this->button69->Location = System::Drawing::Point(812, 378);
			this->button69->Name = L"button69";
			this->button69->Size = System::Drawing::Size(55, 55);
			this->button69->TabIndex = 6;
			this->button69->Text = L" ";
			this->button69->UseVisualStyleBackColor = true;
			this->button69->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button79
			// 
			this->button79->Cursor = System::Windows::Forms::Cursors::Default;
			this->button79->FlatAppearance->BorderSize = 0;
			this->button79->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button79->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button79->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button79->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button79->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button79->ForeColor = System::Drawing::Color::Black;
			this->button79->Location = System::Drawing::Point(812, 439);
			this->button79->Name = L"button79";
			this->button79->Size = System::Drawing::Size(55, 55);
			this->button79->TabIndex = 7;
			this->button79->Text = L" ";
			this->button79->UseVisualStyleBackColor = true;
			this->button79->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button89
			// 
			this->button89->Cursor = System::Windows::Forms::Cursors::Default;
			this->button89->FlatAppearance->BorderSize = 0;
			this->button89->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button89->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button89->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button89->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button89->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button89->ForeColor = System::Drawing::Color::Black;
			this->button89->Location = System::Drawing::Point(812, 500);
			this->button89->Name = L"button89";
			this->button89->Size = System::Drawing::Size(55, 55);
			this->button89->TabIndex = 8;
			this->button89->Text = L" ";
			this->button89->UseVisualStyleBackColor = true;
			this->button89->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button99
			// 
			this->button99->Cursor = System::Windows::Forms::Cursors::Default;
			this->button99->FlatAppearance->BorderSize = 0;
			this->button99->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button99->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button99->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button99->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button99->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button99->ForeColor = System::Drawing::Color::Black;
			this->button99->Location = System::Drawing::Point(812, 561);
			this->button99->Name = L"button99";
			this->button99->Size = System::Drawing::Size(55, 55);
			this->button99->TabIndex = 9;
			this->button99->Text = L" ";
			this->button99->UseVisualStyleBackColor = true;
			this->button99->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button17
			// 
			this->button17->Cursor = System::Windows::Forms::Cursors::Default;
			this->button17->FlatAppearance->BorderSize = 0;
			this->button17->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button17->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button17->ForeColor = System::Drawing::Color::Black;
			this->button17->Location = System::Drawing::Point(690, 73);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(55, 55);
			this->button17->TabIndex = 10;
			this->button17->Text = L" ";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button28
			// 
			this->button28->Cursor = System::Windows::Forms::Cursors::Default;
			this->button28->FlatAppearance->BorderSize = 0;
			this->button28->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button28->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button28->ForeColor = System::Drawing::Color::Black;
			this->button28->Location = System::Drawing::Point(751, 134);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(55, 55);
			this->button28->TabIndex = 11;
			this->button28->Text = L" ";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button27
			// 
			this->button27->Cursor = System::Windows::Forms::Cursors::Default;
			this->button27->FlatAppearance->BorderSize = 0;
			this->button27->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button27->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button27->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button27->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button27->ForeColor = System::Drawing::Color::Black;
			this->button27->Location = System::Drawing::Point(690, 134);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(55, 55);
			this->button27->TabIndex = 12;
			this->button27->Text = L" ";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button38
			// 
			this->button38->Cursor = System::Windows::Forms::Cursors::Default;
			this->button38->FlatAppearance->BorderSize = 0;
			this->button38->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button38->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button38->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button38->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button38->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button38->ForeColor = System::Drawing::Color::Black;
			this->button38->Location = System::Drawing::Point(751, 195);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(55, 55);
			this->button38->TabIndex = 13;
			this->button38->Text = L" ";
			this->button38->UseVisualStyleBackColor = true;
			this->button38->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button37
			// 
			this->button37->Cursor = System::Windows::Forms::Cursors::Default;
			this->button37->FlatAppearance->BorderSize = 0;
			this->button37->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button37->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button37->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button37->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button37->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button37->ForeColor = System::Drawing::Color::Black;
			this->button37->Location = System::Drawing::Point(690, 195);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(55, 55);
			this->button37->TabIndex = 14;
			this->button37->Text = L" ";
			this->button37->UseVisualStyleBackColor = true;
			this->button37->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button47
			// 
			this->button47->Cursor = System::Windows::Forms::Cursors::Default;
			this->button47->FlatAppearance->BorderSize = 0;
			this->button47->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button47->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button47->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button47->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button47->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button47->ForeColor = System::Drawing::Color::Black;
			this->button47->Location = System::Drawing::Point(690, 256);
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(55, 55);
			this->button47->TabIndex = 15;
			this->button47->Text = L" ";
			this->button47->UseVisualStyleBackColor = true;
			this->button47->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button48
			// 
			this->button48->Cursor = System::Windows::Forms::Cursors::Default;
			this->button48->FlatAppearance->BorderSize = 0;
			this->button48->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button48->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button48->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button48->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button48->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button48->ForeColor = System::Drawing::Color::Black;
			this->button48->Location = System::Drawing::Point(751, 256);
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(55, 55);
			this->button48->TabIndex = 16;
			this->button48->Text = L" ";
			this->button48->UseVisualStyleBackColor = true;
			this->button48->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button57
			// 
			this->button57->Cursor = System::Windows::Forms::Cursors::Default;
			this->button57->FlatAppearance->BorderSize = 0;
			this->button57->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button57->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button57->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button57->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button57->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button57->ForeColor = System::Drawing::Color::Black;
			this->button57->Location = System::Drawing::Point(690, 317);
			this->button57->Name = L"button57";
			this->button57->Size = System::Drawing::Size(55, 55);
			this->button57->TabIndex = 17;
			this->button57->Text = L" ";
			this->button57->UseVisualStyleBackColor = true;
			this->button57->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button58
			// 
			this->button58->Cursor = System::Windows::Forms::Cursors::Default;
			this->button58->FlatAppearance->BorderSize = 0;
			this->button58->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button58->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button58->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button58->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button58->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button58->ForeColor = System::Drawing::Color::Black;
			this->button58->Location = System::Drawing::Point(751, 317);
			this->button58->Name = L"button58";
			this->button58->Size = System::Drawing::Size(55, 55);
			this->button58->TabIndex = 18;
			this->button58->Text = L" ";
			this->button58->UseVisualStyleBackColor = true;
			this->button58->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button67
			// 
			this->button67->Cursor = System::Windows::Forms::Cursors::Default;
			this->button67->FlatAppearance->BorderSize = 0;
			this->button67->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button67->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button67->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button67->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button67->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button67->ForeColor = System::Drawing::Color::Black;
			this->button67->Location = System::Drawing::Point(690, 378);
			this->button67->Name = L"button67";
			this->button67->Size = System::Drawing::Size(55, 55);
			this->button67->TabIndex = 19;
			this->button67->Text = L" ";
			this->button67->UseVisualStyleBackColor = true;
			this->button67->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button77
			// 
			this->button77->Cursor = System::Windows::Forms::Cursors::Default;
			this->button77->FlatAppearance->BorderSize = 0;
			this->button77->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button77->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button77->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button77->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button77->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button77->ForeColor = System::Drawing::Color::Black;
			this->button77->Location = System::Drawing::Point(690, 439);
			this->button77->Name = L"button77";
			this->button77->Size = System::Drawing::Size(55, 55);
			this->button77->TabIndex = 20;
			this->button77->Text = L" ";
			this->button77->UseVisualStyleBackColor = true;
			this->button77->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button87
			// 
			this->button87->Cursor = System::Windows::Forms::Cursors::Default;
			this->button87->FlatAppearance->BorderSize = 0;
			this->button87->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button87->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button87->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button87->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button87->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button87->ForeColor = System::Drawing::Color::Black;
			this->button87->Location = System::Drawing::Point(690, 500);
			this->button87->Name = L"button87";
			this->button87->Size = System::Drawing::Size(55, 55);
			this->button87->TabIndex = 21;
			this->button87->Text = L" ";
			this->button87->UseVisualStyleBackColor = true;
			this->button87->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button97
			// 
			this->button97->Cursor = System::Windows::Forms::Cursors::Default;
			this->button97->FlatAppearance->BorderSize = 0;
			this->button97->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button97->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button97->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button97->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button97->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button97->ForeColor = System::Drawing::Color::Black;
			this->button97->Location = System::Drawing::Point(690, 561);
			this->button97->Name = L"button97";
			this->button97->Size = System::Drawing::Size(55, 55);
			this->button97->TabIndex = 22;
			this->button97->Text = L" ";
			this->button97->UseVisualStyleBackColor = true;
			this->button97->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button68
			// 
			this->button68->Cursor = System::Windows::Forms::Cursors::Default;
			this->button68->FlatAppearance->BorderSize = 0;
			this->button68->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button68->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button68->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button68->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button68->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button68->ForeColor = System::Drawing::Color::Black;
			this->button68->Location = System::Drawing::Point(751, 378);
			this->button68->Name = L"button68";
			this->button68->Size = System::Drawing::Size(55, 55);
			this->button68->TabIndex = 23;
			this->button68->Text = L" ";
			this->button68->UseVisualStyleBackColor = true;
			this->button68->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button78
			// 
			this->button78->Cursor = System::Windows::Forms::Cursors::Default;
			this->button78->FlatAppearance->BorderSize = 0;
			this->button78->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button78->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button78->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button78->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button78->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button78->ForeColor = System::Drawing::Color::Black;
			this->button78->Location = System::Drawing::Point(751, 439);
			this->button78->Name = L"button78";
			this->button78->Size = System::Drawing::Size(55, 55);
			this->button78->TabIndex = 24;
			this->button78->Text = L" ";
			this->button78->UseVisualStyleBackColor = true;
			this->button78->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button88
			// 
			this->button88->Cursor = System::Windows::Forms::Cursors::Default;
			this->button88->FlatAppearance->BorderSize = 0;
			this->button88->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button88->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button88->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button88->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button88->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button88->ForeColor = System::Drawing::Color::Black;
			this->button88->Location = System::Drawing::Point(751, 500);
			this->button88->Name = L"button88";
			this->button88->Size = System::Drawing::Size(55, 55);
			this->button88->TabIndex = 25;
			this->button88->Text = L" ";
			this->button88->UseVisualStyleBackColor = true;
			this->button88->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button98
			// 
			this->button98->Cursor = System::Windows::Forms::Cursors::Default;
			this->button98->FlatAppearance->BorderSize = 0;
			this->button98->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button98->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button98->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button98->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button98->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button98->ForeColor = System::Drawing::Color::Black;
			this->button98->Location = System::Drawing::Point(751, 561);
			this->button98->Name = L"button98";
			this->button98->Size = System::Drawing::Size(55, 55);
			this->button98->TabIndex = 26;
			this->button98->Text = L" ";
			this->button98->UseVisualStyleBackColor = true;
			this->button98->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button16
			// 
			this->button16->Cursor = System::Windows::Forms::Cursors::Default;
			this->button16->FlatAppearance->BorderSize = 0;
			this->button16->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button16->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button16->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button16->ForeColor = System::Drawing::Color::Black;
			this->button16->Location = System::Drawing::Point(629, 73);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(55, 55);
			this->button16->TabIndex = 27;
			this->button16->Text = L" ";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button26
			// 
			this->button26->Cursor = System::Windows::Forms::Cursors::Default;
			this->button26->FlatAppearance->BorderSize = 0;
			this->button26->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button26->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button26->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button26->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button26->ForeColor = System::Drawing::Color::Black;
			this->button26->Location = System::Drawing::Point(629, 134);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(55, 55);
			this->button26->TabIndex = 28;
			this->button26->Text = L" ";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button36
			// 
			this->button36->Cursor = System::Windows::Forms::Cursors::Default;
			this->button36->FlatAppearance->BorderSize = 0;
			this->button36->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button36->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button36->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button36->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button36->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button36->ForeColor = System::Drawing::Color::Black;
			this->button36->Location = System::Drawing::Point(629, 195);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(55, 55);
			this->button36->TabIndex = 29;
			this->button36->Text = L" ";
			this->button36->UseVisualStyleBackColor = true;
			this->button36->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button46
			// 
			this->button46->Cursor = System::Windows::Forms::Cursors::Default;
			this->button46->FlatAppearance->BorderSize = 0;
			this->button46->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button46->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button46->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button46->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button46->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button46->ForeColor = System::Drawing::Color::Black;
			this->button46->Location = System::Drawing::Point(629, 256);
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(55, 55);
			this->button46->TabIndex = 30;
			this->button46->Text = L" ";
			this->button46->UseVisualStyleBackColor = true;
			this->button46->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button56
			// 
			this->button56->Cursor = System::Windows::Forms::Cursors::Default;
			this->button56->FlatAppearance->BorderSize = 0;
			this->button56->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button56->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button56->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button56->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button56->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button56->ForeColor = System::Drawing::Color::Black;
			this->button56->Location = System::Drawing::Point(629, 317);
			this->button56->Name = L"button56";
			this->button56->Size = System::Drawing::Size(55, 55);
			this->button56->TabIndex = 31;
			this->button56->Text = L" ";
			this->button56->UseVisualStyleBackColor = true;
			this->button56->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button66
			// 
			this->button66->Cursor = System::Windows::Forms::Cursors::Default;
			this->button66->FlatAppearance->BorderSize = 0;
			this->button66->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button66->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button66->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button66->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button66->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button66->ForeColor = System::Drawing::Color::Black;
			this->button66->Location = System::Drawing::Point(629, 378);
			this->button66->Name = L"button66";
			this->button66->Size = System::Drawing::Size(55, 55);
			this->button66->TabIndex = 32;
			this->button66->Text = L" ";
			this->button66->UseVisualStyleBackColor = true;
			this->button66->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button76
			// 
			this->button76->Cursor = System::Windows::Forms::Cursors::Default;
			this->button76->FlatAppearance->BorderSize = 0;
			this->button76->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button76->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button76->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button76->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button76->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button76->ForeColor = System::Drawing::Color::Black;
			this->button76->Location = System::Drawing::Point(629, 439);
			this->button76->Name = L"button76";
			this->button76->Size = System::Drawing::Size(55, 55);
			this->button76->TabIndex = 33;
			this->button76->Text = L" ";
			this->button76->UseVisualStyleBackColor = true;
			this->button76->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button86
			// 
			this->button86->Cursor = System::Windows::Forms::Cursors::Default;
			this->button86->FlatAppearance->BorderSize = 0;
			this->button86->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button86->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button86->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button86->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button86->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button86->ForeColor = System::Drawing::Color::Black;
			this->button86->Location = System::Drawing::Point(629, 500);
			this->button86->Name = L"button86";
			this->button86->Size = System::Drawing::Size(55, 55);
			this->button86->TabIndex = 34;
			this->button86->Text = L" ";
			this->button86->UseVisualStyleBackColor = true;
			this->button86->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button96
			// 
			this->button96->Cursor = System::Windows::Forms::Cursors::Default;
			this->button96->FlatAppearance->BorderSize = 0;
			this->button96->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button96->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button96->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button96->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button96->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button96->ForeColor = System::Drawing::Color::Black;
			this->button96->Location = System::Drawing::Point(629, 561);
			this->button96->Name = L"button96";
			this->button96->Size = System::Drawing::Size(55, 55);
			this->button96->TabIndex = 35;
			this->button96->Text = L" ";
			this->button96->UseVisualStyleBackColor = true;
			this->button96->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button15
			// 
			this->button15->Cursor = System::Windows::Forms::Cursors::Default;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button15->ForeColor = System::Drawing::Color::Black;
			this->button15->Location = System::Drawing::Point(568, 73);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(55, 55);
			this->button15->TabIndex = 36;
			this->button15->Text = L" ";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button14
			// 
			this->button14->Cursor = System::Windows::Forms::Cursors::Default;
			this->button14->FlatAppearance->BorderSize = 0;
			this->button14->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button14->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button14->ForeColor = System::Drawing::Color::Black;
			this->button14->Location = System::Drawing::Point(507, 73);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(55, 55);
			this->button14->TabIndex = 37;
			this->button14->Text = L" ";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button13
			// 
			this->button13->Cursor = System::Windows::Forms::Cursors::Default;
			this->button13->FlatAppearance->BorderSize = 0;
			this->button13->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button13->ForeColor = System::Drawing::Color::Black;
			this->button13->Location = System::Drawing::Point(446, 73);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(55, 55);
			this->button13->TabIndex = 38;
			this->button13->Text = L" ";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button12
			// 
			this->button12->Cursor = System::Windows::Forms::Cursors::Default;
			this->button12->FlatAppearance->BorderSize = 0;
			this->button12->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button12->ForeColor = System::Drawing::Color::Black;
			this->button12->Location = System::Drawing::Point(385, 73);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(55, 55);
			this->button12->TabIndex = 39;
			this->button12->Text = L" ";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button11
			// 
			this->button11->Cursor = System::Windows::Forms::Cursors::Default;
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button11->ForeColor = System::Drawing::Color::Black;
			this->button11->Location = System::Drawing::Point(324, 73);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(55, 55);
			this->button11->TabIndex = 40;
			this->button11->Text = L" ";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button21
			// 
			this->button21->Cursor = System::Windows::Forms::Cursors::Default;
			this->button21->FlatAppearance->BorderSize = 0;
			this->button21->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button21->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button21->ForeColor = System::Drawing::Color::Black;
			this->button21->Location = System::Drawing::Point(324, 134);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(55, 55);
			this->button21->TabIndex = 41;
			this->button21->Text = L" ";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button22
			// 
			this->button22->Cursor = System::Windows::Forms::Cursors::Default;
			this->button22->FlatAppearance->BorderSize = 0;
			this->button22->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button22->ForeColor = System::Drawing::Color::Black;
			this->button22->Location = System::Drawing::Point(385, 134);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(55, 55);
			this->button22->TabIndex = 42;
			this->button22->Text = L" ";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button23
			// 
			this->button23->Cursor = System::Windows::Forms::Cursors::Default;
			this->button23->FlatAppearance->BorderSize = 0;
			this->button23->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button23->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button23->ForeColor = System::Drawing::Color::Black;
			this->button23->Location = System::Drawing::Point(446, 134);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(55, 55);
			this->button23->TabIndex = 43;
			this->button23->Text = L" ";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button24
			// 
			this->button24->Cursor = System::Windows::Forms::Cursors::Default;
			this->button24->FlatAppearance->BorderSize = 0;
			this->button24->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button24->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button24->ForeColor = System::Drawing::Color::Black;
			this->button24->Location = System::Drawing::Point(507, 134);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(55, 55);
			this->button24->TabIndex = 44;
			this->button24->Text = L" ";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button25
			// 
			this->button25->Cursor = System::Windows::Forms::Cursors::Default;
			this->button25->FlatAppearance->BorderSize = 0;
			this->button25->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button25->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button25->ForeColor = System::Drawing::Color::Black;
			this->button25->Location = System::Drawing::Point(568, 134);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(55, 55);
			this->button25->TabIndex = 45;
			this->button25->Text = L" ";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button31
			// 
			this->button31->Cursor = System::Windows::Forms::Cursors::Default;
			this->button31->FlatAppearance->BorderSize = 0;
			this->button31->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button31->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button31->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button31->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button31->ForeColor = System::Drawing::Color::Black;
			this->button31->Location = System::Drawing::Point(324, 195);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(55, 55);
			this->button31->TabIndex = 46;
			this->button31->Text = L" ";
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button32
			// 
			this->button32->Cursor = System::Windows::Forms::Cursors::Default;
			this->button32->FlatAppearance->BorderSize = 0;
			this->button32->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button32->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button32->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button32->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button32->ForeColor = System::Drawing::Color::Black;
			this->button32->Location = System::Drawing::Point(385, 195);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(55, 55);
			this->button32->TabIndex = 47;
			this->button32->Text = L" ";
			this->button32->UseVisualStyleBackColor = true;
			this->button32->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button33
			// 
			this->button33->Cursor = System::Windows::Forms::Cursors::Default;
			this->button33->FlatAppearance->BorderSize = 0;
			this->button33->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button33->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button33->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button33->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button33->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button33->ForeColor = System::Drawing::Color::Black;
			this->button33->Location = System::Drawing::Point(446, 195);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(55, 55);
			this->button33->TabIndex = 48;
			this->button33->Text = L" ";
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button34
			// 
			this->button34->Cursor = System::Windows::Forms::Cursors::Default;
			this->button34->FlatAppearance->BorderSize = 0;
			this->button34->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button34->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button34->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button34->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button34->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button34->ForeColor = System::Drawing::Color::Black;
			this->button34->Location = System::Drawing::Point(507, 195);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(55, 55);
			this->button34->TabIndex = 49;
			this->button34->Text = L" ";
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button35
			// 
			this->button35->Cursor = System::Windows::Forms::Cursors::Default;
			this->button35->FlatAppearance->BorderSize = 0;
			this->button35->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button35->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button35->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button35->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button35->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button35->ForeColor = System::Drawing::Color::Black;
			this->button35->Location = System::Drawing::Point(568, 195);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(55, 55);
			this->button35->TabIndex = 50;
			this->button35->Text = L" ";
			this->button35->UseVisualStyleBackColor = true;
			this->button35->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button41
			// 
			this->button41->Cursor = System::Windows::Forms::Cursors::Default;
			this->button41->FlatAppearance->BorderSize = 0;
			this->button41->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button41->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button41->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button41->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button41->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button41->ForeColor = System::Drawing::Color::Black;
			this->button41->Location = System::Drawing::Point(324, 256);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(55, 55);
			this->button41->TabIndex = 51;
			this->button41->Text = L" ";
			this->button41->UseVisualStyleBackColor = true;
			this->button41->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button42
			// 
			this->button42->Cursor = System::Windows::Forms::Cursors::Default;
			this->button42->FlatAppearance->BorderSize = 0;
			this->button42->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button42->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button42->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button42->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button42->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button42->ForeColor = System::Drawing::Color::Black;
			this->button42->Location = System::Drawing::Point(385, 256);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(55, 55);
			this->button42->TabIndex = 52;
			this->button42->Text = L" ";
			this->button42->UseVisualStyleBackColor = true;
			this->button42->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button43
			// 
			this->button43->Cursor = System::Windows::Forms::Cursors::Default;
			this->button43->FlatAppearance->BorderSize = 0;
			this->button43->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button43->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button43->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button43->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button43->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button43->ForeColor = System::Drawing::Color::Black;
			this->button43->Location = System::Drawing::Point(446, 256);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(55, 55);
			this->button43->TabIndex = 53;
			this->button43->Text = L" ";
			this->button43->UseVisualStyleBackColor = true;
			this->button43->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button44
			// 
			this->button44->Cursor = System::Windows::Forms::Cursors::Default;
			this->button44->FlatAppearance->BorderSize = 0;
			this->button44->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button44->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button44->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button44->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button44->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button44->ForeColor = System::Drawing::Color::Black;
			this->button44->Location = System::Drawing::Point(507, 256);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(55, 55);
			this->button44->TabIndex = 54;
			this->button44->Text = L" ";
			this->button44->UseVisualStyleBackColor = true;
			this->button44->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button45
			// 
			this->button45->Cursor = System::Windows::Forms::Cursors::Default;
			this->button45->FlatAppearance->BorderSize = 0;
			this->button45->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button45->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button45->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button45->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button45->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button45->ForeColor = System::Drawing::Color::Black;
			this->button45->Location = System::Drawing::Point(568, 256);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(55, 55);
			this->button45->TabIndex = 55;
			this->button45->Text = L" ";
			this->button45->UseVisualStyleBackColor = true;
			this->button45->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button51
			// 
			this->button51->Cursor = System::Windows::Forms::Cursors::Default;
			this->button51->FlatAppearance->BorderSize = 0;
			this->button51->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button51->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button51->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button51->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button51->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button51->ForeColor = System::Drawing::Color::Black;
			this->button51->Location = System::Drawing::Point(324, 317);
			this->button51->Name = L"button51";
			this->button51->Size = System::Drawing::Size(55, 55);
			this->button51->TabIndex = 56;
			this->button51->Text = L" ";
			this->button51->UseVisualStyleBackColor = true;
			this->button51->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button52
			// 
			this->button52->Cursor = System::Windows::Forms::Cursors::Default;
			this->button52->FlatAppearance->BorderSize = 0;
			this->button52->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button52->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button52->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button52->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button52->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button52->ForeColor = System::Drawing::Color::Black;
			this->button52->Location = System::Drawing::Point(385, 317);
			this->button52->Name = L"button52";
			this->button52->Size = System::Drawing::Size(55, 55);
			this->button52->TabIndex = 57;
			this->button52->Text = L" ";
			this->button52->UseVisualStyleBackColor = true;
			this->button52->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button53
			// 
			this->button53->Cursor = System::Windows::Forms::Cursors::Default;
			this->button53->FlatAppearance->BorderSize = 0;
			this->button53->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button53->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button53->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button53->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button53->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button53->ForeColor = System::Drawing::Color::Black;
			this->button53->Location = System::Drawing::Point(446, 317);
			this->button53->Name = L"button53";
			this->button53->Size = System::Drawing::Size(55, 55);
			this->button53->TabIndex = 58;
			this->button53->Text = L" ";
			this->button53->UseVisualStyleBackColor = true;
			this->button53->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button54
			// 
			this->button54->Cursor = System::Windows::Forms::Cursors::Default;
			this->button54->FlatAppearance->BorderSize = 0;
			this->button54->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button54->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button54->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button54->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button54->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button54->ForeColor = System::Drawing::Color::Black;
			this->button54->Location = System::Drawing::Point(507, 317);
			this->button54->Name = L"button54";
			this->button54->Size = System::Drawing::Size(55, 55);
			this->button54->TabIndex = 59;
			this->button54->Text = L" ";
			this->button54->UseVisualStyleBackColor = true;
			this->button54->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button55
			// 
			this->button55->Cursor = System::Windows::Forms::Cursors::Default;
			this->button55->FlatAppearance->BorderSize = 0;
			this->button55->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button55->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button55->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button55->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button55->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button55->ForeColor = System::Drawing::Color::Black;
			this->button55->Location = System::Drawing::Point(568, 317);
			this->button55->Name = L"button55";
			this->button55->Size = System::Drawing::Size(55, 55);
			this->button55->TabIndex = 60;
			this->button55->Text = L" ";
			this->button55->UseVisualStyleBackColor = true;
			this->button55->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button61
			// 
			this->button61->Cursor = System::Windows::Forms::Cursors::Default;
			this->button61->FlatAppearance->BorderSize = 0;
			this->button61->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button61->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button61->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button61->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button61->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button61->ForeColor = System::Drawing::Color::Black;
			this->button61->Location = System::Drawing::Point(324, 378);
			this->button61->Name = L"button61";
			this->button61->Size = System::Drawing::Size(55, 55);
			this->button61->TabIndex = 61;
			this->button61->Text = L" ";
			this->button61->UseVisualStyleBackColor = true;
			this->button61->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button62
			// 
			this->button62->Cursor = System::Windows::Forms::Cursors::Default;
			this->button62->FlatAppearance->BorderSize = 0;
			this->button62->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button62->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button62->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button62->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button62->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button62->ForeColor = System::Drawing::Color::Black;
			this->button62->Location = System::Drawing::Point(385, 378);
			this->button62->Name = L"button62";
			this->button62->Size = System::Drawing::Size(55, 55);
			this->button62->TabIndex = 62;
			this->button62->Text = L" ";
			this->button62->UseVisualStyleBackColor = true;
			this->button62->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button63
			// 
			this->button63->Cursor = System::Windows::Forms::Cursors::Default;
			this->button63->FlatAppearance->BorderSize = 0;
			this->button63->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button63->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button63->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button63->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button63->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button63->ForeColor = System::Drawing::Color::Black;
			this->button63->Location = System::Drawing::Point(446, 378);
			this->button63->Name = L"button63";
			this->button63->Size = System::Drawing::Size(55, 55);
			this->button63->TabIndex = 63;
			this->button63->Text = L" ";
			this->button63->UseVisualStyleBackColor = true;
			this->button63->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button64
			// 
			this->button64->Cursor = System::Windows::Forms::Cursors::Default;
			this->button64->FlatAppearance->BorderSize = 0;
			this->button64->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button64->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button64->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button64->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button64->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button64->ForeColor = System::Drawing::Color::Black;
			this->button64->Location = System::Drawing::Point(507, 378);
			this->button64->Name = L"button64";
			this->button64->Size = System::Drawing::Size(55, 55);
			this->button64->TabIndex = 64;
			this->button64->Text = L" ";
			this->button64->UseVisualStyleBackColor = true;
			this->button64->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button65
			// 
			this->button65->Cursor = System::Windows::Forms::Cursors::Default;
			this->button65->FlatAppearance->BorderSize = 0;
			this->button65->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button65->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button65->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button65->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button65->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button65->ForeColor = System::Drawing::Color::Black;
			this->button65->Location = System::Drawing::Point(568, 378);
			this->button65->Name = L"button65";
			this->button65->Size = System::Drawing::Size(55, 55);
			this->button65->TabIndex = 65;
			this->button65->Text = L" ";
			this->button65->UseVisualStyleBackColor = true;
			this->button65->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button71
			// 
			this->button71->Cursor = System::Windows::Forms::Cursors::Default;
			this->button71->FlatAppearance->BorderSize = 0;
			this->button71->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button71->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button71->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button71->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button71->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button71->ForeColor = System::Drawing::Color::Black;
			this->button71->Location = System::Drawing::Point(324, 439);
			this->button71->Name = L"button71";
			this->button71->Size = System::Drawing::Size(55, 55);
			this->button71->TabIndex = 66;
			this->button71->Text = L" ";
			this->button71->UseVisualStyleBackColor = true;
			this->button71->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button72
			// 
			this->button72->Cursor = System::Windows::Forms::Cursors::Default;
			this->button72->FlatAppearance->BorderSize = 0;
			this->button72->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button72->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button72->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button72->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button72->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button72->ForeColor = System::Drawing::Color::Black;
			this->button72->Location = System::Drawing::Point(385, 439);
			this->button72->Name = L"button72";
			this->button72->Size = System::Drawing::Size(55, 55);
			this->button72->TabIndex = 67;
			this->button72->Text = L" ";
			this->button72->UseVisualStyleBackColor = true;
			this->button72->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button73
			// 
			this->button73->Cursor = System::Windows::Forms::Cursors::Default;
			this->button73->FlatAppearance->BorderSize = 0;
			this->button73->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button73->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button73->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button73->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button73->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button73->ForeColor = System::Drawing::Color::Black;
			this->button73->Location = System::Drawing::Point(446, 439);
			this->button73->Name = L"button73";
			this->button73->Size = System::Drawing::Size(55, 55);
			this->button73->TabIndex = 68;
			this->button73->Text = L" ";
			this->button73->UseVisualStyleBackColor = true;
			this->button73->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button74
			// 
			this->button74->Cursor = System::Windows::Forms::Cursors::Default;
			this->button74->FlatAppearance->BorderSize = 0;
			this->button74->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button74->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button74->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button74->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button74->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button74->ForeColor = System::Drawing::Color::Black;
			this->button74->Location = System::Drawing::Point(507, 439);
			this->button74->Name = L"button74";
			this->button74->Size = System::Drawing::Size(55, 55);
			this->button74->TabIndex = 69;
			this->button74->Text = L" ";
			this->button74->UseVisualStyleBackColor = true;
			this->button74->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button75
			// 
			this->button75->Cursor = System::Windows::Forms::Cursors::Default;
			this->button75->FlatAppearance->BorderSize = 0;
			this->button75->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button75->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button75->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button75->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button75->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button75->ForeColor = System::Drawing::Color::Black;
			this->button75->Location = System::Drawing::Point(568, 439);
			this->button75->Name = L"button75";
			this->button75->Size = System::Drawing::Size(55, 55);
			this->button75->TabIndex = 70;
			this->button75->Text = L" ";
			this->button75->UseVisualStyleBackColor = true;
			this->button75->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button81
			// 
			this->button81->Cursor = System::Windows::Forms::Cursors::Default;
			this->button81->FlatAppearance->BorderSize = 0;
			this->button81->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button81->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button81->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button81->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button81->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button81->ForeColor = System::Drawing::Color::Black;
			this->button81->Location = System::Drawing::Point(324, 500);
			this->button81->Name = L"button81";
			this->button81->Size = System::Drawing::Size(55, 55);
			this->button81->TabIndex = 71;
			this->button81->Text = L" ";
			this->button81->UseVisualStyleBackColor = true;
			this->button81->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button82
			// 
			this->button82->Cursor = System::Windows::Forms::Cursors::Default;
			this->button82->FlatAppearance->BorderSize = 0;
			this->button82->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button82->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button82->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button82->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button82->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button82->ForeColor = System::Drawing::Color::Black;
			this->button82->Location = System::Drawing::Point(385, 500);
			this->button82->Name = L"button82";
			this->button82->Size = System::Drawing::Size(55, 55);
			this->button82->TabIndex = 72;
			this->button82->Text = L" ";
			this->button82->UseVisualStyleBackColor = true;
			this->button82->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button83
			// 
			this->button83->Cursor = System::Windows::Forms::Cursors::Default;
			this->button83->FlatAppearance->BorderSize = 0;
			this->button83->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button83->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button83->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button83->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button83->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button83->ForeColor = System::Drawing::Color::Black;
			this->button83->Location = System::Drawing::Point(446, 500);
			this->button83->Name = L"button83";
			this->button83->Size = System::Drawing::Size(55, 55);
			this->button83->TabIndex = 73;
			this->button83->Text = L" ";
			this->button83->UseVisualStyleBackColor = true;
			this->button83->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button84
			// 
			this->button84->Cursor = System::Windows::Forms::Cursors::Default;
			this->button84->FlatAppearance->BorderSize = 0;
			this->button84->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button84->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button84->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button84->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button84->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button84->ForeColor = System::Drawing::Color::Black;
			this->button84->Location = System::Drawing::Point(507, 500);
			this->button84->Name = L"button84";
			this->button84->Size = System::Drawing::Size(55, 55);
			this->button84->TabIndex = 74;
			this->button84->Text = L" ";
			this->button84->UseVisualStyleBackColor = true;
			this->button84->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button85
			// 
			this->button85->Cursor = System::Windows::Forms::Cursors::Default;
			this->button85->FlatAppearance->BorderSize = 0;
			this->button85->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button85->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button85->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button85->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button85->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button85->ForeColor = System::Drawing::Color::Black;
			this->button85->Location = System::Drawing::Point(568, 500);
			this->button85->Name = L"button85";
			this->button85->Size = System::Drawing::Size(55, 55);
			this->button85->TabIndex = 75;
			this->button85->Text = L" ";
			this->button85->UseVisualStyleBackColor = true;
			this->button85->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button91
			// 
			this->button91->Cursor = System::Windows::Forms::Cursors::Default;
			this->button91->FlatAppearance->BorderSize = 0;
			this->button91->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button91->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button91->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button91->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button91->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button91->ForeColor = System::Drawing::Color::Black;
			this->button91->Location = System::Drawing::Point(324, 561);
			this->button91->Name = L"button91";
			this->button91->Size = System::Drawing::Size(55, 55);
			this->button91->TabIndex = 76;
			this->button91->Text = L" ";
			this->button91->UseVisualStyleBackColor = true;
			this->button91->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button92
			// 
			this->button92->Cursor = System::Windows::Forms::Cursors::Default;
			this->button92->FlatAppearance->BorderSize = 0;
			this->button92->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button92->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button92->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button92->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button92->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button92->ForeColor = System::Drawing::Color::Black;
			this->button92->Location = System::Drawing::Point(385, 561);
			this->button92->Name = L"button92";
			this->button92->Size = System::Drawing::Size(55, 55);
			this->button92->TabIndex = 77;
			this->button92->Text = L" ";
			this->button92->UseVisualStyleBackColor = true;
			this->button92->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button93
			// 
			this->button93->Cursor = System::Windows::Forms::Cursors::Default;
			this->button93->FlatAppearance->BorderSize = 0;
			this->button93->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button93->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button93->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button93->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button93->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button93->ForeColor = System::Drawing::Color::Black;
			this->button93->Location = System::Drawing::Point(446, 561);
			this->button93->Name = L"button93";
			this->button93->Size = System::Drawing::Size(55, 55);
			this->button93->TabIndex = 78;
			this->button93->Text = L" ";
			this->button93->UseVisualStyleBackColor = true;
			this->button93->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button94
			// 
			this->button94->Cursor = System::Windows::Forms::Cursors::Default;
			this->button94->FlatAppearance->BorderSize = 0;
			this->button94->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button94->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button94->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button94->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button94->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button94->ForeColor = System::Drawing::Color::Black;
			this->button94->Location = System::Drawing::Point(507, 561);
			this->button94->Name = L"button94";
			this->button94->Size = System::Drawing::Size(55, 55);
			this->button94->TabIndex = 79;
			this->button94->Text = L" ";
			this->button94->UseVisualStyleBackColor = true;
			this->button94->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// button95
			// 
			this->button95->Cursor = System::Windows::Forms::Cursors::Default;
			this->button95->FlatAppearance->BorderSize = 0;
			this->button95->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button95->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button95->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button95->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button95->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button95->ForeColor = System::Drawing::Color::Black;
			this->button95->Location = System::Drawing::Point(568, 561);
			this->button95->Name = L"button95";
			this->button95->Size = System::Drawing::Size(55, 55);
			this->button95->TabIndex = 80;
			this->button95->Text = L" ";
			this->button95->UseVisualStyleBackColor = true;
			this->button95->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(300, 49);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(591, 591);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 81;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(34, 310);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(284, 367);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 82;
			this->pictureBox2->TabStop = false;
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::White;
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->ForeColor = System::Drawing::Color::Black;
			this->button9->Location = System::Drawing::Point(212, 510);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(51, 53);
			this->button9->TabIndex = 91;
			this->button9->Text = L"9";
			this->button9->UseMnemonic = false;
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Судоку::ButtonChange_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::White;
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->ForeColor = System::Drawing::Color::Black;
			this->button8->Location = System::Drawing::Point(152, 510);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(51, 53);
			this->button8->TabIndex = 90;
			this->button8->Text = L"8";
			this->button8->UseMnemonic = false;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Судоку::ButtonChange_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::White;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::Color::Black;
			this->button7->Location = System::Drawing::Point(90, 510);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(51, 53);
			this->button7->TabIndex = 89;
			this->button7->Text = L"7";
			this->button7->UseMnemonic = false;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Судоку::ButtonChange_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::White;
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->Location = System::Drawing::Point(212, 449);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(51, 53);
			this->button6->TabIndex = 88;
			this->button6->Text = L"6";
			this->button6->UseMnemonic = false;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Судоку::ButtonChange_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::White;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::Color::Black;
			this->button5->Location = System::Drawing::Point(152, 449);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(51, 53);
			this->button5->TabIndex = 87;
			this->button5->Text = L"5";
			this->button5->UseMnemonic = false;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Судоку::ButtonChange_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::White;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Location = System::Drawing::Point(90, 449);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(51, 53);
			this->button4->TabIndex = 86;
			this->button4->Text = L"4";
			this->button4->UseMnemonic = false;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Судоку::ButtonChange_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(212, 388);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(51, 53);
			this->button3->TabIndex = 85;
			this->button3->Text = L"3";
			this->button3->UseMnemonic = false;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Судоку::ButtonChange_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(152, 388);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(51, 53);
			this->button2->TabIndex = 84;
			this->button2->Text = L"2";
			this->button2->UseMnemonic = false;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Судоку::ButtonChange_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(90, 388);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(51, 53);
			this->button1->TabIndex = 83;
			this->button1->Text = L"1";
			this->button1->UseMnemonic = false;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Судоку::ButtonChange_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::White;
			this->button10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button10->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button10->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MistyRose;
			this->button10->FlatAppearance->MouseOverBackColor = System::Drawing::Color::MistyRose;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"DejaVu Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->ForeColor = System::Drawing::Color::Black;
			this->button10->Location = System::Drawing::Point(152, 571);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(111, 32);
			this->button10->TabIndex = 93;
			this->button10->Text = L"Очистить";
			this->button10->UseMnemonic = false;
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &Судоку::ButtonDelete_Click);
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::Color::White;
			this->button20->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button20.BackgroundImage")));
			this->button20->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button20->Cursor = System::Windows::Forms::Cursors::Default;
			this->button20->FlatAppearance->BorderSize = 0;
			this->button20->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button20->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button20->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Font = (gcnew System::Drawing::Font(L"Onyx", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button20->ForeColor = System::Drawing::Color::Black;
			this->button20->Location = System::Drawing::Point(90, 571);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(51, 32);
			this->button20->TabIndex = 94;
			this->button20->UseMnemonic = false;
			this->button20->UseVisualStyleBackColor = false;
			// 
			// button30
			// 
			this->button30->BackColor = System::Drawing::Color::White;
			this->button30->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button30->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button30->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->button30->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button30->Font = (gcnew System::Drawing::Font(L"DejaVu Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button30->ForeColor = System::Drawing::Color::Black;
			this->button30->Location = System::Drawing::Point(90, 273);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(173, 55);
			this->button30->TabIndex = 95;
			this->button30->Text = L"Проверить\r\nрешение";
			this->button30->UseMnemonic = false;
			this->button30->UseVisualStyleBackColor = false;
			this->button30->Click += gcnew System::EventHandler(this, &Судоку::Check_the_solution);
			// 
			// button40
			// 
			this->button40->BackColor = System::Drawing::Color::White;
			this->button40->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button40->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button40->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(154)));
			this->button40->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(154)));
			this->button40->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button40->Font = (gcnew System::Drawing::Font(L"DejaVu Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button40->ForeColor = System::Drawing::Color::Black;
			this->button40->Location = System::Drawing::Point(90, 203);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(173, 55);
			this->button40->TabIndex = 96;
			this->button40->Text = L"Сгенерировать\r\nСудоку";
			this->button40->UseMnemonic = false;
			this->button40->UseVisualStyleBackColor = false;
			this->button40->Click += gcnew System::EventHandler(this, &Судоку::Logic_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(0, 0);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(956, 728);
			this->pictureBox4->TabIndex = 98;
			this->pictureBox4->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"DejaVu Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(74, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(205, 21);
			this->label1->TabIndex = 100;
			this->label1->Text = L"Уровень сложности:";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::Window;
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"DejaVu Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Лёгкий", L"Средний", L"Сложный" });
			this->comboBox1->Location = System::Drawing::Point(116, 95);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 28);
			this->comboBox1->TabIndex = 101;
			this->comboBox1->DropDownClosed += gcnew System::EventHandler(this, &Судоку::comboBox1_DropDownClosed);
			// 
			// button50
			// 
			this->button50->Cursor = System::Windows::Forms::Cursors::Default;
			this->button50->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button50->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightGray;
			this->button50->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightGray;
			this->button50->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button50->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button50->ForeColor = System::Drawing::Color::Black;
			this->button50->Location = System::Drawing::Point(115, 94);
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(123, 30);
			this->button50->TabIndex = 102;
			this->button50->Text = L" ";
			// 
			// comboBox2
			// 
			this->comboBox2->BackColor = System::Drawing::SystemColors::Window;
			this->comboBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"DejaVu Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Russian", L"English" });
			this->comboBox2->Location = System::Drawing::Point(771, 22);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(99, 28);
			this->comboBox2->TabIndex = 103;
			this->comboBox2->DropDownClosed += gcnew System::EventHandler(this, &Судоку::comboBox2_DropDownClosed);
			// 
			// button60
			// 
			this->button60->Cursor = System::Windows::Forms::Cursors::Default;
			this->button60->FlatAppearance->CheckedBackColor = System::Drawing::SystemColors::ButtonFace;
			this->button60->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightGray;
			this->button60->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightGray;
			this->button60->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button60->Font = (gcnew System::Drawing::Font(L"NSimSun", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button60->ForeColor = System::Drawing::Color::Black;
			this->button60->Location = System::Drawing::Point(770, 21);
			this->button60->Name = L"button60";
			this->button60->Size = System::Drawing::Size(101, 30);
			this->button60->TabIndex = 104;
			this->button60->Text = L" ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"DejaVu Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(656, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 21);
			this->label2->TabIndex = 105;
			this->label2->Text = L"Language:";
			// 
			// Судоку
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(940, 689);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->button60);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button40);
			this->Controls->Add(this->button30);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button95);
			this->Controls->Add(this->button94);
			this->Controls->Add(this->button93);
			this->Controls->Add(this->button92);
			this->Controls->Add(this->button91);
			this->Controls->Add(this->button85);
			this->Controls->Add(this->button84);
			this->Controls->Add(this->button83);
			this->Controls->Add(this->button82);
			this->Controls->Add(this->button81);
			this->Controls->Add(this->button75);
			this->Controls->Add(this->button74);
			this->Controls->Add(this->button73);
			this->Controls->Add(this->button72);
			this->Controls->Add(this->button71);
			this->Controls->Add(this->button65);
			this->Controls->Add(this->button64);
			this->Controls->Add(this->button63);
			this->Controls->Add(this->button62);
			this->Controls->Add(this->button61);
			this->Controls->Add(this->button55);
			this->Controls->Add(this->button54);
			this->Controls->Add(this->button53);
			this->Controls->Add(this->button52);
			this->Controls->Add(this->button51);
			this->Controls->Add(this->button45);
			this->Controls->Add(this->button44);
			this->Controls->Add(this->button43);
			this->Controls->Add(this->button42);
			this->Controls->Add(this->button41);
			this->Controls->Add(this->button35);
			this->Controls->Add(this->button34);
			this->Controls->Add(this->button33);
			this->Controls->Add(this->button32);
			this->Controls->Add(this->button31);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button96);
			this->Controls->Add(this->button86);
			this->Controls->Add(this->button76);
			this->Controls->Add(this->button66);
			this->Controls->Add(this->button56);
			this->Controls->Add(this->button46);
			this->Controls->Add(this->button36);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button98);
			this->Controls->Add(this->button88);
			this->Controls->Add(this->button78);
			this->Controls->Add(this->button68);
			this->Controls->Add(this->button97);
			this->Controls->Add(this->button87);
			this->Controls->Add(this->button77);
			this->Controls->Add(this->button67);
			this->Controls->Add(this->button58);
			this->Controls->Add(this->button57);
			this->Controls->Add(this->button48);
			this->Controls->Add(this->button47);
			this->Controls->Add(this->button37);
			this->Controls->Add(this->button38);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button99);
			this->Controls->Add(this->button89);
			this->Controls->Add(this->button79);
			this->Controls->Add(this->button69);
			this->Controls->Add(this->button59);
			this->Controls->Add(this->button49);
			this->Controls->Add(this->button39);
			this->Controls->Add(this->button29);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button50);
			this->Controls->Add(this->pictureBox4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Судоку";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Судоку";
			this->Click += gcnew System::EventHandler(this, &Судоку::ButtonNum_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
			this->comboBox1->Text = L"Средний";
			this->comboBox2->Text = L"Russian";
			this->button20->Focus();
		}
#pragma endregion

	private: System::Void Clear() {
		this->button1->BackColor = System::Drawing::Color::White;
		this->button2->BackColor = System::Drawing::Color::White;
		this->button3->BackColor = System::Drawing::Color::White;
		this->button4->BackColor = System::Drawing::Color::White;
		this->button5->BackColor = System::Drawing::Color::White;
		this->button6->BackColor = System::Drawing::Color::White;
		this->button7->BackColor = System::Drawing::Color::White;
		this->button8->BackColor = System::Drawing::Color::White;
		this->button9->BackColor = System::Drawing::Color::White;
		this->button10->BackColor = System::Drawing::Color::White;

		this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button16->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button18->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button26->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button27->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button31->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button32->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button33->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button34->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button35->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button36->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button37->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button38->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button39->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button41->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button42->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button43->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button44->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button45->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button46->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button47->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button48->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button49->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button51->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button52->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button53->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button54->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button55->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button56->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button57->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button58->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button59->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button61->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button62->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button63->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button64->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button65->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button66->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button67->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button68->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button69->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button71->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button72->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button73->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button74->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button75->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button76->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button77->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button78->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button79->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button81->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button82->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button83->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button84->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button85->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button86->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button87->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button88->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button89->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button91->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button92->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button93->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button94->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button95->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button96->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button97->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button98->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button99->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::ButtonFace;

		this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button14->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button16->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button17->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button18->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button26->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button27->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button31->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button32->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button33->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button34->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button35->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button36->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button37->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button38->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button39->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button41->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button42->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button43->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button44->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button45->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button46->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button47->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button48->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button49->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button51->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button52->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button53->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button54->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button55->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button56->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button57->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button58->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button59->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button61->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button62->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button63->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button64->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button65->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button66->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button67->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button68->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button69->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button71->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button72->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button73->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button74->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button75->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button76->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button77->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button78->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button79->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button81->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button82->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button83->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button84->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button85->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button86->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button87->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button88->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button89->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button91->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button92->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button93->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button94->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button95->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button96->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button97->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button98->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;
		this->button99->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::ButtonFace;

		this->button11->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button12->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button13->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button14->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button15->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button16->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button17->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button18->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button19->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button21->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button22->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button23->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button24->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button25->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button26->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button27->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button28->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button29->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button31->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button32->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button33->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button34->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button35->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button36->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button37->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button38->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button39->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button41->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button42->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button43->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button44->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button45->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button46->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button47->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button48->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button49->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button51->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button52->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button53->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button54->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button55->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button56->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button57->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button58->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button59->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button61->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button62->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button63->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button64->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button65->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button66->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button67->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button68->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button69->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button71->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button72->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button73->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button74->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button75->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button76->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button77->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button78->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button79->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button81->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button82->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button83->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button84->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button85->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button86->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button87->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button88->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button89->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button91->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button92->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button93->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button94->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button95->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button96->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button97->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button98->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->button99->BackColor = System::Drawing::SystemColors::ButtonFace;

		this->button11->Cursor = System::Windows::Forms::Cursors::Default;
		this->button12->Cursor = System::Windows::Forms::Cursors::Default;
		this->button13->Cursor = System::Windows::Forms::Cursors::Default;
		this->button14->Cursor = System::Windows::Forms::Cursors::Default;
		this->button15->Cursor = System::Windows::Forms::Cursors::Default;
		this->button16->Cursor = System::Windows::Forms::Cursors::Default;
		this->button17->Cursor = System::Windows::Forms::Cursors::Default;
		this->button18->Cursor = System::Windows::Forms::Cursors::Default;
		this->button19->Cursor = System::Windows::Forms::Cursors::Default;
		this->button21->Cursor = System::Windows::Forms::Cursors::Default;
		this->button22->Cursor = System::Windows::Forms::Cursors::Default;
		this->button23->Cursor = System::Windows::Forms::Cursors::Default;
		this->button24->Cursor = System::Windows::Forms::Cursors::Default;
		this->button25->Cursor = System::Windows::Forms::Cursors::Default;
		this->button26->Cursor = System::Windows::Forms::Cursors::Default;
		this->button27->Cursor = System::Windows::Forms::Cursors::Default;
		this->button28->Cursor = System::Windows::Forms::Cursors::Default;
		this->button29->Cursor = System::Windows::Forms::Cursors::Default;
		this->button31->Cursor = System::Windows::Forms::Cursors::Default;
		this->button32->Cursor = System::Windows::Forms::Cursors::Default;
		this->button33->Cursor = System::Windows::Forms::Cursors::Default;
		this->button34->Cursor = System::Windows::Forms::Cursors::Default;
		this->button35->Cursor = System::Windows::Forms::Cursors::Default;
		this->button36->Cursor = System::Windows::Forms::Cursors::Default;
		this->button37->Cursor = System::Windows::Forms::Cursors::Default;
		this->button38->Cursor = System::Windows::Forms::Cursors::Default;
		this->button39->Cursor = System::Windows::Forms::Cursors::Default;
		this->button41->Cursor = System::Windows::Forms::Cursors::Default;
		this->button42->Cursor = System::Windows::Forms::Cursors::Default;
		this->button43->Cursor = System::Windows::Forms::Cursors::Default;
		this->button44->Cursor = System::Windows::Forms::Cursors::Default;
		this->button45->Cursor = System::Windows::Forms::Cursors::Default;
		this->button46->Cursor = System::Windows::Forms::Cursors::Default;
		this->button47->Cursor = System::Windows::Forms::Cursors::Default;
		this->button48->Cursor = System::Windows::Forms::Cursors::Default;
		this->button49->Cursor = System::Windows::Forms::Cursors::Default;
		this->button51->Cursor = System::Windows::Forms::Cursors::Default;
		this->button52->Cursor = System::Windows::Forms::Cursors::Default;
		this->button53->Cursor = System::Windows::Forms::Cursors::Default;
		this->button54->Cursor = System::Windows::Forms::Cursors::Default;
		this->button55->Cursor = System::Windows::Forms::Cursors::Default;
		this->button56->Cursor = System::Windows::Forms::Cursors::Default;
		this->button57->Cursor = System::Windows::Forms::Cursors::Default;
		this->button58->Cursor = System::Windows::Forms::Cursors::Default;
		this->button59->Cursor = System::Windows::Forms::Cursors::Default;
		this->button61->Cursor = System::Windows::Forms::Cursors::Default;
		this->button62->Cursor = System::Windows::Forms::Cursors::Default;
		this->button63->Cursor = System::Windows::Forms::Cursors::Default;
		this->button64->Cursor = System::Windows::Forms::Cursors::Default;
		this->button65->Cursor = System::Windows::Forms::Cursors::Default;
		this->button66->Cursor = System::Windows::Forms::Cursors::Default;
		this->button67->Cursor = System::Windows::Forms::Cursors::Default;
		this->button68->Cursor = System::Windows::Forms::Cursors::Default;
		this->button69->Cursor = System::Windows::Forms::Cursors::Default;
		this->button71->Cursor = System::Windows::Forms::Cursors::Default;
		this->button72->Cursor = System::Windows::Forms::Cursors::Default;
		this->button73->Cursor = System::Windows::Forms::Cursors::Default;
		this->button74->Cursor = System::Windows::Forms::Cursors::Default;
		this->button75->Cursor = System::Windows::Forms::Cursors::Default;
		this->button76->Cursor = System::Windows::Forms::Cursors::Default;
		this->button77->Cursor = System::Windows::Forms::Cursors::Default;
		this->button78->Cursor = System::Windows::Forms::Cursors::Default;
		this->button79->Cursor = System::Windows::Forms::Cursors::Default;
		this->button81->Cursor = System::Windows::Forms::Cursors::Default;
		this->button82->Cursor = System::Windows::Forms::Cursors::Default;
		this->button83->Cursor = System::Windows::Forms::Cursors::Default;
		this->button84->Cursor = System::Windows::Forms::Cursors::Default;
		this->button85->Cursor = System::Windows::Forms::Cursors::Default;
		this->button86->Cursor = System::Windows::Forms::Cursors::Default;
		this->button87->Cursor = System::Windows::Forms::Cursors::Default;
		this->button88->Cursor = System::Windows::Forms::Cursors::Default;
		this->button89->Cursor = System::Windows::Forms::Cursors::Default;
		this->button91->Cursor = System::Windows::Forms::Cursors::Default;
		this->button92->Cursor = System::Windows::Forms::Cursors::Default;
		this->button93->Cursor = System::Windows::Forms::Cursors::Default;
		this->button94->Cursor = System::Windows::Forms::Cursors::Default;
		this->button95->Cursor = System::Windows::Forms::Cursors::Default;
		this->button96->Cursor = System::Windows::Forms::Cursors::Default;
		this->button97->Cursor = System::Windows::Forms::Cursors::Default;
		this->button98->Cursor = System::Windows::Forms::Cursors::Default;
		this->button99->Cursor = System::Windows::Forms::Cursors::Default;
	}

	private: System::Void ButtonChange_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ ButtonChange = safe_cast<Button^>(sender);
		this->Changed = ButtonChange->Text;

		this->button1->BackColor = System::Drawing::Color::White;
		this->button2->BackColor = System::Drawing::Color::White;
		this->button3->BackColor = System::Drawing::Color::White;
		this->button4->BackColor = System::Drawing::Color::White;
		this->button5->BackColor = System::Drawing::Color::White;
		this->button6->BackColor = System::Drawing::Color::White;
		this->button7->BackColor = System::Drawing::Color::White;
		this->button8->BackColor = System::Drawing::Color::White;
		this->button9->BackColor = System::Drawing::Color::White;
		this->button10->BackColor = System::Drawing::Color::White;
		ButtonChange->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
			static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(255)));

		if (this->button11->Text == L" ") {
			this->button11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button12->Text == L" ") {
			this->button12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button13->Text == L" ") {
			this->button13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button14->Text == L" ") {
			this->button14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button14->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button14->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button15->Text == L" ") {
			this->button15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button16->Text == L" ") {
			this->button16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button16->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button16->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button16->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button16->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button17->Text == L" ") {
			this->button17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button17->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button17->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button18->Text == L" ") {
			this->button18->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button18->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button18->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button18->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button18->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button19->Text == L" ") {
			this->button19->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button21->Text == L" ") {
			this->button21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button22->Text == L" ") {
			this->button22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button23->Text == L" ") {
			this->button23->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button24->Text == L" ") {
			this->button24->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button25->Text == L" ") {
			this->button25->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button26->Text == L" ") {
			this->button26->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button26->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button26->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button26->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button26->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button27->Text == L" ") {
			this->button27->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button27->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button27->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button27->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button27->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button28->Text == L" ") {
			this->button28->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button29->Text == L" ") {
			this->button29->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button31->Text == L" ") {
			this->button31->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button31->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button31->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button31->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button31->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button32->Text == L" ") {
			this->button32->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button32->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button32->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button32->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button32->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button33->Text == L" ") {
			this->button33->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button33->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button33->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button33->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button33->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button34->Text == L" ") {
			this->button34->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button34->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button34->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button34->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button34->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button35->Text == L" ") {
			this->button35->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button35->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button35->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button35->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button35->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button36->Text == L" ") {
			this->button36->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button36->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button36->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button36->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button36->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button37->Text == L" ") {
			this->button37->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button37->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button37->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button37->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button37->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button38->Text == L" ") {
			this->button38->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button38->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button38->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button38->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button38->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button39->Text == L" ") {
			this->button39->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button39->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button39->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button39->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button39->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button41->Text == L" ") {
			this->button41->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button41->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button41->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button41->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button41->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button42->Text == L" ") {
			this->button42->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button42->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button42->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button42->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button42->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button43->Text == L" ") {
			this->button43->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button43->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button43->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button43->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button43->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button44->Text == L" ") {
			this->button44->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button44->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button44->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button44->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button44->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button45->Text == L" ") {
			this->button45->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button45->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button45->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button45->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button45->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button46->Text == L" ") {
			this->button46->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button46->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button46->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button46->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button46->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button47->Text == L" ") {
			this->button47->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button47->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button47->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button47->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button47->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button48->Text == L" ") {
			this->button48->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button48->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button48->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button48->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button48->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button49->Text == L" ") {
			this->button49->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button49->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button49->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button49->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button49->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button51->Text == L" ") {
			this->button51->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button51->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button51->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button51->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button51->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button52->Text == L" ") {
			this->button52->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button52->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button52->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button52->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button52->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button53->Text == L" ") {
			this->button53->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button53->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button53->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button53->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button53->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button54->Text == L" ") {
			this->button54->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button54->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button54->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button54->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button54->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button55->Text == L" ") {
			this->button55->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button55->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button55->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button55->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button55->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button56->Text == L" ") {
			this->button56->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button56->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button56->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button56->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button56->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button57->Text == L" ") {
			this->button57->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button57->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button57->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button57->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button57->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button58->Text == L" ") {
			this->button58->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button58->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button58->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button58->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button58->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button59->Text == L" ") {
			this->button59->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button59->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button59->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button59->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button59->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button61->Text == L" ") {
			this->button61->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button61->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button61->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button61->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button61->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button62->Text == L" ") {
			this->button62->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button62->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button62->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button62->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button62->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button63->Text == L" ") {
			this->button63->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button63->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button63->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button63->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button63->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button64->Text == L" ") {
			this->button64->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button64->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button64->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button64->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button64->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button65->Text == L" ") {
			this->button65->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button65->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button65->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button65->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button65->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button66->Text == L" ") {
			this->button66->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button66->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button66->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button66->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button66->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button67->Text == L" ") {
			this->button67->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button67->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button67->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button67->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button67->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button68->Text == L" ") {
			this->button68->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button68->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button68->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button68->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button68->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button69->Text == L" ") {
			this->button69->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button69->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button69->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button69->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button69->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button71->Text == L" ") {
			this->button71->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button71->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button71->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button71->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button71->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button72->Text == L" ") {
			this->button72->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button72->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button72->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button72->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button72->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button73->Text == L" ") {
			this->button73->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button73->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button73->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button73->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button73->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button74->Text == L" ") {
			this->button74->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button74->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button74->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button74->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button74->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button75->Text == L" ") {
			this->button75->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button75->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button75->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button75->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button75->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button76->Text == L" ") {
			this->button76->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button76->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button76->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button76->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button76->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button77->Text == L" ") {
			this->button77->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button77->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button77->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button77->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button77->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button78->Text == L" ") {
			this->button78->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button78->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button78->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button78->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button78->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button79->Text == L" ") {
			this->button79->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button79->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button79->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button79->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button79->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button81->Text == L" ") {
			this->button81->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button81->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button81->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button81->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button81->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button82->Text == L" ") {
			this->button82->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button82->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button82->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button82->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button82->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button83->Text == L" ") {
			this->button83->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button83->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button83->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button83->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button83->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button84->Text == L" ") {
			this->button84->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button84->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button84->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button84->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button84->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button85->Text == L" ") {
			this->button85->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button85->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button85->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button85->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button85->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button86->Text == L" ") {
			this->button86->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button86->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button86->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button86->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button86->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button87->Text == L" ") {
			this->button87->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button87->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button87->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button87->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button87->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button88->Text == L" ") {
			this->button88->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button88->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button88->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button88->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button88->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button89->Text == L" ") {
			this->button89->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button89->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button89->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button89->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button89->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button91->Text == L" ") {
			this->button91->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button91->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button91->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button91->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button91->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button92->Text == L" ") {
			this->button92->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button92->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button92->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button92->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button92->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button93->Text == L" ") {
			this->button93->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button93->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button93->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button93->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button93->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button94->Text == L" ") {
			this->button94->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button94->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button94->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button94->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button94->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button95->Text == L" ") {
			this->button95->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button95->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button95->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button95->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button95->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button96->Text == L" ") {
			this->button96->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button96->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button96->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button96->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button96->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button97->Text == L" ") {
			this->button97->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button97->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button97->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button97->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button97->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button98->Text == L" ") {
			this->button98->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button98->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button98->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button98->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button98->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button99->Text == L" ") {
			this->button99->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button99->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightBlue;
			this->button99->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightBlue;
		}
		else {
			this->button99->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button99->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		this->button20->Focus();
	}
	private: System::Void ButtonNum_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ ButtonNum = safe_cast<Button^>(sender);
		if (ButtonNum->UseMnemonic) {
			if ((ButtonNum->Text == L" ") && (Changed != L" ") && (Changed != L"0")) {
				ButtonNum->Text = Changed;
				Changed = L" ";
				Clear();
				this->button20->Focus();
			}
			if ((ButtonNum->Text != L" ") && (Changed == L"0")) {
				ButtonNum->Text = L" ";
				Changed = L" ";
				Clear();
				this->button20->Focus();
			}
		}
	}
	private: System::Void Logic() {
		srand(time(0));
		int i, j;
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				for (;;) {
					if (!test(i, j)) move_back(i, j);
					if (i < 0) break;
					sudokulog[i, j] = rand() % 9 + 1;
					if (check_repeated(i, j)) continue;
					write(i, j);
					if (check_sqr(i, j) && check_row(i, j) && check_col(i, j)) {
						write_to_base(i, j);
						break;
					}
				}
			}
		}

		cli::array<int, 2>^ sudokuboard_zeros = gcnew cli::array<int, 2>(SIZE, SIZE);
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				sudokuboard_zeros[i, j] = sudokulog[i, j];
			}
		}

		int k1;	int k2;	int k_remove = 0; int value; int diff = 48;

		if (Difficulty == L"Лёгкий") diff = 43;
		if (Difficulty == L"Средний") diff = 48;
		if (Difficulty == L"Сложный") diff = 53;

		for (;;) {
			if (k_remove == diff) break;
			k1 = rand() % 9;
			k2 = rand() % 9;
			if (sudokuboard_zeros[k1, k2] == 0) continue;
			value = sudokuboard_zeros[k1, k2];
			sudokuboard_zeros[k1, k2] = 0;
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 9; j++) {
					sudokulog[i, j] = sudokuboard_zeros[i, j];
				}
			}
			solver_plus();
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 9; j++) {
					sudokutest_plus[i, j] = sudokulog[i, j];
				}
			}
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 9; j++) {
					sudokulog[i, j] = sudokuboard_zeros[i, j];
				}
			}
			solver_minus();
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 9; j++) {
					sudokutest_minus[i, j] = sudokulog[i, j];
				}
			}
			if (!check_the_correctness()) {
				sudokuboard_zeros[k1, k2] = value;
				continue;
			}
			k_remove++;
		}
		if (sudokuboard_zeros[0, 0] != 0) {
			this->button11->Text = System::Convert::ToString(sudokuboard_zeros[0, 0]);
			this->button11->UseMnemonic = false;
		}
		else {
			this->button11->Text = L" ";
			this->button11->UseMnemonic = true;
		}
		if (sudokuboard_zeros[0, 1] != 0) {
			this->button12->Text = System::Convert::ToString(sudokuboard_zeros[0, 1]);
			this->button12->UseMnemonic = false;
		}
		else {
			this->button12->Text = L" ";
			this->button12->UseMnemonic = true;
		}
		if (sudokuboard_zeros[0, 2] != 0) {
			this->button13->Text = System::Convert::ToString(sudokuboard_zeros[0, 2]);
			this->button13->UseMnemonic = false;
		}
		else {
			this->button13->Text = L" ";
			this->button13->UseMnemonic = true;
		}
		if (sudokuboard_zeros[0, 3] != 0) {
			this->button14->Text = System::Convert::ToString(sudokuboard_zeros[0, 3]);
			this->button14->UseMnemonic = false;
		}
		else {
			this->button14->Text = L" ";
			this->button14->UseMnemonic = true;
		}
		if (sudokuboard_zeros[0, 4] != 0) {
			this->button15->Text = System::Convert::ToString(sudokuboard_zeros[0, 4]);
			this->button15->UseMnemonic = false;
		}
		else {
			this->button15->Text = L" ";
			this->button15->UseMnemonic = true;
		}
		if (sudokuboard_zeros[0, 5] != 0) {
			this->button16->Text = System::Convert::ToString(sudokuboard_zeros[0, 5]);
			this->button16->UseMnemonic = false;
		}
		else {
			this->button16->Text = L" ";
			this->button16->UseMnemonic = true;
		}
		if (sudokuboard_zeros[0, 6] != 0) {
			this->button17->Text = System::Convert::ToString(sudokuboard_zeros[0, 6]);
			this->button17->UseMnemonic = false;
		}
		else {
			this->button17->Text = L" ";
			this->button17->UseMnemonic = true;
		}
		if (sudokuboard_zeros[0, 7] != 0) {
			this->button18->Text = System::Convert::ToString(sudokuboard_zeros[0, 7]);
			this->button18->UseMnemonic = false;
		}
		else {
			this->button18->Text = L" ";
			this->button18->UseMnemonic = true;
		}
		if (sudokuboard_zeros[0, 8] != 0) {
			this->button19->Text = System::Convert::ToString(sudokuboard_zeros[0, 8]);
			this->button19->UseMnemonic = false;
		}
		else {
			this->button19->Text = L" ";
			this->button19->UseMnemonic = true;
		}
		if (sudokuboard_zeros[1, 0] != 0) {
			this->button21->Text = System::Convert::ToString(sudokuboard_zeros[1, 0]);
			this->button21->UseMnemonic = false;
		}
		else {
			this->button21->Text = L" ";
			this->button21->UseMnemonic = true;
		}
		if (sudokuboard_zeros[1, 1] != 0) {
			this->button22->Text = System::Convert::ToString(sudokuboard_zeros[1, 1]);
			this->button22->UseMnemonic = false;
		}
		else {
			this->button22->Text = L" ";
			this->button22->UseMnemonic = true;
		}
		if (sudokuboard_zeros[1, 2] != 0) {
			this->button23->Text = System::Convert::ToString(sudokuboard_zeros[1, 2]);
			this->button23->UseMnemonic = false;
		}
		else {
			this->button23->Text = L" ";
			this->button23->UseMnemonic = true;
		}
		if (sudokuboard_zeros[1, 3] != 0) {
			this->button24->Text = System::Convert::ToString(sudokuboard_zeros[1, 3]);
			this->button24->UseMnemonic = false;
		}
		else {
			this->button24->Text = L" ";
			this->button24->UseMnemonic = true;
		}
		if (sudokuboard_zeros[1, 4] != 0) {
			this->button25->Text = System::Convert::ToString(sudokuboard_zeros[1, 4]);
			this->button25->UseMnemonic = false;
		}
		else {
			this->button25->Text = L" ";
			this->button25->UseMnemonic = true;
		}
		if (sudokuboard_zeros[1, 5] != 0) {
			this->button26->Text = System::Convert::ToString(sudokuboard_zeros[1, 5]);
			this->button26->UseMnemonic = false;
		}
		else {
			this->button26->Text = L" ";
			this->button26->UseMnemonic = true;
		}
		if (sudokuboard_zeros[1, 6] != 0) {
			this->button27->Text = System::Convert::ToString(sudokuboard_zeros[1, 6]);
			this->button27->UseMnemonic = false;
		}
		else {
			this->button27->Text = L" ";
			this->button27->UseMnemonic = true;
		}
		if (sudokuboard_zeros[1, 7] != 0) {
			this->button28->Text = System::Convert::ToString(sudokuboard_zeros[1, 7]);
			this->button28->UseMnemonic = false;
		}
		else {
			this->button28->Text = L" ";
			this->button28->UseMnemonic = true;
		}
		if (sudokuboard_zeros[1, 8] != 0) {
			this->button29->Text = System::Convert::ToString(sudokuboard_zeros[1, 8]);
			this->button29->UseMnemonic = false;
		}
		else {
			this->button29->Text = L" ";
			this->button29->UseMnemonic = true;
		}
		if (sudokuboard_zeros[2, 0] != 0) {
			this->button31->Text = System::Convert::ToString(sudokuboard_zeros[2, 0]);
			this->button31->UseMnemonic = false;
		}
		else {
			this->button31->Text = L" ";
			this->button31->UseMnemonic = true;
		}
		if (sudokuboard_zeros[2, 1] != 0) {
			this->button32->Text = System::Convert::ToString(sudokuboard_zeros[2, 1]);
			this->button32->UseMnemonic = false;
		}
		else {
			this->button32->Text = L" ";
			this->button32->UseMnemonic = true;
		}
		if (sudokuboard_zeros[2, 2] != 0) {
			this->button33->Text = System::Convert::ToString(sudokuboard_zeros[2, 2]);
			this->button33->UseMnemonic = false;
		}
		else {
			this->button33->Text = L" ";
			this->button33->UseMnemonic = true;
		}
		if (sudokuboard_zeros[2, 3] != 0) {
			this->button34->Text = System::Convert::ToString(sudokuboard_zeros[2, 3]);
			this->button34->UseMnemonic = false;
		}
		else {
			this->button34->Text = L" ";
			this->button34->UseMnemonic = true;
		}
		if (sudokuboard_zeros[2, 4] != 0) {
			this->button35->Text = System::Convert::ToString(sudokuboard_zeros[2, 4]);
			this->button35->UseMnemonic = false;
		}
		else {
			this->button35->Text = L" ";
			this->button35->UseMnemonic = true;
		}
		if (sudokuboard_zeros[2, 5] != 0) {
			this->button36->Text = System::Convert::ToString(sudokuboard_zeros[2, 5]);
			this->button36->UseMnemonic = false;
		}
		else {
			this->button36->Text = L" ";
			this->button36->UseMnemonic = true;
		}
		if (sudokuboard_zeros[2, 6] != 0) {
			this->button37->Text = System::Convert::ToString(sudokuboard_zeros[2, 6]);
			this->button37->UseMnemonic = false;
		}
		else {
			this->button37->Text = L" ";
			this->button37->UseMnemonic = true;
		}
		if (sudokuboard_zeros[2, 7] != 0) {
			this->button38->Text = System::Convert::ToString(sudokuboard_zeros[2, 7]);
			this->button38->UseMnemonic = false;
		}
		else {
			this->button38->Text = L" ";
			this->button38->UseMnemonic = true;
		}
		if (sudokuboard_zeros[2, 8] != 0) {
			this->button39->Text = System::Convert::ToString(sudokuboard_zeros[2, 8]);
			this->button39->UseMnemonic = false;
		}
		else {
			this->button39->Text = L" ";
			this->button39->UseMnemonic = true;
		}
		if (sudokuboard_zeros[3, 0] != 0) {
			this->button41->Text = System::Convert::ToString(sudokuboard_zeros[3, 0]);
			this->button41->UseMnemonic = false;
		}
		else {
			this->button41->Text = L" ";
			this->button41->UseMnemonic = true;
		}
		if (sudokuboard_zeros[3, 1] != 0) {
			this->button42->Text = System::Convert::ToString(sudokuboard_zeros[3, 1]);
			this->button42->UseMnemonic = false;
		}
		else {
			this->button42->Text = L" ";
			this->button42->UseMnemonic = true;
		}
		if (sudokuboard_zeros[3, 2] != 0) {
			this->button43->Text = System::Convert::ToString(sudokuboard_zeros[3, 2]);
			this->button43->UseMnemonic = false;
		}
		else {
			this->button43->Text = L" ";
			this->button43->UseMnemonic = true;
		}
		if (sudokuboard_zeros[3, 3] != 0) {
			this->button44->Text = System::Convert::ToString(sudokuboard_zeros[3, 3]);
			this->button44->UseMnemonic = false;
		}
		else {
			this->button44->Text = L" ";
			this->button44->UseMnemonic = true;
		}
		if (sudokuboard_zeros[3, 4] != 0) {
			this->button45->Text = System::Convert::ToString(sudokuboard_zeros[3, 4]);
			this->button45->UseMnemonic = false;
		}
		else {
			this->button45->Text = L" ";
			this->button45->UseMnemonic = true;
		}
		if (sudokuboard_zeros[3, 5] != 0) {
			this->button46->Text = System::Convert::ToString(sudokuboard_zeros[3, 5]);
			this->button46->UseMnemonic = false;
		}
		else {
			this->button46->Text = L" ";
			this->button46->UseMnemonic = true;
		}
		if (sudokuboard_zeros[3, 6] != 0) {
			this->button47->Text = System::Convert::ToString(sudokuboard_zeros[3, 6]);
			this->button47->UseMnemonic = false;
		}
		else {
			this->button47->Text = L" ";
			this->button47->UseMnemonic = true;
		}
		if (sudokuboard_zeros[3, 7] != 0) {
			this->button48->Text = System::Convert::ToString(sudokuboard_zeros[3, 7]);
			this->button48->UseMnemonic = false;
		}
		else {
			this->button48->Text = L" ";
			this->button48->UseMnemonic = true;
		}
		if (sudokuboard_zeros[3, 8] != 0) {
			this->button49->Text = System::Convert::ToString(sudokuboard_zeros[3, 8]);
			this->button49->UseMnemonic = false;
		}
		else {
			this->button49->Text = L" ";
			this->button49->UseMnemonic = true;
		}
		if (sudokuboard_zeros[4, 0] != 0) {
			this->button51->Text = System::Convert::ToString(sudokuboard_zeros[4, 0]);
			this->button51->UseMnemonic = false;
		}
		else {
			this->button51->Text = L" ";
			this->button51->UseMnemonic = true;
		}
		if (sudokuboard_zeros[4, 1] != 0) {
			this->button52->Text = System::Convert::ToString(sudokuboard_zeros[4, 1]);
			this->button52->UseMnemonic = false;
		}
		else {
			this->button52->Text = L" ";
			this->button52->UseMnemonic = true;
		}
		if (sudokuboard_zeros[4, 2] != 0) {
			this->button53->Text = System::Convert::ToString(sudokuboard_zeros[4, 2]);
			this->button53->UseMnemonic = false;
		}
		else {
			this->button53->Text = L" ";
			this->button53->UseMnemonic = true;
		}
		if (sudokuboard_zeros[4, 3] != 0) {
			this->button54->Text = System::Convert::ToString(sudokuboard_zeros[4, 3]);
			this->button54->UseMnemonic = false;
		}
		else {
			this->button54->Text = L" ";
			this->button54->UseMnemonic = true;
		}
		if (sudokuboard_zeros[4, 4] != 0) {
			this->button55->Text = System::Convert::ToString(sudokuboard_zeros[4, 4]);
			this->button55->UseMnemonic = false;
		}
		else {
			this->button55->Text = L" ";
			this->button55->UseMnemonic = true;
		}
		if (sudokuboard_zeros[4, 5] != 0) {
			this->button56->Text = System::Convert::ToString(sudokuboard_zeros[4, 5]);
			this->button56->UseMnemonic = false;
		}
		else {
			this->button56->Text = L" ";
			this->button56->UseMnemonic = true;
		}
		if (sudokuboard_zeros[4, 6] != 0) {
			this->button57->Text = System::Convert::ToString(sudokuboard_zeros[4, 6]);
			this->button57->UseMnemonic = false;
		}
		else {
			this->button57->Text = L" ";
			this->button57->UseMnemonic = true;
		}
		if (sudokuboard_zeros[4, 7] != 0) {
			this->button58->Text = System::Convert::ToString(sudokuboard_zeros[4, 7]);
			this->button58->UseMnemonic = false;
		}
		else {
			this->button58->Text = L" ";
			this->button58->UseMnemonic = true;
		}
		if (sudokuboard_zeros[4, 8] != 0) {
			this->button59->Text = System::Convert::ToString(sudokuboard_zeros[4, 8]);
			this->button59->UseMnemonic = false;
		}
		else {
			this->button59->Text = L" ";
			this->button59->UseMnemonic = true;
		}
		if (sudokuboard_zeros[5, 0] != 0) {
			this->button61->Text = System::Convert::ToString(sudokuboard_zeros[5, 0]);
			this->button61->UseMnemonic = false;
		}
		else {
			this->button61->Text = L" ";
			this->button61->UseMnemonic = true;
		}
		if (sudokuboard_zeros[5, 1] != 0) {
			this->button62->Text = System::Convert::ToString(sudokuboard_zeros[5, 1]);
			this->button62->UseMnemonic = false;
		}
		else {
			this->button62->Text = L" ";
			this->button62->UseMnemonic = true;
		}
		if (sudokuboard_zeros[5, 2] != 0) {
			this->button63->Text = System::Convert::ToString(sudokuboard_zeros[5, 2]);
			this->button63->UseMnemonic = false;
		}
		else {
			this->button63->Text = L" ";
			this->button63->UseMnemonic = true;
		}
		if (sudokuboard_zeros[5, 3] != 0) {
			this->button64->Text = System::Convert::ToString(sudokuboard_zeros[5, 3]);
			this->button64->UseMnemonic = false;
		}
		else {
			this->button64->Text = L" ";
			this->button64->UseMnemonic = true;
		}
		if (sudokuboard_zeros[5, 4] != 0) {
			this->button65->Text = System::Convert::ToString(sudokuboard_zeros[5, 4]);
			this->button65->UseMnemonic = false;
		}
		else {
			this->button65->Text = L" ";
			this->button65->UseMnemonic = true;
		}
		if (sudokuboard_zeros[5, 5] != 0) {
			this->button66->Text = System::Convert::ToString(sudokuboard_zeros[5, 5]);
			this->button66->UseMnemonic = false;
		}
		else {
			this->button66->Text = L" ";
			this->button66->UseMnemonic = true;
		}
		if (sudokuboard_zeros[5, 6] != 0) {
			this->button67->Text = System::Convert::ToString(sudokuboard_zeros[5, 6]);
			this->button67->UseMnemonic = false;
		}
		else {
			this->button67->Text = L" ";
			this->button67->UseMnemonic = true;
		}
		if (sudokuboard_zeros[5, 7] != 0) {
			this->button68->Text = System::Convert::ToString(sudokuboard_zeros[5, 7]);
			this->button68->UseMnemonic = false;
		}
		else {
			this->button68->Text = L" ";
			this->button68->UseMnemonic = true;
		}
		if (sudokuboard_zeros[5, 8] != 0) {
			this->button69->Text = System::Convert::ToString(sudokuboard_zeros[5, 8]);
			this->button69->UseMnemonic = false;
		}
		else {
			this->button69->Text = L" ";
			this->button69->UseMnemonic = true;
		}
		if (sudokuboard_zeros[6, 0] != 0) {
			this->button71->Text = System::Convert::ToString(sudokuboard_zeros[6, 0]);
			this->button71->UseMnemonic = false;
		}
		else {
			this->button71->Text = L" ";
			this->button71->UseMnemonic = true;
		}
		if (sudokuboard_zeros[6, 1] != 0) {
			this->button72->Text = System::Convert::ToString(sudokuboard_zeros[6, 1]);
			this->button72->UseMnemonic = false;
		}
		else {
			this->button72->Text = L" ";
			this->button72->UseMnemonic = true;
		}
		if (sudokuboard_zeros[6, 2] != 0) {
			this->button73->Text = System::Convert::ToString(sudokuboard_zeros[6, 2]);
			this->button73->UseMnemonic = false;
		}
		else {
			this->button73->Text = L" ";
			this->button73->UseMnemonic = true;
		}
		if (sudokuboard_zeros[6, 3] != 0) {
			this->button74->Text = System::Convert::ToString(sudokuboard_zeros[6, 3]);
			this->button74->UseMnemonic = false;
		}
		else {
			this->button74->Text = L" ";
			this->button74->UseMnemonic = true;
		}
		if (sudokuboard_zeros[6, 4] != 0) {
			this->button75->Text = System::Convert::ToString(sudokuboard_zeros[6, 4]);
			this->button75->UseMnemonic = false;
		}
		else {
			this->button75->Text = L" ";
			this->button75->UseMnemonic = true;
		}
		if (sudokuboard_zeros[6, 5] != 0) {
			this->button76->Text = System::Convert::ToString(sudokuboard_zeros[6, 5]);
			this->button76->UseMnemonic = false;
		}
		else {
			this->button76->Text = L" ";
			this->button76->UseMnemonic = true;
		}
		if (sudokuboard_zeros[6, 6] != 0) {
			this->button77->Text = System::Convert::ToString(sudokuboard_zeros[6, 6]);
			this->button77->UseMnemonic = false;
		}
		else {
			this->button77->Text = L" ";
			this->button77->UseMnemonic = true;
		}
		if (sudokuboard_zeros[6, 7] != 0) {
			this->button78->Text = System::Convert::ToString(sudokuboard_zeros[6, 7]);
			this->button78->UseMnemonic = false;
		}
		else {
			this->button78->Text = L" ";
			this->button78->UseMnemonic = true;
		}
		if (sudokuboard_zeros[6, 8] != 0) {
			this->button79->Text = System::Convert::ToString(sudokuboard_zeros[6, 8]);
			this->button79->UseMnemonic = false;
		}
		else {
			this->button79->Text = L" ";
			this->button79->UseMnemonic = true;
		}
		if (sudokuboard_zeros[7, 0] != 0) {
			this->button81->Text = System::Convert::ToString(sudokuboard_zeros[7, 0]);
			this->button81->UseMnemonic = false;
		}
		else {
			this->button81->Text = L" ";
			this->button81->UseMnemonic = true;
		}
		if (sudokuboard_zeros[7, 1] != 0) {
			this->button82->Text = System::Convert::ToString(sudokuboard_zeros[7, 1]);
			this->button82->UseMnemonic = false;
		}
		else {
			this->button82->Text = L" ";
			this->button82->UseMnemonic = true;
		}
		if (sudokuboard_zeros[7, 2] != 0) {
			this->button83->Text = System::Convert::ToString(sudokuboard_zeros[7, 2]);
			this->button83->UseMnemonic = false;
		}
		else {
			this->button83->Text = L" ";
			this->button83->UseMnemonic = true;
		}
		if (sudokuboard_zeros[7, 3] != 0) {
			this->button84->Text = System::Convert::ToString(sudokuboard_zeros[7, 3]);
			this->button84->UseMnemonic = false;
		}
		else {
			this->button84->Text = L" ";
			this->button84->UseMnemonic = true;
		}
		if (sudokuboard_zeros[7, 4] != 0) {
			this->button85->Text = System::Convert::ToString(sudokuboard_zeros[7, 4]);
			this->button85->UseMnemonic = false;
		}
		else {
			this->button85->Text = L" ";
			this->button85->UseMnemonic = true;
		}
		if (sudokuboard_zeros[7, 5] != 0) {
			this->button86->Text = System::Convert::ToString(sudokuboard_zeros[7, 5]);
			this->button86->UseMnemonic = false;
		}
		else {
			this->button86->Text = L" ";
			this->button86->UseMnemonic = true;
		}
		if (sudokuboard_zeros[7, 6] != 0) {
			this->button87->Text = System::Convert::ToString(sudokuboard_zeros[7, 6]);
			this->button87->UseMnemonic = false;
		}
		else {
			this->button87->Text = L" ";
			this->button87->UseMnemonic = true;
		}
		if (sudokuboard_zeros[7, 7] != 0) {
			this->button88->Text = System::Convert::ToString(sudokuboard_zeros[7, 7]);
			this->button88->UseMnemonic = false;
		}
		else {
			this->button88->Text = L" ";
			this->button88->UseMnemonic = true;
		}
		if (sudokuboard_zeros[7, 8] != 0) {
			this->button89->Text = System::Convert::ToString(sudokuboard_zeros[7, 8]);
			this->button89->UseMnemonic = false;
		}
		else {
			this->button89->Text = L" ";
			this->button89->UseMnemonic = true;
		}
		if (sudokuboard_zeros[8, 0] != 0) {
			this->button91->Text = System::Convert::ToString(sudokuboard_zeros[8, 0]);
			this->button91->UseMnemonic = false;
		}
		else {
			this->button91->Text = L" ";
			this->button91->UseMnemonic = true;
		}
		if (sudokuboard_zeros[8, 1] != 0) {
			this->button92->Text = System::Convert::ToString(sudokuboard_zeros[8, 1]);
			this->button92->UseMnemonic = false;
		}
		else {
			this->button92->Text = L" ";
			this->button92->UseMnemonic = true;
		}
		if (sudokuboard_zeros[8, 2] != 0) {
			this->button93->Text = System::Convert::ToString(sudokuboard_zeros[8, 2]);
			this->button93->UseMnemonic = false;
		}
		else {
			this->button93->Text = L" ";
			this->button93->UseMnemonic = true;
		}
		if (sudokuboard_zeros[8, 3] != 0) {
			this->button94->Text = System::Convert::ToString(sudokuboard_zeros[8, 3]);
			this->button94->UseMnemonic = false;
		}
		else {
			this->button94->Text = L" ";
			this->button94->UseMnemonic = true;
		}
		if (sudokuboard_zeros[8, 4] != 0) {
			this->button95->Text = System::Convert::ToString(sudokuboard_zeros[8, 4]);
			this->button95->UseMnemonic = false;
		}
		else {
			this->button95->Text = L" ";
			this->button95->UseMnemonic = true;
		}
		if (sudokuboard_zeros[8, 5] != 0) {
			this->button96->Text = System::Convert::ToString(sudokuboard_zeros[8, 5]);
			this->button96->UseMnemonic = false;
		}
		else {
			this->button96->Text = L" ";
			this->button96->UseMnemonic = true;
		}
		if (sudokuboard_zeros[8, 6] != 0) {
			this->button97->Text = System::Convert::ToString(sudokuboard_zeros[8, 6]);
			this->button97->UseMnemonic = false;
		}
		else {
			this->button97->Text = L" ";
			this->button97->UseMnemonic = true;
		}
		if (sudokuboard_zeros[8, 7] != 0) {
			this->button98->Text = System::Convert::ToString(sudokuboard_zeros[8, 7]);
			this->button98->UseMnemonic = false;
		}
		else {
			this->button98->Text = L" ";
			this->button98->UseMnemonic = true;
		}
		if (sudokuboard_zeros[8, 8] != 0) {
			this->button99->Text = System::Convert::ToString(sudokuboard_zeros[8, 8]);
			this->button99->UseMnemonic = false;
		}
		else {
			this->button99->Text = L" ";
			this->button99->UseMnemonic = true;
		}
		Changed = L" ";
		Clear();
	}
	private: System::Void ButtonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		Changed = L"0";

		this->button1->BackColor = System::Drawing::Color::White;
		this->button2->BackColor = System::Drawing::Color::White;
		this->button3->BackColor = System::Drawing::Color::White;
		this->button4->BackColor = System::Drawing::Color::White;
		this->button5->BackColor = System::Drawing::Color::White;
		this->button6->BackColor = System::Drawing::Color::White;
		this->button7->BackColor = System::Drawing::Color::White;
		this->button8->BackColor = System::Drawing::Color::White;
		this->button9->BackColor = System::Drawing::Color::White;
		this->button10->BackColor = System::Drawing::Color::MistyRose;

		if (this->button11->UseMnemonic) {
			this->button11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button11->BackColor = System::Drawing::Color::Gainsboro;
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button12->UseMnemonic) {
			this->button12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button12->BackColor = System::Drawing::Color::Gainsboro;
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button13->UseMnemonic) {
			this->button13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button13->BackColor = System::Drawing::Color::Gainsboro;
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button14->UseMnemonic) {
			this->button14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button14->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button14->BackColor = System::Drawing::Color::Gainsboro;
			this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button14->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button15->UseMnemonic) {
			this->button15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button15->BackColor = System::Drawing::Color::Gainsboro;
			this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button16->UseMnemonic) {
			this->button16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button16->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button16->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button16->BackColor = System::Drawing::Color::Gainsboro;
			this->button16->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button16->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button17->UseMnemonic) {
			this->button17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button17->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button17->BackColor = System::Drawing::Color::Gainsboro;
			this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button17->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button18->UseMnemonic) {
			this->button18->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button18->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button18->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button18->BackColor = System::Drawing::Color::Gainsboro;
			this->button18->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button18->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button19->UseMnemonic) {
			this->button19->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button19->BackColor = System::Drawing::Color::Gainsboro;
			this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button21->UseMnemonic) {
			this->button21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button21->BackColor = System::Drawing::Color::Gainsboro;
			this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button22->UseMnemonic) {
			this->button22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button22->BackColor = System::Drawing::Color::Gainsboro;
			this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button23->UseMnemonic) {
			this->button23->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button23->BackColor = System::Drawing::Color::Gainsboro;
			this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button24->UseMnemonic) {
			this->button24->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button24->BackColor = System::Drawing::Color::Gainsboro;
			this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button25->UseMnemonic) {
			this->button25->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button25->BackColor = System::Drawing::Color::Gainsboro;
			this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button26->UseMnemonic) {
			this->button26->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button26->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button26->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button26->BackColor = System::Drawing::Color::Gainsboro;
			this->button26->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button26->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button27->UseMnemonic) {
			this->button27->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button27->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button27->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button27->BackColor = System::Drawing::Color::Gainsboro;
			this->button27->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button27->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button28->UseMnemonic) {
			this->button28->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button28->BackColor = System::Drawing::Color::Gainsboro;
			this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button29->UseMnemonic) {
			this->button29->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button29->BackColor = System::Drawing::Color::Gainsboro;
			this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button31->UseMnemonic) {
			this->button31->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button31->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button31->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button31->BackColor = System::Drawing::Color::Gainsboro;
			this->button31->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button31->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button32->UseMnemonic) {
			this->button32->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button32->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button32->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button32->BackColor = System::Drawing::Color::Gainsboro;
			this->button32->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button32->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button33->UseMnemonic) {
			this->button33->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button33->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button33->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button33->BackColor = System::Drawing::Color::Gainsboro;
			this->button33->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button33->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button34->UseMnemonic) {
			this->button34->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button34->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button34->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button34->BackColor = System::Drawing::Color::Gainsboro;
			this->button34->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button34->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button35->UseMnemonic) {
			this->button35->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button35->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button35->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button35->BackColor = System::Drawing::Color::Gainsboro;
			this->button35->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button35->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button36->UseMnemonic) {
			this->button36->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button36->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button36->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button36->BackColor = System::Drawing::Color::Gainsboro;
			this->button36->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button36->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button37->UseMnemonic) {
			this->button37->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button37->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button37->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button37->BackColor = System::Drawing::Color::Gainsboro;
			this->button37->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button37->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button38->UseMnemonic) {
			this->button38->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button38->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button38->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button38->BackColor = System::Drawing::Color::Gainsboro;
			this->button38->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button38->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button39->UseMnemonic) {
			this->button39->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button39->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button39->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button39->BackColor = System::Drawing::Color::Gainsboro;
			this->button39->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button39->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button41->UseMnemonic) {
			this->button41->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button41->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button41->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button41->BackColor = System::Drawing::Color::Gainsboro;
			this->button41->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button41->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button42->UseMnemonic) {
			this->button42->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button42->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button42->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button42->BackColor = System::Drawing::Color::Gainsboro;
			this->button42->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button42->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button43->UseMnemonic) {
			this->button43->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button43->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button43->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button43->BackColor = System::Drawing::Color::Gainsboro;
			this->button43->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button43->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button44->UseMnemonic) {
			this->button44->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button44->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button44->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button44->BackColor = System::Drawing::Color::Gainsboro;
			this->button44->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button44->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button45->UseMnemonic) {
			this->button45->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button45->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button45->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button45->BackColor = System::Drawing::Color::Gainsboro;
			this->button45->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button45->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button46->UseMnemonic) {
			this->button46->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button46->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button46->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button46->BackColor = System::Drawing::Color::Gainsboro;
			this->button46->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button46->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button47->UseMnemonic) {
			this->button47->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button47->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button47->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button47->BackColor = System::Drawing::Color::Gainsboro;
			this->button47->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button47->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button48->UseMnemonic) {
			this->button48->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button48->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button48->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button48->BackColor = System::Drawing::Color::Gainsboro;
			this->button48->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button48->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button49->UseMnemonic) {
			this->button49->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button49->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button49->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button49->BackColor = System::Drawing::Color::Gainsboro;
			this->button49->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button49->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button51->UseMnemonic) {
			this->button51->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button51->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button51->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button51->BackColor = System::Drawing::Color::Gainsboro;
			this->button51->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button51->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button52->UseMnemonic) {
			this->button52->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button52->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button52->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button52->BackColor = System::Drawing::Color::Gainsboro;
			this->button52->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button52->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button53->UseMnemonic) {
			this->button53->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button53->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button53->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button53->BackColor = System::Drawing::Color::Gainsboro;
			this->button53->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button53->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button54->UseMnemonic) {
			this->button54->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button54->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button54->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button54->BackColor = System::Drawing::Color::Gainsboro;
			this->button54->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button54->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button55->UseMnemonic) {
			this->button55->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button55->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button55->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button55->BackColor = System::Drawing::Color::Gainsboro;
			this->button55->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button55->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button56->UseMnemonic) {
			this->button56->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button56->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button56->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button56->BackColor = System::Drawing::Color::Gainsboro;
			this->button56->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button56->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button57->UseMnemonic) {
			this->button57->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button57->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button57->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button57->BackColor = System::Drawing::Color::Gainsboro;
			this->button57->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button57->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button58->UseMnemonic) {
			this->button58->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button58->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button58->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button58->BackColor = System::Drawing::Color::Gainsboro;
			this->button58->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button58->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button59->UseMnemonic) {
			this->button59->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button59->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button59->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button59->BackColor = System::Drawing::Color::Gainsboro;
			this->button59->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button59->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button61->UseMnemonic) {
			this->button61->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button61->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button61->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button61->BackColor = System::Drawing::Color::Gainsboro;
			this->button61->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button61->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button62->UseMnemonic) {
			this->button62->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button62->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button62->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button62->BackColor = System::Drawing::Color::Gainsboro;
			this->button62->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button62->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button63->UseMnemonic) {
			this->button63->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button63->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button63->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button63->BackColor = System::Drawing::Color::Gainsboro;
			this->button63->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button63->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button64->UseMnemonic) {
			this->button64->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button64->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button64->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button64->BackColor = System::Drawing::Color::Gainsboro;
			this->button64->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button64->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button65->UseMnemonic) {
			this->button65->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button65->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button65->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button65->BackColor = System::Drawing::Color::Gainsboro;
			this->button65->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button65->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button66->UseMnemonic) {
			this->button66->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button66->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button66->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button66->BackColor = System::Drawing::Color::Gainsboro;
			this->button66->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button66->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button67->UseMnemonic) {
			this->button67->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button67->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button67->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button67->BackColor = System::Drawing::Color::Gainsboro;
			this->button67->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button67->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button68->UseMnemonic) {
			this->button68->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button68->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button68->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button68->BackColor = System::Drawing::Color::Gainsboro;
			this->button68->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button68->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button69->UseMnemonic) {
			this->button69->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button69->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button69->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button69->BackColor = System::Drawing::Color::Gainsboro;
			this->button69->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button69->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button71->UseMnemonic) {
			this->button71->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button71->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button71->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button71->BackColor = System::Drawing::Color::Gainsboro;
			this->button71->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button71->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button72->UseMnemonic) {
			this->button72->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button72->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button72->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button72->BackColor = System::Drawing::Color::Gainsboro;
			this->button72->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button72->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button73->UseMnemonic) {
			this->button73->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button73->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button73->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button73->BackColor = System::Drawing::Color::Gainsboro;
			this->button73->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button73->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button74->UseMnemonic) {
			this->button74->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button74->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button74->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button74->BackColor = System::Drawing::Color::Gainsboro;
			this->button74->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button74->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button75->UseMnemonic) {
			this->button75->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button75->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button75->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button75->BackColor = System::Drawing::Color::Gainsboro;
			this->button75->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button75->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button76->UseMnemonic) {
			this->button76->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button76->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button76->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button76->BackColor = System::Drawing::Color::Gainsboro;
			this->button76->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button76->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button77->UseMnemonic) {
			this->button77->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button77->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button77->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button77->BackColor = System::Drawing::Color::Gainsboro;
			this->button77->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button77->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button78->UseMnemonic) {
			this->button78->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button78->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button78->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button78->BackColor = System::Drawing::Color::Gainsboro;
			this->button78->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button78->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button79->UseMnemonic) {
			this->button79->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button79->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button79->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button79->BackColor = System::Drawing::Color::Gainsboro;
			this->button79->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button79->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button81->UseMnemonic) {
			this->button81->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button81->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button81->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button81->BackColor = System::Drawing::Color::Gainsboro;
			this->button81->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button81->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button82->UseMnemonic) {
			this->button82->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button82->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button82->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button82->BackColor = System::Drawing::Color::Gainsboro;
			this->button82->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button82->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button83->UseMnemonic) {
			this->button83->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button83->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button83->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button83->BackColor = System::Drawing::Color::Gainsboro;
			this->button83->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button83->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button84->UseMnemonic) {
			this->button84->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button84->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button84->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button84->BackColor = System::Drawing::Color::Gainsboro;
			this->button84->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button84->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button85->UseMnemonic) {
			this->button85->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button85->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button85->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button85->BackColor = System::Drawing::Color::Gainsboro;
			this->button85->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button85->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button86->UseMnemonic) {
			this->button86->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button86->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button86->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button86->BackColor = System::Drawing::Color::Gainsboro;
			this->button86->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button86->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button87->UseMnemonic) {
			this->button87->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button87->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button87->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button87->BackColor = System::Drawing::Color::Gainsboro;
			this->button87->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button87->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button88->UseMnemonic) {
			this->button88->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button88->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button88->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button88->BackColor = System::Drawing::Color::Gainsboro;
			this->button88->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button88->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button89->UseMnemonic) {
			this->button89->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button89->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button89->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button89->BackColor = System::Drawing::Color::Gainsboro;
			this->button89->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button89->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button91->UseMnemonic) {
			this->button91->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button91->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button91->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button91->BackColor = System::Drawing::Color::Gainsboro;
			this->button91->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button91->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button92->UseMnemonic) {
			this->button92->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button92->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button92->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button92->BackColor = System::Drawing::Color::Gainsboro;
			this->button92->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button92->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button93->UseMnemonic) {
			this->button93->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button93->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button93->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button93->BackColor = System::Drawing::Color::Gainsboro;
			this->button93->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button93->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button94->UseMnemonic) {
			this->button94->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button94->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button94->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button94->BackColor = System::Drawing::Color::Gainsboro;
			this->button94->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button94->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button95->UseMnemonic) {
			this->button95->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button95->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button95->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button95->BackColor = System::Drawing::Color::Gainsboro;
			this->button95->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button95->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button96->UseMnemonic) {
			this->button96->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button96->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button96->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button96->BackColor = System::Drawing::Color::Gainsboro;
			this->button96->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button96->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button97->UseMnemonic) {
			this->button97->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button97->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button97->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button97->BackColor = System::Drawing::Color::Gainsboro;
			this->button97->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button97->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button98->UseMnemonic) {
			this->button98->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button98->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button98->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button98->BackColor = System::Drawing::Color::Gainsboro;
			this->button98->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button98->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		if (this->button99->UseMnemonic) {
			this->button99->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button99->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
			this->button99->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
		}
		else {
			this->button99->BackColor = System::Drawing::Color::Gainsboro;
			this->button99->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gainsboro;
			this->button99->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
		}
		this->button20->Focus();
	}
	private: System::Void Logic_Click(System::Object^ sender, System::EventArgs^ e) {
		Logic();
		this->button20->Focus();
	}
	private: System::Void Check_the_solution(System::Object^ sender, System::EventArgs^ e) {
		Changed = L" ";
		Clear();
		Int32 value;
		cli::array<bool, 2>^ sudokutest_bool = gcnew cli::array<bool, 2>(SIZE, SIZE);

		if ((this->button11->Text == L" ") || (this->button12->Text == L" ") || (this->button13->Text == L" ") || (this->button14->Text == L" ") || (this->button15->Text == L" ") || (this->button16->Text == L" ") || (this->button17->Text == L" ") || (this->button18->Text == L" ") || (this->button19->Text == L" ") ||
			(this->button21->Text == L" ") || (this->button22->Text == L" ") || (this->button23->Text == L" ") || (this->button24->Text == L" ") || (this->button25->Text == L" ") || (this->button26->Text == L" ") || (this->button27->Text == L" ") || (this->button28->Text == L" ") || (this->button29->Text == L" ") ||
			(this->button31->Text == L" ") || (this->button32->Text == L" ") || (this->button33->Text == L" ") || (this->button34->Text == L" ") || (this->button35->Text == L" ") || (this->button36->Text == L" ") || (this->button37->Text == L" ") || (this->button38->Text == L" ") || (this->button39->Text == L" ") ||
			(this->button41->Text == L" ") || (this->button42->Text == L" ") || (this->button43->Text == L" ") || (this->button44->Text == L" ") || (this->button45->Text == L" ") || (this->button46->Text == L" ") || (this->button47->Text == L" ") || (this->button48->Text == L" ") || (this->button49->Text == L" ") ||
			(this->button51->Text == L" ") || (this->button52->Text == L" ") || (this->button53->Text == L" ") || (this->button54->Text == L" ") || (this->button55->Text == L" ") || (this->button56->Text == L" ") || (this->button57->Text == L" ") || (this->button58->Text == L" ") || (this->button59->Text == L" ") ||
			(this->button61->Text == L" ") || (this->button62->Text == L" ") || (this->button63->Text == L" ") || (this->button64->Text == L" ") || (this->button65->Text == L" ") || (this->button66->Text == L" ") || (this->button67->Text == L" ") || (this->button68->Text == L" ") || (this->button69->Text == L" ") ||
			(this->button71->Text == L" ") || (this->button72->Text == L" ") || (this->button73->Text == L" ") || (this->button74->Text == L" ") || (this->button75->Text == L" ") || (this->button76->Text == L" ") || (this->button77->Text == L" ") || (this->button78->Text == L" ") || (this->button79->Text == L" ") ||
			(this->button81->Text == L" ") || (this->button82->Text == L" ") || (this->button83->Text == L" ") || (this->button84->Text == L" ") || (this->button85->Text == L" ") || (this->button86->Text == L" ") || (this->button87->Text == L" ") || (this->button88->Text == L" ") || (this->button89->Text == L" ") ||
			(this->button91->Text == L" ") || (this->button92->Text == L" ") || (this->button93->Text == L" ") || (this->button94->Text == L" ") || (this->button95->Text == L" ") || (this->button96->Text == L" ") || (this->button97->Text == L" ") || (this->button98->Text == L" ") || (this->button99->Text == L" ")) {
			if (comboBox2->Text == L"Russian") MessageBox::Show("   Судоку решено не до конца   ", "Проверка решения", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			if (comboBox2->Text == L"English") MessageBox::Show("   Sudoku is not completely solved   ", "Checking the solution", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			//
			// i = 0
			//
			value = System::Convert::ToInt32(this->button11->Text) - 1;
			if (arraylog_base[0, value] == 1) sudokutest_bool[0, 0] = true;
			else sudokutest_bool[0, 0] = false;
			value = System::Convert::ToInt32(this->button12->Text) - 1;
			if (arraylog_base[1, value] == 1) sudokutest_bool[0, 1] = true;
			else sudokutest_bool[0, 1] = false;
			value = System::Convert::ToInt32(this->button13->Text) - 1;
			if (arraylog_base[2, value] == 1) sudokutest_bool[0, 2] = true;
			else sudokutest_bool[0, 2] = false;
			value = System::Convert::ToInt32(this->button14->Text) - 1;
			if (arraylog_base[3, value] == 1) sudokutest_bool[0, 3] = true;
			else sudokutest_bool[0, 3] = false;
			value = System::Convert::ToInt32(this->button15->Text) - 1;
			if (arraylog_base[4, value] == 1) sudokutest_bool[0, 4] = true;
			else sudokutest_bool[0, 4] = false;
			value = System::Convert::ToInt32(this->button16->Text) - 1;
			if (arraylog_base[5, value] == 1) sudokutest_bool[0, 5] = true;
			else sudokutest_bool[0, 5] = false;
			value = System::Convert::ToInt32(this->button17->Text) - 1;
			if (arraylog_base[6, value] == 1) sudokutest_bool[0, 6] = true;
			else sudokutest_bool[0, 6] = false;
			value = System::Convert::ToInt32(this->button18->Text) - 1;
			if (arraylog_base[7, value] == 1) sudokutest_bool[0, 7] = true;
			else sudokutest_bool[0, 7] = false;
			value = System::Convert::ToInt32(this->button19->Text) - 1;
			if (arraylog_base[8, value] == 1) sudokutest_bool[0, 8] = true;
			else sudokutest_bool[0, 8] = false;
			//
			// i = 1
			//
			value = System::Convert::ToInt32(this->button21->Text) - 1;
			if (arraylog_base[9, value] == 1) sudokutest_bool[1, 0] = true;
			else sudokutest_bool[1, 0] = false;
			value = System::Convert::ToInt32(this->button22->Text) - 1;
			if (arraylog_base[10, value] == 1) sudokutest_bool[1, 1] = true;
			else sudokutest_bool[1, 1] = false;
			value = System::Convert::ToInt32(this->button23->Text) - 1;
			if (arraylog_base[11, value] == 1) sudokutest_bool[1, 2] = true;
			else sudokutest_bool[1, 2] = false;
			value = System::Convert::ToInt32(this->button24->Text) - 1;
			if (arraylog_base[12, value] == 1) sudokutest_bool[1, 3] = true;
			else sudokutest_bool[1, 3] = false;
			value = System::Convert::ToInt32(this->button25->Text) - 1;
			if (arraylog_base[13, value] == 1) sudokutest_bool[1, 4] = true;
			else sudokutest_bool[1, 4] = false;
			value = System::Convert::ToInt32(this->button26->Text) - 1;
			if (arraylog_base[14, value] == 1) sudokutest_bool[1, 5] = true;
			else sudokutest_bool[1, 5] = false;
			value = System::Convert::ToInt32(this->button27->Text) - 1;
			if (arraylog_base[15, value] == 1) sudokutest_bool[1, 6] = true;
			else sudokutest_bool[1, 6] = false;
			value = System::Convert::ToInt32(this->button28->Text) - 1;
			if (arraylog_base[16, value] == 1) sudokutest_bool[1, 7] = true;
			else sudokutest_bool[1, 7] = false;
			value = System::Convert::ToInt32(this->button29->Text) - 1;
			if (arraylog_base[17, value] == 1) sudokutest_bool[1, 8] = true;
			else sudokutest_bool[1, 8] = false;
			//
			// i = 2
			//
			value = System::Convert::ToInt32(this->button31->Text) - 1;
			if (arraylog_base[18, value] == 1) sudokutest_bool[2, 0] = true;
			else sudokutest_bool[2, 0] = false;
			value = System::Convert::ToInt32(this->button32->Text) - 1;
			if (arraylog_base[19, value] == 1) sudokutest_bool[2, 1] = true;
			else sudokutest_bool[2, 1] = false;
			value = System::Convert::ToInt32(this->button33->Text) - 1;
			if (arraylog_base[20, value] == 1) sudokutest_bool[2, 2] = true;
			else sudokutest_bool[2, 2] = false;
			value = System::Convert::ToInt32(this->button34->Text) - 1;
			if (arraylog_base[21, value] == 1) sudokutest_bool[2, 3] = true;
			else sudokutest_bool[2, 3] = false;
			value = System::Convert::ToInt32(this->button35->Text) - 1;
			if (arraylog_base[22, value] == 1) sudokutest_bool[2, 4] = true;
			else sudokutest_bool[2, 4] = false;
			value = System::Convert::ToInt32(this->button36->Text) - 1;
			if (arraylog_base[23, value] == 1) sudokutest_bool[2, 5] = true;
			else sudokutest_bool[2, 5] = false;
			value = System::Convert::ToInt32(this->button37->Text) - 1;
			if (arraylog_base[24, value] == 1) sudokutest_bool[2, 6] = true;
			else sudokutest_bool[2, 6] = false;
			value = System::Convert::ToInt32(this->button38->Text) - 1;
			if (arraylog_base[25, value] == 1) sudokutest_bool[2, 7] = true;
			else sudokutest_bool[2, 7] = false;
			value = System::Convert::ToInt32(this->button39->Text) - 1;
			if (arraylog_base[26, value] == 1) sudokutest_bool[2, 8] = true;
			else sudokutest_bool[2, 8] = false;
			//
			// i = 3
			//
			value = System::Convert::ToInt32(this->button41->Text) - 1;
			if (arraylog_base[27, value] == 1) sudokutest_bool[3, 0] = true;
			else sudokutest_bool[3, 0] = false;
			value = System::Convert::ToInt32(this->button42->Text) - 1;
			if (arraylog_base[28, value] == 1) sudokutest_bool[3, 1] = true;
			else sudokutest_bool[3, 1] = false;
			value = System::Convert::ToInt32(this->button43->Text) - 1;
			if (arraylog_base[29, value] == 1) sudokutest_bool[3, 2] = true;
			else sudokutest_bool[3, 2] = false;
			value = System::Convert::ToInt32(this->button44->Text) - 1;
			if (arraylog_base[30, value] == 1) sudokutest_bool[3, 3] = true;
			else sudokutest_bool[3, 3] = false;
			value = System::Convert::ToInt32(this->button45->Text) - 1;
			if (arraylog_base[31, value] == 1) sudokutest_bool[3, 4] = true;
			else sudokutest_bool[3, 4] = false;
			value = System::Convert::ToInt32(this->button46->Text) - 1;
			if (arraylog_base[32, value] == 1) sudokutest_bool[3, 5] = true;
			else sudokutest_bool[3, 5] = false;
			value = System::Convert::ToInt32(this->button47->Text) - 1;
			if (arraylog_base[33, value] == 1) sudokutest_bool[3, 6] = true;
			else sudokutest_bool[3, 6] = false;
			value = System::Convert::ToInt32(this->button48->Text) - 1;
			if (arraylog_base[34, value] == 1) sudokutest_bool[3, 7] = true;
			else sudokutest_bool[3, 7] = false;
			value = System::Convert::ToInt32(this->button49->Text) - 1;
			if (arraylog_base[35, value] == 1) sudokutest_bool[3, 8] = true;
			else sudokutest_bool[3, 8] = false;
			//
			// i = 4
			//
			value = System::Convert::ToInt32(this->button51->Text) - 1;
			if (arraylog_base[36, value] == 1) sudokutest_bool[4, 0] = true;
			else sudokutest_bool[4, 0] = false;
			value = System::Convert::ToInt32(this->button52->Text) - 1;
			if (arraylog_base[37, value] == 1) sudokutest_bool[4, 1] = true;
			else sudokutest_bool[4, 1] = false;
			value = System::Convert::ToInt32(this->button53->Text) - 1;
			if (arraylog_base[38, value] == 1) sudokutest_bool[4, 2] = true;
			else sudokutest_bool[4, 2] = false;
			value = System::Convert::ToInt32(this->button54->Text) - 1;
			if (arraylog_base[39, value] == 1) sudokutest_bool[4, 3] = true;
			else sudokutest_bool[4, 3] = false;
			value = System::Convert::ToInt32(this->button55->Text) - 1;
			if (arraylog_base[40, value] == 1) sudokutest_bool[4, 4] = true;
			else sudokutest_bool[4, 4] = false;
			value = System::Convert::ToInt32(this->button56->Text) - 1;
			if (arraylog_base[41, value] == 1) sudokutest_bool[4, 5] = true;
			else sudokutest_bool[4, 5] = false;
			value = System::Convert::ToInt32(this->button57->Text) - 1;
			if (arraylog_base[42, value] == 1) sudokutest_bool[4, 6] = true;
			else sudokutest_bool[4, 6] = false;
			value = System::Convert::ToInt32(this->button58->Text) - 1;
			if (arraylog_base[43, value] == 1) sudokutest_bool[4, 7] = true;
			else sudokutest_bool[4, 7] = false;
			value = System::Convert::ToInt32(this->button59->Text) - 1;
			if (arraylog_base[44, value] == 1) sudokutest_bool[4, 8] = true;
			else sudokutest_bool[4, 8] = false;
			//
			// i = 5
			//
			value = System::Convert::ToInt32(this->button61->Text) - 1;
			if (arraylog_base[45, value] == 1) sudokutest_bool[5, 0] = true;
			else sudokutest_bool[5, 0] = false;
			value = System::Convert::ToInt32(this->button62->Text) - 1;
			if (arraylog_base[46, value] == 1) sudokutest_bool[5, 1] = true;
			else sudokutest_bool[5, 1] = false;
			value = System::Convert::ToInt32(this->button63->Text) - 1;
			if (arraylog_base[47, value] == 1) sudokutest_bool[5, 2] = true;
			else sudokutest_bool[5, 2] = false;
			value = System::Convert::ToInt32(this->button64->Text) - 1;
			if (arraylog_base[48, value] == 1) sudokutest_bool[5, 3] = true;
			else sudokutest_bool[5, 3] = false;
			value = System::Convert::ToInt32(this->button65->Text) - 1;
			if (arraylog_base[49, value] == 1) sudokutest_bool[5, 4] = true;
			else sudokutest_bool[5, 4] = false;
			value = System::Convert::ToInt32(this->button66->Text) - 1;
			if (arraylog_base[50, value] == 1) sudokutest_bool[5, 5] = true;
			else sudokutest_bool[5, 5] = false;
			value = System::Convert::ToInt32(this->button67->Text) - 1;
			if (arraylog_base[51, value] == 1) sudokutest_bool[5, 6] = true;
			else sudokutest_bool[5, 6] = false;
			value = System::Convert::ToInt32(this->button68->Text) - 1;
			if (arraylog_base[52, value] == 1) sudokutest_bool[5, 7] = true;
			else sudokutest_bool[5, 7] = false;
			value = System::Convert::ToInt32(this->button69->Text) - 1;
			if (arraylog_base[53, value] == 1) sudokutest_bool[5, 8] = true;
			else sudokutest_bool[5, 8] = false;
			//
			// i = 6
			//
			value = System::Convert::ToInt32(this->button71->Text) - 1;
			if (arraylog_base[54, value] == 1) sudokutest_bool[6, 0] = true;
			else sudokutest_bool[6, 0] = false;
			value = System::Convert::ToInt32(this->button72->Text) - 1;
			if (arraylog_base[55, value] == 1) sudokutest_bool[6, 1] = true;
			else sudokutest_bool[6, 1] = false;
			value = System::Convert::ToInt32(this->button73->Text) - 1;
			if (arraylog_base[56, value] == 1) sudokutest_bool[6, 2] = true;
			else sudokutest_bool[6, 2] = false;
			value = System::Convert::ToInt32(this->button74->Text) - 1;
			if (arraylog_base[57, value] == 1) sudokutest_bool[6, 3] = true;
			else sudokutest_bool[6, 3] = false;
			value = System::Convert::ToInt32(this->button75->Text) - 1;
			if (arraylog_base[58, value] == 1) sudokutest_bool[6, 4] = true;
			else sudokutest_bool[6, 4] = false;
			value = System::Convert::ToInt32(this->button76->Text) - 1;
			if (arraylog_base[59, value] == 1) sudokutest_bool[6, 5] = true;
			else sudokutest_bool[6, 5] = false;
			value = System::Convert::ToInt32(this->button77->Text) - 1;
			if (arraylog_base[60, value] == 1) sudokutest_bool[6, 6] = true;
			else sudokutest_bool[6, 6] = false;
			value = System::Convert::ToInt32(this->button78->Text) - 1;
			if (arraylog_base[61, value] == 1) sudokutest_bool[6, 7] = true;
			else sudokutest_bool[6, 7] = false;
			value = System::Convert::ToInt32(this->button79->Text) - 1;
			if (arraylog_base[62, value] == 1) sudokutest_bool[6, 8] = true;
			else sudokutest_bool[6, 8] = false;
			//
			// i = 7
			//
			value = System::Convert::ToInt32(this->button81->Text) - 1;
			if (arraylog_base[63, value] == 1) sudokutest_bool[7, 0] = true;
			else sudokutest_bool[7, 0] = false;
			value = System::Convert::ToInt32(this->button82->Text) - 1;
			if (arraylog_base[64, value] == 1) sudokutest_bool[7, 1] = true;
			else sudokutest_bool[7, 1] = false;
			value = System::Convert::ToInt32(this->button83->Text) - 1;
			if (arraylog_base[65, value] == 1) sudokutest_bool[7, 2] = true;
			else sudokutest_bool[7, 2] = false;
			value = System::Convert::ToInt32(this->button84->Text) - 1;
			if (arraylog_base[66, value] == 1) sudokutest_bool[7, 3] = true;
			else sudokutest_bool[7, 3] = false;
			value = System::Convert::ToInt32(this->button85->Text) - 1;
			if (arraylog_base[67, value] == 1) sudokutest_bool[7, 4] = true;
			else sudokutest_bool[7, 4] = false;
			value = System::Convert::ToInt32(this->button86->Text) - 1;
			if (arraylog_base[68, value] == 1) sudokutest_bool[7, 5] = true;
			else sudokutest_bool[7, 5] = false;
			value = System::Convert::ToInt32(this->button87->Text) - 1;
			if (arraylog_base[69, value] == 1) sudokutest_bool[7, 6] = true;
			else sudokutest_bool[7, 6] = false;
			value = System::Convert::ToInt32(this->button88->Text) - 1;
			if (arraylog_base[70, value] == 1) sudokutest_bool[7, 7] = true;
			else sudokutest_bool[7, 7] = false;
			value = System::Convert::ToInt32(this->button89->Text) - 1;
			if (arraylog_base[71, value] == 1) sudokutest_bool[7, 8] = true;
			else sudokutest_bool[7, 8] = false;
			//
			// i = 8
			//
			value = System::Convert::ToInt32(this->button91->Text) - 1;
			if (arraylog_base[72, value] == 1) sudokutest_bool[8, 0] = true;
			else sudokutest_bool[8, 0] = false;
			value = System::Convert::ToInt32(this->button92->Text) - 1;
			if (arraylog_base[73, value] == 1) sudokutest_bool[8, 1] = true;
			else sudokutest_bool[8, 1] = false;
			value = System::Convert::ToInt32(this->button93->Text) - 1;
			if (arraylog_base[74, value] == 1) sudokutest_bool[8, 2] = true;
			else sudokutest_bool[8, 2] = false;
			value = System::Convert::ToInt32(this->button94->Text) - 1;
			if (arraylog_base[75, value] == 1) sudokutest_bool[8, 3] = true;
			else sudokutest_bool[8, 3] = false;
			value = System::Convert::ToInt32(this->button95->Text) - 1;
			if (arraylog_base[76, value] == 1) sudokutest_bool[8, 4] = true;
			else sudokutest_bool[8, 4] = false;
			value = System::Convert::ToInt32(this->button96->Text) - 1;
			if (arraylog_base[77, value] == 1) sudokutest_bool[8, 5] = true;
			else sudokutest_bool[8, 5] = false;
			value = System::Convert::ToInt32(this->button97->Text) - 1;
			if (arraylog_base[78, value] == 1) sudokutest_bool[8, 6] = true;
			else sudokutest_bool[8, 6] = false;
			value = System::Convert::ToInt32(this->button98->Text) - 1;
			if (arraylog_base[79, value] == 1) sudokutest_bool[8, 7] = true;
			else sudokutest_bool[8, 7] = false;
			value = System::Convert::ToInt32(this->button99->Text) - 1;
			if (arraylog_base[80, value] == 1) sudokutest_bool[8, 8] = true;
			else sudokutest_bool[8, 8] = false;

			int result = 0;

			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (sudokutest_bool[i, j] == true) result++;
				}
			}

			if ((result == 81) && (comboBox2->Text == L"Russian")) MessageBox::Show("   Судоку решено правильно   ", "Проверка решения", MessageBoxButtons::OK, MessageBoxIcon::Information);
			else if ((result == 81) && (comboBox2->Text == L"English")) MessageBox::Show("   Sudoku solved correctly   ", "Checking the solution", MessageBoxButtons::OK, MessageBoxIcon::Information);
			else {
				System::Windows::Forms::DialogResult help;
				if (comboBox2->Text == L"Russian") help = MessageBox::Show("   Судоку решено неверно   \n\n   Хотите увидеть ошибки?   ", "Проверка решения", MessageBoxButtons::YesNo, MessageBoxIcon::Error);
				if (comboBox2->Text == L"English") help = MessageBox::Show("   Sudoku solved incorrectly   \n\n   Do you want to see the mistakes?   ", "Checking the solution", MessageBoxButtons::YesNo, MessageBoxIcon::Error);
				if (help == System::Windows::Forms::DialogResult::Yes) {
					if (!sudokutest_bool[0, 0]) {
						this->button11->BackColor = System::Drawing::Color::Pink;
						this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[0, 1]) {
						this->button12->BackColor = System::Drawing::Color::Pink;
						this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[0, 2]) {
						this->button13->BackColor = System::Drawing::Color::Pink;
						this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[0, 3]) {
						this->button14->BackColor = System::Drawing::Color::Pink;
						this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button14->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[0, 4]) {
						this->button15->BackColor = System::Drawing::Color::Pink;
						this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[0, 5]) {
						this->button16->BackColor = System::Drawing::Color::Pink;
						this->button16->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button16->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[0, 6]) {
						this->button17->BackColor = System::Drawing::Color::Pink;
						this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button17->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[0, 7]) {
						this->button18->BackColor = System::Drawing::Color::Pink;
						this->button18->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button18->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[0, 8]) {
						this->button19->BackColor = System::Drawing::Color::Pink;
						this->button19->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button19->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[1, 0]) {
						this->button21->BackColor = System::Drawing::Color::Pink;
						this->button21->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button21->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[1, 1]) {
						this->button22->BackColor = System::Drawing::Color::Pink;
						this->button22->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button22->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[1, 2]) {
						this->button23->BackColor = System::Drawing::Color::Pink;
						this->button23->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button23->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[1, 3]) {
						this->button24->BackColor = System::Drawing::Color::Pink;
						this->button24->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button24->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[1, 4]) {
						this->button25->BackColor = System::Drawing::Color::Pink;
						this->button25->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button25->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[1, 5]) {
						this->button26->BackColor = System::Drawing::Color::Pink;
						this->button26->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button26->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[1, 6]) {
						this->button27->BackColor = System::Drawing::Color::Pink;
						this->button27->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button27->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[1, 7]) {
						this->button28->BackColor = System::Drawing::Color::Pink;
						this->button28->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button28->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[1, 8]) {
						this->button29->BackColor = System::Drawing::Color::Pink;
						this->button29->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button29->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[2, 0]) {
						this->button31->BackColor = System::Drawing::Color::Pink;
						this->button31->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button31->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[2, 1]) {
						this->button32->BackColor = System::Drawing::Color::Pink;
						this->button32->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button32->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[2, 2]) {
						this->button33->BackColor = System::Drawing::Color::Pink;
						this->button33->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button33->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[2, 3]) {
						this->button34->BackColor = System::Drawing::Color::Pink;
						this->button34->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button34->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[2, 4]) {
						this->button35->BackColor = System::Drawing::Color::Pink;
						this->button35->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button35->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[2, 5]) {
						this->button36->BackColor = System::Drawing::Color::Pink;
						this->button36->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button36->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[2, 6]) {
						this->button37->BackColor = System::Drawing::Color::Pink;
						this->button37->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button37->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[2, 7]) {
						this->button38->BackColor = System::Drawing::Color::Pink;
						this->button38->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button38->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[2, 8]) {
						this->button39->BackColor = System::Drawing::Color::Pink;
						this->button39->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button39->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[3, 0]) {
						this->button41->BackColor = System::Drawing::Color::Pink;
						this->button41->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button41->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[3, 1]) {
						this->button42->BackColor = System::Drawing::Color::Pink;
						this->button42->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button42->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[3, 2]) {
						this->button43->BackColor = System::Drawing::Color::Pink;
						this->button43->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button43->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[3, 3]) {
						this->button44->BackColor = System::Drawing::Color::Pink;
						this->button44->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button44->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[3, 4]) {
						this->button45->BackColor = System::Drawing::Color::Pink;
						this->button45->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button45->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[3, 5]) {
						this->button46->BackColor = System::Drawing::Color::Pink;
						this->button46->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button46->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[3, 6]) {
						this->button47->BackColor = System::Drawing::Color::Pink;
						this->button47->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button47->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[3, 7]) {
						this->button48->BackColor = System::Drawing::Color::Pink;
						this->button48->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button48->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[3, 8]) {
						this->button49->BackColor = System::Drawing::Color::Pink;
						this->button49->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button49->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[4, 0]) {
						this->button51->BackColor = System::Drawing::Color::Pink;
						this->button51->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button51->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[4, 1]) {
						this->button52->BackColor = System::Drawing::Color::Pink;
						this->button52->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button52->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[4, 2]) {
						this->button53->BackColor = System::Drawing::Color::Pink;
						this->button53->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button53->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[4, 3]) {
						this->button54->BackColor = System::Drawing::Color::Pink;
						this->button54->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button54->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[4, 4]) {
						this->button55->BackColor = System::Drawing::Color::Pink;
						this->button55->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button55->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[4, 5]) {
						this->button56->BackColor = System::Drawing::Color::Pink;
						this->button56->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button56->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[4, 6]) {
						this->button57->BackColor = System::Drawing::Color::Pink;
						this->button57->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button57->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[4, 7]) {
						this->button58->BackColor = System::Drawing::Color::Pink;
						this->button58->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button58->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[4, 8]) {
						this->button59->BackColor = System::Drawing::Color::Pink;
						this->button59->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button59->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[5, 0]) {
						this->button61->BackColor = System::Drawing::Color::Pink;
						this->button61->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button61->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[5, 1]) {
						this->button62->BackColor = System::Drawing::Color::Pink;
						this->button62->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button62->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[5, 2]) {
						this->button63->BackColor = System::Drawing::Color::Pink;
						this->button63->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button63->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[5, 3]) {
						this->button64->BackColor = System::Drawing::Color::Pink;
						this->button64->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button64->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[5, 4]) {
						this->button65->BackColor = System::Drawing::Color::Pink;
						this->button65->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button65->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[5, 5]) {
						this->button66->BackColor = System::Drawing::Color::Pink;
						this->button66->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button66->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[5, 6]) {
						this->button67->BackColor = System::Drawing::Color::Pink;
						this->button67->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button67->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[5, 7]) {
						this->button68->BackColor = System::Drawing::Color::Pink;
						this->button68->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button68->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[5, 8]) {
						this->button69->BackColor = System::Drawing::Color::Pink;
						this->button69->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button69->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[6, 0]) {
						this->button71->BackColor = System::Drawing::Color::Pink;
						this->button71->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button71->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[6, 1]) {
						this->button72->BackColor = System::Drawing::Color::Pink;
						this->button72->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button72->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[6, 2]) {
						this->button73->BackColor = System::Drawing::Color::Pink;
						this->button73->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button73->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[6, 3]) {
						this->button74->BackColor = System::Drawing::Color::Pink;
						this->button74->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button74->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[6, 4]) {
						this->button75->BackColor = System::Drawing::Color::Pink;
						this->button75->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button75->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[6, 5]) {
						this->button76->BackColor = System::Drawing::Color::Pink;
						this->button76->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button76->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[6, 6]) {
						this->button77->BackColor = System::Drawing::Color::Pink;
						this->button77->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button77->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[6, 7]) {
						this->button78->BackColor = System::Drawing::Color::Pink;
						this->button78->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button78->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[6, 8]) {
						this->button79->BackColor = System::Drawing::Color::Pink;
						this->button79->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button79->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[7, 0]) {
						this->button81->BackColor = System::Drawing::Color::Pink;
						this->button81->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button81->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[7, 1]) {
						this->button82->BackColor = System::Drawing::Color::Pink;
						this->button82->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button82->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[7, 2]) {
						this->button83->BackColor = System::Drawing::Color::Pink;
						this->button83->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button83->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[7, 3]) {
						this->button84->BackColor = System::Drawing::Color::Pink;
						this->button84->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button84->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[7, 4]) {
						this->button85->BackColor = System::Drawing::Color::Pink;
						this->button85->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button85->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[7, 5]) {
						this->button86->BackColor = System::Drawing::Color::Pink;
						this->button86->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button86->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[7, 6]) {
						this->button87->BackColor = System::Drawing::Color::Pink;
						this->button87->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button87->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[7, 7]) {
						this->button88->BackColor = System::Drawing::Color::Pink;
						this->button88->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button88->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[7, 8]) {
						this->button89->BackColor = System::Drawing::Color::Pink;
						this->button89->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button89->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[8, 0]) {
						this->button91->BackColor = System::Drawing::Color::Pink;
						this->button91->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button91->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[8, 1]) {
						this->button92->BackColor = System::Drawing::Color::Pink;
						this->button92->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button92->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[8, 2]) {
						this->button93->BackColor = System::Drawing::Color::Pink;
						this->button93->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button93->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[8, 3]) {
						this->button94->BackColor = System::Drawing::Color::Pink;
						this->button94->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button94->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[8, 4]) {
						this->button95->BackColor = System::Drawing::Color::Pink;
						this->button95->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button95->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[8, 5]) {
						this->button96->BackColor = System::Drawing::Color::Pink;
						this->button96->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button96->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[8, 6]) {
						this->button97->BackColor = System::Drawing::Color::Pink;
						this->button97->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button97->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[8, 7]) {
						this->button98->BackColor = System::Drawing::Color::Pink;
						this->button98->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button98->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
					if (!sudokutest_bool[8, 8]) {
						this->button99->BackColor = System::Drawing::Color::Pink;
						this->button99->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Pink;
						this->button99->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Pink;
					}
				}
			}
		}
		this->button20->Focus();
	}
	private: System::Void comboBox1_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {
		Difficulty = comboBox1->Text;
		if (Difficulty == L"Easy") Difficulty = L"Лёгкий";
		if (Difficulty == L"Normal") Difficulty = L"Средний";
		if (Difficulty == L"Hard") Difficulty = L"Сложный";
		this->button20->Focus();
	}
	private: System::Void comboBox2_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox2->Text == L"English") {
			this->label1->Text = L"Difficulty level:";
			this->label1->Location = Point(101, 66);
			this->comboBox1->Items->Clear();
			this->comboBox1->Items->Add(L"Easy");
			this->comboBox1->Items->Add(L"Normal");
			this->comboBox1->Items->Add(L"Hard");
			this->button40->Text = L"Generate Sudoku";
			this->button30->Text = L"Check the solution";
			this->button10->Text = L"Clear";
			if (Difficulty == L"Лёгкий") this->comboBox1->Text = L"Easy";
			if (Difficulty == L"Средний") this->comboBox1->Text = L"Normal";
			if (Difficulty == L"Сложный") this->comboBox1->Text = L"Hard";
			this->Name = L"Sudoku";
			this->Text = L"Sudoku";
		}
		if (comboBox2->Text == L"Russian") {
			this->label1->Text = L"Уровень сложности:";
			this->label1->Location = Point(74, 66);
			this->comboBox1->Items->Clear();
			this->comboBox1->Items->Add(L"Лёгкий");
			this->comboBox1->Items->Add(L"Средний");
			this->comboBox1->Items->Add(L"Сложный");
			this->button40->Text = L"Сгенерировать Судоку";
			this->button30->Text = L"Проверить решение";
			this->button10->Text = L"Очистить";
			if (Difficulty == L"Лёгкий") this->comboBox1->Text = L"Лёгкий";
			if (Difficulty == L"Средний") this->comboBox1->Text = L"Средний";
			if (Difficulty == L"Сложный") this->comboBox1->Text = L"Сложный";
			this->Name = L"Судоку";
			this->Text = L"Судоку";
		}
		this->button20->Focus();
	}
};
}