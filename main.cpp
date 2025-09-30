#include <iostream>
#include <string>

class RegisterFile {
private:
    int ScalarRegisters[8];       // r0–r7
    float VectorRegisters[4][4];  // v0–v3, each with 4 elements

    int getScalarIndex(const std::string& name) {
        return name[1] - '0';   // "r1" -> 1
    }

    int getVectorIndex(const std::string& name) {
        return name[1] - '0';   // "v2" -> 2
    }

public:
    RegisterFile() {
        for (int i = 0; i < 8; i++) ScalarRegisters[i] = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                VectorRegisters[i][j] = 0.0f;
    }

    void writeReg(const std::string& name, double value) {
        ScalarRegisters[getScalarIndex(name)] = static_cast<int>(value);
    }

    double readReg(const std::string& name) {
        return ScalarRegisters[getScalarIndex(name)];
    }

    void writeVec(const std::string& name, int index, double value) {
        VectorRegisters[getVectorIndex(name)][index] = static_cast<float>(value);
    }

    double readVec(const std::string& name, int index) {
        return VectorRegisters[getVectorIndex(name)][index];
    }
};

class ISAController {
private:
    RegisterFile rf;

public:
    void execute() {
        rf.writeReg("r1", 42);
        rf.writeVec("v0", 2, 3.14);

        std::cout << "r1 = " << rf.readReg("r1") << std::endl;
        std::cout << "v0[2] = " << rf.readVec("v0", 2) << std::endl;
    }
};

int main(int argc, char* argv[]) {
    ISAController controller;
    controller.execute();
    return 0;
}
