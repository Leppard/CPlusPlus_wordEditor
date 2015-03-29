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
				//若无法读入文档内容，则结束程序，返回-1
			}
	ifstream infile_2("c:\\1_in_2.txt");
		if(!infile_2)
			{
				cout<<"Sorry can't find article c:\1_in_2.txt"<<endl;
				return -1;
				//若无法读入文档内容，则结束程序，返回-1
			}

	string str_1,str_2;
	set<string> word_except;
	while(infile_2>>str_2)
		{
			word_except.insert(str_2);
	//生成需要排除的单词和标点	
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
		//判断单词最后一位是标点时，生成子字符串去掉标点

			if(word_except.count(str_1))
				{
					continue;
					//当单词出现在排除单词列表中时跳过当前单词的循环，不使用该单词
				}
		
			if(words[str_1]==0)
				{
					words[str_1]++;
					//单词第一次出现时，自动在字典里生成key，且出现次数+1
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
				//输出按字典排序的map
			}
		it=words.begin();
		//it指针回到开头
		multimap<int,string> another_words;
		//生成multimap存放词频排序
		for(;it!=words.end();++it)
			{
				another_words.insert(make_pair(it->second,it->first));
			//将map中的每个pair颠倒顺序后放入multimap
			}
		multimap<int,string>::iterator itt=another_words.begin();
			ofstream outfile_2("c:\\1_out_2.txt");
			for(;itt!=another_words.end();++itt)
			{
				outfile_2<<itt->first<<' '<<itt->second<<endl;
				//输出按词频排序的multimap
			}

			cout<<"次数统计和词频排序均已成功产生！"<<endl;
			cout<<"次数统计：C:\1_out_1.txt"<<endl;
			cout<<"词频排序：C:\1_out_2.txt"<<endl;
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
				//若无法读入文档内容，则结束程序，返回-1
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
			//判断单词最后一位是标点时，生成子字符串去掉标点

			vector<string>::iterator result = find(comp_words.begin(), comp_words.end(), str); 
			if(result!=comp_words.end())
				{
					continue;
					//若单词已存在，则跳过本次循环
				}


			if(count==0)
				{
					comp_words.push_back(str);
					count=1;
					continue;
					//第一次出现单词放入
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
												//实现相同长度比较
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
					//实现首字母相同时的排序
					}	
			
				}
		}		
			vector<string>::iterator it=comp_words.begin();
			ofstream outfile("c:\\1_out_3.txt");
			for(;it!=comp_words.end();++it)
				{
					outfile<<*it<<endl;
				//输出到文档
				}
		cout<<"自定义排序已产生: c:\1_out_3.txt"<<endl;

}