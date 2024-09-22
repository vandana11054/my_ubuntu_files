

#include<iostream>
#include<string>
using namespace std;
string Opcode(string a){
	if(a=="add" || a=="sub"||a=="xor"||a=="or"||a=="and"||a=="sll"||a=="srl"||a=="sra")   return "0110011" ;                                                  
	else if(a=="addi"|| a=="xori"||a=="ori"||a=="andi"||a=="slli"||a=="srli"||a=="srai") return "0010011";
	else if(a=="lb"||a=="lh"||a=="ld"||a=="lw"||a=="lhu"||a=="lbu"||a=="lwu") return "0000011";
	else if(a=="sw"||a=="sd"||a=="sh"||a=="sb") return "0100011";
	else if(a=="blt"||a=="beq"||a=="bne"||a=="bge"||a=="bgeu"||a=="bltu") return "1100011";
	else if(a=="lui") return "0110111";
	else if(a=="jalr") return "1100111"; 
	else if(a=="jal") return "1101111"; 
        return "invalid";	
}
char conv(int a){
	switch(a){
		case 0:  return '0';
			 break;
		case 1: return '1' ;
			break;
		case 10: return '2' ;
			 break;
		case 11:  return '3';
			  break;
		case 100: return '4' ;
			  break;
		case 101:  return '5';
			   break;
		case 110: return '6';
			  break;
		case 111:  return '7';
			   break;
		case 1000:  return '8';
			    break;
		case 1001:  return '9';
			    break;
		case 1010:  return 'a';
			    break;
		case 1011: return 'b' ;
			   break;
		case 1100:  return 'c';
			    break;
		case 1101: return 'd' ;
			   break;
		case 1110:  return 'e';
			    break;
		case 1111:  return 'f';
			    break;
	}
	return '0';
}

string dec_to_bin(int a){
	switch(a){
		case 0:  return "0000";
			 break;
		case 1: return "0001";
			break;
		case 2: return "0010" ;
			break;
		case 3:  return "0011";
			 break;
		case 4: return  "0100";
			break;
		case 5:  return "0101";
			 break;
		case 6: return "0110";
			break;
		case 7:  return "0111";
			 break;
		case 8:  return "1000";
			 break;
		case 9:  return "1001";
			 break;
		case 10:  return "1010";
			  break;
		case 11: return  "1011";
			 break;
		case 12:  return "1100";
			  break;
		case 13: return  "1101";
			 break;
		case 14:  return "1110";
			  break;
		case 15:  return "1111";
			  break;
	}
	return "error";
}

string hex_to_bin(char a){
  switch(a){
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'a': return "1010";
        case 'b': return "1011";
        case 'c': return "1100";
        case 'd': return "1101";
        case 'e': return "1110";
        case 'f': return "1111";
  }
  return "error";
}

string reg(string a){
	if(a=="x0" || a=="zero")   return "00000" ;                                                  
	else if(a=="x1"|| a=="ra") return "00001";                                                                                    
	else if(a=="x2"|| a=="sp") return "00010";                                                                                   
	else if(a=="x3"|| a=="gp") return "00011";                                                                                   
	else if(a=="x4"|| a=="tp") return "00100";                                                                                   
	else if(a=="x5"|| a=="t0") return "00101";                                                                                   
	else if(a=="x6"|| a=="t1") return "00110";                                                                                    
	else if(a=="x7"|| a=="t2") return "00111";                                                                                   
	else if(a=="x8"|| a=="s0"||a=="fp") return "01000";                                                                                    
	else if(a=="x9"|| a=="s1") return "01001";                                                                                    
	else if(a=="x10"|| a=="a0") return "01010";                                                                                    
	else if(a=="x11"|| a=="a1") return "01011";                                                                                    
	else if(a=="x12"|| a=="a2") return "01100";
	else if(a=="x13"|| a=="a3") return "01101"; 
	else if(a=="x14"|| a=="a4") return "01110";                                                                                    
	else if(a=="x15"|| a=="a5") return "01111";
	else if(a=="x16"|| a=="a6") return "10000";
	else if(a=="x17"|| a=="a7") return "10001";
	else if(a=="x18"|| a=="s2") return "10010";
	else if(a=="x19"|| a=="s3") return "10011";
	else if(a=="x20"|| a=="s4") return "10100";
	else if(a=="x21"|| a=="s5") return "10101";
	else if(a=="x22"|| a=="s6") return "10110";
	else if(a=="x23"|| a=="s7") return "10111";
	else if(a=="x24"|| a=="s8") return "11000";
	else if(a=="x25"|| a=="s9") return "11001";
	else if(a=="x26"|| a=="s10") return "11010";
	else if(a=="x27"|| a=="s11") return "11011";
	else if(a=="x28"|| a=="t3") return "11100";
	else if(a=="x29"|| a=="t4") return "11101";
	else if(a=="x30"|| a=="t5") return "11110";
	else if(a=="x31"|| a=="t6") return "11111";
	else return "invalid";
}

void reg_val(string a,string val,string* regs){
	if(a=="x0" || a=="zero")  {
	       regs[0] = val;
	}		
	else if(a=="x1"|| a=="ra") {
	regs[1]=val;
	}		
	else if(a=="x2"|| a=="sp") 
	{
	regs[2]=val;
	}		
	else if(a=="x3"|| a=="gp")                                                                                   
	{
	regs[3]=val;
	}		
	else if(a=="x4"|| a=="tp")                                                                                    
	{
	regs[4]=val;
	}		
	else if(a=="x5"|| a=="t0")                                                                                    
	{
	regs[5]=val;
	}		
	else if(a=="x6"|| a=="t1")                                                                                     
	{
	regs[6]=val;
	}		
	else if(a=="x7"|| a=="t2")                                                                                    
	{
	regs[7]=val;
	}		
	else if(a=="x8"|| a=="s0"||a=="fp")                                                                                     
	{
	regs[8]=val;
	}		
	else if(a=="x9"|| a=="s1")                                                                                     
	{
	regs[9]=val;
	}		
	else if(a=="x10"|| a=="a0")                                                                                     
	{
	regs[10]=val;
	}		
	else if(a=="x11"|| a=="a1")                                                                                     
	{
	regs[11]=val;
	}		
	else if(a=="x12"|| a=="a2") 
	{
	regs[12]=val;
	}		
	else if(a=="x13"|| a=="a3") 
	{
	regs[13]=val;
	}		
	else if(a=="x14"|| a=="a4") 
	{
	regs[14]=val;
	}		
	else if(a=="x15"|| a=="a5") 
	{
	regs[15]=val;
	}		
	else if(a=="x16"|| a=="a6") 
	{
	regs[16]=val;
	}		
	else if(a=="x17"|| a=="a7") 
	{
	regs[17]=val;
	}		
	else if(a=="x18"|| a=="s2")
	{
	regs[18]=val;
	}		
	else if	(a=="x19"|| a=="s3")
	{
	regs[19]=val;
	}		
	else if(a=="x20"|| a=="s4") 
	{
	regs[20]=val;
	}		
	else if(a=="x21"|| a=="s5") 
	{
	regs[21]=val;
	}		
	else if(a=="x22"|| a=="s6") 
	{
	regs[22]=val;
	}		
	else if(a=="x23"|| a=="s7") 
	{
	regs[23]=val;
	}		
	else if(a=="x24"|| a=="s8") 
	{
	regs[24]=val;
	}		
	else if(a=="x25"|| a=="s9") 
	{
	regs[25]=val;
	}		
	else if(a=="x26"|| a=="s10") 
	{
	regs[26]=val;
	}		
	else if(a=="x27"|| a=="s11") 
	{
	regs[27]=val;
	}		
	else if(a=="x28"|| a=="t3") 
	{
	regs[28]=val;
	}		
	else if(a=="x29"|| a=="t4") 
	{
	regs[29]=val;
	}		
	else if(a=="x30"|| a=="t5") 
	{
	regs[30]=val;
	}		
	else if(a=="x31"|| a=="t6") 
	{
	regs[31]=val;
	}		
}
