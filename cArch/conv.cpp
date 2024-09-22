

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<utility>
#include"functions.hpp"
using namespace std;

string Rfunc7(string a){
	if(a=="sra" || a=="sub")   return "0100000" ;                                                  
	else if(a=="add"||a=="xor"||a=="or"||a=="and"||a=="sll"||a=="srl") 
		return "0000000";                                                   
        return "error";                                                 
}
string Rfunc3(string a){
	if(a=="add" || a=="sub")   return "000" ;                                                  
	else if(a=="srl"|| a=="sra") return "101";                                                   
	else if(a=="sll") return "001";                                                   
	else if(a=="xor") return "100";                                                                                   
	else if(a=="or") return "110";                                                
	else if(a=="and") return "111";                                               
	return "error";

}

string Sfunc3(string a)
{
    if(a=="sb")
    return "000";
    else if(a=="sh")
    return "001";
    else if(a=="sw")
    return "010";
    else if(a=="sd")
    return "011";
    return "error";
}
string Ifunc3(string a)
{
    if (a == "addi")
        return "000";

    else if (a == "xori")
        return "100";

    else if (a == "ori")
        return "110";

    else if (a == "andi")
        return "111";

    else if (a == "slli")
        return "001";

    else if (a == "srli")
        return "101";

    else if (a == "srai")
        return "101";

    else if (a == "jalr")
        return "000";
    else if (a == "lb")
        return "000";
    else if (a == "lh")
        return "001";
    else if (a == "lw")
        return "010";
    else if (a == "ld")
        return "011";
    else if (a == "lbu")
        return "100";
    else if (a == "lhu")
        return "101";
    else if (a == "lwu")
        return "110";
    return "error";
}
string Ifunc6(string a)
{
    if (a == "slli")
        return "000000";

    else if (a == "srli")
        return "000000";

    else if (a == "srai")
        return "010000";
    return "error";
}
string Bfunc3(string func){        //3 bits of func3 returned
if(func=="beq") return "000";
else if(func=="bne") return "001";
else if(func=="blt") return "100";
else if(func=="bge") return "101";
else if(func=="bltu") return "110";
else if(func=="bgeu") return "111";
return "error3";    //invalid function 
}
string constant(string imm,string value,string Opcode){
//function to provide a 20 bit binary value for a decimal number(string value)
  int temp = stoi(value); // convert value to integer 
  if((temp>= -2048 && temp<=2047)||(temp>=-4096 && temp<=4094 && Opcode=="1100011" )){
//for B format range of immediate is [-4096,4094] 
//for I,S  formats range of immediate is [-2048,2047]
  if(temp<0){ // if immediate is negative
	bool a= true; 
	// variable that indicates right-most one is met or not for calculating 2's
	// complement in simple method
	temp = 0-temp; //convert imm to positive
	int i=0;
        for(;i<12;i++){ //loop for generating binary equivalent of  +ve decimal number
	  imm.push_back(temp%2 + '0'); 
	  temp = temp/2;
	  if(temp==1){
		  imm.push_back(1+'0');
		  i++;
		  break;
	  }
	}
		  while(i<11){ //if number of bits in immediate's binary form < 12 
			  imm.push_back('0');
			  i++;
		  }
               for(int u=0;u<11;u++){ 
	//loop for calculating 2's complement of a given  binary number
                   if(imm[u]==1+'0'){ //encounter left-most one (still imm. is not reversed)
                            a=false;
			    for(int k=u+1;k<12;k++){ //flip all other bits that are left
               if(imm[k]==0+'0') imm[k]=1+'0'; 
	       else if(imm[k]==1+'0') imm[k]=0+'0';
			    }
		   }
	     if(a==false) break;
	       }
	}
  else{  //if immediate value is positive 
	int i=0;
        for(;i<12;i++){ //loop for generating binary equivalent of  +ve decimal number
	  imm.push_back(temp%2 + '0');
	  temp = temp/2;
	  if(temp==1){
		  imm.push_back(1+'0');
		  i++;
		  break;
	  }
	}
		  while(i<11){ //if number of bits in immediate's binary form < 12
			  imm.push_back(0+'0');
			  i++;
		  }
  }
	reverse(imm.begin(),imm.end());//now reverse string imm to get correct binary value
  return imm;
  }else{
     return "rangeError"; //out_of_range error 
  }
}
string Bformat(string line,string rs1,string rs2,string func,string imm,string in,int i,int count,vector<pair<int,string>> label){
//function to generate binary format of given instruction
   bool next = true;
   i++;
   for(;i<line.length();i++){
        if(line[i]!=',' && !(isspace(line[i]))){
	//second argument(rs1) terminates at comma or space
		  next = false;
                  rs1.push_back(line[i]);
			}
	else if(line[i]==',') break;
   }
    i++;
    next = true;
   for(;i<line.length();i++){
        if(line[i]!=','&& !(isspace(line[i]))){
// rs2 terminates with comma or space
		  next = false;
                  rs2.push_back(line[i]);
			}
	 else if(line[i]==',' && !(next)) break;
   }
   next =true;
   string target;  // string to  store decimal immediate value
   for(;i<line.length();i++){
        if(line[i]!=','&& !(isspace(line[i]))){
		  next = false;
                  target.push_back(line[i]);
			}
   }
   for(int m=0;m<label.size();m++){
        if(label[m].second == target){ 
         imm =constant(imm,to_string(4*(label[m].first-count)),Opcode(func));
//label[m].first returns line number of given label
// label[m].first-count returns no. of lines between label and b-instruction with label 
   	 break;
       }
	if(label[m].second != target && m==label.size()-1){
 //label not found in vector of pairs (label) 	
	    cout<<"label at line "<<count<<" not found"<<endl;
	    return "1";
	}
   }
   if(imm.empty()){
//empty label
          cout<<"Empty label found at line "<<count<<endl;
	  return "1";
   }
     if(!imm.empty() && (imm != "rangeError")){
	  // ignore last bit(imm[0]) and sign-extend 
          imm.pop_back();
          reverse(imm.begin(),imm.end());
          if(imm[10] == 0+'0') imm.push_back(0+'0');
	  else if(imm[10] == 1+'0') imm.push_back(1+'0');
          reverse(imm.begin(),imm.end());	  
     }
        if(imm != "rangeError") {  
	  in.append(imm.substr(0,1));//imm[12]
          in.append(imm.substr(2,6));//imm[10:5]
	}else{
           cout<<"Immediate out of range in line "<<count<<endl;
	   return "1";
	}
        if(reg(rs2)!="invalid")  {
		in.append(reg(rs2));
	}else{
             cout<<"Invalid identifier at source register-2 in line "<<count<<endl;
	     return "1"; 
	}
        if(reg(rs1)!="invalid"){
	      	in.append(reg(rs1));
	}else{
             cout<<"Invalid identifier at source register-1 in line "<<count<<endl;
	     return "1"; 
	}
        if(Bfunc3(func)!="error3") { //3 bits of func3 appended
		in.append(Bfunc3(func));
	}else{
	cout<<"Suspected wrong function syntax in line "<<count<<endl;
	return "1";
	}
	if(imm != "rangeError"){
	      	in.append(imm.substr(8,4)); //imm[4:1]
                in.append(imm.substr(1,1)); //imm[11]
	}
        in.append(Opcode(func));
return in;
}

string Rformat(string line,string rd,string rs1,string rs2,string func,string in,int i,vector<pair<string,string>> regs){
   bool next = true;
   i++;
   for(;i<line.length();i++){
        if(line[i]!=',' && !(isspace(line[i]))){
		  next = false;
                  rd.push_back(line[i]);
			}
	else if(line[i]==',') break;
   }
    i++;
    next = true;
   for(;i<line.length();i++){
        if(line[i]!=','&& !(isspace(line[i]))){
		  next = false;
                  rs1.push_back(line[i]);
			}
	 else if(line[i]==',' && !(next)) break;
   }
	if(Rfunc7(func)=="error"){
		cout<<"Invalid operation in the instruction"<<endl;
		return "1";
	}else{
		in.append(Rfunc7(func));
	}
   i++;
   next =true;
   for(;i<line.length();i++){
        if(line[i]!=','&& !(isspace(line[i]))){
		  next = false;
                  rs2.push_back(line[i]);
			}
	 else if(line[i]==',' && !(next)) break;
   }
        if(reg(rs2)!="invalid")  in.append(reg(rs2));
        if(reg(rs1)!="invalid")  in.append(reg(rs1));
        if(Rfunc3(func)!="error") in.append(Rfunc3(func));
        if(reg(rd)!="invalid")  in.append(reg(rd));
	in.append(Opcode(func));
	return in;
}
string lowerConstant(string imm,string value){
  int temp = stoi(value);
	int i=0;
        for(;i<6;i++){
	  imm.push_back(temp%2 + '0');
	  temp = temp/2;
	  if(temp==1){
		  imm.push_back(1+'0');
		  i++;
		  break;
	  }
	}
		  while(i<5){
			  imm.push_back('0');
			  i++;
		  }
	reverse(imm.begin(),imm.end());
	return imm;
}
string Sformat(string line,string rs1,string rs2,string func,string imm,string in,int i,int count,vector<pair<string,string>> regs){
	i++;
	for(;i<line.length();i++){
        if(!isspace(line[i]) && line[i]!=','){
 //second argument terminating characters are comma and blank space
                 rs2.push_back(line[i]);
			}
			else if(line[i]==',' ) break;
			}
	string temp;
	i++;
        for(;i<line.length();i++){
        if(((int)line[i] <=57 && (int)line[i] >= 48 && !(isspace(line[i])))||(int)line[i]==45){  // number or minus sign is pushed to temporary string
                  temp.push_back(line[i]);
			}
	else if(line[i]=='(') break;  // stop storing at (
	}
	imm =  constant(imm,temp,Opcode(func)); //binary immediate initialised
        bool next = true;
	i++;
	for(;i<line.length(); i++){
         if(line[i]!=')' && line[i]!='(' && !(isspace(line[i]))){
		// argument of form (arg.) stored in rs1
		 next = false;
		 rs1.push_back(line[i]);
	 }
	 else if(line[i]==')' && !(next)) break; //stop storing at )
	}
        if(imm != "rangeError") {
	       	in.append(imm.substr(0,7)); //imm[11:5]
	}else{
          cout<<"Immediate out of range in line "<<count<<endl;
	  return "1";
	}
        if(reg(rs2)!="invalid") {
	     in.append(reg(rs2));  //append 5 bits of source register
	}else{
             cout<<"Invalid identifier at source register-2 in line "<<count<<endl;
	     return "1"; 
	}
        if(reg(rs1)!="invalid"){
	     in.append(reg(rs1)); //append 5 bits of source register
	}else{
             cout<<"Invalid identifier at source register-1 in line "<<count<<endl;
	     return "1"; 
	}
        if(Sfunc3(func)!="error3") { //3 bits of func3 appended
	    in.append(Sfunc3(func));
	}else{
            cout<<"Suspected syntax error at function in line "<<count<<endl;
	    return "1";
	}
	if(imm != "rangeError")  in.append(imm.substr(7,5));//imm[4:0]
        in.append(Opcode(func));
	return in;
}
      string IGformat (string line,string rs1,string func,string imm,string rd,string in,int i,int count,vector<pair<string,string>> regs){ //function for general I-format instruction parsing
   bool next = true;
   i++;
   for(;i<line.length();i++){
        if(line[i]!=',' && !(isspace(line[i]))){
		//second argument(rd) terminates with comma or space
		  next = false;
                  rd.push_back(line[i]);
			}
	else if(line[i]==',') break;
   }
    i++;
    next = true;
   for(;i<line.length();i++){
        if(line[i]!=','&& !(isspace(line[i]))){
	//third argument(rs1) terminates with comma or space
		  next = false;
                  rs1.push_back(line[i]);
			}
	 else if(line[i]==',' && !(next)) break;
   }
   i++;
   string temp;
   for(;i<line.length();i++){
        if(((int)line[i] <=57 && (int)line[i] >= 48)||(int)line[i]==45){
	//digits or minus symbol appended to string
		temp.push_back(line[i]);
			}
   }
	if(func=="slli" || func=="srli" || func=="srai"){
	imm =  lowerConstant(imm,temp); //6 bit immediate value
       if(Ifunc6(func)!="error6") {
	       in.append(Ifunc6(func)); // 6 bits of func6 appended
       }else{
            cout<<"Suspected syntax error at function in line "<<count<<endl;
	    return "1";
       }
	if(imm == "rangeError"){
            cout<<"Immediate out of range in line "<<count<<endl;
	    return "1"; 
            	}	
	 in.append(imm); 
	}else{
	imm =  constant(imm,temp,Opcode(func)); //12 bit binary number
	if(imm == "rangeError"){
            cout<<"Immediate value provided is out of range in line "<<count<<endl;
            return "1";
	        }
	in.append(imm);
	}
        if(reg(rs1)!="invalid") {
	       	in.append(reg(rs1));
	}else{
             cout<<"Invalid identifier at source register in line "<<count<<endl;
	     return "1"; 
	}
        if(Ifunc3(func)!="error") {
		in.append(Ifunc3(func)); 
	}else{
            cout<<"Suspected syntax error at function in line "<<count<<endl;
	    return "1";
	}
        if(reg(rd)!="invalid") {
	       	in.append(reg(rd));
	}else{
             cout<<"Invalid identifier at destination register in line "<<count<<endl;
	     return "1"; 
	}
        in.append(Opcode(func));
	return in;
      }
      string  ILformat( string line,string rs1,string func,string imm,string rd,string in,int i,int count,vector<pair<string,string>> regs){ 
	//function for  I-format load instruction parsing      
	i++;
	for(;i<line.length();i++){
        if(!isspace(line[i]) && line[i]!=','){
      //second argument(rd) terminating characters are comma and blank space
                 rd.push_back(line[i]);
			}
			else if(line[i]==',' ) break;
			}
	string temp;
	i++;
        for(;i<line.length();i++){
        if(((int)line[i] <=57 && (int)line[i] >= 48)||(int)line[i]==45){
        // digit or minus sign is appended
                  temp.push_back(line[i]);
			}
	else if(line[i]=='(') break;
	}
	imm =  constant(imm,temp,Opcode(func));
	if(imm == "rangeError") {
            cout<<"Immediate value provided is out of range in line "<<count<<endl;
	       	return "1";
	}
	in.append(imm);
        bool next = true;
	i++;
	for(;i<line.length(); i++){
         if(line[i]!=')' && line[i]!='(' && !(isspace(line[i]))){
         //input is of the form (rs1)
		 next = false;
		 rs1.push_back(line[i]);
	 }
	 else if(line[i]==')' && !(next)) break;
	}
        if(reg(rs1)!="invalid"){
	      	in.append(reg(rs1));
	}else{
             cout<<"Invalid identifier at source register-1 in line "<<count<<endl;
	     return "1"; 
	}
        if(Ifunc3(func)!="error") { //3 bits of func3 appended
		in.append(Ifunc3(func));
	}else{
	cout<<"Suspected wrong function syntax in line "<<count<<endl;
	return "1";
	}
        if(reg(rd)!="invalid") {
	       	in.append(reg(rd));
	}else{
             cout<<"Invalid identifier at destination register in line "<<count<<endl;
	     return "1"; 
	}
        in.append(Opcode(func));
	return in; //binary instruction returned
      }
string upperConstant(string imm,string value,string Opcode){
//function for calculating 20-bit binary equivalent of a decimal number 
  int temp = stoi(value);
 if((Opcode == "0110111" && temp>=-524288 && temp<=524287)||(Opcode == "1101111" && temp>=-1048576 && temp<=1048574)){ 
  if(temp<0){   //if immediate is negative
	bool a = true;
	temp = 0-temp;
	int i=0;
        for(;i<20;i++){  //calculates binary form of decimal (in reverse order)
	  imm.push_back(temp%2 + '0');
	  temp = temp/2;
	  if(temp==1){
		  imm.push_back(1+'0');
		  i++;
		  break;
	  }
	}
		  while(i<19){  //if imm. less than 20 bits
			  imm.push_back(0+'0');
			  i++;
		  }
               for(int u=0;u<19;u++){ //loop for calculating 2's complement
                   if(imm[u]==1+'0'){
                            a=false;
			    for(int k=u+1;k<=19;k++){ //after leftmost 1 flip all other bits
               if(imm[k]==0+'0') imm[k]=1+'0';
	       else if(imm[k]==1+'0') imm[k]=0+'0';
			    }
		   }
	       if(a==false) break;
	       }
	reverse(imm.begin(),imm.end());//reverse imm string to get binary form
  }
  else{ //if immediate is positive
	int i=0;
        for(;i<20;i++){ //calculates binary form of decimal (in reverse order)
	  imm.push_back(temp%2 + '0');
	  temp = temp/2;
	  if(temp==1){
		  imm.push_back(1+'0');
		  i++;
		  break;
	  }
	}
		  while(i<19){ //if imm. less than 20 bits
			  imm.push_back(0+'0');
			  i++;
		  }
	reverse(imm.begin(),imm.end());
  }
  return imm;
 }else{
  return "rangeError"; //out_of_range error
 }
}
 
string Uformat(string line,string rd,string func,string imm,string in,int i,int count){
   i++;
   for(;i<line.length();i++){
        if(line[i] !=',' && !(isspace(line[i]))){
	// argument terminates with comma or space
                  rd.push_back(line[i]);
			}
        else if(line[i] == ',') break;
   }
   string temp;
   for(;i<line.length();i++){
      if(!isspace(line[i]) && line[i]!=',') temp.push_back(line[i]);
   } //temp stores immediate
   if(temp[0] == '0' && temp[1] == 'x'){ //if imm. is in hex format
      if (temp.length()>2)  { //if valid immediate
      temp.erase(0,2);   //erase 0 and x 
      if(temp.length()<=5){
        for(int f=0;f<temp.length();f++){
           in.append(hex_to_bin(temp[f]));   //calculate binary of given hex digit    
	}
      }
      }
   }
   else{
          imm = upperConstant(imm,temp,Opcode(func));//20-bit imm. appended
    }
   if(imm != "rangeError" )  {
	   in.append(imm.substr(0,20));
   }else{
          cout<<"Immediate out of range in line "<<count<<endl;
	  return "1";
   }
   if(reg(rd)!= "invalid") {
	   in.append(reg(rd));
   }else{
             cout<<"Invalid identifier at destination register in line "<<count<<endl;
	     return "1"; 
   }
   if(Opcode(func)!="invalid")  in.append(Opcode(func)); 
   return in;
}
string Jformat(string line,string rd,string func,string imm,string in,int i,int count,
		 vector<pair<int,string>> label){
//function that parses J-instruction to binary format
     bool next = true;
     i++;
     for (; i < line.length(); i++)
     {
          if (line[i] != ',' && !(isspace(line[i])))
          { //second argument terminates with comma or space
               next = false;
               rd.push_back(line[i]);
          }
          else if (line[i] == ',')
               break;
     }
     i++;
     next = true;
     string target;
     for (; i < line.length(); i++)
     { //target stores label name
          if (line[i] != ',' && !(isspace(line[i])))
          {
               next = false;
               target.push_back(line[i]);
          }
     }
     for (int m = 0; m < label.size(); m++)
     {
          if (label[m].second == target)
          {    //if label name present in vector of pairs label
               imm = upperConstant(imm,to_string(4*(label[m].first-count)),Opcode(func));
               break;
          }
     }
	  if (imm != "rangeError")
     {   //ignore last bit and extend sign
	  imm.pop_back();
          reverse(imm.begin(),imm.end());	  
          if(imm[18] == 0+'0')      imm.push_back(0+'0');
	  else if(imm[18] == 1+'0') imm.push_back(1+'0');
          reverse(imm.begin(),imm.end());	  
     }else{
           cout<<"Immediate value out of range in line "<<count<<endl;
	   return "1";
     }
          in.append(imm.substr(0, 1));//imm[20]
          in.append(imm.substr(10, 10));//imm[10:1]
	  in.append(imm.substr(9,1));//imm[11]
	  in.append(imm.substr(1,8));//imm[19:12]
     if (reg(rd) != "invalid") {
	     in.append(reg(rd));
     }else{
             cout<<"Invalid identifier at destination register in line "<<count<<endl;
	     return "1"; 
     }
     in.append(Opcode(func));
     return in;
 }
int main(int argc,char* argv[])
{
   vector<pair<string,string>> regs;
   string PC = "0x00000000";
   bool load = false;
   string cmd;
   while(cmd!="exit"){
      getline(cin,cmd);
      string temp;
      if(cmd == "load input.txt"){
              for(int i=0;i<32;i++){
	      temp.push_back('x');
	      temp.append(to_string(i));
	      regs.push_back(make_pair(reg(temp),"0x00000000"));
	      temp.erase();
	      }
      }
      else if(cmd == "run" ){
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
   /*string ins;*/
   ifstream inp("input.s");
   while(!inp.eof()){  
   string line;
   getline(inp,line);
   count+=1;
   if(!line.empty()){
string b = "100";
string res;
      reverse(PC.begin(),PC.end());
      PC.pop_back();
      PC.pop_back();
      reverse(PC.begin(),PC.end());
int q=0;
string a;
for(int d=0;d<PC.length();d=d+1){
    a.append(hex_to_bin(PC[d]));
}
int k=a.length()-b.length()-1;
reverse(b.begin(),b.end());
for(;k>=0;k--){
     b.push_back('0');
}
reverse(b.begin(),b.end());
for(int i= a.length()-1;i>=0;i--){
      int p = (a[i]-'0')+(b[i]-'0')+q;
      if(p>1) {
	      res.push_back('0'); 
              q=1;
      }
      else{
	      res.push_back(p + '0'); 
	      q=0;
      }
}
      reverse(res.begin(),res.end());
       PC.erase();
	for(int i=0;i<res.length();i=i+4){
		string bin = res.substr(i,4);
		char c= conv(stoi(bin));
		PC.push_back(c);
	}
      res.erase();
      reverse(PC.begin(),PC.end());
      PC.push_back('x');
      PC.push_back('0');
      reverse(PC.begin(),PC.end());
   string check;
   int i=0;
   bool space=true;
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
   space = true;
   for(;i<line.length();i++){
	if(isspace(line[i]) && space) i++;
        if(!isspace(line[i])){
	          space = false;
                  func.push_back(line[i]);
		}
	else break;
   }
   check = Opcode(func);
   if(check=="error"){
        string temp = func;
	func.erase();
	space = true;
        for(;i<line.length();i++){
	      if(isspace(line[i]) && space) i++;
              if(!isspace(line[i])){
	          space = false;
                  func.push_back(line[i]);
		}
	else break;
   }
   }
   if(check == "0110011"){
	  in = Rformat(line,rd,rs1,rs2,func,in,i,regs);
   }
   else if(check == "0100011") {
         in = Sformat(line,rs1,rs2,func,imm,in,i,count,regs);
   }                                         
   else if (check=="0000011" || check == "1100111"){
	   in= ILformat(line,rs1,func,imm,rd,in,i,count,regs);
   }
   else if (check == "0010011"){
          in= IGformat(line,rs1,func,imm,rd,in,i,count,regs);
   }
   else if(check == "1100011"){
          in = Bformat(line,rs1,rs2,func,imm,in,i,count,label);
   }
   else if(check == "0110111"){
          in = Uformat(line,rd,func,imm,in,i,count);
   }else if(check == "1101111"){
          in = Jformat(line,rd,func,imm,in,i,count,label);
   }
	string array;
	for(int i=0;i<in.length();i=i+4){
		string bin = in.substr(i,4);
		char c= conv(stoi(bin));
		array.push_back(c);
	}
	/*for(int l=0;l<32;l++){
    cout<<regs[l]<<"reg "<<l<<" value: "<<endl;
	}*/
   ofstream obj("outsim.hex",ios::app);
   if(obj.is_open()){
    obj<<array<<endl;
   obj.close();
   }
   cout<<"Executed: "<<line<<" ; ";
   cout<<" PC = "<<PC<<endl;
   cout<<endl;
        array.erase();
	func.erase();
	rd.erase();
	rs1.erase();
	rs2.erase();
	in.erase();
	imm.erase();
   }
}
inp.close();
      }
      else if(cmd == "regs" ){
            cout<<"Executed: "<<cmd <<endl;
	    string temp;
              for(int i=0;i<32;i++){ 
	      temp.push_back('x');
	      temp.append(to_string(i));
	      cout<<temp;
	      if(i<=9) cout<<"   =  ";
	      else cout<<"  =  ";
	      cout<<regs[i].second<<endl;
	      temp.erase();
	      }
      }
   }
	return 0;
}

