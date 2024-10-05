


void upper_imm(string rd,string imm,vector<pair<string,string>> *regs){
int  a=0;
    for(int i=4;i>=0;i--){
    int b=0;
      b+=(rd[i]-'0');
      for(int k=1;k<5-i;k++){
              b*=2;
      }
      a=a+b;
    }
 if(imm.length() <= 20){
    reverse(imm.begin(),imm.end());
    for (int i = imm.length(); i < 20; i++)
    { 
      imm.push_back('0');
    }
    reverse(imm.begin(),imm.end());
   for (int i = 0; i < 12; i++)
   {
     imm.push_back('0');
   }
   reverse(imm.begin(),imm.end());
   for (int i = 32; i < 64; i++)
   {   
	    imm.push_back(imm[31]);
   }
   reverse(imm.begin(),imm.end());
   string adder;
  	for(int i=0;i<imm.length();i=i+4){
		string bin = imm.substr(i,4);
		char c= conv(stoi(bin));
		adder.push_back(c);
	}
	if(adder.length()<18){
           reverse (adder.begin(),adder.end());
	   while(adder.length()<16){
		 adder.push_back(adder[adder.length()-1]);
	   }
	   adder.push_back('x');
	   adder.push_back('0');
           reverse (adder.begin(),adder.end());
	}
	regs->at(a).second.erase();
	regs->at(a).second.append(adder);
 }
 else{
       cout<<"error out of bounds ";
 }
}
