#include <iostream>

#include "ISAController.hpp"

int main(int argc, char* argv[]) {
    riscv_sim::ISAController controller;
    controller.execute();
    return 0;
}
