#include <GLFW/glfw3.h>
#include <bits/stdc++.h>
#include <glad/glad.h>

#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <unistd.h>

#include "camera.h"
#include "shader.h"
#define GLT_IMPLEMENTATION
#include "glText.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 5.0f));

// variables
glm::mat4 transform = glm::mat4(1.0f);
glm::mat4 transform1 = glm::mat4(1.0f);
glm::mat4 transform2 = glm::mat4(1.0f);
glm::mat4 transform3 = glm::mat4(1.0f);

int n = 80;
float Bvertices[18 * 80];
float Rvertices[180];
float objPos[3] = {-1.65f, 0.0f, 0.0f};
int start_time=(int)glfwGetTime();
bool rendering=true;//just for shrinking the code
bool fill=true;//just for shrinking the code
bool game_over =false;
bool up = true;
int score = 0;
int num_of_obstacle = 2;
int level = 1;
float Obstacle1[36 * 2];
float Caution1[2];
float Obstacle2[36 * 2];
float Caution2[2];
float Obstacle3[36 * 3];
float Caution3[3];
float enemy = 0;

float E1[18 * 80];
float E2[2 * 18 * 80];
float E3[3 * 18 * 80];

float C1a[18 * 80];
float C1b[18 * 80];
float C1c[18 * 80];
float C1d[18 * 80];

std::vector<std::pair<float, float>> c1;
int b1[4] = {1, 1, 1, 1};
float C2a[18 * 80];
float C2b[18 * 80];
float C2c[18 * 80];
float C2d[18 * 80];
float C2e[18 * 80];
float C2f[18 * 80];
int b2[6] = {1, 1, 1, 1,1,1};


std::vector<std::pair<float, float>> c2;
float C3a[18 * 80];
float C3b[18 * 80];
float C3c[18 * 80];
float C3d[18 * 80];
float C3e[18 * 80];

float C3f[18 * 80];
float C3g[18 * 80];
float C3h[18 * 80];
float C3i[18 * 80];
float C3j[18 * 80];

int b3[10]={1,1,1,1,1,1,1,1,1,1};
std::vector<std::pair<float, float>> c3;

// time
float deltaTime = 0.0f;  // time between current frame and last frame
float lastFrame = 0.0f;

float cal_sin(float n) {
	float sinx = sin(n);
	if (sinx <= 0.00001 && sinx >= -0.0001)
		return 0;
	return sinx;
}

float cal_cos(float n) {
	float cosx = cos(n);
	if (cosx <= 0.00001 && cosx >= -0.0001)
		return 0;
	return cosx;
}
void FillRvertices() {
	int c = 0;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -2.0f;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -1.75f;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -1.75f;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -1.75f;
	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 1.75f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 1.75f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 1.75f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 2.0f;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 1.75f;
	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 1.75;
	Rvertices[c++] = 2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 1.75f;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 2.0f;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -2.0f;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 2.0f;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 2.0f;
	Rvertices[c++] = -1.75f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -2.0f;
	Rvertices[c++] = -1.75f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = +2.0f;
	Rvertices[c++] = -1.75f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = -2.0f;
	Rvertices[c++] = -2.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 0.0f;

	Rvertices[c++] = 1.73f;
	Rvertices[c++] = -0.2f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;

	Rvertices[c++] = 1.73f;
	Rvertices[c++] = 0.2f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;

	Rvertices[c++] = 1.75f;
	Rvertices[c++] = 0.2f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;

	Rvertices[c++] = 1.75f;
	Rvertices[c++] = -0.2f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;

	Rvertices[c++] = 1.75f;
	Rvertices[c++] = 0.2f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;

	Rvertices[c++] = 1.73f;
	Rvertices[c++] = -0.2f;
	Rvertices[c++] = 0.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;
	Rvertices[c++] = 1.0f;
}

//Player
void FillBvertices(int n) {
	double angle = (2 * 3.14159265) / n;
	double modulus = 0.1;
	int c = 0;
	for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
		Bvertices[c++] = -1.65f;
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 1.0f;

		Bvertices[c++] = -1.65 + (float)modulus * cal_cos(i - angle);
		Bvertices[c++] = (float)modulus * cal_sin(i - angle);
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 1.0f;

		Bvertices[c++] = -1.65 + (float)modulus * cal_cos(i);
		Bvertices[c++] = (float)modulus * cal_sin(i);
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 0.0f;
		Bvertices[c++] = 1.0f;
	}
}
//Obstacles
void FillO1vertices() {
	int c = 0;
	float a = 5.0;
	while (a > 1.3) a = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	Obstacle1[c++] = a;
	Obstacle1[c++] = 1.75;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = a + 0.2;
	Obstacle1[c++] = 1.75;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = a;
	Obstacle1[c++] = 0.0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = a + 0.2;
	Obstacle1[c++] = 0.0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = a + 0.2;
	Obstacle1[c++] = 1.75;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = a;
	Obstacle1[c++] = 0.0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;
	float b = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	while ((b >= a - 0.45 && b <= a + 0.45) || b > 1.3) {
		b = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	}
	Obstacle1[c++] = b;
	Obstacle1[c++] = -1.75;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = b + 0.2;
	Obstacle1[c++] = -1.75;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = b;
	Obstacle1[c++] = 0.5;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = b + 0.2;
	Obstacle1[c++] = 0.5;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = b + 0.2;
	Obstacle1[c++] = -1.75;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;

	Obstacle1[c++] = b;
	Obstacle1[c++] = 0.5;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 0;
	Obstacle1[c++] = 1;
	Obstacle1[c++] = 0;
	Caution1[0] = a;
	Caution1[1] = b;
}
void FillO2vertices() {
	int c = 0;
	float a = 5.0;
	while (a > 1.3) a = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	Obstacle2[c++] = a;
	Obstacle2[c++] = 1.75;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = a + 0.2;
	Obstacle2[c++] = 1.75;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = a;
	Obstacle2[c++] = 0.0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = a + 0.2;
	Obstacle2[c++] = 0.0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = a + 0.2;
	Obstacle2[c++] = 1.75;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = a;
	Obstacle2[c++] = 0.0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;
	float b = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	while ((b >= a - 0.45 && b <= a + 0.45) || b > 1.3) {
		b = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	}
	Obstacle2[c++] = b;
	Obstacle2[c++] = -1.75;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = b + 0.2;
	Obstacle2[c++] = -1.75;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = b;
	Obstacle2[c++] = 0.5;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = b + 0.2;
	Obstacle2[c++] = 0.5;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = b + 0.2;
	Obstacle2[c++] = -1.75;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;

	Obstacle2[c++] = b;
	Obstacle2[c++] = 0.5;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 0;
	Obstacle2[c++] = 1;
	Obstacle2[c++] = 0.7;
	Caution2[0] = a;
	Caution2[1] = b;
}
void FillO3vertices() {
	int c = 0;
	float a = 5.0;
	while (a > 1.3) a = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	Obstacle3[c++] = a;
	Obstacle3[c++] = 1.75;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = a + 0.2;
	Obstacle3[c++] = 1.75;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = a;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = a + 0.2;
	Obstacle3[c++] = 0.0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = a + 0.2;
	Obstacle3[c++] = 1.75;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = a;
	Obstacle3[c++] = 0.0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;
	float b = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	while ((b >= a - 0.45 && b <= a + 0.45) || b > 1.3) {
		b = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	}
	Obstacle3[c++] = b;
	Obstacle3[c++] = -1.75;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = b + 0.2;
	Obstacle3[c++] = -1.75;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = b;
	Obstacle3[c++] = 0.5;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = b + 0.2;
	Obstacle3[c++] = 0.5;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = b + 0.2;
	Obstacle3[c++] = -1.75;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = b;
	Obstacle3[c++] = 0.5;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	float C = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	while ((C >= a - 0.45 && C <= a + 0.45) || C > 1.3 ||
		   (C >= b - 0.45 && C <= b + 0.45)) {
		C = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	}
	Obstacle3[c++] = C;
	Obstacle3[c++] = -1.75;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = C + 0.2;
	Obstacle3[c++] = -1.75;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = C;
	Obstacle3[c++] = 0.25;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = C + 0.2;
	Obstacle3[c++] = 0.25;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = C + 0.2;
	Obstacle3[c++] = -1.75;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Obstacle3[c++] = C;
	Obstacle3[c++] = 0.25;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 0;
	Obstacle3[c++] = 1;
	Obstacle3[c++] = 0;

	Caution3[0] = a;
	Caution3[1] = b;
	Caution3[2] = C;
}
//Enemies
void FillE1() {
	double angle = (2 * 3.14159265) / 80;
	double modulus = 0.1;
	int c = 0;
	// ball
	for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
		E1[c++] = (Caution1[0] + 0.2 + Caution1[1]) / 2;
		E1[c++] = 0.0f;
		E1[c++] = 0.0f;
		E1[c++] = 0.8f;
		E1[c++] = 0.4f;
		E1[c++] = 0.5f;

		E1[c++] = (Caution1[0] + 0.2 + Caution1[1]) / 2 +
				  (float)modulus * cal_cos(i - angle);
		E1[c++] = (float)modulus * cal_sin(i - angle);
		E1[c++] = 0.0f;
		E1[c++] = 0.8f;
		E1[c++] = 0.4f;
		E1[c++] = 0.5f;

		E1[c++] =
			(Caution1[0] + 0.2 + Caution1[1]) / 2 + (float)modulus * cal_cos(i);
		E1[c++] = (float)modulus * cal_sin(i);
		E1[c++] = 0.0f;
		E1[c++] = 0.8f;
		E1[c++] = 0.4f;
		E1[c++] = 0.5f;
	}
}
void FillE2() {
	double angle = (2 * 3.14159265) / 80;
	double modulus = 0.1;
	int c = 0;
	// ball
	for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
		E2[c++] = (Caution2[0] + 0.2 + Caution2[1]) / 2;
		E2[c++] = 0.0f;
		E2[c++] = 0.0f;
		E2[c++] = 0.5f;
		E2[c++] = 0.4f;
		E2[c++] = 0.8f;

		E2[c++] = (Caution2[0] + 0.2 + Caution2[1]) / 2 +
				  (float)modulus * cal_cos(i - angle);
		E2[c++] = (float)modulus * cal_sin(i - angle);
		E2[c++] = 0.0f;
		E2[c++] = 0.5f;
		E2[c++] = 0.4f;
		E2[c++] = 0.8f;

		E2[c++] =
			(Caution2[0] + 0.2 + Caution2[1]) / 2 + (float)modulus * cal_cos(i);
		E2[c++] = (float)modulus * cal_sin(i);
		E2[c++] = 0.0f;
		E2[c++] = 0.5f;
		E2[c++] = 0.4f;
		E2[c++] = 0.8f;
	}
	int x;
	if (Caution2[0] > Caution2[1])
		x = Caution2[0];
	else
		x = Caution2[1];
	for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
		E2[c++] = 1.6;
		E2[c++] = 0.0f;
		E2[c++] = 0.0f;
		E2[c++] = 0.5f;
		E2[c++] = 0.4f;
		E2[c++] = 0.8f;

		E2[c++] = 1.6 + (float)modulus * cal_cos(i - angle);
		E2[c++] = (float)modulus * cal_sin(i - angle);
		E2[c++] = 0.0f;
		E2[c++] = 0.5f;
		E2[c++] = 0.4f;
		E2[c++] = 0.8f;

		E2[c++] = 1.6 + (float)modulus * cal_cos(i);
		E2[c++] = (float)modulus * cal_sin(i);
		E2[c++] = 0.0f;
		E2[c++] = 0.5f;
		E2[c++] = 0.4f;
		E2[c++] = 0.8f;
	}
}
void FillE3() {
	double angle = (2 * 3.14159265) / 80;
	double modulus = 0.1;
	int c = 0;
	// ball
	for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
		E3[c++] = 1.6;
		E3[c++] = 0.0f;
		E3[c++] = 0.0f;
		E3[c++] = 0.5f;
		E3[c++] = 0.4f;
		E3[c++] = 0.8f;

		E3[c++] = 1.6 + (float)modulus * cal_cos(i - angle);
		E3[c++] = (float)modulus * cal_sin(i - angle);
		E3[c++] = 0.0f;
		E3[c++] = 0.5f;
		E3[c++] = 0.4f;
		E3[c++] = 0.8f;

		E3[c++] = 1.6 + (float)modulus * cal_cos(i);
		E3[c++] = (float)modulus * cal_sin(i);
		E3[c++] = 0.0f;
		E3[c++] = 0.5f;
		E3[c++] = 0.4f;
		E3[c++] = 0.8f;
	}
	float temp[3];
	temp[0] = Caution3[1] > Caution3[2] ? Caution3[1] - Caution3[2]
										: Caution3[2] - Caution3[1];
	temp[1] = Caution3[1] > Caution3[0] ? Caution3[1] - Caution3[0]
										: Caution3[0] - Caution3[1];
	temp[2] = Caution3[0] > Caution3[2] ? Caution3[0] - Caution3[2]
										: Caution3[2] - Caution3[0];

	if (temp[2] > temp[1] && temp[2] > temp[0]) {
		for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
			E3[c++] = (Caution3[0] + 0.2 + Caution3[1]) / 2;
			E3[c++] = 0.0f;
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[0] + 0.2 + Caution3[1]) / 2 +
					  (float)modulus * cal_cos(i - angle);
			E3[c++] = (float)modulus * cal_sin(i - angle);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[0] + 0.2 + Caution3[1]) / 2 +
					  (float)modulus * cal_cos(i);
			E3[c++] = (float)modulus * cal_sin(i);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;
		}
		for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
			E3[c++] = (Caution3[1] + 0.2 + Caution3[2]) / 2;
			E3[c++] = 0.0f;
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[1] + 0.2 + Caution3[2]) / 2 +
					  (float)modulus * cal_cos(i - angle);
			E3[c++] = (float)modulus * cal_sin(i - angle);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[1] + 0.2 + Caution3[2]) / 2 +
					  (float)modulus * cal_cos(i);
			E3[c++] = (float)modulus * cal_sin(i);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;
		}
	}
	if (temp[1] > temp[2] && temp[1] > temp[0]) {
		for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
			E3[c++] = (Caution3[0] + 0.2 + Caution3[2]) / 2;
			E3[c++] = 0.0f;
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[0] + 0.2 + Caution3[2]) / 2 +
					  (float)modulus * cal_cos(i - angle);
			E3[c++] = (float)modulus * cal_sin(i - angle);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[0] + 0.2 + Caution3[2]) / 2 +
					  (float)modulus * cal_cos(i);
			E3[c++] = (float)modulus * cal_sin(i);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;
		}
		for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
			E3[c++] = (Caution3[1] + 0.2 + Caution3[2]) / 2;
			E3[c++] = 0.0f;
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[1] + 0.2 + Caution3[2]) / 2 +
					  (float)modulus * cal_cos(i - angle);
			E3[c++] = (float)modulus * cal_sin(i - angle);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[1] + 0.2 + Caution3[2]) / 2 +
					  (float)modulus * cal_cos(i);
			E3[c++] = (float)modulus * cal_sin(i);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;
		}
	}
	if (temp[0] > temp[2] && temp[0] > temp[1]) {
		for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
			E3[c++] = (Caution3[0] + 0.2 + Caution3[2]) / 2;
			E3[c++] = 0.0f;
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[0] + 0.2 + Caution3[2]) / 2 +
					  (float)modulus * cal_cos(i - angle);
			E3[c++] = (float)modulus * cal_sin(i - angle);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[0] + 0.2 + Caution3[2]) / 2 +
					  (float)modulus * cal_cos(i);
			E3[c++] = (float)modulus * cal_sin(i);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;
		}
		for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
			E3[c++] = (Caution3[1] + 0.2 + Caution3[0]) / 2;
			E3[c++] = 0.0f;
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[1] + 0.2 + Caution3[0]) / 2 +
					  (float)modulus * cal_cos(i - angle);
			E3[c++] = (float)modulus * cal_sin(i - angle);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;

			E3[c++] = (Caution3[1] + 0.2 + Caution3[0]) / 2 +
					  (float)modulus * cal_cos(i);
			E3[c++] = (float)modulus * cal_sin(i);
			E3[c++] = 0.0f;
			E3[c++] = 0.5f;
			E3[c++] = 0.4f;
			E3[c++] = 0.8f;
		}
	}
}
//Coins
void FillC1(float vertex[]) {
	double angle = (2 * 3.14159265) / 80;
	double modulus = 0.05;
	int c = 0;
	// ball

	float x = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	float y = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	while ((x > Caution1[0] - 0.05 && x <= Caution1[0] + 0.25 && y > -0.08) ||
		   (x > Caution1[1] - 0.05 && x <= Caution1[1] + 0.25 && y < 0.58)) {
		x = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
		y = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	}
	c1.push_back(std::make_pair(x, y));
	for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
		vertex[c++] = x;
		vertex[c++] = y;
		vertex[c++] = 0.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 0.0f;

		vertex[c++] = x + (float)modulus * cal_cos(i - angle);
		vertex[c++] = y + (float)modulus * cal_sin(i - angle);
		vertex[c++] = 0.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 0.0f;

		vertex[c++] = x + (float)modulus * cal_cos(i);
		vertex[c++] = y + (float)modulus * cal_sin(i);
		vertex[c++] = 0.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 0.0f;
	}
}
void FillC2(float vertex[]) {
	double angle = (2 * 3.14159265) / 80;
	double modulus = 0.05;
	int c = 0;
	// ball

	float x = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	float y = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	while ((x > Caution2[0] - 0.05 && x <= Caution2[0] + 0.25 && y > -0.08) ||
		   (x > Caution2[1] - 0.05 && x <= Caution2[1] + 0.25 && y < 0.58)) {
		x = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
		y = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	}
	c2.push_back(std::make_pair(x, y));
	for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
		vertex[c++] = x;
		vertex[c++] = y;
		vertex[c++] = 0.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 0.0f;

		vertex[c++] = x + (float)modulus * cal_cos(i - angle);
		vertex[c++] = y + (float)modulus * cal_sin(i - angle);
		vertex[c++] = 0.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 0.0f;

		vertex[c++] = x + (float)modulus * cal_cos(i);
		vertex[c++] = y + (float)modulus * cal_sin(i);
		vertex[c++] = 0.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 0.0f;
	}
}
void FillC3(float vertex[]) {
	double angle = (2 * 3.14159265) / 80;
	double modulus = 0.05;
	int c = 0;
	// ball

	float x = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	float y = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	while ((x > Caution3[0] - 0.05 && x <= Caution3[0] + 0.25 && y > -0.08) ||
		   (x > Caution3[1] - 0.05 && x <= Caution3[1] + 0.25 && y < 0.58) ||
		   (x > Caution3[2] - 0.05 && x <= Caution3[2] + 0.25 && y < 0.33)) {
		x = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
		y = ((float)rand() / (float)RAND_MAX) * 3 - 1.5;
	}
	c3.push_back(std::make_pair(x, y));
	for (double i = angle; i <= 2 * 3.1415926535897; i += angle) {
		vertex[c++] = x;
		vertex[c++] = y;
		vertex[c++] = 0.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 0.0f;

		vertex[c++] = x + (float)modulus * cal_cos(i - angle);
		vertex[c++] = y + (float)modulus * cal_sin(i - angle);
		vertex[c++] = 0.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 0.0f;

		vertex[c++] = x + (float)modulus * cal_cos(i);
		vertex[c++] = y + (float)modulus * cal_sin(i);
		vertex[c++] = 0.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 1.0f;
		vertex[c++] = 0.0f;
	}
}

void game_over_message(){
    GLTtext *text1 = gltCreateText();
	gltSetText(text1, "Welcome to the arena!");
    char str[50];

    gltBeginDraw();

    gltColor(1.0f, 1.0f, 1.0f, 1.0f);
    sprintf(str, "Game over!");
    gltSetText(text1, str);
    gltDrawText2DAligned(text1,
			(GLfloat)(SCR_WIDTH / 2),
			(GLfloat)(SCR_HEIGHT / 2.1),
			5.0f,
			GLT_CENTER, GLT_CENTER);
    sprintf(str, "Score: %d", score);
    gltSetText(text1, str);
    gltDrawText2DAligned(text1,
			(GLfloat)(SCR_WIDTH / 2),
			(GLfloat)(SCR_HEIGHT / 1.5),
			3.0f,
			GLT_CENTER, GLT_CENTER);
    gltEndDraw();   
}

void HUD()
{
	GLTtext *text1 = gltCreateText();
	gltSetText(text1, "Welcome to the arena!");
    char str[50];

    gltBeginDraw();

    gltColor(1.0f, 1.0f, 1.0f, 1.0f);
    sprintf(str, "Score: %d",score);
    gltSetText(text1, str);
    gltDrawText2D(text1,1.65,1.65,2.0f);

	gltColor(1.0f, 1.0f, 1.0f, 1.0f);
    sprintf(str, "Time: %d", (int)glfwGetTime()-start_time);
    gltSetText(text1, str);
    gltDrawText2DAligned(text1,(GLfloat)SCR_WIDTH-69.0f,15.0f,2.0f, GLT_CENTER,GLT_CENTER);

	gltEndDraw();
}

int main(int argc, char **argv) {
	// glfw: initialize and configure
	srand(time(0));
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// glfw window creation
	GLFWwindow *window =
		glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// build and compile our shader program
	Shader ourShader("../src/vertex.shader", "../src/fragment.shader");
	//Generating vertices of the objects
	if(fill){
	//Player
	FillBvertices(n);
	//Room
	FillRvertices();
	//Obstacles
	FillO1vertices();
	FillO2vertices();
	FillO3vertices();
	//Enemies
	FillE1();
	FillE2();
	FillE3();
	//Coins of level-1
	FillC1(C1a);
	FillC1(C1b);
	FillC1(C1c);
	FillC1(C1d);
	//Coins of level-2
	FillC2(C2a);
	FillC2(C2b);
	FillC2(C2c);
	FillC2(C2d);
	FillC2(C2e);
	FillC2(C2f);
	//Coins of level-3
	FillC3(C3a);
	FillC3(C3b);
	FillC3(C3c);
	FillC3(C3d);
	FillC3(C3e);
	FillC3(C3f);
	FillC3(C3g);
	FillC3(C3h);
	FillC3(C3i);
	FillC3(C3j);
	}
	unsigned int NUM_Bvertices = (sizeof(Bvertices) / sizeof(Bvertices[0])) / 6;
	unsigned int NUM_Rvertices = (sizeof(Rvertices) / sizeof(Rvertices[0])) / 6;
	unsigned int NUM_Obstacle1 = (sizeof(Obstacle1) / sizeof(Obstacle1[0])) / 6;
	unsigned int NUM_Obstacle2 = (sizeof(Obstacle2) / sizeof(Obstacle2[0])) / 6;
	unsigned int NUM_Obstacle3 = (sizeof(Obstacle3) / sizeof(Obstacle3[0])) / 6;
	unsigned int NUM_Enemy1 = (sizeof(E1) / sizeof(E1[0])) / 6;
	unsigned int NUM_Enemy2 = (sizeof(E2) / sizeof(E2[0])) / 6;
	unsigned int NUM_Enemy3 = (sizeof(E3) / sizeof(E3[0])) / 6;
	

	unsigned int VBO, VAO, VAO1, VBO1, VBO2, VAO2, VBO3, VAO3, VBO4, VAO4, VAO5,
		VBO5, VAO6, VBO6, VAO7, VBO7;
	unsigned int VBOC1a, VBOC1b, VBOC1c, VBOC1d;
	unsigned int VAOC1a, VAOC1b, VAOC1c, VAOC1d;
	unsigned int VBOC2a, VBOC2b, VBOC2c, VBOC2d, VBOC2e, VBOC2f ;
	unsigned int VAOC2a, VAOC2b, VAOC2c, VAOC2d, VAOC2e, VAOC2f;
	unsigned int VBOC3a, VBOC3b, VBOC3c, VBOC3d, VBOC3e, VBOC3f,VBOC3g,VBOC3h,VBOC3i,VBOC3j  ;
	unsigned int VAOC3a, VAOC3b, VAOC3c, VAOC3d, VAOC3e, VAOC3f,VAOC3g,VAOC3h,VAOC3i,VAOC3j;

	if(rendering){
	//For Level-1 coins
	glGenVertexArrays(1, &(VAOC1a));
	glGenBuffers(1, &(VBOC1a));
	glBindVertexArray(VAOC1a);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC1a);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C1a), C1a, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC1b));
	glGenBuffers(1, &(VBOC1b));
	glBindVertexArray(VAOC1b);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC1b);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C1b), C1b, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC1c));
	glGenBuffers(1, &(VBOC1c));
	glBindVertexArray(VAOC1c);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC1c);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C1c), C1c, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC1d));
	glGenBuffers(1, &(VBOC1d));
	glBindVertexArray(VAOC1d);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC1d);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C1d), C1d, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);








	//For Level-2  Coins
	glGenVertexArrays(1, &(VAOC2a));
	glGenBuffers(1, &(VBOC2a));
	glBindVertexArray(VAOC2a);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC2a);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C2a), C2a, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC2b));
	glGenBuffers(1, &(VBOC2b));
	glBindVertexArray(VAOC2b);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC2b);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C2b), C2b, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC2c));
	glGenBuffers(1, &(VBOC2c));
	glBindVertexArray(VAOC2c);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC2c);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C2c), C2c, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC2d));
	glGenBuffers(1, &(VBOC2d));
	glBindVertexArray(VAOC2d);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC2d);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C2d), C2d, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC2e));
	glGenBuffers(1, &(VBOC2e));
	glBindVertexArray(VAOC2e);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC2e);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C2e), C2e, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC2f));
	glGenBuffers(1, &(VBOC2f));
	glBindVertexArray(VAOC2f);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC2f);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C2f), C2f, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);










	//For Level-3 coins
	glGenVertexArrays(1, &(VAOC3a));
	glGenBuffers(1, &(VBOC3a));
	glBindVertexArray(VAOC3a);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3a);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3a), C3a, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC3b));
	glGenBuffers(1, &(VBOC3b));
	glBindVertexArray(VAOC3b);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3b);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3b), C3b, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC3c));
	glGenBuffers(1, &(VBOC3c));
	glBindVertexArray(VAOC3c);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3c);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3c), C3c, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC3d));
	glGenBuffers(1, &(VBOC3d));
	glBindVertexArray(VAOC3d);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3d);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3d), C3d, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC3e));
	glGenBuffers(1, &(VBOC3e));
	glBindVertexArray(VAOC3e);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3e);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3e), C3e, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC3f));
	glGenBuffers(1, &(VBOC3f));
	glBindVertexArray(VAOC3f);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3f);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3f), C3f, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC3g));
	glGenBuffers(1, &(VBOC3g));
	glBindVertexArray(VAOC3g);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3g);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3g), C3g, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC3h));
	glGenBuffers(1, &(VBOC3h));
	glBindVertexArray(VAOC3h);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3h);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3h), C3h, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenVertexArrays(1, &(VAOC3i));
	glGenBuffers(1, &(VBOC3i));
	glBindVertexArray(VAOC3i);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3i);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3i), C3i, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);


	glGenVertexArrays(1, &(VAOC3j));
	glGenBuffers(1, &(VBOC3j));
	glBindVertexArray(VAOC3j);
	glBindBuffer(GL_ARRAY_BUFFER, VBOC3j);
	glBufferData(GL_ARRAY_BUFFER, sizeof(C3j), C3j, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);






	// FOR PLAYER
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Bvertices), Bvertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	// FOR ROOM
	glGenVertexArrays(1, &VAO1);
	glBindVertexArray(VAO1);

	glGenBuffers(1, &VBO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Rvertices), Rvertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(0, VBO1);
	glBindVertexArray(0);

	// FOR LEVEL-1 OBSTACLE
	glGenVertexArrays(1, &VAO2);
	glBindVertexArray(VAO2);

	glGenBuffers(1, &VBO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Obstacle1), Obstacle1, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(0, VBO2);
	glBindVertexArray(0);

	// FOR LEVEL-2 OBSTACLE
	glGenVertexArrays(1, &VAO3);
	glBindVertexArray(VAO3);

	glGenBuffers(1, &VBO3);
	glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Obstacle2), Obstacle2, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(0, VBO3);
	glBindVertexArray(0);

	// FOR LEVEL-3 OBSTACLE
	glGenVertexArrays(1, &VAO4);
	glBindVertexArray(VAO4);

	glGenBuffers(1, &VBO4);
	glBindBuffer(GL_ARRAY_BUFFER, VBO4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Obstacle3), Obstacle3, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(0, VBO4);
	glBindVertexArray(0);

	// FOR LEVEL-1 ENEMY
	glGenVertexArrays(1, &VAO5);
	glBindVertexArray(VAO5);

	glGenBuffers(1, &VBO5);
	glBindBuffer(GL_ARRAY_BUFFER, VBO5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(E1), E1, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(0, VBO5);
	glBindVertexArray(0);

	// FOR LEVEL-2 ENEMY
	glGenVertexArrays(1, &VAO6);
	glBindVertexArray(VAO6);

	glGenBuffers(1, &VBO6);
	glBindBuffer(GL_ARRAY_BUFFER, VBO6);
	glBufferData(GL_ARRAY_BUFFER, sizeof(E2), E2, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(0, VBO6);
	glBindVertexArray(0);

	// FOR LEVEL-3 ENEMY
	glGenVertexArrays(1, &VAO7);
	glBindVertexArray(VAO7);

	glGenBuffers(1, &VBO7);
	glBindBuffer(GL_ARRAY_BUFFER, VBO7);
	glBufferData(GL_ARRAY_BUFFER, sizeof(E3), E3, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
						  (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(0, VBO7);
	glBindVertexArray(0);
	}
	// enable depth testing for 3d
	glEnable(GL_DEPTH_TEST);

	//Heads Up Display
	gltInit();
    GLTtext *text1 = gltCreateText();
	gltSetText(text1, "Welcome to the arena!");

	start_time = (int)glfwGetTime();
	// render loop
	while (!glfwWindowShouldClose(window)) {
		// input
		processInput(window);

		// render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if(game_over)
		{
			game_over_message();
			sleep(3);
			glfwSetWindowShouldClose(window, true);
			return 0;
		}
		else 
			HUD();

		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS &&
			objPos[1] < 1.64f) {
			if (level == 1) {
				if (!(objPos[0] > Caution1[0] - 0.08 &&
					  objPos[0] < Caution1[0] + 0.28 && objPos[1] > -0.1)) {
					objPos[1] += 0.01f;
					transform =
						glm::translate(transform, glm::vec3(0.0f, 0.01f, 0.0f));
				}
			} else if (level == 2) {
				if (!(objPos[0] > Caution2[0] - 0.08 &&
					  objPos[0] < Caution2[0] + 0.28 && objPos[1] > -0.1)) {
					objPos[1] += 0.01f;
					transform =
						glm::translate(transform, glm::vec3(0.0f, 0.01f, 0.0f));
				}
			} else if (level == 3) {
				if (!(objPos[0] > Caution3[0] - 0.08 &&
					  objPos[0] < Caution3[0] + 0.28 && objPos[1] > -0.1)) {
					objPos[1] += 0.01f;
					transform =
						glm::translate(transform, glm::vec3(0.0f, 0.01f, 0.0f));
				}
			}
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS &&
			objPos[1] > -1.64f) {
			if (level == 1) {
				if (!(objPos[0] > Caution1[1] - 0.08 &&
					  objPos[0] < Caution1[1] + 0.28 && objPos[1] < 0.6)) {
					objPos[1] -= 0.01f;
					transform = glm::translate(transform,
											   glm::vec3(0.0f, -0.01f, 0.0f));
				}
			}
			if (level == 2) {
				if (!(objPos[0] > Caution2[1] - 0.08 &&
					  objPos[0] < Caution2[1] + 0.28 && objPos[1] < 0.6)) {
					objPos[1] -= 0.01f;
					transform = glm::translate(transform,
											   glm::vec3(0.0f, -0.01f, 0.0f));
				}
			}
			if (level == 3) {
				if (!((objPos[0] > Caution3[1] - 0.08 &&
					   objPos[0] < Caution3[1] + 0.28 && objPos[1] < 0.6) ||
					  (objPos[0] > Caution3[2] - 0.08 &&
					   objPos[0] < Caution3[2] + 0.28 && objPos[1] < 0.35))) {
					objPos[1] -= 0.01f;
					transform = glm::translate(transform,
											   glm::vec3(0.0f, -0.01f, 0.0f));
				}
			}
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS &&
			objPos[0] < 1.64f) {
			if (level == 1) {
				if (!((objPos[0] > Caution1[1] - 0.1 &&
					   objPos[0] < Caution1[1] && objPos[1] < 0.58) ||
					  (objPos[0] > Caution1[0] - 0.1 &&
					   objPos[0] < Caution1[0] && objPos[1] > -0.08))) {
					objPos[0] += 0.01f;
					transform =
						glm::translate(transform, glm::vec3(0.01f, 0.0f, 0.0f));
				}
			}
			if (level == 2) {
				if (!((objPos[0] > Caution2[1] - 0.1 &&
					   objPos[0] < Caution2[1] && objPos[1] < 0.58) ||
					  (objPos[0] > Caution2[0] - 0.1 &&
					   objPos[0] < Caution2[0] && objPos[1] > -0.08))) {
					objPos[0] += 0.01f;
					transform =
						glm::translate(transform, glm::vec3(0.01f, 0.0f, 0.0f));
				}
			}
			if (level == 3) {
				if (!((objPos[0] > Caution3[1] - 0.1 &&
					   objPos[0] < Caution3[1] && objPos[1] < 0.58) ||
					  (objPos[0] > Caution3[2] - 0.1 &&
					   objPos[0] < Caution3[2] && objPos[1] < 0.33) ||
					  (objPos[0] > Caution3[0] - 0.1 &&
					   objPos[0] < Caution3[0] && objPos[1] > -0.08))) {
					objPos[0] += 0.01f;
					transform =
						glm::translate(transform, glm::vec3(0.01f, 0.0f, 0.0f));
				}
			}
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS &&
			objPos[0] > -1.64f) {
			if (level == 1) {
				if (!((objPos[0] > Caution1[1] &&
					   objPos[0] < Caution1[1] + 0.3 && objPos[1] < 0.58) ||
					  (objPos[0] > Caution1[0] &&
					   objPos[0] < Caution1[0] + 0.3 && objPos[1] > -0.08))) {
					objPos[0] -= 0.01f;
					transform = glm::translate(transform,
											   glm::vec3(-0.01f, 0.0f, 0.0f));
				}
			}
			if (level == 2) {
				if (!((objPos[0] > Caution2[1] &&
					   objPos[0] < Caution2[1] + 0.3 && objPos[1] < 0.58) ||
					  (objPos[0] > Caution2[0] &&
					   objPos[0] < Caution2[0] + 0.3 && objPos[1] > -0.08))) {
					objPos[0] -= 0.01f;
					transform = glm::translate(transform,
											   glm::vec3(-0.01f, 0.0f, 0.0f));
				}
			}
			if (level == 3) {
				if (!((objPos[0] > Caution3[1] &&
					   objPos[0] < Caution3[1] + 0.3 && objPos[1] < 0.58) ||
					  (objPos[0] > Caution3[2] &&
					   objPos[0] < Caution3[2] + 0.3 && objPos[1] < 0.33) ||
					  (objPos[0] > Caution3[0] &&
					   objPos[0] < Caution3[0] + 0.3 && objPos[1] > -0.08))) {
					objPos[0] -= 0.01f;
					transform = glm::translate(transform,
											   glm::vec3(-0.01f, 0.0f, 0.0f));
				}
			}
		}

		ourShader.use();
		ourShader.setMat4("transform", transform);

		// view matrix
		glm::mat4 view = camera.GetViewMatrix(glm::vec3(0.0f));

		// glm::mat4 view = glm::lookAt(camera.Position, camera.Front,
		// camera.Up);
		ourShader.setMat4("view", view);

		// projection matrix

		glm::mat4 projection = glm::perspective(
			glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT,
			0.1f, 100.0f);
		ourShader.setMat4("projection", projection);
		//Rendering player
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, NUM_Bvertices);
		glBindVertexArray(0);
		//enemy movement
		if (up) {
			if (enemy < 1.64f) {
				enemy += 0.02f;
				transform2 =
					glm::translate(transform2, glm::vec3(0.00f, 0.02f, 0.0f));
			} else
				up = false;
		} else {
			if (enemy >= -1.64f) {
				enemy -= 0.02f;
				transform2 =
					glm::translate(transform2, glm::vec3(0.00f, -0.02f, 0.0f));
			} else
				up = true;
		}
		//Rendering Enemy
		ourShader.setMat4("transform", transform2);
		if (level == 1) {
			glBindVertexArray(VAO5);
			glDrawArrays(GL_TRIANGLES, 0, NUM_Enemy1);
			glBindVertexArray(0);
		} else if (level == 2) {
			glBindVertexArray(VAO6);
			glDrawArrays(GL_TRIANGLES, 0, NUM_Enemy2);
			glBindVertexArray(0);
		} else if (level == 3) {
			glBindVertexArray(VAO7);
			glDrawArrays(GL_TRIANGLES, 0, NUM_Enemy3);
			glBindVertexArray(0);
		}

		transform1 = glm::mat4(1.0f);
		ourShader.setMat4("transform", transform1);
		//Rendering Room
		glBindVertexArray(VAO1);
		glDrawArrays(GL_TRIANGLES, 0, NUM_Rvertices);
		glBindVertexArray(0);
		//Rendering Obstacle
		if (level == 1) {
			glBindVertexArray(VAO2);
			glDrawArrays(GL_TRIANGLES, 0, NUM_Obstacle1);
			glBindVertexArray(0);
		} else if (level == 2) {
			glBindVertexArray(VAO3);
			glDrawArrays(GL_TRIANGLES, 0, NUM_Obstacle2);
			glBindVertexArray(0);
		} else if (level == 3) {
			glBindVertexArray(VAO4);
			glDrawArrays(GL_TRIANGLES, 0, NUM_Obstacle3);
			glBindVertexArray(0);
		}


		// Rendering Coins and checking touch of coin
		if (level == 1) {
			if (b1[0] == 1) {
				glBindVertexArray(VAOC1a);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b1[1] == 1) {
				glBindVertexArray(VAOC1b);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b1[2] == 1) {
				glBindVertexArray(VAOC1c);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b1[3] == 1) {
				glBindVertexArray(VAOC1d);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			for (int i = 0; i < 4; i++) {
				float cxi = c1[i].first;
				float cxj = c1[i].second;

				if (objPos[0] + 0.1 >= cxi - 0.05 &&
					objPos[0] - 0.1 <= cxi + 0.05 &&
					objPos[1] + 0.1 >= cxj - 0.05 && objPos[1] <= cxj + 0.15 && b1[i]==1) {
					b1[i] = 0;
					score+=50;
				}
			}
		}
		else if(level==2)
		{
			if (b2[0] == 1) {
				glBindVertexArray(VAOC2a);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b2[1] == 1) {
				glBindVertexArray(VAOC2b);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b2[2] == 1) {
				glBindVertexArray(VAOC2c);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b2[3] == 1) {
				glBindVertexArray(VAOC2d);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}

			if (b2[4] == 1) {
				glBindVertexArray(VAOC2e);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b2[5] == 1) {
				glBindVertexArray(VAOC2f);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			for (int i = 0; i < 6; i++) {
				float cxi = c2[i].first;
				float cxj = c2[i].second;

				if (objPos[0] + 0.1 >= cxi - 0.05 &&
					objPos[0] - 0.1 <= cxi + 0.05 &&
					objPos[1] + 0.1 >= cxj - 0.05 && objPos[1] <= cxj + 0.15 && b2[i]==1) {
					b2[i] = 0;
					score+=50;
				}
			}
		}
		else if(level==3)
		{
			if (b3[0] == 1) {
				glBindVertexArray(VAOC3a);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b3[1] == 1) {
				glBindVertexArray(VAOC3b);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b3[2] == 1) {
				glBindVertexArray(VAOC3c);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b3[3] == 1) {
				glBindVertexArray(VAOC3d);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}

			if (b3[4] == 1) {
				glBindVertexArray(VAOC3e);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b3[5] == 1) {
				glBindVertexArray(VAOC3f);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b3[6] == 1) {
				glBindVertexArray(VAOC3g);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b3[7] == 1) {
				glBindVertexArray(VAOC3h);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b3[8] == 1) {
				glBindVertexArray(VAOC3i);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			if (b3[9] == 1) {
				glBindVertexArray(VAOC3j);
				glDrawArrays(GL_TRIANGLES, 0, 240);
				glBindVertexArray(0);
			}
			for (int i = 0; i < 10; i++) {
				float cxi = c3[i].first;
				float cxj = c3[i].second;

				if (objPos[0] + 0.1 >= cxi - 0.05 &&
					objPos[0] - 0.1 <= cxi + 0.05 &&
					objPos[1] + 0.1 >= cxj - 0.05 && objPos[1] <= cxj + 0.15 && b3[i]==1) {
					b3[i] = 0;
					score+=50;
				}
			}
		}
		// Gate Touch
		if (objPos[0] >= 1.64 && objPos[1] <= 0.2 && objPos[1] >= -0.2) {
			if (level < 3)
				level++;
			else if (level == 3) {
				game_over=true;
				std::cout << "Game Over!!" << std::endl;
				std ::cout << "Score: " << score << std::endl;
				game_over_message();
				
			}
			objPos[0] = -1.65;
			objPos[1] = 0.0f;
			transform = glm::mat4(1.0f);
		}
		//Enemy Touch
		if (level == 1) {
			float cx = (Caution1[0] + 0.2 + Caution1[1]) / 2;
			if (objPos[0] + 0.1 >= cx - 0.1 && objPos[0] - 0.1 <= cx + 0.1 &&
				objPos[1] + 0.1 >= enemy - 0.1 && objPos[1] <= enemy + 0.2) {
				game_over=true;	
				std::cout << "Game Over!!" << std::endl;
				std ::cout << "Score: " << score << std::endl;
				game_over_message();
				
			}
		} else if (level == 2) {
			float cx = (Caution2[0] + 0.2 + Caution2[1]) / 2;
			float cx1 = 1.6;
			if (objPos[0] + 0.1 >= cx - 0.1 && objPos[0] - 0.1 <= cx + 0.1 &&
				objPos[1] + 0.1 >= enemy - 0.1 && objPos[1] <= enemy + 0.2) {
				game_over=true;
				std::cout << "Game Over!!" << std::endl;
				std ::cout << "Score: " << score << std::endl;
				game_over_message();
				
			}
			if (objPos[0] + 0.1 >= cx1 - 0.1 && objPos[0] - 0.1 <= cx1 + 0.1 &&
				objPos[1] + 0.1 >= enemy - 0.1 && objPos[1] <= enemy + 0.2) {
				game_over=true;
				std::cout << "Game Over!!" << std::endl;
				std ::cout << "Score: " << score << std::endl;
				game_over_message();
				
			}
		} else if (level == 3) {
			float cx1 = 1.6;
			float cx, cx2;
			if (objPos[0] + 0.1 >= cx1 - 0.1 && objPos[0] - 0.1 <= cx1 + 0.1 &&
				objPos[1] + 0.1 >= enemy - 0.1 && objPos[1] <= enemy + 0.2) {
				game_over=true;
				std::cout << "Game Over!!" << std::endl;
				std ::cout << "Score: " << score << std::endl;
				game_over_message();
				
			}
			float temp[3];
			temp[0] = Caution3[1] > Caution3[2] ? Caution3[1] - Caution3[2]
												: Caution3[2] - Caution3[1];
			temp[1] = Caution3[1] > Caution3[0] ? Caution3[1] - Caution3[0]
												: Caution3[0] - Caution3[1];
			temp[2] = Caution3[0] > Caution3[2] ? Caution3[0] - Caution3[2]
												: Caution3[2] - Caution3[0];

			if (temp[2] > temp[1] && temp[2] > temp[0]) {
				cx = (Caution3[0] + 0.2 + Caution3[1]) / 2;

				cx2 = (Caution3[1] + 0.2 + Caution3[2]) / 2;
			}
			else if (temp[1] > temp[2] && temp[1] > temp[0]) {
				cx = (Caution3[0] + 0.2 + Caution3[2]) / 2;
				cx2 = (Caution3[1] + 0.2 + Caution3[2]) / 2;
			}
			else if (temp[0] > temp[2] && temp[0] > temp[1]) {
				cx = (Caution3[0] + 0.2 + Caution3[2]) / 2;
				cx2 = (Caution3[1] + 0.2 + Caution3[0]) / 2;
			}
			if (objPos[0] + 0.1 >= cx - 0.1 && objPos[0] - 0.1 <= cx + 0.1 &&
				objPos[1] + 0.1 >= enemy - 0.1 && objPos[1] <= enemy + 0.2) {
				game_over=true;
				std::cout << "Game Over!!" << std::endl;
				std ::cout << "Score: " << score << std::endl;
				game_over_message();
				
			}
			if (objPos[0] + 0.1 >= cx2 - 0.1 && objPos[0] - 0.1 <= cx2 + 0.1 &&
				objPos[1] + 0.1 >= enemy - 0.1 && objPos[1] <= enemy + 0.2) {
				game_over=true;
				std::cout << "Game Over!!" << std::endl;
				std ::cout << "Score: " << score << std::endl;
				game_over_message();
				
			}
		}

		// glfw: swap buffers and poll IO events (keys pressed/released,
		// mouse moved etc.)
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their
	// purpose:
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glDeleteVertexArrays(1, &VAO1);
	glDeleteBuffers(1, &VBO1);

	// glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	return 0;
}


void processInput(GLFWwindow *window) {
	float cameraSpeed = static_cast<float>(2.5 * deltaTime);
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}
