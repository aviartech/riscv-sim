#include "RegisterFile.hpp"
#include <gtest/gtest.h>

using namespace riscv_sim;

TEST(RegisterFileTest, ScalarRegisterWriteRead) {
  RegisterFile rf;
  rf.writeReg("r1", 123);
  EXPECT_EQ(rf.readReg("r1"), 123);
}

TEST(RegisterFileTest, VectorRegisterWriteRead) {
  RegisterFile rf;
  rf.writeVec("v0", 2, 3.14);
  EXPECT_FLOAT_EQ(rf.readVec("v0", 2), 3.14f);
}
