#include <iostream>
#include <time.h>
#include "FileOperation.h"
#include "MatrixConstruct.h"
#include "MatrixComputation.h"
#include <string>
#include <vector>
using namespace std;
int main(int argc,const char *argv[])
{
	vector<string> parameter;
	parameter.clear();
	string func=argv[1];
	for(int i=2;i<argc;i++)
	{
		parameter.push_back(argv[i]);
	}
	void SelectFunc(string func,vector<string> parameter);
	SelectFunc(func,parameter);	
	return 0;
}

void SelectFunc(string func,vector<string> parameter)
{
	FileOperation *fileoper=new FileOperation();
	MatrixConstruct *matrixconst=new MatrixConstruct();
	MatrixComputation *matrixcomp=new MatrixComputation();
	
	if(func=="SplitFile"||func=="-spf")
	{
		string file,selectword,out;
		int stp,length;
		file=parameter.at(0);
		selectword=parameter.at(1);
		stp=atoi(parameter.at(2).c_str());
		length=atoi(parameter.at(3).c_str());
		out=parameter.at(4);		
		fileoper->SplitFile(file,selectword,stp,length,out);
	}
	else if(func=="SubFile"||func=="-sbf")
	{
		string style,file,splitcondition,out;
		int delcol;
		style=parameter.at(0);
		file=parameter.at(1);
		delcol=atoi(parameter.at(2).c_str());
		splitcondition=parameter.at(3);
		out=parameter.at(4);
		fileoper->SubFile(style,file,delcol,splitcondition,out);
	}
	else if(func=="ConstructG"||func=="-cg")
	{
		string ofile="./data/";
		string filename;
		int row=0,col=0;
		double *GMatrix;		
		GMatrix=matrixconst->ConstructG(row,col);
		cout<<"-----please input out filename-----"<<endl;
		cin>>filename;
		ofile=ofile+filename;
		fileoper->WriteMatrix(ofile,GMatrix,row,row);
	}
	else if(func=="ConstructGT"||func=="-cgt")
	{
		string file,out;
		int row,col;
		double *GMatrix;
		file=parameter.at(0);
		out=parameter.at(1);
		GMatrix=matrixconst->ConstructGT(file,row,col,out);
	}
	else if(func=="ConstructA"||func=="-ca")
	{
		string file,out,filename;
		int row,col,num,*source;		
		double *A;
		file=parameter.at(0);
		num=atoi(parameter.at(1).c_str());
		out=parameter.at(2);		
		source=fileoper->ReadMatrix(file,row,col,"I");
		A=new double[row*row];
		matrixconst->ConstructA(source,row,A);		
		fileoper->SubMat(A,row,row,num,num,"d",out);
		//fileoper->WriteMatrix(ofile,A,length,length);
	}
	else if(func=="PPMCC"||func=="-pcc")
	{
		string filea,fileg;
		filea=parameter.at(0);
		fileg=parameter.at(1);		
		double *am,*gm;
		int row,col;
		am=fileoper->ReadMatrix(filea,row,col);
		gm=fileoper->ReadMatrix(fileg,row,col);		
		cout<<"-----read complete-----"<<endl;
		double r=matrixcomp->PPMCC(am,gm,row,col);		
		cout<<"row,col and pcc: "<<row<<" "<<col<<" "<<r<<endl;
	}
	else if(func=="PPMCCv"||func=="-pccv")
	{
		string filea,fileg;
		filea=parameter.at(0);
		fileg=parameter.at(1);			
		vector<double> am,gm;		
		fileoper->ReadMatrix(filea,am);
		fileoper->ReadMatrix(fileg,gm);		
		cout<<"-----read complete-----"<<endl;
		double r=matrixcomp->PPMCC_T(am,gm);
		cout<<"pcc: "<<r<<endl;
	}
	else if(func=="CSVToPed"||func=="-ctp")
	{
		string file,out;
		file=parameter.at(0);
		out=parameter.at(1);
		fileoper->CSVToPed(file,out);
	}	
	else if(func=="EffiectivePedigree"||func=="-ep")
	{
		fileoper->EffiectivePedigree();
	}
	
	else if(func=="SelectPedigree"||func=="-sp")
	{
		string fsource,fneed,out;
		fsource=parameter.at(0);
		fneed=parameter.at(1);
		out=parameter.at(2);
		fileoper->SelectPedigree(fsource,fneed,out);
		
	}
	
	else if(func=="SelectSibs"||func=="-ss")
	{
		string fped,famat,fgmat;
		fped=parameter.at(0);
		famat=parameter.at(1);
		fgmat=parameter.at(2);
		fileoper->SelectSibs(fped,famat,fgmat);
	}
	
	else if(func=="ConsistencyOfGameticPhase"||func=="-cgp")
	{
		string filea,fileb,out;		
		filea=parameter.at(0);
		fileb=parameter.at(1);
		out=parameter.at(2);		
		fileoper->ConsistencyOfGameticPhase(filea,fileb,out);
	}
	
	else if(func=="-h"||func=="-help")
	{
		cout<<"-----Commands list and function-----"<<endl<<endl;
		
		cout<<"   -spf SplitFile parameter: file,selectword,stp,length,out"<<endl;
		cout<<"-----If the words start at stp and length char equal to selectword,keep this line-----"<<endl<<endl;
		
		cout<<"   -sbf SubFile parameter: style,file,delcol,splitcondition,out"<<endl;
		cout<<"-----If style is -f(-b),then save the front(back) delcol(col-decol) column with split condition  if the split condition is space character, please use double quote(like \"space\")-----"<<endl<<endl;
		
		cout<<"   -pcc(-pccv) PPMCC(PPMCC_T) parameter: filea,fileg"<<endl;
		cout<<"-----Two matrix file----"<<endl<<endl;
		
		cout<<"   -ctp CSVToPed parameter: file,out"<<endl;
		cout<<"-----Change the file to ped format to make it easier to use plink to generate VCF-----"<<endl<<endl;
		
		cout<<"   -ss SelectSibs parameter: fped,famat,fgmat"<<endl;
		cout<<"-----Three file(ped,Amat Gmat)-----"<<endl<<endl;
		
		cout<<"   -sp SelectPedigree parameter: fsource,fneed,out"<<endl;
		cout<<"-----Three file(source file(individual male female),need file(this individual is need to make pedigree and must in birth order),out file)-----"<<endl<<endl;
		
		cout<<"   -cgt ConstructGT parameter: file,out"<<endl;
		cout<<"-----Two file(read file and write result matrix file)-----"<<endl<<endl;
		
		cout<<"   -ca ConstructA parameter: file,num,out"<<endl;
		cout<<"-----read pedigree file construct A matrix and keep the number of you need from Amat-----"<<endl<<endl;
	}
	else 
	{
		cout<<"-----func name error!-----"<<endl;
	}	
}

