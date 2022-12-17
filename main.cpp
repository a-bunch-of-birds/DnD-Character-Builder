#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "character.h"
#include "charclass.h"
#include "abilityscore.h"
#include "species.h"
#include "command.h"
#include "imgui_util.h"

bool is_commit_clicked = false; //need this as a global variable

int abscore_total = 0;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void init()
{
	std::cout << "Future dev" << std::endl;
}

void display()
{
	std::cout << "Future dev" << std::endl;
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//GLFWwindow* window = glfwCreateWindow(800, 600, "Character Creator", NULL, NULL);
	GLFWwindow* window = glfwCreateWindow(1500, 900, "Character Creator", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	srand(time(NULL)); //seed rand()
	
	Abilityscore abilities; //create class object to retain and work with scores
	Species species;
	Charclass chrctr;

	//adding command interface
	RollComm roll_bttn(&abilities);
	Invoker roll_inv(&roll_bttn);

	RollComm res(&abilities);
	Invoker res_inv(&res);

	ClrComm clr(&abilities);
	Invoker clr_inv(&clr);

	CommitRollComm cmt(&abilities);
	Invoker cmt_inv(&cmt);
	
	//testing imgui wrapper
	ImGuiUtil util;

	util.Init(window);
	
	while (!glfwWindowShouldClose(window))
	{
		process_input(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		util.NewFrame();
		util.Update(abscore_total, true, is_commit_clicked, abilities, species, chrctr, res_inv, clr_inv, roll_inv, cmt_inv, util);
		util.Render();
		
		glfwSwapBuffers(window);	
		glfwPollEvents();

	}

	/*testing to see what the init_scores vector looks like to ensure it has the right organization of data*/
	for (auto ec : abilities.fetch_init_scores())
	{
		std::cout << ec << std::endl;
	}
	std::cout << "Here are the final stored ability scores from the ability scores struct" << std::endl;
	std::cout << abilities.StrengthScore() << std::endl;
	std::cout << abilities.DexterityScore() << std::endl;
	std::cout << abilities.ConstitutionScore() << std::endl;
	std::cout << abilities.IntelligenceScore() << std::endl;
	std::cout << abilities.WisdomScore() << std::endl;
	std::cout << abilities.CharismaScore() << std::endl;

	std::cout << "Here are the final stored ability modifiers from the ability scores struct" << std::endl;

	std::cout << abilities.StrAbm() << std::endl;
	std::cout << abilities.DexAbm() << std::endl;
	std::cout << abilities.ConAbm() << std::endl;
	std::cout << abilities.IntAbm() << std::endl;
	std::cout << abilities.WisAbm() << std::endl;
	std::cout << abilities.ChaAbm() << std::endl;

	std::cout << "class scores" << std::endl;
	std::cout << "HP: ";
	std::cout << chrctr.csumm.hit_points << std::endl;
	std::cout << "Hit die: ";
	std::cout << chrctr.csumm.hit_dice << std::endl;
	std::cout << "level: ";
	std::cout << chrctr.csumm.level << std::endl;
	std::cout << "prof bonus: ";
	std::cout << chrctr.csumm.prof_bonus << std::endl;
	std::cout << "spell save dc: ";
	std::cout << chrctr.csumm.spell_save_dc << std::endl;
	std::cout << "spell attack mod: ";
	std::cout << chrctr.csumm.spell_attk_mod << std::endl;

	util.Shutdown();
	glfwTerminate();

	return 0;
}