#include "entity.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

entity *lookup_entity(entity *tree, uint64_t entity_id) {
  if (tree != NULL) {
    if (entity_id == tree->id) {
      return tree;
    } else if (entity_id < tree->id) {
      return lookup_entity(tree->left, entity_id);
    } else {
      return lookup_entity(tree->right, entity_id);
    }
  } else
    return NULL;
}

entity *create_entity(entity **tree) {
  // Keep track of id that is available.
  // TODO: thread safe increment, checking
  static uint64_t id = 0;
  // Empty tree case
  if (*tree == NULL) {
    *tree = malloc(sizeof(entity));
    (*tree)->id = id;
    (*tree)->left = NULL;
    (*tree)->right = NULL;

    // empty components
    (*tree)->position = -1;
    (*tree)->movement_ai = -1;

    // id consumed, increment
    id++;
    return *tree;
  } else if (id < (*tree)->id) {
    return create_entity(&((*tree)->left));
  } else if (id > (*tree)->id) {
    return create_entity(&((*tree)->right));
  } else {
    // id already exists. return cannot insert (0).
    return NULL;
  }
}

int count_entities(entity *tree) {
  if (tree == NULL)
    return 0;
  int descend = count_entities(tree->left) + count_entities(tree->right);
  return descend + 1;
}

void destroy_entities(entity **tree) {
  if (*tree != NULL) {
    destroy_entities(&(*tree)->left);
    destroy_entities(&(*tree)->right);
    free(*tree);
    *tree = NULL;
  }
}
