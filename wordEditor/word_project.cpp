#include "word_project.h"


word_project::word_project(void)
{
}
word_project::~word_project(void)
{
}

int word_project::function_1()
{

	ifstream infile_1("c:\\1_in_1.txt");
		if(!infile_1)
			{
				cout<<"Sorry can't find article c:\1_in_1.txt"<<endl;
				return -1;
				//���޷������ĵ����ݣ���������򣬷���-1
			}
	ifstream infile_2("c:\\1_in_2.txt");
		if(!infile_2)
			{
				cout<<"Sorry can't find article c:\1_in_2.txt"<<endl;
				return -1;
				//���޷������ĵ����ݣ���������򣬷���-1
			}

	string str_1,str_2;
	set<string> word_except;
	while(infile_2>>str_2)
		{
			word_except.insert(str_2);
	//������Ҫ�ų��ĵ��ʺͱ��	
	}

	map<string,int> words;
	while(infile_1>>str_1)
		{
			int str_length=str_1.size();
			if((str_1[str_length-1]<='z'&&str_1[str_length-1]>='a')||(str_1[str_length-1]=='\''))
				{
			
				}
			else
				{
					string substring=str_1.substr(0,str_length-1);
					str_1=substring;
				}
		//�жϵ������һλ�Ǳ��ʱ���������ַ���ȥ�����

			if(word_except.count(str_1))
				{
					continue;
					//�����ʳ������ų������б���ʱ������ǰ���ʵ�ѭ������ʹ�øõ���
				}
		
			if(words[str_1]==0)
				{
					words[str_1]++;
					//���ʵ�һ�γ���ʱ���Զ����ֵ�������key���ҳ��ִ���+1
				}
			else
				{
					words[str_1]++;
				}
		}

	map<string,int>::iterator it=words.begin();
		ofstream outfile_1("c:\\1_out_1.txt");
		for(;it!=words.end();++it)
			{
				outfile_1<<it->first<<' '<<it->second<<endl;
				//������ֵ������map
			}
		it=words.begin();
		//itָ��ص���ͷ
		multimap<int,string> another_words;
		//����multimap��Ŵ�Ƶ����
		for(;it!=words.end();++it)
			{
				another_words.insert(make_pair(it->second,it->first));
			//��map�е�ÿ��pair�ߵ�˳������multimap
			}
		multimap<int,string>::iterator itt=another_words.begin();
			ofstream outfile_2("c:\\1_out_2.txt");
			for(;itt!=another_words.end();++itt)
			{
				outfile_2<<itt->first<<' '<<itt->second<<endl;
				//�������Ƶ�����multimap
			}

			cout<<"����ͳ�ƺʹ�Ƶ������ѳɹ�������"<<endl;
			cout<<"����ͳ�ƣ�C:\1_out_1.txt"<<endl;
			cout<<"��Ƶ����C:\1_out_2.txt"<<endl;
			return 0;
}

int word_project::function_2()
{			
	vector<string> comp_words;
	ifstream infile("c:\\1_in_1.txt");
	while(!infile)
		{
			cout<<"Sorry can't find article c:\1_in_1.txt"<<endl;
				return -1;
				//���޷������ĵ����ݣ���������򣬷���-1
		}
	string str;
	int count=0;
	while(infile>>str)
		{
			int str_length=str.size();
			if((str[str_length-1]<='z'&&str[str_length-1]>='a')||(str[str_length-1]=='\''))
				{
			
				}
			else
				{
					string substring=str.substr(0,str_length-1);
					str=substring;
				}
			//�жϵ������һλ�Ǳ��ʱ���������ַ���ȥ�����

			vector<string>::iterator result = find(comp_words.begin(), comp_words.end(), str); 
			if(result!=comp_words.end())
				{
					continue;
					//�������Ѵ��ڣ�����������ѭ��
				}


			if(count==0)
				{
					comp_words.push_back(str);
					count=1;
					continue;
					//��һ�γ��ֵ��ʷ���
				}
			else
				{
					int str_length=str.size();
					for(int pos=0;pos<=(comp_words.size()-1);pos++)
						{
							if(str_length<(comp_words[pos].size()))
								{
									comp_words.insert(comp_words.begin()+pos,str);
									break;								
								}
							if(str_length>(comp_words[pos].size()))
								{	
									if(pos==comp_words.size()-1)
										{
											comp_words.insert(comp_words.end(),str);
											break;
										}									
									continue;							
								}
							int temp=pos;int num=0;
							if(str_length==(comp_words[pos].size()))
								{
									for(;(temp<=comp_words.size()-1)&&str_length==(comp_words[temp].size());temp++)
										{		
											if(str[0]<comp_words[temp][0])
												{
													comp_words.insert(comp_words.begin()+temp,str);
													num=1;
													break;
												//ʵ����ͬ���ȱȽ�
												}
											else
											{
												continue; 
											}
										}	
								}
							
							if(num==0)
								{
									comp_words.insert(comp_words.begin()+temp,str);
									break;
								}	
							
							if(str[0]<comp_words[temp+1][0])
							{
								break;
							}
					//ʵ������ĸ��ͬʱ������
					}	
			
				}
		}		
			vector<string>::iterator it=comp_words.begin();
			ofstream outfile("c:\\1_out_3.txt");
			for(;it!=comp_words.end();++it)
				{
					outfile<<*it<<endl;
				//������ĵ�
				}
		cout<<"�Զ��������Ѳ���: c:\1_out_3.txt"<<endl;

}