
#include "RegisterFile.hpp"

namespace riscv_sim {

RegisterFile::RegisterFile() {
  for (int i = 0; i < 8; i++)
    ScalarRegisters[i] = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      VectorRegisters[i][j] = 0.0f;
}

int RegisterFile::getScalarIndex(const std::string &name) {
  return name[1] - '0'; // "r1" -> 1
}

int RegisterFile::getVectorIndex(const std::string &name) {
  return name[1] - '0'; // "v2" -> 2
}

void RegisterFile::writeReg(const std::string &name, double value) {
  ScalarRegisters[getScalarIndex(name)] = static_cast<int>(value);
}

double RegisterFile::readReg(const std::string &name) {
  return ScalarRegisters[getScalarIndex(name)];
}

void RegisterFile::writeVec(const std::string &name, int index, double value) {
  VectorRegisters[getVectorIndex(name)][index] = static_cast<float>(value);
}

double RegisterFile::readVec(const std::string &name, int index) {
  return VectorRegisters[getVectorIndex(name)][index];
}

} // namespace riscv_sim
