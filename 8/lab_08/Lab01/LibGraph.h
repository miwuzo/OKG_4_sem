#ifndef LIBGRAPH
#define LIBGRAPH 1
const double pi = 3.14159;
typedef double(*pfunc2)(double, double);	// ��������� �� �������

struct CSizeD
{
	double cx;
	double cy;
};
//-----------------------------------------------------------------------------------
struct CRectD
{
	double left;
	double top;
	double right;
	double bottom;
	CRectD() { left = top = right = bottom = 0; };
	CRectD(double l, double t, double r, double b);
	void SetRectD(double l, double t, double r, double b);
	CSizeD SizeD();
};

//------------------------------------------------------------------------------------

CMatrix SpaceToWindow(CRectD& rs, CRect& rw);
// ���������� ������� ��������� ��������� �� ������� � �������
// rs - ������� � ������� ����������� - double
// rw - ������� � ������� ����������� - int
//-----------------------------------------------------------------------------------
void SetMyMode(CDC& dc, CRect& RS, CRect& RW);  //MFC
// ������������� ����� ����������� MM_ANISOTROPIC � ��� ���������
// dc - ������ �� ����� CDC MFC
// RS -  ������� � ������� ����������� - int
// RW -	 ������� � ������� ����������� - int  
//---------------------------------------------------------------------------------
CMatrix CreateTranslate2D(double dx, double dy);
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� 
// �� dx �� ��� X � �� dy �� ��� Y � ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� �� -dx ��� X � �� -dy �� ��� Y ��� ������������� ��������� ������� 
//----------------------------------------------------------------------------------
CMatrix CreateTranslate3D(double dx, double dy, double dz);
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� 
// �� dx �� ��� X, �� dy �� ��� Y,�� dz �� ��� Z � ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� �� -dx ��� X,�� -dy �� ��� Y, �� -dz �� ��� Z 
// ��� ������������� ��������� ������� 
//---------------------------------------------------------------------------------
CMatrix CreateRotate2D(double fi);
// ��������� ������� ��� �������������� ��������� ������� ��� ��� ��������
// �� ���� fi (��� fi>0 ������ ������� �������)� ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� �� ���� -fi ��� ������������� ��������� ������� 
// fi - ���� � ��������

//--------------------------------------------------------------------------------
CMatrix CreateRotate3DZ(double fi);
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� ������ ��� Z
// �� ���� fi (��� fi>0 ������ ������� �������)� ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� ������ ��� Z �� ���� -fi ��� ������������� ��������� ������� 
// fi - ���� � ��������

//--------------------------------------------------------------------------------
CMatrix CreateRotate3DX(double fi);
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� ������ ��� X
// �� ���� fi (��� fi>0 ������ ������� �������)� ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� ������ ��� X �� ���� -fi ��� ������������� ��������� ������� 
// fi - ���� � ��������
//--------------------------------------------------------------------------------
CMatrix CreateRotate3DY(double fi);
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� ������ ��� Y
// �� ���� fi (��� fi>0 ������ ������� �������)� ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� ������ ��� Y �� ���� -fi ��� ������������� ��������� ������� 
// fi - ���� � ��������

//--------------------------------------------------------------------------------
CMatrix CreateViewCoord(double r, double fi, double q);
// ������� ������� ��������� ����� �� ������� ������� ��������� � �������
// (r,fi,q)- ���������� ����� ����������(������ ������� ������� ���������)
// � ������� ����������� ������� ���������( ���� fi � q � ��������)
//-------------------------------------------------------------------------------
CMatrix VectorMult(CMatrix& V1, CMatrix& V2);
// ��������� ��������� ������������ �������� V1 � V2
//-------------------------------------------------------------------------------
double ScalarMult(CMatrix& V1, CMatrix& V2);
// ��������� ��������� ������������ �������� V1 � V2
//-------------------------------------------------------------------------------
double ModVec(CMatrix& V);
// ��������� ������ ������� V
//------------------------------------------------------------------------------
double CosV1V2(CMatrix& V1, CMatrix& V2);
// ��������� ������� ���� ����� ��������� V1 � V2
//-----------------------------------------------------------------------------
double AngleV1V2(CMatrix& V1, CMatrix& V2);
// ��������� ���� ����� ��������� V1 � V2 � ��������
//-----------------------------------------------------------------------------------
CMatrix SphereToCart(CMatrix& PView);
// ����������� ����������� ���������� PView  ����� � ���������
// PView(0) - r
// PView(1) - fi - ������(������ �� ��� X), ����.
// PView(2) - q - ����(�������� ��� Z), ����.
// ���������: R(0)- x, R(1)- y, R(2)- z	
//-----------------------------------------------------------------------------------
void GetProjection(CRectD& RS, CMatrix& Data, CMatrix& PView, CRectD& PR);
// ��������� ���������� �������� ������������� ������ �������������� �� 
// ��������� XY � ������� ������� ���������
// Data - ������� ������
// RS - ������� �� ��������� XY, �� ������� ��������� ������������ �����������
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// PR - ��������
//-----------------------------------------------------------------------------------

#endif

