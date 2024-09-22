

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
