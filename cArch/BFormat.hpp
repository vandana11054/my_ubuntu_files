


string Bfunc3(string func){        //3 bits of func3 returned
if(func=="beq") return "000";
else if(func=="bne") return "001";
else if(func=="blt") return "100";
else if(func=="bge") return "101";
else if(func=="bltu") return "110";
else if(func=="bgeu") return "111";
return "error3";    //invalid function 
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
