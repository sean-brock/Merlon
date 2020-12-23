#ifndef ENTITY_H
#define ENTITY_H

// entity.c
// Defines entity data structure for all game objects.
// Each entity is only a list of component indices in the component arrays. -1 == component not present in entity.
// Additionally, each entity is a node in a binary tree for making entity id lookup fast.
typedef struct entity_st entity;

typedef struct entity_st {
    unsigned int id;
    entity *left;
    entity *right;

    // component indices
    int position;
    int movement_ai;
} entity;

entity *lookup_entity(entity *node, unsigned int entity_id);

// Creates an empy entity node and returns the entity.
entity *create_entity(entity **node);

void destroy_entities(entity *node);

#endif