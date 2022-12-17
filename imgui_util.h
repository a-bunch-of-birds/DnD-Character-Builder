#pragma once

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <vector>
#include <algorithm>

#include "abilityscore.h"
#include "species.h"
#include "charclass.h"
#include "command.h"

class ImGuiUtil {
public:
	static void HelpMarker(const char* desc);
	void Init(GLFWwindow* window);
	void NewFrame();
	void HistoUndo(bool& swap_disabled, bool& threerolls, int& three_roll_ctr, Abilityscore& obj);
	void Histogram(Abilityscore& obj, bool swap_disabled);
	void SpeciesList(Abilityscore& abilities, Species species);
	void ClassList(Abilityscore& abilities, Charclass& chrctr);
	void LevelUp(Abilityscore& abilities, Charclass& chrctr, int& abscore_total, Invoker* cmt_inv);
	void ScoreDisplay(Abilityscore& abilities);
	virtual void Update(int& abscore_total, bool mode, bool is_commit_clicked, Abilityscore& abilities, Species species, 
		Charclass& chrctr, Invoker res_inv, Invoker clr_inv, Invoker roll_inv, Invoker cmt_inv, ImGuiUtil util);
	void Render();
	void Shutdown();
};