#include "../entity.h"
#include "minunit.h"

MU_TEST(test_entity_create) {
  entity *entities = NULL;
  int num_created = 100;
  for (int i = 0; i < num_created; i++)
    create_entity(&entities);

  mu_assert_int_eq(count_entities(entities), num_created);

  destroy_entities(&entities);
  mu_check(entities == NULL);
}
MU_TEST_SUITE(test_entity) { MU_RUN_TEST(test_entity_create); }