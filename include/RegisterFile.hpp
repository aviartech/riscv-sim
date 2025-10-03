#ifndef RISCV_SIM_REGISTER_FILE_HPP
#define RISCV_SIM_REGISTER_FILE_HPP

#include <string>

namespace riscv_sim {

class RegisterFile {
private:
    int ScalarRegisters[8];       // r0–r7
    float VectorRegisters[4][4];  // v0–v3, each with 4 elements

    int getScalarIndex(const std::string& name);
    int getVectorIndex(const std::string& name);

public:
    RegisterFile();

    void writeReg(const std::string& name, double value);
    double readReg(const std::string& name);

    void writeVec(const std::string& name, int index, double value);
    double readVec(const std::string& name, int index);
};

} // namespace riscv_sim

#endif // RISCV_SIM_REGISTER_FILE_HPP
