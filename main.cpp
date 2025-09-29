#include <iostream> 
#include <vector> 

class RegisterFile{
    private: 
    int ScalarRegisters[8];
    float VectorRegisters[4][4]; // 4 vector registers, each with 4 elements

    public: 

    RegisterFile(){
        // Initialize scalar registers to 0
        for(int i = 0; i < 8; i++){
            ScalarRegisters[i] = 0;
        }

        // Initialize vector registers to 0.0f
     for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                VectorRegisters[i][j] = 0.0f;
            }
        }
    }

    void writeReg(const std::string& name, double value) {
        
    };
    double readReg(const std::string& name) {};
    void writeVec(const std::string& name, int index, double value) {}
    double readVec(const std::string& name, int index) {};
   



};