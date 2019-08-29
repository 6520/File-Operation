#include "FileOperation.h"
using namespace std;
FileOperation::FileOperation()
{

}
FileOperation::~FileOperation()
{

}
void FileOperation::Split(const string& str,vector<double>& tokens,const string&delimiters)
{
	string ::size_type lastpos=str.find_first_not_of(delimiters,0);
    string ::size_type pos=str.find_first_of(delimiters,lastpos);
    while (string::npos!=pos||string::npos!=lastpos)
    {
        string strtd=str.substr(lastpos,pos-lastpos);
        tokens.push_back(atof(strtd.c_str()));
        lastpos=str.find_first_not_of(delimiters,pos);
        pos=str.find_first_of(delimiters,lastpos);
    }
}

void FileOperation::Split(const string& str,vector<string>& tokens,const string& delimiters)//function for split
{

    string::size_type lastpos=str.find_first_not_of(delimiters,0);
    string::size_type pos=str.find_first_of(delimiters,lastpos);
    while (string::npos!=pos||string::npos!=lastpos)
    {
        tokens.push_back(str.substr(lastpos,pos - lastpos));
        lastpos=str.find_first_not_of(delimiters,pos);
        pos=str.find_first_of(delimiters,lastpos);
    }
}
void FileOperation::Split(const string& str,vector<int>& tokens,const string& delimiters)
{
    string ::size_type lastpos=str.find_first_not_of(delimiters,0);
    string ::size_type pos=str.find_first_of(delimiters,lastpos);
    while (string::npos!=pos||string::npos!=lastpos)
    {
        string strtd=str.substr(lastpos,pos-lastpos);
        tokens.push_back(atoi(strtd.c_str()));
        lastpos=str.find_first_not_of(delimiters,pos);
        pos=str.find_first_of(delimiters,lastpos);
    }
}

void FileOperation::ReadMatrix(string file,double *Matrix,int length)
{
	string line;	
	vector<double> templine;
	ifstream read;
	read.open(file.c_str());
	int j=0;
	if(!read.is_open())
	{
		cout<<"Open error"<<file<<endl;
	}
	while(getline(read,line))
	{
		templine.clear();
		Split(line,templine," ");
		int col=templine.size();
		for(int i=0;i<col;i++)
		{			
			Matrix[j*col+i]=templine[i];			
		}
		j++;
		if(j>length)
		{
			cout<<"row nummber is greater than length"<<endl;
			break;
		}
	}
	read.close();
}

void FileOperation::ReadMatrix(string file,int *Matrix,int length)
{
	cout<<"------read-------"<<endl;
	string line;	
	vector<int> templine;
	ifstream read;
	read.open(file.c_str());
	int j=0;
	if(!read.is_open())
	{
		cout<<"Open error"<<file<<endl;
	}
	while(getline(read,line))
	{
		templine.clear();
		Split(line,templine," ");
		int col=templine.size();
		for(int i=0;i<col;i++)
		{
			Matrix[j*col+i]=templine[i];			
		}
		j++;
		if(j>length)
		{
			cout<<"row nummber is greater than length"<<endl;
			break;
		}
	}
	read.close();
}

void FileOperation::ReadMatrix(string file,vector<double> &templine)
{
	string line;	
	templine.clear();
	ifstream read;
	read.open(file.c_str());	
	if(!read.is_open())
	{
		cout<<"Open error"<<file<<endl;
	}
	while(getline(read,line))
	{		
		Split(line,templine," ");		
	}
	read.close();
}

double *FileOperation::ReadMatrix(string file,int &row,int &col)
{
	double *Matrix;
	string line;	
	vector<double> templine;
	
	templine.clear();
	ifstream read;
	read.open(file.c_str());
	int j=0;
	if(!read.is_open())
	{
		cout<<"Open error"<<file<<endl;
	}
	while(getline(read,line))
	{			
		Split(line,templine," ");		
		j++;
		
	}
	row=j;
	col=templine.size();
	col=col/row;
	Matrix=matrixoper->VectToP(templine);	
	read.close();
	return Matrix;
}

int *FileOperation::ReadMatrix(string file,int &row,int &col,string type)
{
	int *Matrix;
	string line;	
	vector<int> templine;
	templine.clear();
	ifstream read;
	read.open(file.c_str());
	int j=0;
	if(!read.is_open())
	{
		cout<<"Open error"<<file<<endl;
	}
	while(getline(read,line))
	{		
		Split(line,templine," ");		
		j++;		
	}
	row=j;
	col=templine.size();
	col=col/row;
	Matrix=matrixoper->VectToP(templine);
	read.close();
	return Matrix;
}

/*template <class type>
type *FileOperation::ReadMatrix(string file,int &row,int &col);
{
	type *Matrix;
	string line;	
	vector<type> templine;
	templine.clear();
	ifstream read;
	read.open(file.c_str());
	int j=0;
	if(!read.is_open())
	{
		cout<<"Open error"<<file<<endl;
	}
	while(getline(read,line))
	{		
		Split(line,templine," ");		
		j++;		
	}
	row=j;
	col=templine.size();
	col=col/row;
	Matrix=matrixoper->VectToP(templine);
	read.close();
	return Matrix;
}*/

void FileOperation::WriteMatrix(string file,double *Matrix,int row,int col)
{
	ofstream write;
	write.open(file,ios::trunc);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			write<<Matrix[i*col+j]<<" ";
		}
		write<<endl;
	}
	write.close();
}

void FileOperation::WriteMatrix(string file,vector<string> vect,int row,int col)
{
	ofstream write;
	write.open(file,ios::trunc);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			write<<vect.at(i*col+j)<<" ";
		}
		write<<endl;
	}
	write.close();
}

void FileOperation::WriteMatrix(string file,vector<int> vect,int row,int col)
{
	ofstream write;
	write.open(file,ios::trunc);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			write<<vect.at(i*col+j)<<" ";
		}
		write<<endl;
	}
	write.close();
}

void FileOperation::WriteMatrix(string file,vector<double> vect,int row,int col)
{
	ofstream write;
	write.open(file,ios::trunc);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			write<<vect.at(i*col+j)<<" ";
		}
		write<<endl;
	}
	write.close();
}

void FileOperation::SplitFile(string file,string selectword,int stp,int length,string out)//splite files according to specific strings
{
	string line;	
	ifstream read(file.c_str());
	ofstream write;
	write.open(out.c_str(),ios::trunc);
	vector<string> templine;
	if (!read.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	while(getline(read,line))
	{
		templine.clear();
		string spword=line.substr(stp,length);
		if (spword==selectword)
		{
			write<<line<<endl;
		}
	}
		
	
}

void FileOperation::MakePedigree()
{
	ofstream write;
	string path,filename,line,splitcondition,allorpart,wfile,nfile;
	vector<string> templine,ind,male,female,time,addind,nind,wind,mfped,tempimf,sped;
	vector<string> ::iterator location;
	ind.clear();
	male.clear();
	female.clear();
	time.clear();	
	mfped.clear();
	int m,f,maloc,feloc;
	cout<<"-----please input path and filename-----"<<endl;
	cin>>path>>filename;
	string readaddress=path+filename;
	string writeaddress=path+filename+".ped";
	ifstream read(readaddress.c_str());		
	write.open(writeaddress.c_str(),ios::trunc);
	if (!read.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	while(getline(read,line))
	{
		templine.clear();
		sped.push_back(line);
		Split(line,templine," ");			
		ind.push_back(templine.at(0));
		male.push_back(templine.at(1));
		female.push_back(templine.at(2));
		time.push_back(templine.at(3));			
	}	
	for(int i=0;i<male.size();i++)
	{
		m=f=0;
		string ma=male.at(i);
		string fe=female.at(i);
		//RecPed(ma,sped,mfped);
		//RecPed(fe,sped,mfped);
		
		for(int j=0;j<ind.size();j++)
		{
			string in=ind.at(j);
			if(!ma.compare(in))
			{
				m++;
			}
			if(!fe.compare(in))
			{
				f++;
			}
		}
		if(m==0)
		{
			addind.push_back(ma);
		}
		if(f==0)
		{
			addind.push_back(fe);
		}
	}
	sort(addind.begin(),addind.end());
	addind.erase(unique(addind.begin(),addind.end()),addind.end());
	for(int i=0;i<addind.size();i++)
	{
		ind.insert(ind.begin(),addind.at(i));
		male.insert(male.begin(),"0");
		female.insert(female.begin(),"0");
		//ind.push_front(addind.at(i));
		//male.push_front(0);
		//female.push_front(0);
	}
	for(int i=0;i<ind.size();i++)
	{
		write<<i+1<<" ";
		string nma=male.at(i);
		string nfe=female.at(i);
		if(nma=="0")
		{
			write<<0<<" ";
		}
		else
		{
			location=find(ind.begin(),ind.end(),nma);
			maloc=location-ind.begin();
			write<<maloc+1<<" ";
		}
		if(nfe=="0")
		{
			write<<0<<endl;
		}
		else
		{
			location=find(ind.begin(),ind.end(),nfe);
			feloc=location-ind.begin();
			write<<feloc+1<<endl;
		}
	}
}
	

void FileOperation::SelectPedigree(string fsource,string fneed,string out)
{	
	vector<string> ::iterator location;
	int m,f,maloc,feloc;
	string line;	
	ifstream readw(fsource.c_str());
	ifstream readn(fneed.c_str());
	ofstream write;
	write.open(out.c_str(),ios::trunc);	
	vector<string> ped,mfped,nvect,wvect,templine,mvect,fvect;
	mfped.clear();
	ped.clear();
	wvect.clear();
	nvect.clear();
	mvect.clear();
	fvect.clear();
	if (!readw.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	if (!readn.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	while(getline(readn,line))
	{
		templine.clear();
		Split(line,templine,",");		
		nvect.push_back(templine.at(0));
		//cout<<nvect.size()<<endl;
		//cout<<templine.at(0)<<endl;
	}	
	while(getline(readw,line))
	{
		string tem;
		templine.clear();
		Split(line,templine,",");
		tem=templine.at(0);
		//tem=tem.substr(0,15);
		//cout<<tem<<endl;
		wvect.push_back(tem);
		tem=templine.at(1);
		//tem=tem.substr(0,15);
		mvect.push_back(tem);
		tem=templine.at(2);
		//tem=tem.substr(0,15);
		fvect.push_back(tem);
		//cout<<templine.at(0)<<endl;
	}
	cout<<"read complete"<<endl;
	for(int i=0;i<nvect.size();i++)
	{				
		location=find(wvect.begin(),wvect.end(),nvect[i]);
		//cout<<distance(wvect.begin(),location)<<endl;
		if(location!=wvect.end())
		{
			maloc=distance(wvect.begin(),location);			
			string temp=wvect.at(maloc)+" "+mvect.at(maloc)+" "+fvect.at(maloc);
			
			//cout<<temp<<endl;
			ped.push_back(temp);		
			string ma=mvect.at(maloc);
			//ma=ma.substr(0,15);
			string fe=fvect.at(maloc);
			//fe=fe.substr(0,15);
			if(ma!="0")
			{				
				RecPed(ma,wvect,mvect,fvect,mfped);
			}
			if(fe!="0")
			{
				RecPed(fe,wvect,mvect,fvect,mfped);
			}
		}
		else
		{
			string tp=nvect[i]+" 0 0";
			ped.push_back(tp);
		}
	}		
	sort(mfped.begin(),mfped.end());
	mfped.erase(unique(mfped.begin(),mfped.end()),mfped.end());
	matrixoper->BubbleSortPed(mfped);
	for(int i=0;i<mfped.size();i++)
	{
		write<<mfped.at(i)<<endl;
		//cout<<mfped.at(i)<<endl;
	}
	for(int i=0;i<ped.size();i++)
	{
		//cout<<ped.at(i)<<endl;
		write<<ped.at(i)<<endl;
	}
	TransPed(out);
			 
}
	
void FileOperation::SelectSibs(string fped,string famat,string fgmat)
{
	string line;
	int rownum=0,row,col,lnum;
	double *gmat,*amat;
	double afssum,fsnum,ahfsum,hfnum,aphsum,phnum,gfssum,ghfsum,gphsum;
	afssum=fsnum=ahfsum=hfnum=aphsum=phnum=gfssum=ghfsum=gphsum=0;	
	ifstream read;
	ofstream write;	
	read.open(fped.c_str());	
	vector<int> templine,ind,ma,fe;
	ind.clear();
	ma.clear();
	fe.clear();
	gmat=ReadMatrix(fgmat,row,col);
	amat=ReadMatrix(famat,row,col);
	if(!read.is_open())
	{
		cout<<"Open error"<<fped<<endl;
	}
	while(getline(read,line))
	{
		
		templine.clear();
		Split(line,templine," ");
		ind.push_back(templine.at(0));
		ma.push_back(templine.at(1));
		fe.push_back(templine.at(2));		
		rownum++;
	}
	lnum=rownum-row; 
	for(int i=0;i<ma.size();i++)
	{
		for(int j=0;j<ma.size();j++)
		{
			if((ma[i]!=0&&fe[i]!=0)&&(i>=lnum&&j>=lnum))
			{
				if(ma[i]==ma[j]&&fe[i]==fe[j])
				{
					if(i!=j)
					{
						afssum+=amat[(i-lnum)*col+(j-lnum)];
						gfssum+=gmat[(i-lnum)*col+(j-lnum)];
						fsnum++;
						//cout<<i<<" "<<j<<" : "<<amat[(i-lnum)*col+(j-lnum)]<<" "<<gmat[(i-lnum)*col+(j-lnum)]<<endl;
					}
				}
				else if((ma[i]==ma[j]&&fe[i]!=fe[j])||(ma[i]!=ma[j]&&fe[i]==fe[j]))
				{
					ahfsum+=amat[(i-lnum)*col+(j-lnum)];
					ghfsum+=gmat[(i-lnum)*col+(j-lnum)];
					hfnum++;
					//write<<"Half Sibs: "<<i<<" "<<j<<endl;
				}
				else if(ind[i]==ma[j]||ind[i]==fe[j])
				{
					aphsum+=amat[(i-lnum)*col+(j-lnum)];
					gphsum+=gmat[(i-lnum)*col+(j-lnum)];
					phnum++;
					//write<<"parenthood: "<<i<<" "<<j<<endl;
				}
			}
			
		}
	}
	//!!!!!need a func to get mean and std!!!!!;
	cout<<"Full Sibs(amat and gmat): "<<afssum/fsnum<<"  "<<gfssum/fsnum<<endl;
	cout<<"Half Sibs(amat and gmat): "<<ahfsum/hfnum<<"  "<<ghfsum/hfnum<<endl;
	cout<<"parenthood(amat and gmat): "<<aphsum/phnum<<"  "<<gphsum/phnum<<endl;
}

void FileOperation::RecPed(string indnum,vector<string> wvect,vector<string> mvect,vector<string> fvect,vector<string> &ped)
{
	vector<string> templine;
	vector<string> ::iterator location;
	int maloc;
	location=find(wvect.begin(),wvect.end(),indnum);
	if(location==wvect.end())
	{
		string tp=indnum+" 0 0";
		ped.insert(ped.begin(),tp);
		//cout<<tp<<endl;
	}
	else 
	{		
		maloc=distance(wvect.begin(),location);
		string temp=wvect.at(maloc)+" "+mvect.at(maloc)+" "+fvect.at(maloc);
		ped.insert(ped.begin(),temp);		
		string ma=mvect.at(maloc);
		string fe=fvect.at(maloc);
		//ma=ma.substr(0,15);			
		//fe=fe.substr(0,15);
		if(ma!="0")
		{
			RecPed(ma,wvect,mvect,fvect,ped);
		}
		if(fe!="0")
		{
			RecPed(fe,wvect,mvect,fvect,ped);
		}
	}
}

void FileOperation::TransPed(string file)
{
	string line;
	vector<string> ::iterator location;
	int maloc,feloc;
	ifstream read(file.c_str());
	ofstream write;
	string ofile=file+"Nstyle";
	write.open(ofile.c_str(),ios::trunc);
	vector<string> templine,ind,male,female;
	templine.clear();
	ind.clear();
	male.clear();
	female.clear();
	if(!read.is_open())
	{
		cout<<"-----open file error-----"<<endl;
	}
	while(getline(read,line))
	{
		templine.clear();
		string tem;
		Split(line,templine," ");
		tem=templine.at(0);
		tem=tem.substr(0,15);
		
		ind.push_back(tem);
		tem=templine.at(1);
		tem=tem.substr(0,15);
		
		male.push_back(tem);
		tem=templine.at(2);
		tem=tem.substr(0,15);
		
		female.push_back(tem);
	}
	for(int i=0;i<ind.size();i++)
	{
		location=find(ind.begin(),ind.end(),male.at(i));
		if(location!=ind.end())
		{			
			maloc=distance(ind.begin(),location);
			//cout<<maloc<<endl;
		}
		else 
		{
			maloc=-1;
		}
		location=find(ind.begin(),ind.end(),female.at(i));
		if(location!=ind.end())
		{			
			feloc=distance(ind.begin(),location);
			//cout<<feloc<<endl;
		}
		else 
		{
			feloc=-1;
		}		
		write<<i+1<<" "<<maloc+1<<" "<<feloc+1<<endl;
	}
}

void FileOperation::SubFile(string style,string file,int delcol,string splitcondition,string out)
{
	string line;	
	ifstream read(file.c_str());
	ofstream write;
	write.open(out.c_str(),ios::trunc);
	vector<string> templine;
	if (!read.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	while(getline(read,line))
	{
		int num=line.size();
		line=line.substr(0,num-1);
		templine.clear();
		Split(line,templine,splitcondition);
		if(style=="-b"||style=="-back")
		{			
			for(int i=delcol;i<templine.size();i++)
			{
				write<<templine.at(i)<<" ";
			}
			write<<endl;
		}
		else if(style=="-f"||style=="-front")
		{
			for(int i=0;i<delcol;i++)
			{
				write<<templine.at(i)<<" ";
			}
			write<<endl;
		}
	}
}

void FileOperation::SubFileFront()
{
	string path,filename,line,splitcondition;
	int delcol;
	cout<<"-----please input path and filename-----"<<endl;
	cin>>path;
	cin>>filename;
	cout<<"-----please input the nummber of colums you want to keep and the split conditions-----"<<endl;
	cin>>delcol;
	cin>>splitcondition;
	string readaddress=path+filename;
	string writeaddress=path+filename+"subfilefront";
	ifstream read(readaddress.c_str());
	ofstream write;
	write.open(writeaddress.c_str(),ios::trunc);
	vector<string> templine;
	if (!read.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	while(getline(read,line))
	{
		templine.clear();
		Split(line,templine,splitcondition);
		for(int i=0;i<delcol;i++)
		{
			write<<templine.at(i)<<" ";
		}
		write<<endl;
	}
}

void FileOperation::CSVToPed(string file,string out)
{
	string line;
	int row=1;	
	ifstream read(file.c_str());
	ofstream write;
	write.open(out.c_str(),ios::trunc);
	vector<string> templine;
	if (!read.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	while(getline(read,line))
	{
		templine.clear();
		Split(line,templine,",");
		write<<row;
		for(int i=0;i<templine.size();i++)
		{
			if(i==1)
			{
				write<<" 0 0 0 0";
			}
			else if(i==2)
			{
				string ATCG=templine.at(i);
				for(int j=0;j<ATCG.size();j++)
				{
					write<<" "<<ATCG.substr(j,1);
				}
				write<<endl;
			}
			else 
			{
				write<<" "<<templine.at(i);
			}			
		}		
		row++;
	}
}

void FileOperation::EffiectivePedigree()
{
	string path,filenameM,filenameEind,line,splitcondition;	
	cout<<"-----please input path and filename(Matrix file and Effiective individual file)-----"<<endl;
	cin>>path;
	cin>>filenameM>>filenameEind;	
	string readaddressM=path+filenameM;
	string readaddressEind=path+filenameEind;
	string writeaddress=path+filenameM+"subeffind";
	ifstream readM(readaddressM.c_str());
	ifstream readEind(readaddressEind.c_str());
	ofstream write;
	write.open(writeaddress.c_str(),ios::trunc);
	vector<string> templine;
	vector<int> tempEind;
	tempEind.clear();
	int row=0;
	if (!readM.is_open())
	{
		cout<<"open fileM error!"<<endl;
	}
	if (!readEind.is_open())
	{
		cout<<"open fileEind error!"<<endl;
	}
	while(getline(readEind,line))
	{		
		Split(line,tempEind," ");
	}
	//cout<<tempEind.size()<<endl;
	while(getline(readM,line))
	{
		templine.clear();		
		for(int j=0;j<tempEind.size();j++)
		{
			if(tempEind.at(j)==61545)			
			if(row==tempEind.at(j))
			{	cout<<row<<endl;
				Split(line,templine," ");	
				for(int i=0;i<templine.size();i++)
				{
					for(int k=0;k<tempEind.size();k++)
					{
						if(i==tempEind.at(k))
						{
							write<<templine.at(i)<<" ";
						}
					}
				}
				write<<endl;
			}			
		}
		//cout<<row<<endl;
		row++;
	}
}

void FileOperation::SubMat(double *Mat,int row,int col,int subr,int subc,string sub,string file)
{
	if(sub=="d"||sub=="D")
	{
		ofstream write;	
		write.open(file.c_str(),ios::trunc);
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(i>=row-subr&&j>=col-subc)
				{
					write<<Mat[i*col+j]<<" ";
				}
			}
			if(i>=row-subr)
			{
				write<<endl;
			}
		}
	}
	else if(sub=="a"||sub=="A")
	{
		
	}
	else if(sub=="b"||sub=="B")
	{
		
	}
	else if(sub=="c"||sub=="C")
	{
		
	}
}

void FileOperation::ReadGenoFile(vector<string> &vGeno,int &row,int &col)//read genotype file as a matrix and did quality control(call rate).
{
	string path,filename,line,splitcondition,indline;	
	cout<<"-----please input path and filename-----"<<endl;
	cin>>path>>filename;	
	string readaddress=path+filename;
	string writeaddress=path+filename+".log";
	ifstream read(readaddress.c_str());
	ofstream write;
	write.open(writeaddress.c_str(),ios::trunc);
	vector<string> Matrix,templine;
	vector<double> misssnp;
	Matrix.clear();
	misssnp.clear();
	vGeno.clear();
	int miss,delind,delsnp,misspos;
	double missrate;
	row=0;
	delind=delsnp=0;
	if (!read.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	while(getline(read,line))
	{
		//cout<<"-----"<<endl;
		miss=0;
		templine.clear();
		Split(line,templine," ");		
		string temp=templine.at(0);
		col=temp.size();
		//cout<<col<<endl;
		for(int i=0;i<col;i++)
		{
						
			string snp=temp.substr(i,1);
			//templine.push_back(snp);
			if(snp=="0"||snp=="-")
			{
				miss++;
			}			
		}
		missrate=static_cast<double>(miss)/col;
		if(missrate<0.1)
		{
			//for(int i=0;i<col;i++)
			//{
				//string snp=line.substr(i,1);
				Matrix.push_back(temp);
				//cout<<temp<<endl;
			//}
		}		
		else
		{
			write<<"row num: "<<row<<" missrate(individual): "<<missrate<<endl;
			delind++;
		}		
		row++;
	}
	//cout<<"row and col: "<<row<<" "<<col<<endl;
	for(int j=0;j<col;j=j+2)
	{
		miss=0;
		for(int i=0;i<row-delind;i++)
		{			
			indline=Matrix.at(i);
			//cout<<indline<<endl;
			if(indline.substr(j,1)=="0"||indline.substr(j,1)=="-")
			{
				miss++;
			}
			/*else if(indline.substr(j+1,1)=="0"||indline.substr(j+1,1)=="-")
			{
				miss++;
			}*/
		}
		missrate=static_cast<double>(miss)/(row-delind);
		//cout<<"miss and row; "<<miss<<" "<<row<<endl;
		if(missrate>0.1)
		{
			//cout<<"missrate and col; "<<missrate<<" "<<j<<endl;
			write<<"col num: "<<j<<" missrate(loci): "<<missrate<<endl;
			misssnp.push_back(j);
			delsnp++;			
		}
		//cout<<delsnp<<endl;
	}
	/*for(int i=0;i<row-delind;i++)
	{
		indline=Matrix.at(i);
		for(int j=0;j<delsnp;j++)
		{
			int pos=misssnp.at(j);
			indline.erase(pos,);
		}
		vGeno.push_back(snpindline);
	}*/
	
	//ofstream oot;
	//oot.open("./data/ootvg",ios::trunc);
	for(int i=0;i<row-delind;i++)
	{
		for(int j=0;j<col;j=j+2)
		{
			misspos=0;
			for(int k=0;k<delsnp;k++)
			{						
				if(misssnp.at(k)==j)
				{
					misspos++;
				}			
			}
			if(misspos==0)
			{
				indline=Matrix.at(i);
				string snpindline=indline.substr(j,2);
				vGeno.push_back(snpindline);
				//cout<<"indline.size: "<<indline.size()<<endl;
				//cout<<snpindline<<endl;
				//oot<<snpindline<<" ";
				//cout<<"||"<<endl;
			}
			
		}
		//cout<<vGeno.size()<<endl;
		//cout<<endl;
	}		
	row=row-delind;
	col=(col-(delsnp*2))/2;	
}

void FileOperation::ReadGenoFileT(string file,vector<string> &vGeno,int &row,int &col)
{
	string line,splitcondition,indline;	
	string writeaddress=file+".log";
	ifstream read(file.c_str());
	ofstream write;
	write.open(writeaddress.c_str(),ios::trunc);
	vector<string> Matrix,templine;
	//vector<double> misssnp;	
	Matrix.clear();
	//misssnp.clear();
	vGeno.clear();
	int miss,delind,delsnp,misspos;
	double missrate;
	row=0;
	delind=delsnp=0;
	if (!read.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	while(getline(read,line))
	{		
		miss=0;
		templine.clear();
		Split(line,templine," ");		
		string temp=templine.at(0);
		col=temp.size();		
		for(int i=0;i<col;i++)
		{						
			string snp=temp.substr(i,1);			
			if(snp=="0"||snp=="-")
			{
				miss++;				
			}			
		}
		missrate=static_cast<double>(miss)/col;		
		if(missrate<0.1)
		{
			for(int i=0;i<col;i=i+2)
			{
				string snp=line.substr(i,2);
				Matrix.push_back(snp);				
			}
		}		
		else
		{
			write<<"row num: "<<row<<" missrate(individual): "<<missrate<<endl;
			delind++;
		}		
		row++;
	}
	row=row-delind;
	col=col/2;
	matrixoper->Trans(Matrix,row,col);	
	for(int i=0;i<row;i++)
	{
		miss=0;
		for(int j=0;j<col;j++)
		{			
			string snp=Matrix.at(i*col+j);			
			if(snp=="00")
			{
				miss++;
			}			
		}
		missrate=static_cast<double>(miss)/col;		
		if(missrate<0.1)
		{
			for(int k=0;k<col;k++)
			{			
				string snp=Matrix.at(i*col+k);
				vGeno.push_back(snp);
			}					
		}
		else 
		{
			write<<"col num: "<<i<<" missrate(loci): "<<missrate<<endl;			
			delsnp++;	
		}		
	}
	row=row-delsnp;
}

void FileOperation::ConsistencyOfGameticPhase(string filea,string fileb,string out)
{
	vector<string> ::iterator location;
	vector<string> templinea,templineb,samea,sameb;
	vector<double> tempres,rvaluea,rvalueb;
	vector<int> distv;
	samea.clear();sameb.clear();rvaluea.clear();rvalueb.clear();distv.clear();
	
	vector<double> dist1,dist2,dist3,dist4,dist5,dist6,dist7,dist8,dist9,dist10,dist11,dist12,dist13,dist14,dist15,dist16,dist17,dist18,dist19,dist20,dist21,dist22,dist23,dist24,dist25;
	dist1.clear();dist1.clear();dist2.clear();dist3.clear();dist4.clear();dist5.clear();dist6.clear();dist7.clear();dist8.clear();dist9.clear();dist10.clear();dist11.clear();dist12.clear();dist13.clear();
	dist14.clear();dist15.clear();dist16.clear();dist17.clear();dist18.clear();dist19;dist20.clear();dist21.clear();dist22.clear();dist23.clear();dist24.clear();dist25.clear();
	vector<double> distb1,distb2,distb3,distb4,distb5,distb6,distb7,distb8,distb9,distb10,distb11,distb12,distb13,distb14,distb15,distb16,distb17,distb18,distb19,distb20,distb21,distb22,distb23,distb24,distb25;
	distb1.clear();distb1.clear();distb2.clear();distb3.clear();distb4.clear();distb5.clear();distb6.clear();distb7.clear();distb8.clear();distb9.clear();distb10.clear();distb11.clear();distb12.clear();distb13.clear();
	distb14.clear();distb15.clear();distb16.clear();distb17.clear();distb18.clear();distb19;distb20.clear();distb21.clear();distb22.clear();distb23.clear();distb24.clear();distb25.clear();
	
	string linea,lineb;
	double r;
	int maloc,d1,d2,distan;
	tempres.clear();
	ifstream reada(filea.c_str());
	ifstream readb(fileb.c_str());
	if (!reada.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	if (!readb.is_open())
	{
		cout<<"open file error!"<<endl;
	}
	cout<<"-----"<<endl;
	//////
	while(getline(reada,linea))
	{
		templinea.clear();		
		Split(linea,templinea," ");	
		if(templinea.at(0)!="0")
		{
			if(templinea.at(6)!="nan")
			{
				string chrsnp=templinea.at(0)+templinea.at(2)+templinea.at(3)+templinea.at(5);
				samea.push_back(chrsnp);
				d1=atoi(templinea.at(1).c_str());
				d2=atoi(templinea.at(4).c_str());
				distan=d2-d1;				
				if (distan<0)
				{
					distan=-distan;
				}
				distv.push_back(distan);
				rvaluea.push_back(atof(templinea.at(6).c_str()));
							
			}
		}
	}
	while(getline(readb,lineb))
	{
		templineb.clear();		
		Split(lineb,templineb," ");	
		if(templineb.at(0)!="0")
		{
			if(templineb.at(6)!="nan")
			{
				string chrsnp=templineb.at(0)+templineb.at(2)+templineb.at(3)+templineb.at(5);
				sameb.push_back(chrsnp);				
				rvalueb.push_back(atof(templineb.at(6).c_str()));
							
			}
		}
	}
	cout<<"-----read complete-----"<<endl;
	for(int i=0;i<samea.size();i++)
	{
		location=find(sameb.begin(),sameb.end(),samea[i]);
		if(location!=sameb.end())
		{
			maloc=distance(sameb.begin(),location);
			int dist=distv.at(i);
			if(dist<10000)
			{
				dist1.push_back(rvaluea.at(i));
				distb1.push_back(rvalueb.at(maloc));
			}
			else if(dist>=10000&&dist<20000)
			{
				dist2.push_back(rvaluea.at(i));
				distb2.push_back(rvalueb.at(maloc));
			}
			else if(dist>=20000&&dist<30000)
			{
				dist3.push_back(rvaluea.at(i));
				distb3.push_back(rvalueb.at(maloc));
			}
			else if(dist>=30000&&dist<40000)
			{
				dist4.push_back(rvaluea.at(i));
				distb4.push_back(rvalueb.at(maloc));
			}
			else if(dist>=40000&&dist<50000)
			{
				dist5.push_back(rvaluea.at(i));
				distb5.push_back(rvalueb.at(maloc));
			}
			else if(dist>=50000&&dist<60000)
			{
				dist6.push_back(rvaluea.at(i));
				distb6.push_back(rvalueb.at(maloc));
			}
			else if(dist>=60000&&dist<70000)
			{
				dist7.push_back(rvaluea.at(i));
				distb7.push_back(rvalueb.at(maloc));
			}
			else if(dist>=70000&&dist<80000)
			{
				dist8.push_back(rvaluea.at(i));
				distb8.push_back(rvalueb.at(maloc));
			}
			else if(dist>=80000&&dist<90000)
			{
				dist9.push_back(rvaluea.at(i));
				distb9.push_back(rvalueb.at(maloc));
			}
			else if(dist>=90000&&dist<100000)
			{
				dist10.push_back(rvaluea.at(i));
				distb10.push_back(rvalueb.at(maloc));
			}
			else if(dist>=100000&&dist<110000)
			{
				dist11.push_back(rvaluea.at(i));
				distb11.push_back(rvalueb.at(maloc));
			}
			else if(dist>=110000&&dist<120000)
			{
				dist12.push_back(rvaluea.at(i));
				distb12.push_back(rvalueb.at(maloc));
			}
			else if(dist>=120000&&dist<130000)
			{
				dist13.push_back(rvaluea.at(i));
				distb13.push_back(rvalueb.at(maloc));
			}
			else if(dist>=130000&&dist<140000)
			{
				dist14.push_back(rvaluea.at(i));
				distb14.push_back(rvalueb.at(maloc));
			}
			else if(dist>=140000&&dist<150000)
			{
				dist15.push_back(rvaluea.at(i));
				distb15.push_back(rvalueb.at(maloc));
			}
			else if(dist>=150000&&dist<160000)
			{
				dist16.push_back(rvaluea.at(i));
				distb16.push_back(rvalueb.at(maloc));
			}
			else if(dist>=160000&&dist<170000)
			{
				dist17.push_back(rvaluea.at(i));
				distb17.push_back(rvalueb.at(maloc));
			}
			else if(dist>=170000&&dist<180000)
			{
				dist18.push_back(rvaluea.at(i));
				distb18.push_back(rvalueb.at(maloc));
			}
			else if(dist>=180000&&dist<190000)
			{
				dist19.push_back(rvaluea.at(i));
				distb19.push_back(rvalueb.at(maloc));
			}
			else if(dist>=190000&&dist<200000)
			{
				dist20.push_back(rvaluea.at(i));
				distb20.push_back(rvalueb.at(maloc));
			}
			else if(dist>=200000&&dist<210000)
			{
				dist21.push_back(rvaluea.at(i));
				distb21.push_back(rvalueb.at(maloc));
			}
			else if(dist>=210000&&dist<220000)
			{
				dist22.push_back(rvaluea.at(i));
				distb22.push_back(rvalueb.at(maloc));
			}
			else if(dist>=220000&&dist<230000)
			{
				dist23.push_back(rvaluea.at(i));
				distb23.push_back(rvalueb.at(maloc));
			}
			else if(dist>=230000&&dist<240000)
			{
				dist24.push_back(rvaluea.at(i));
				distb24.push_back(rvalueb.at(maloc));
			}
			else if(dist>=240000&&dist<250000)
			{
				dist25.push_back(rvaluea.at(i));
				distb25.push_back(rvalueb.at(maloc));
			}	
		}
	}
	
	//cout<<endl;
	cout<<dist1.size()<<"  "<<distb1.size()<<endl;
	//matrixoper->CutsizeV(dist1,distb1);
	WriteMatrix("./data/dist1",dist1,dist1.size(),1);
	//WriteMatrix("./data/distb1",distb11,54362,1);
	//cout<<dist11.size()<<"  "<<distb11.size()<<endl;
	r=matrixcomp->PPMCC_T(dist1,distb1);
	tempres.push_back(0.1);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist2,distb2);
	r=matrixcomp->PPMCC_T(dist2,distb2);
	tempres.push_back(0.2);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist3,distb3);
	r=matrixcomp->PPMCC_T(dist3,distb3);
	tempres.push_back(0.3);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist4,distb4);
	r=matrixcomp->PPMCC_T(dist4,distb4);
	tempres.push_back(0.4);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist5,distb5);
	r=matrixcomp->PPMCC_T(dist5,distb5);
	tempres.push_back(0.5);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist6,distb6);
	r=matrixcomp->PPMCC_T(dist6,distb6);
	tempres.push_back(0.6);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist7,distb7);
	r=matrixcomp->PPMCC_T(dist7,distb7);
	tempres.push_back(0.7);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist8,distb8);
	r=matrixcomp->PPMCC_T(dist8,distb8);
	tempres.push_back(0.8);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist9,distb9);
	r=matrixcomp->PPMCC_T(dist9,distb9);
	tempres.push_back(0.9);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist10,distb10);
	r=matrixcomp->PPMCC_T(dist10,distb10);
	tempres.push_back(1.0);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist11,distb11);
	r=matrixcomp->PPMCC_T(dist11,distb11);
	tempres.push_back(1.1);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist12,distb12);
	r=matrixcomp->PPMCC_T(dist12,distb12);
	tempres.push_back(1.2);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist13,distb13);
	r=matrixcomp->PPMCC_T(dist13,distb13);
	tempres.push_back(1.3);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist14,distb14);
	r=matrixcomp->PPMCC_T(dist14,distb14);
	tempres.push_back(1.4);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist15,distb15);
	r=matrixcomp->PPMCC_T(dist15,distb15);
	tempres.push_back(1.5);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist16,distb16);
	r=matrixcomp->PPMCC_T(dist16,distb16);
	tempres.push_back(1.6);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist17,distb17);
	r=matrixcomp->PPMCC_T(dist17,distb17);
	tempres.push_back(1.7);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist18,distb18);
	r=matrixcomp->PPMCC_T(dist18,distb18);
	tempres.push_back(1.8);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist19,distb19);
	r=matrixcomp->PPMCC_T(dist19,distb19);
	tempres.push_back(1.9);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist20,distb20);
	r=matrixcomp->PPMCC_T(dist20,distb20);
	tempres.push_back(2.0);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist21,distb21);
	r=matrixcomp->PPMCC_T(dist21,distb21);
	tempres.push_back(2.1);
	tempres.push_back(r);
	matrixoper->CutsizeV(dist22,distb22);
	r=matrixcomp->PPMCC_T(dist22,distb22);
	tempres.push_back(2.2);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist23,distb23);
	r=matrixcomp->PPMCC_T(dist23,distb23);
	tempres.push_back(2.3);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist24,distb24);
	r=matrixcomp->PPMCC_T(dist24,distb24);
	tempres.push_back(2.4);
	tempres.push_back(r);
	//matrixoper->CutsizeV(dist25,distb25);
	r=matrixcomp->PPMCC_T(dist25,distb25);
	tempres.push_back(2.5);
	tempres.push_back(r);	
	WriteMatrix(out,tempres,25,2);
	
	
}
