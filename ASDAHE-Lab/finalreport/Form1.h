#pragma once
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
#include <iostream>
#include <msclr/marshal_cppstd.h>

#include <sstream>
#include <conio.h>

#include <fstream>
#include <msclr/marshal.h>
#include "math.h"
#include <codecvt>
#include <windows.h>
#include <winuser.h>
#include <iomanip>
#include <fstream> 
#include <Windows.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <opencv2\opencv.hpp>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <conio.h>
#include <opencv2\opencv.hpp>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\calib3d\calib3d.hpp>
#include <opencv2\nonfree\nonfree.hpp>


using namespace System::Runtime::InteropServices;
using namespace cv;
using namespace std;
using namespace msclr::interop;
using namespace System::Data;
using namespace System::Drawing;

static int vt;
static Mat denoise, image_clahe, img_svd, img_src;

static Mat drawhistogram(Mat img)
{
	// draw histogram
	/// Separate the image in 3 places ( B, G and R )
	vector<Mat> bgr_planes;
	split( img, bgr_planes );

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 255 } ;
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;

	Mat b_hist, g_hist, r_hist;

	/// Compute the histograms:
	calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
	calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
	calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

	// Draw the histograms for B, G and R
	int hist_w = 1024; int hist_h = 400;
	int bin_w = cvRound( (double) hist_w/histSize );

	Mat histImage( hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255) );//white, (0,0,0) is black
				
	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

	// Draw for each channel
	for( int i = 1; i < histSize; i++ )
	{
		line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
						 cv::Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                         Scalar( 255, 0, 0), 2, 8, 0  );//blue
		line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
						 cv::Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                         Scalar( 0, 255, 0), 2, 8, 0  );//green
		line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                         cv::Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                         Scalar( 0, 0, 255), 2, 8, 0  );//red
	}
	return histImage;		
}
namespace finalreport {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::NumericUpDown^  nUD_sigma;
	private: System::Windows::Forms::NumericUpDown^  nUD_mGa;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label3;























































	private: System::Windows::Forms::Label^  lab_result;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lab_ori;
	private: System::Windows::Forms::PictureBox^  pB_hist_dst;
	private: System::Windows::Forms::PictureBox^  pB_hist_src;
	private: System::Windows::Forms::PictureBox^  pB_ASVD;
	private: System::Windows::Forms::PictureBox^  pB_ori;



































































































private: System::Windows::Forms::TextBox^  txt_src_rows;

private: System::Windows::Forms::TextBox^  col_dct;
private: System::Windows::Forms::TextBox^  row_dct;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::TextBox^  txt_src_cols;


private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::Label^  label62;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::PictureBox^  pB_hist_he;
private: System::Windows::Forms::PictureBox^  pB_he;
private: System::Windows::Forms::PictureBox^  pB_hist_blur;



private: System::Windows::Forms::PictureBox^  pB_blur;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::Label^  label71;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::CheckBox^  chY;
private: System::Windows::Forms::CheckBox^  chCb;

private: System::Windows::Forms::CheckBox^  chCr;
private: System::Windows::Forms::TextBox^  vt1;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::TextBox^  txt_xiB;
private: System::Windows::Forms::TextBox^  txt_xiG;
private: System::Windows::Forms::TextBox^  txt_xiR;
private: System::Windows::Forms::GroupBox^  ASVD;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::NumericUpDown^  nsWS;
private: System::Windows::Forms::NumericUpDown^  ntWS;
private: System::Windows::Forms::NumericUpDown^  nHC;
private: System::Windows::Forms::NumericUpDown^  nH;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;









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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->nUD_sigma = (gcnew System::Windows::Forms::NumericUpDown());
			this->nUD_mGa = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lab_result = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lab_ori = (gcnew System::Windows::Forms::Label());
			this->pB_hist_dst = (gcnew System::Windows::Forms::PictureBox());
			this->pB_hist_src = (gcnew System::Windows::Forms::PictureBox());
			this->pB_ASVD = (gcnew System::Windows::Forms::PictureBox());
			this->pB_ori = (gcnew System::Windows::Forms::PictureBox());
			this->txt_src_rows = (gcnew System::Windows::Forms::TextBox());
			this->col_dct = (gcnew System::Windows::Forms::TextBox());
			this->row_dct = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->txt_src_cols = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pB_hist_he = (gcnew System::Windows::Forms::PictureBox());
			this->pB_he = (gcnew System::Windows::Forms::PictureBox());
			this->pB_hist_blur = (gcnew System::Windows::Forms::PictureBox());
			this->pB_blur = (gcnew System::Windows::Forms::PictureBox());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nsWS = (gcnew System::Windows::Forms::NumericUpDown());
			this->ntWS = (gcnew System::Windows::Forms::NumericUpDown());
			this->nHC = (gcnew System::Windows::Forms::NumericUpDown());
			this->nH = (gcnew System::Windows::Forms::NumericUpDown());
			this->vt1 = (gcnew System::Windows::Forms::TextBox());
			this->chCb = (gcnew System::Windows::Forms::CheckBox());
			this->chCr = (gcnew System::Windows::Forms::CheckBox());
			this->chY = (gcnew System::Windows::Forms::CheckBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->txt_xiB = (gcnew System::Windows::Forms::TextBox());
			this->txt_xiG = (gcnew System::Windows::Forms::TextBox());
			this->txt_xiR = (gcnew System::Windows::Forms::TextBox());
			this->ASVD = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUD_sigma))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUD_mGa))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_hist_dst))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_hist_src))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_ASVD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_ori))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_hist_he))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_he))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_hist_blur))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_blur))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nsWS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ntWS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nHC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nH))->BeginInit();
			this->ASVD->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(4, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog1";
			// 
			// nUD_sigma
			// 
			this->nUD_sigma->Location = System::Drawing::Point(98, 92);
			this->nUD_sigma->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nUD_sigma->Name = L"nUD_sigma";
			this->nUD_sigma->Size = System::Drawing::Size(64, 20);
			this->nUD_sigma->TabIndex = 82;
			this->nUD_sigma->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {32, 0, 0, 0});
			// 
			// nUD_mGa
			// 
			this->nUD_mGa->Location = System::Drawing::Point(98, 45);
			this->nUD_mGa->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->nUD_mGa->Name = L"nUD_mGa";
			this->nUD_mGa->Size = System::Drawing::Size(64, 20);
			this->nUD_mGa->TabIndex = 83;
			this->nUD_mGa->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {127, 0, 0, 0});
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(2, 94);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(97, 13);
			this->label7->TabIndex = 80;
			this->label7->Text = L"Standard Gaussian";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 13);
			this->label3->TabIndex = 81;
			this->label3->Text = L"Mean Gaussian";
			// 
			// lab_result
			// 
			this->lab_result->AutoSize = true;
			this->lab_result->Location = System::Drawing::Point(683, 420);
			this->lab_result->Name = L"lab_result";
			this->lab_result->Size = System::Drawing::Size(76, 13);
			this->lab_result->TabIndex = 88;
			this->lab_result->Text = L"ASVDD Image";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(666, 193);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 13);
			this->label2->TabIndex = 90;
			this->label2->Text = L"ASVDD Image Histogram";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(165, 193);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 13);
			this->label1->TabIndex = 91;
			this->label1->Text = L"Original Image Histogram";
			// 
			// lab_ori
			// 
			this->lab_ori->AutoSize = true;
			this->lab_ori->Location = System::Drawing::Point(182, 420);
			this->lab_ori->Name = L"lab_ori";
			this->lab_ori->Size = System::Drawing::Size(74, 13);
			this->lab_ori->TabIndex = 89;
			this->lab_ori->Text = L"Original Image";
			// 
			// pB_hist_dst
			// 
			this->pB_hist_dst->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pB_hist_dst->Location = System::Drawing::Point(487, 220);
			this->pB_hist_dst->Name = L"pB_hist_dst";
			this->pB_hist_dst->Size = System::Drawing::Size(470, 185);
			this->pB_hist_dst->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_hist_dst->TabIndex = 87;
			this->pB_hist_dst->TabStop = false;
			// 
			// pB_hist_src
			// 
			this->pB_hist_src->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pB_hist_src->Location = System::Drawing::Point(9, 220);
			this->pB_hist_src->Name = L"pB_hist_src";
			this->pB_hist_src->Size = System::Drawing::Size(470, 185);
			this->pB_hist_src->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_hist_src->TabIndex = 86;
			this->pB_hist_src->TabStop = false;
			// 
			// pB_ASVD
			// 
			this->pB_ASVD->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pB_ASVD->Location = System::Drawing::Point(487, 447);
			this->pB_ASVD->Name = L"pB_ASVD";
			this->pB_ASVD->Size = System::Drawing::Size(470, 470);
			this->pB_ASVD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_ASVD->TabIndex = 84;
			this->pB_ASVD->TabStop = false;
			// 
			// pB_ori
			// 
			this->pB_ori->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pB_ori->Location = System::Drawing::Point(9, 447);
			this->pB_ori->Name = L"pB_ori";
			this->pB_ori->Size = System::Drawing::Size(470, 470);
			this->pB_ori->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_ori->TabIndex = 85;
			this->pB_ori->TabStop = false;
			// 
			// txt_src_rows
			// 
			this->txt_src_rows->Location = System::Drawing::Point(133, 48);
			this->txt_src_rows->Name = L"txt_src_rows";
			this->txt_src_rows->Size = System::Drawing::Size(55, 20);
			this->txt_src_rows->TabIndex = 111;
			// 
			// col_dct
			// 
			this->col_dct->Location = System::Drawing::Point(36, 86);
			this->col_dct->Name = L"col_dct";
			this->col_dct->Size = System::Drawing::Size(55, 20);
			this->col_dct->TabIndex = 113;
			// 
			// row_dct
			// 
			this->row_dct->Location = System::Drawing::Point(36, 48);
			this->row_dct->Name = L"row_dct";
			this->row_dct->Size = System::Drawing::Size(55, 20);
			this->row_dct->TabIndex = 112;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label67);
			this->groupBox1->Controls->Add(this->label66);
			this->groupBox1->Controls->Add(this->label65);
			this->groupBox1->Controls->Add(this->label64);
			this->groupBox1->Controls->Add(this->label63);
			this->groupBox1->Controls->Add(this->label62);
			this->groupBox1->Controls->Add(this->txt_src_cols);
			this->groupBox1->Controls->Add(this->row_dct);
			this->groupBox1->Controls->Add(this->txt_src_rows);
			this->groupBox1->Controls->Add(this->col_dct);
			this->groupBox1->Location = System::Drawing::Point(193, 49);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 125);
			this->groupBox1->TabIndex = 114;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"DCT Parameters";
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Location = System::Drawing::Point(98, 51);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(29, 13);
			this->label67->TabIndex = 119;
			this->label67->Text = L"rows";
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(101, 88);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(26, 13);
			this->label66->TabIndex = 118;
			this->label66->Text = L"cols";
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(7, 89);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(26, 13);
			this->label65->TabIndex = 117;
			this->label65->Text = L"cols";
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(5, 51);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(29, 13);
			this->label64->TabIndex = 116;
			this->label64->Text = L"rows";
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(130, 26);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(69, 13);
			this->label63->TabIndex = 115;
			this->label63->Text = L"Result Image";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(17, 23);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(74, 13);
			this->label62->TabIndex = 115;
			this->label62->Text = L"Original Image";
			// 
			// txt_src_cols
			// 
			this->txt_src_cols->Location = System::Drawing::Point(133, 86);
			this->txt_src_cols->Name = L"txt_src_cols";
			this->txt_src_cols->Size = System::Drawing::Size(55, 20);
			this->txt_src_cols->TabIndex = 114;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->nUD_mGa);
			this->groupBox2->Controls->Add(this->nUD_sigma);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Location = System::Drawing::Point(4, 49);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(165, 125);
			this->groupBox2->TabIndex = 115;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ga Parameters";
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel1->Location = System::Drawing::Point(1073, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(839, 183);
			this->panel1->TabIndex = 110;
			// 
			// pB_hist_he
			// 
			this->pB_hist_he->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pB_hist_he->Location = System::Drawing::Point(965, 220);
			this->pB_hist_he->Name = L"pB_hist_he";
			this->pB_hist_he->Size = System::Drawing::Size(470, 185);
			this->pB_hist_he->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_hist_he->TabIndex = 116;
			this->pB_hist_he->TabStop = false;
			// 
			// pB_he
			// 
			this->pB_he->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pB_he->Location = System::Drawing::Point(965, 447);
			this->pB_he->Name = L"pB_he";
			this->pB_he->Size = System::Drawing::Size(470, 470);
			this->pB_he->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_he->TabIndex = 117;
			this->pB_he->TabStop = false;
			// 
			// pB_hist_blur
			// 
			this->pB_hist_blur->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pB_hist_blur->Location = System::Drawing::Point(1445, 220);
			this->pB_hist_blur->Name = L"pB_hist_blur";
			this->pB_hist_blur->Size = System::Drawing::Size(470, 185);
			this->pB_hist_blur->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_hist_blur->TabIndex = 118;
			this->pB_hist_blur->TabStop = false;
			// 
			// pB_blur
			// 
			this->pB_blur->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pB_blur->Location = System::Drawing::Point(1445, 447);
			this->pB_blur->Name = L"pB_blur";
			this->pB_blur->Size = System::Drawing::Size(470, 470);
			this->pB_blur->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_blur->TabIndex = 119;
			this->pB_blur->TabStop = false;
			this->pB_blur->Click += gcnew System::EventHandler(this, &Form1::pB_blur_Click);
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(1144, 420);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(104, 13);
			this->label68->TabIndex = 120;
			this->label68->Text = L"ASDAHE-Lab Image";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Location = System::Drawing::Point(1120, 193);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(154, 13);
			this->label69->TabIndex = 121;
			this->label69->Text = L"ASDAHE-Lab Image Histogram";
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Location = System::Drawing::Point(1651, 420);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(78, 13);
			this->label70->TabIndex = 122;
			this->label70->Text = L"Denoise Image";
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Location = System::Drawing::Point(1616, 193);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(128, 13);
			this->label71->TabIndex = 123;
			this->label71->Text = L"Denoise Image Histogram";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->nsWS);
			this->groupBox3->Controls->Add(this->ntWS);
			this->groupBox3->Controls->Add(this->nHC);
			this->groupBox3->Controls->Add(this->nH);
			this->groupBox3->Location = System::Drawing::Point(415, 51);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(216, 124);
			this->groupBox3->TabIndex = 124;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Denoise Parameters";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(24, 105);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(98, 13);
			this->label8->TabIndex = 123;
			this->label8->Text = L"searchWindowSize";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(16, 79);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(106, 13);
			this->label6->TabIndex = 122;
			this->label6->Text = L"templateWindowSize";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(31, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 13);
			this->label5->TabIndex = 121;
			this->label5->Text = L"color components";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(67, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 120;
			this->label4->Text = L"luminance ";
			// 
			// nsWS
			// 
			this->nsWS->Location = System::Drawing::Point(145, 98);
			this->nsWS->Name = L"nsWS";
			this->nsWS->Size = System::Drawing::Size(65, 20);
			this->nsWS->TabIndex = 3;
			this->nsWS->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
			// 
			// ntWS
			// 
			this->ntWS->Location = System::Drawing::Point(145, 72);
			this->ntWS->Name = L"ntWS";
			this->ntWS->Size = System::Drawing::Size(65, 20);
			this->ntWS->TabIndex = 2;
			this->ntWS->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {3, 0, 0, 0});
			// 
			// nHC
			// 
			this->nHC->Location = System::Drawing::Point(145, 46);
			this->nHC->Name = L"nHC";
			this->nHC->Size = System::Drawing::Size(65, 20);
			this->nHC->TabIndex = 1;
			this->nHC->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {30, 0, 0, 0});
			// 
			// nH
			// 
			this->nH->Location = System::Drawing::Point(145, 19);
			this->nH->Name = L"nH";
			this->nH->Size = System::Drawing::Size(65, 20);
			this->nH->TabIndex = 0;
			this->nH->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {30, 0, 0, 0});
			// 
			// vt1
			// 
			this->vt1->Location = System::Drawing::Point(173, 52);
			this->vt1->Name = L"vt1";
			this->vt1->Size = System::Drawing::Size(29, 20);
			this->vt1->TabIndex = 125;
			this->vt1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// chCb
			// 
			this->chCb->AutoSize = true;
			this->chCb->Location = System::Drawing::Point(13, 87);
			this->chCb->Name = L"chCb";
			this->chCb->Size = System::Drawing::Size(73, 17);
			this->chCb->TabIndex = 2;
			this->chCb->Text = L"channel b";
			this->chCb->UseVisualStyleBackColor = true;
			this->chCb->CheckedChanged += gcnew System::EventHandler(this, &Form1::chCb_CheckedChanged);
			// 
			// chCr
			// 
			this->chCr->AutoSize = true;
			this->chCr->Location = System::Drawing::Point(13, 59);
			this->chCr->Name = L"chCr";
			this->chCr->Size = System::Drawing::Size(73, 17);
			this->chCr->TabIndex = 1;
			this->chCr->Text = L"channel a";
			this->chCr->UseVisualStyleBackColor = true;
			this->chCr->CheckedChanged += gcnew System::EventHandler(this, &Form1::chCr_CheckedChanged);
			// 
			// chY
			// 
			this->chY->AutoSize = true;
			this->chY->Location = System::Drawing::Point(13, 28);
			this->chY->Name = L"chY";
			this->chY->Size = System::Drawing::Size(73, 17);
			this->chY->TabIndex = 0;
			this->chY->Text = L"channel L";
			this->chY->UseVisualStyleBackColor = true;
			this->chY->CheckedChanged += gcnew System::EventHandler(this, &Form1::chY_CheckedChanged);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(10, 24);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(27, 13);
			this->label20->TabIndex = 68;
			this->label20->Text = L"xi_B";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(10, 59);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(28, 13);
			this->label33->TabIndex = 68;
			this->label33->Text = L"xi_G";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(10, 92);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(28, 13);
			this->label46->TabIndex = 68;
			this->label46->Text = L"xi_R";
			// 
			// txt_xiB
			// 
			this->txt_xiB->Location = System::Drawing::Point(36, 21);
			this->txt_xiB->Name = L"txt_xiB";
			this->txt_xiB->Size = System::Drawing::Size(80, 20);
			this->txt_xiB->TabIndex = 69;
			// 
			// txt_xiG
			// 
			this->txt_xiG->Location = System::Drawing::Point(35, 55);
			this->txt_xiG->Name = L"txt_xiG";
			this->txt_xiG->Size = System::Drawing::Size(81, 20);
			this->txt_xiG->TabIndex = 69;
			// 
			// txt_xiR
			// 
			this->txt_xiR->Location = System::Drawing::Point(36, 89);
			this->txt_xiR->Name = L"txt_xiR";
			this->txt_xiR->Size = System::Drawing::Size(80, 20);
			this->txt_xiR->TabIndex = 69;
			// 
			// ASVD
			// 
			this->ASVD->Controls->Add(this->txt_xiR);
			this->ASVD->Controls->Add(this->txt_xiG);
			this->ASVD->Controls->Add(this->txt_xiB);
			this->ASVD->Controls->Add(this->label46);
			this->ASVD->Controls->Add(this->label33);
			this->ASVD->Controls->Add(this->label20);
			this->ASVD->Location = System::Drawing::Point(897, 51);
			this->ASVD->Name = L"ASVD";
			this->ASVD->Size = System::Drawing::Size(122, 125);
			this->ASVD->TabIndex = 79;
			this->ASVD->TabStop = false;
			this->ASVD->Text = L"ASVDD Parameters";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->vt1);
			this->groupBox4->Controls->Add(this->chCr);
			this->groupBox4->Controls->Add(this->chCb);
			this->groupBox4->Controls->Add(this->chY);
			this->groupBox4->Location = System::Drawing::Point(651, 51);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(222, 124);
			this->groupBox4->TabIndex = 125;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Lab Parameters";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1061);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->label71);
			this->Controls->Add(this->label70);
			this->Controls->Add(this->label69);
			this->Controls->Add(this->label68);
			this->Controls->Add(this->pB_blur);
			this->Controls->Add(this->pB_hist_blur);
			this->Controls->Add(this->pB_he);
			this->Controls->Add(this->pB_hist_he);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->lab_result);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lab_ori);
			this->Controls->Add(this->pB_hist_dst);
			this->Controls->Add(this->pB_hist_src);
			this->Controls->Add(this->pB_ASVD);
			this->Controls->Add(this->pB_ori);
			this->Controls->Add(this->ASVD);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUD_sigma))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUD_mGa))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_hist_dst))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_hist_src))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_ASVD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_ori))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_hist_he))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_he))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_hist_blur))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pB_blur))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nsWS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ntWS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nHC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nH))->EndInit();
			this->ASVD->ResumeLayout(false);
			this->ASVD->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

				 openFileDialog->Filter = "Image Files|*.bmp; *.jpg; *.png; *.pgm; *.jpeg|All Files (*.*)|*.*||"; 
				 openFileDialog->Title = "Select a image file"; 
				 openFileDialog->InitialDirectory = "";
				 openFileDialog-> Multiselect = "True"; 

				 int number_of_files;
				 array<System::String^>^ filename_src; // array of filenames
				 if ( openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK )  
				 {
					 filename_src = openFileDialog->FileNames;
					 number_of_files = openFileDialog->FileNames->Length;
				 }
				 else
					 return;
				 RNG rng(255);		
				 int step = 0;
				 while (step < number_of_files)
				 {
					System::String^ OpenFileName;
					OpenFileName = filename_src[step];//duong dan day du, kieu du lieu System::String^

					OpenFileName = OpenFileName->Replace("\\","\\\\");// opencv pathfile is C:\\folder\\filename

					char* imgname;
					imgname = (char*)Marshal::StringToHGlobalAnsi(OpenFileName).ToPointer();
					img_src = imread(imgname);
					
					Mat src;	
					img_src.convertTo(src, CV_32F);

					int m = 2*getOptimalDFTSize((src.rows+1)/2); //on the right border add zero values
					int n = 2*getOptimalDFTSize((src.cols+1)/2); // on the bottom border add zero values
					
					Mat src_padded;
					copyMakeBorder(src, src_padded, 0, m - src.rows, 0, n - src.cols, BORDER_CONSTANT, Scalar::all(0));

					//Split a given color image into three color channels A∈{B,G,R}#1										
					Mat B = Mat_<float>(m,n);
					Mat G = Mat_<float>(m,n);
					Mat R = Mat_<float>(m,n);
					
					//Calculate the average values of each color channel:
					float sumB, sumG, sumR; //sum of Blue. Green, Red channel pixel values#2									
					sumB = 0.0;
					sumG = 0.0;
					sumR = 0.0;
					for (int i = 0;i<img_src.cols;i++)
					{
						for (int j =0; j<img_src.rows;j++)
						{							
							B.at<float>(cv::Point(i, j)) = src_padded.at<Vec3f>(cv::Point(i, j))[0];
							sumB += B.at<float>(cv::Point(i, j)); // sum of all Blue pixel value
							G.at<float>(cv::Point(i, j)) = src_padded.at<Vec3f>(cv::Point(i, j))[1];
							sumG += G.at<float>(cv::Point(i, j));
							R.at<float>(cv::Point(i, j)) = src_padded.at<Vec3f>(cv::Point(i, j))[2];
							sumR += R.at<float>(cv::Point(i, j));							
						}
					}

					float meanB_float, meanG_float, meanR_float; // store mean value of color channels
					meanB_float = sumB/(m*n);
					meanG_float = sumG/(m*n);
					meanR_float = sumR/(m*n);
					
					//Calculate the maximum average values of the three color channels:#3
					float max1 = meanB_float >= meanG_float?meanB_float:meanG_float;
					float max_mean = max1 >= meanR_float?max1:meanR_float;
					
					//Calculate the DCT coefficients matrices of color channels and Gaussian template:#4				
					Mat Ga = Mat(m, n, CV_32F);
					float meanGa = (float)nUD_mGa->Value;
					float sigmaGa = (float)nUD_sigma->Value ;
					randn(Ga, meanGa, sigmaGa);

					Mat dct_Ga;
					dct(Ga,dct_Ga);

					Mat dct_B;
					dct(B,dct_B);

					Mat dct_G;
					dct(G,dct_G);

					Mat dct_R;
					dct(R,dct_R);
									
						
					//Calculate the average values of each DCT coefficients matrices:#5
					float sum_dct_B, sum_dct_G, sum_dct_R; 
					sum_dct_B = 0.0;
					sum_dct_G = 0.0;
					sum_dct_R = 0.0;
					for (int i = 0;i<src.cols;i++)
					{
						for (int j =0; j<src.rows;j++)
						{							
							
							sum_dct_B += fabs(dct_B.at<float>(cv::Point(i, j))); // sum of all Blue pixel value
							sum_dct_G += fabs(dct_G.at<float>(cv::Point(i, j)));			
							sum_dct_R += fabs(dct_R.at<float>(cv::Point(i, j)));														
						}
					}

					float mean_dct_B_float, mean_dct_G_float, mean_dct_R_float; // store mean value of color channels
					mean_dct_B_float = sum_dct_B/(m*n);
					mean_dct_G_float = sum_dct_G/(m*n);
					mean_dct_R_float = sum_dct_R/(m*n);

					//Calculate the maximum average values:#7
					float max_dct_1 = mean_dct_B_float >= mean_dct_G_float?mean_dct_B_float:mean_dct_G_float;
					float max_dct_mean = max_dct_1 >= mean_dct_R_float?max_dct_1:mean_dct_R_float;

					//Calculate SVD of DCT coefficients matrices of color channels and Gaussian template#8
					Mat wGa, uGa,vtGa;
					SVD::compute(dct_Ga,wGa, uGa, vtGa, SVD::NO_UV);
					double minwGa, maxwGa;
					minMaxLoc(wGa, &minwGa, &maxwGa);

					SVD svd(dct_B);
					//double minwB, maxwB;
					//minMaxLoc(svd.w, &minwB, &maxwB);				
					Mat wB, uB, vtB;
					SVD::compute(dct_B,wB,uB,vtB,SVD::FULL_UV);				
					double minwB, maxwB;
					minMaxLoc(wB, &minwB, &maxwB);

					//#9#10
					float xiB =(float)(meanB_float/max_mean)*(max_dct_mean/mean_dct_B_float)*(maxwGa/maxwB);
					
					for (int i = 0;i<svd.w.cols;i++)
					{
						for (int j =0; j<svd.w.rows;j++)
						{
							svd.w.at<float>(cv::Point(i, j))= xiB*(svd.w.at<float>(cv::Point(i, j)));
						}
					}
					for (int i = 0;i<svd.u.cols;i++)
					{
						for (int j =0; j<svd.u.rows;j++)
						{
							svd.u.at<float>(cv::Point(i, j))= uB.at<float>(cv::Point(i, j));
						}
					}
					for (int i = 0;i<svd.vt.cols;i++)
					{
						for (int j =0; j<svd.vt.rows;j++)
						{
							svd.vt.at<float>(cv::Point(i, j))= vtB.at<float>(cv::Point(i, j));
						}
					}
					Mat B_svd = svd.u*Mat::diag(svd.w)*svd.vt;

					Mat wG, uG, vtG;
					SVD::compute(dct_G,wG,uG,vtG,SVD::FULL_UV);				
					double minwG, maxwG;
					minMaxLoc(wG, &minwG, &maxwG);
					
					float xiG = (float)(meanG_float/max_mean)*(max_dct_mean/mean_dct_G_float)*(maxwGa/maxwG);					
					for (int i = 0;i<svd.w.cols;i++)
					{
						for (int j =0; j<svd.w.rows;j++)
						{
							svd.w.at<float>(cv::Point(i, j))= xiG*(wG.at<float>(cv::Point(i, j)));
						}
					}
					for (int i = 0;i<svd.u.cols;i++)
					{
						for (int j =0; j<svd.u.rows;j++)
						{
							svd.u.at<float>(cv::Point(i, j))= uG.at<float>(cv::Point(i, j));
						}
					}
					for (int i = 0;i<svd.vt.cols;i++)
					{
						for (int j =0; j<svd.vt.rows;j++)
						{
							svd.vt.at<float>(cv::Point(i, j))= vtG.at<float>(cv::Point(i, j));
						}
					}
					Mat G_svd = svd.u*Mat::diag(svd.w)*svd.vt;
					
					Mat wR, uR, vtR;
					SVD::compute(dct_R,wR,uR,vtR,SVD::FULL_UV);				
					double minwR, maxwR;
					minMaxLoc(wR, &minwR, &maxwR);
					
					float xiR = (float)(meanR_float/max_mean)*(max_dct_mean/mean_dct_R_float)*(maxwGa/maxwR);
					for (int i = 0;i<svd.w.cols;i++)
					{
						for (int j =0; j<svd.w.rows;j++)
						{
							svd.w.at<float>(cv::Point(i, j))= xiR*(wR.at<float>(cv::Point(i, j)));
						}
					}
					for (int i = 0;i<svd.u.cols;i++)
					{
						for (int j =0; j<svd.u.rows;j++)
						{
						svd.u.at<float>(cv::Point(i, j))= uR.at<float>(cv::Point(i, j));
						}
					}
					for (int i = 0;i<svd.vt.cols;i++)
					{
						for (int j =0; j<svd.vt.rows;j++)
						{
							svd.vt.at<float>(cv::Point(i, j))= vtR.at<float>(cv::Point(i, j));
						}
					}

					Mat R_svd = svd.u*Mat::diag(svd.w)*svd.vt;
					
					//Compute the updated color channels based on the invert dct of compensated DCT coefficients matrices
					Mat NewB1, NewG1, NewR1;
					idct(B_svd,NewB1, 0);
					idct(G_svd,NewG1, 0);
					idct(R_svd,NewR1, 0);

					img_svd = src.clone();
					
					for (int i = 0;i<src.cols;i++)
					{
						for (int j =0; j<src.rows;j++)
						{							
							img_svd.at<Vec3f>(cv::Point(i, j))[0] = NewB1.at<float>(cv::Point(i, j));
							img_svd.at<Vec3f>(cv::Point(i, j))[1] = NewG1.at<float>(cv::Point(i, j));
							img_svd.at<Vec3f>(cv::Point(i, j))[2] = NewR1.at<float>(cv::Point(i, j));
						}
					}


					txt_xiB->Text = xiB.ToString();txt_xiB->Refresh();
					txt_xiG->Text = xiG.ToString();txt_xiG->Refresh();
					txt_xiR->Text = xiR.ToString();txt_xiR->Refresh();

					normalize(img_svd, img_svd, 0, 255, CV_MINMAX);
					img_svd.convertTo(img_svd, CV_8UC3);
					imwrite("C:\\Users\\thuong han\\Desktop\\report_lab\\img_svd.bmp",img_svd);
					Mat lab_image;
					cvtColor(img_svd, lab_image, CV_BGR2Lab);

					// Extract the L channel
					vector<cv::Mat> lab_planes(3);
					split(lab_image, lab_planes);  // now we have the L image in lab_planes[0]

					// apply the CLAHE algorithm to the L channel
					Ptr<cv::CLAHE> clahe = cv::createCLAHE();
					clahe->setClipLimit(5);
					Mat dst10;
					clahe->apply(lab_planes[vt], dst10);

					// Merge the the color planes back into an Lab image
					dst10.copyTo(lab_planes[vt]);
					merge(lab_planes, lab_image);

					// convert back to RGB
					//Mat image_clahe;
					cvtColor(lab_image, image_clahe, CV_Lab2BGR);
					imwrite("C:\\Users\\thuong han\\Desktop\\report_lab\\image_clahe.bmp",image_clahe);
					imwrite("C:\\Users\\thuong han\\Desktop\\report_lab\\img_src.bmp",img_src);
					float h = (float)nH->Value;
					float hC = (float)nHC->Value;
					int tWS = (float)ntWS->Value;
					int sWS = (float)ntWS->Value;

					fastNlMeansDenoisingColored(image_clahe, denoise, h, hC, tWS, sWS);
					//imshow("1",denoise);
					//fastNlMeansDenoisingColoredMulti(hist_equalized_image, denoise, 3, 3, 30, 30, 3, 15);
					//imshow("2",denoise);
					//fastNlMeansDenoisingColoredMulti(hist_equalized_image,denoise,65,129,3,3,3,15);
					
					char* savename;
					savename = (char*)Marshal::StringToHGlobalAnsi("C:\\Users\\thuong han\\Desktop\\report_lab\\" + (step+1).ToString()+".bmp").ToPointer();
					imwrite( savename, denoise );
					 //imwrite("C:\\Users\\thuong han\\Desktop\\draft\\image_clahe.jpg",image_clahe);

					Mat hist = drawhistogram(img_src);
					Mat hist_svd = drawhistogram(img_svd);
					Mat hist_HE = drawhistogram(image_clahe);
					Mat hist_blur = drawhistogram(denoise);

					int row_s = (src.rows/4)*4;
					int col_s = (src.cols/4)*4;

					txt_src_rows->Text = m.ToString();txt_src_rows->Refresh();
					txt_src_cols->Text = n.ToString();txt_src_cols->Refresh();

					row_dct->Text = row_s.ToString();row_dct->Refresh();
					col_dct->Text = col_s.ToString();col_dct->Refresh();

					Mat img_s = Mat(row_s, col_s, img_src.type());
					resize(img_src, img_s, img_s.size(), 0, 0, INTER_LINEAR);

					pB_ori->Image  = gcnew    
					System::Drawing::Bitmap(img_s.size().width,img_s.size().height,img_s.step,
					System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) img_s.data);
					pB_ori->Refresh();

					Mat img_svd_s = Mat(row_s, col_s, img_src.type());
					resize(img_svd, img_svd_s, img_svd_s.size(), 0, 0, INTER_LINEAR);

					pB_ASVD->Image  = gcnew    
					System::Drawing::Bitmap(img_svd_s.size().width,img_svd_s.size().height,img_svd_s.step,
					System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) img_svd_s.data);
					pB_ASVD->Refresh();

					Mat img_he_s = Mat(row_s, col_s, image_clahe.type());
					resize(image_clahe, img_he_s, img_he_s.size(), 0, 0, INTER_LINEAR);

					pB_he->Image  = gcnew    
						System::Drawing::Bitmap(img_he_s.size().width,img_he_s.size().height,img_he_s.step,
						System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) img_he_s.data);
					pB_he->Refresh();

					Mat img_blur_s = Mat(row_s, col_s, denoise.type());
					resize(denoise, img_blur_s, img_blur_s.size(), 0, 0, INTER_LINEAR);

					pB_blur->Image  = gcnew    
						System::Drawing::Bitmap(img_blur_s.size().width,img_blur_s.size().height,img_blur_s.step,
						System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) img_blur_s.data);
					pB_blur->Refresh();
					
					pB_hist_src->Image  = gcnew    
					System::Drawing::Bitmap(hist.size().width,hist.size().height,hist.step,
					System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) hist.data);
					pB_hist_src->Refresh();

					pB_hist_dst->Image  = gcnew    
					System::Drawing::Bitmap(hist_svd.size().width,hist_svd.size().height,hist_svd.step,
					System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) hist_svd.data);
					pB_hist_dst->Refresh();

					pB_hist_he->Image  = gcnew    
						System::Drawing::Bitmap(hist_HE.size().width,hist_HE.size().height,hist_HE.step,
						System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) hist_HE.data);
					pB_hist_he->Refresh();

					pB_hist_blur->Image  = gcnew    
						System::Drawing::Bitmap(hist_blur.size().width,hist_blur.size().height,hist_blur.step,
						System::Drawing::Imaging::PixelFormat::Format24bppRgb,(System::IntPtr) hist_blur.data);
					pB_hist_blur->Refresh();

					step++;
				}
			 }
	private: System::Void chY_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (chY->Checked) 
				 {
					 vt=0;
					 chCr->Checked = false;
					 chCb->Checked = false;
					 vt1->Text = vt.ToString();
				 }
				 
				
			 }
private: System::Void chCr_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (chCr->Checked) 
			 {
				 vt=1;
				 chY->Checked = false;
				 chCb->Checked = false;
				 vt1->Text = vt.ToString();
			 }
		 }
private: System::Void chCb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (chCb->Checked) 
			 {
				 vt=2;
				 chCr->Checked = false;
				 chY->Checked = false;
				 vt1->Text = vt.ToString();
			 }
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 chY->Checked = true;
		 }
private: System::Void pB_blur_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Mat resized1, resized2, resized3, resized4;
			 resize(img_src, resized1, cv::Size(512, 512), INTER_LINEAR);
			 imshow("ORI", resized1);
			 resize(img_svd, resized2, cv::Size(512, 512), INTER_LINEAR);
			 imshow("ASVDD", resized2);
			 resize(image_clahe, resized3, cv::Size(512, 512), INTER_LINEAR);
			 imshow("HE", resized3);
			 resize(denoise, resized4, cv::Size(512, 512), INTER_LINEAR);
			 imshow("denoise", resized4);		 
		 }
};
}

