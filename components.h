#ifndef COMPONENTS_H
#define COMPONENTS_H

// components.h
// Defines all components and their update functions for the ECS
// All components must have an entity id.

#define NUM_COMPONENTS 100

typedef struct {
    int entity_id;
    int x;
    int y;
} position;

/*
typedef struct {
    int entity_id;
    int hitpoints;
} Health;
*/

typedef struct {
    int entity_id;
    char symbol;
} graphic;

typedef struct {
    int entity_id;
    int steps;
} movement_ai;

typedef struct {
    position position_components[NUM_COMPONENTS];
    int total_position_components;
    graphic graphic_components[NUM_COMPONENTS];
    int total_graphic_components;
    movement_ai movement_ai_components[NUM_COMPONENTS];
    int total_movement_ai_components;
} component_lists;

void movement_system(position* p, component_lists* components);

#endif