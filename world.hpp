/*
 *  Mrtp: A simple raytracing tool.
 *  Copyright (C) 2017  Mikolaj Feliks <mikolaj.feliks@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef _WORLD_H
#define _WORLD_H

/* NULL pointer. */
#include <cstddef>

#include <list>
#include <string>
#include <iostream>

#include "vector.hpp"
#include "actors.hpp"
#include "camera.hpp"
#include "parser.hpp"
#include "color.hpp"
#include "texture.hpp"


class World {
    Parser  *parser_;
    Camera  *camera_;
    Light   *light_;

    Actor *actors_;
    unsigned int nactors_;

    Texture *textures_;
    unsigned int ntextures_;

    /*
     * Private methods.
     */
    void CreateCamera (Entry *entry);
    void CreateLight (Entry *light);
    void CreatePlane (Entry *entry);
    void CreateSphere (Entry *entry);
    void CreateCylinder (Entry *entry);

    void PushActor (Actor *actor);
    Actor *PopActor ();

    Texture *PushTexture (std::string *filename);
    Texture *PopTexture ();

public:
    World (Parser *parser);
    ~World ();
    void Initialize ();

    void AssignCamera (Camera **camera);
    void AssignLightActors (Light **light, Actor **actors);
};

#endif /* _WORLD_H */
