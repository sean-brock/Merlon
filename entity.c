#include <stddef.h>
#include "entity.h"

entity *lookup_entity(entity *node, unsigned int entity_id) {
    if(node != NULL) {
        if (entity_id == node->id) {
            return node;
        } else if(entity_id < node->id) {
            return lookup_entity(node->left, entity_id);
        } else {
            return lookup_entity(node->right, entity_id);
        }
    } else return NULL;
}


entity *create_entity(entity **node) {
    // Keep track of id that is available.
    // TODO: recycle ids
    static unsigned int id = 1;

    // Empty tree case
    if (*node != NULL) {
        *node = malloc(sizeof(entity));
        (*node)->id = id;
        (*node)->left = NULL;
        (*node)->right = NULL;

        // empty components
        (*node)->position = -1;
        (*node)->movement_ai = -1;

        // id consumed, increment
        id++;
        return *node;
    } else if (id < (*node)->id) {
        return create_entity(&(*node)->left);
    } else if (id > (*node)->id) {
        return create_entity(&(*node)->right);
    } else {
        // id already exists. return cannot insert (0).
        return NULL;
    }
}

void destroy_entities(entity *node) {
    if (node != NULL) {
        destroy_entities(node->left);
        destroy_entities(node->right);
        free(node);
    }
}