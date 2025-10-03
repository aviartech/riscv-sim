#ifndef RISCV_SIM_ISA_CONTROLLER_HPP
#define RISCV_SIM_ISA_CONTROLLER_HPP

#include <iostream>
#include "RegisterFile.hpp"

namespace riscv_sim {

class ISAController {
private:
    RegisterFile rf;

public:
    void execute();
};

} // namespace riscv_sim

#endif // RISCV_SIM_ISA_CONTROLLER_HPP
