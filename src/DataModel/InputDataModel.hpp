//
// Created by VonBrank on 2022/4/8.
//

#ifndef SPHERE_SHADING_INPUTDATAMODEL_HPP
#define SPHERE_SHADING_INPUTDATAMODEL_HPP

struct InputDataModel
{
    bool leftButtonDown = false;
    bool rightButtonDown = false;
    float mouseCursorPosX = 0;
    float mouseCursorPosY = 0;
    float mouseMoveSpeedX = 0;
    float mouseMoveSpeedY = 0;
    float mouseMoveSpeedPercentageX = 0;
    float mouseMoveSpeedPercentageY = 0;
};

#endif //SPHERE_SHADING_INPUTDATAMODEL_HPP
