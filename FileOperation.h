#ifndef FILEOPERATION_H
#define FILEOPERATION_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <stdio.h>
#include <algorithm>
#include "MatrixOperation.h"
#include "MatrixComputation.h"
using namespace std;
class FileOperation
{
	public:
		FileOperation();
		~FileOperation();
		void Split(const string &str,vector<string> &tokens,const string &delimiters);
		void Split(const string &str,vector<double> &tokens,const string &delimiters);
		void Split(const string &str,vector<int> &tokens,const string &delimiters);
		
		void ReadMatrix(string file,double *Matrix,int length);
		void ReadMatrix(string file,int *Matrix,int length);
		double *ReadMatrix(string file,int &row,int &col);
		int *ReadMatrix(string file,int &row,int &col,string type);
		void ReadMatrix(string file,vector<double> &templine);
		//template <class type>
		//type *ReadMatrix(string file,int &row,int &col);
		void ReadGenoFile(vector<string> &vGeno,int &row,int &col);
		void ReadGenoFileT(string file,vector<string> &vGeno,int &row,int &col);
		
		void WriteMatrix(string file,double *Matrix,int row,int col);
		void WriteMatrix(string file,vector<string> vect,int row,int col);
		void WriteMatrix(string file,vector<int> vect,int row,int col);
		void WriteMatrix(string file,vector<double> vect,int row,int col);
		void MakePedigree();
		void SelectPedigree(string fsource,string fneed,string out);
		void SelectSibs(string fped,string famat,string fgmat);
		void RecPed(string indnum,vector<string> wvect,vector<string> mvect,vector<string> fvect,vector<string> &ped);
		void TransPed(string file);
		void SubMat(double *Mat,int row,int col,int subr,int subc,string sub,string file);
		void ConsistencyOfGameticPhase(string filea,string fileb,string out);
		
		void SplitFile(string file,string selectword,int stp,int length,string out);
		void SubFile(string style,string file,int delcol,string splitcondition,string out);
		void SubFileFront();
		void CSVToPed(string file,string out);
		void EffiectivePedigree();
	protected:
	private:
	MatrixOperation *matrixoper=new MatrixOperation();
	MatrixComputation *matrixcomp=new MatrixComputation();
	
};
#endif // FILEOPERATION_H
