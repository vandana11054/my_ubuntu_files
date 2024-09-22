

string Ifunc3(string a)
{ //3 bits of func3 returned acc. to given function
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
    return "error3";
}
string Ifunc6(string a)
{ //6 bits of func6 for slli or srli or srai
    if (a == "slli")
        return "000000";

    else if (a == "srli")
        return "000000";

    else if (a == "srai")
        return "010000";
    return "error6";
}

string lowerConstant(string imm,string value){
// 6-bit positive immediate value for slli or srli or srai
  int temp = stoi(value);
  if(temp>= 0 && temp<= 63){ //if imm value is in the range of 6-bit 
	int i=0;
        for(;i<6;i++){ //generates 6-bit binary of decimal 
	  imm.push_back(temp%2 + '0');
	  temp = temp/2;
	  if(temp==1){
		  imm.push_back(1+'0');
		  i++;
		  break;
	  }
	}
		  while(i<5){ //if imm length is less than 6
			  imm.push_back('0');
			  i++;
		  }
	reverse(imm.begin(),imm.end()); 
	//reverse imm value(as reminder calculation gives reverse order)
	return imm;
  }else{
	  return "rangeError"; //out_of_range error
}
}
      string IGformat (string line,string rs1,string func,string imm,string rd,string in,int i,int count){ //function for general I-format instruction parsing
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
      string  ILformat( string line,string rs1,string func,string imm,string rd,string in,int i,int count){ 
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
