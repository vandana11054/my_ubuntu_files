

#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include"functions.hpp"
#include"RFormat.hpp"
#include"SFormat.hpp"
#include"IFormat.hpp"
#include"BFormat.hpp"
#include"UFormat.hpp"
#include"JFormat.hpp"

using namespace std;

int main()
{
   vector<pair<int,string>> label; //A vector of pairs for storing label name,line
				   //number pairs

   string in;               //string for storing instruction in binary format 
                            //each argument of input stored as individual string                     
   string func;
   string rd;
   string rs1; 
   string rs2;
   string imm;
   int count=0;          //variable for line-number
   int labelMatch =0;    //variable for storing line-numbers containing valid labels
   ifstream one("input.s");    //open input.s using file stream
			       //while file has not reached end of file
   while(!one.eof()){     //loop  for storing instructions with valid labels
     string test;         // string to store line test
     string tfunc;        // test func string to verify input is label or operation
     getline(one,test);
     if(!test.empty()){
        labelMatch+=1;
	int k=0;
	bool empty = true;   // variable to check empty space after reading an argument 
        for(;k<test.length();k++){
	if(isspace(test[k]) && empty) k++; //if space before argument go to next char
        if(!isspace(test[k])){            
	          empty = false;
                  tfunc.push_back(test[k]); //push non empty argument 
		}
	else break;
	}  
           if(tfunc.find(':')!= string::npos){ //If string is a label
	    tfunc.pop_back();             //remove colon
            label.push_back(make_pair(labelMatch,tfunc));
	    //make a pair of label name and line number of label
      }	
     }
     tfunc.erase(); //after each line execution erase func argument and instruction
     test.erase();
   }
   one.close();   //close input.s
   ifstream inp("input.s"); // input.s file opened using file stream as inp
   while(!inp.eof()){   //while file has not reached end of file
   string line;         // string for storing each line of input.s
   getline(inp,line);   // Read current line 
   count+=1;            // line number incremented
   if(!line.empty()){
   string check;
   int i=0;
   for(int m=0;m<label.size();m++){
      if(count == label[m].first)  { //if line contains label
	    string ignoreLabel;      
	 // string to ignore labels by pushing to it instead of pushing to function argument
            bool before = true;    // variable to check space is before or after argument  
	    for(;i<line.length();i++){
	if(isspace(line[i]) && before) i++;
        if(!isspace(line[i])){
	          before = false;
                  ignoreLabel.push_back(line[i]);//ignore that label argument
		}
	else break;
	    }
	    i++;
      }
   }
   bool space = true;    // variable to check space is before or after argument  
   for(;i<line.length();i++){ //loop for storing func argument
	if(isspace(line[i]) && space) i++;
        if(!isspace(line[i])){
	          space = false;
                  func.push_back(line[i]);// store first argument of input line as func 
		}
	else break;  //after first input taken break from for loop
   }
   check = Opcode(func); //variable containing opcode of func
   if(check == "invalid" && (!func.empty())){
      cout<<"Invalid operation in line "<<count<<" "<<func<<"?"<<endl; 
      // If first argument (after ignoring labels) is not valid operation
      cout<<"Execution terminated"<<endl;
      return 1;
   }
   if(func.empty()){ // If func argument is empty 
       cout<<"Empty label(or operation) found in line "<<count<<endl;
       cout<<"Execution terminated"<<endl;
       return 1;
   }
   // calling respective format functions based on Opcode of first argument
   // each function call with required strings to store respective arguments 
   else  if(check == "0110011"){
	  in = Rformat(line,rd,rs1,rs2,func,in,i,count);
   }
   else if(check == "0100011") {
         in = Sformat(line,rs1,rs2,func,imm,in,i,count);
   }                                         
   else if (check=="0000011" || check == "1100111"){
	   in= ILformat(line,rs1,func,imm,rd,in,i,count);
   }
   else if (check == "0010011"){
          in= IGformat(line,rs1,func,imm,rd,in,i,count);
   }
   else if(check == "1100011"){
          in = Bformat(line,rs1,rs2,func,imm,in,i,count,label);
   }
   else if(check == "0110111"){
          in = Uformat(line,rd,func,imm,in,i,count);
   }else if(check == "1101111"){
          in = Jformat(line,rd,func,imm,in,i,count,label);
   }
        if(in=="1") { //Any error reported as "1"
		cout<<"Execution terminated"<<endl;
		return 1;
	}
	string array;
	//string to contain 4 consecutive digits of binary instruction(in)
	for(int i=0;i<in.length();i=i+4){
		string bin = in.substr(i,4);
		char c= conv(stoi(bin));//convert 4 binary digits into one hex digit
		array.push_back(c);  //push hex digit to answer
	}

   ofstream obj("output.hex",ios::app); //open output.hex in append mode
   if(obj.is_open()){ 
   obj<<array<<endl;  //write hex code of valid instruction to the file
   obj.close();       //close file output.hex
   }
        array.erase();  //erase all strings that contained arguments
	func.erase();
	rd.erase();
	rs1.erase();
	rs2.erase();
	in.erase();
	imm.erase();
   }
   }
inp.close(); //close input.s file
	return 0;
}

