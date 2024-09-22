## **Directory Contents:**
            main.cpp
            RFormat.hpp
            SFormat.hpp
            IFormat.hpp
            BFormat.hpp
            UFormat.hpp
            JFormat.hpp
            makefile        
            input.s
            output.hex

**Commands to run code:**
        To compile makefile:        make
        To run executable:          ./riscv_asm
        To verify output:           vi output.hex
        To clean all files:         make clean

## Description:
        Main.cpp :
                String instruction is stored in a line from ifstream using getline.
                All labels along with thier line numbers are stored in a vector of pairs named label.
                Again input.s is read line-wise and using Opcode of func argument it is sent to different format files.
        RFormat.hpp:
                According to  format encoding,every argument is split into bits of different fileds. 

        IFormat.hpp:
                Two different functions were written to handle general format and load format due to different
                syntax used.
                lowerConstant function for returning immediate of 6-bit length.
        SFormat.hpp: 
                constant function for returning immediate of 12-bit length.
                format file for parsing instruction and splitting immediate value to required fields using substr function.
        BFormat.hpp:
                Labels are already stored in vector of pairs label in main.cpp
                Using line number of label name stored in the vector immediate value is calculated as difference of current line number and label line number multiplied by 4.(length of each instruction)
                Now B-format file parses input instruction and uses constant function of SFormat.hpp to parse 12-bit immediate.
        UFormat.hpp: 
                Upperconstant  function to give 20-bit immediate required vy U,J formats.
                format function to parse given instruction
        JFormat.hpp: 
                format function to parse given instruction and  splitting immediate value to required fields using substr function.
            
