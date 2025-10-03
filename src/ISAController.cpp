#include "ISAController.hpp"

namespace riscv_sim {

void ISAController::execute() {
    rf.writeReg("r1", 42);
    rf.writeVec("v0", 2, 3.14);

    std::cout << "r1 = " << rf.readReg("r1") << std::endl;
    std::cout << "v0[2] = " << rf.readVec("v0", 2) << std::endl;
}

} // namespace riscv_sim
