#pragma once
#include <string>


/* Window size */
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

/* Path for codes or data */
const std::string VS_PATH = ".\\shader\\shader.vs";
const std::string FS_PATH = ".\\shader\\shader.fs";
const std::string TEXTURE_PATH = ".\\snowflower.jpg";

/* Number generator for particles */
const int AVG_PARTICLE_NUM = 5;
const int VAR_PARTICLE_NUM = 5;

/* Screen bound */
const float X_LEFT_BOUND  = -5.0;
const float X_RIGHT_BOUND =  5.0;
const float Y_UPPER_BOUND =  5.0;
const float Y_LOWER_BOUND = -5.0;
const float Z_CLOSE_BOUND =  5.0;
const float Z_FAR_BOUND   = -5.0;

/* Delta time */
const float DT = 1.0;

/* Age */
const int MAX_AGE = 556;
const int MIN_AGE = 228;
