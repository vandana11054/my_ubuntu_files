

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
