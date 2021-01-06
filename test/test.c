#include "minunit.h"
#include "test_entity.h"

int main(int argc, char *argv[]) {
  MU_RUN_SUITE(test_entity);
  MU_REPORT();
  return MU_EXIT_CODE;
}