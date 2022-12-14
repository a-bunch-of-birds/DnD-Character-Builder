#include "imgui_util.h"

void ImGuiUtil::HelpMarker(const char* desc)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void ImGuiUtil::Init(GLFWwindow* window) {
	
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void ImGuiUtil::NewFrame() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void ImGuiUtil::HistoUndo(bool& swap_disabled, bool& threerolls, int& three_roll_ctr, Abilityscore& obj) {
	/*
	* NOTE: THIS IS EXPERIMENTAL AND SHOULD NOT BE EXPANDED INTO ACTUAL FUNCTIONALITY
	* - using three_roll_ctr as your marker and then decrementing it is not the intended final functionality
	* - proof of concept ONLY for undo/redo
	*/
	
	swap_disabled = false;
	if (three_roll_ctr > 0) {
		if (three_roll_ctr == 3) {
			//block here to keep the value
			threerolls = true;
		}
		else {
			three_roll_ctr--;
		}
	}
	if (three_roll_ctr == 0) {
		threerolls = false;
	}
	std::sort(obj.fetch_init_scores().rbegin(), obj.fetch_init_scores().rend());
}

void ImGuiUtil::Histogram(Abilityscore& obj, bool swap_disabled) {
	
	float histogram_conv[6]; //we need floats for the integer values to show up on an ImGui histogram, so we're gonna static cast as float below and shove into a raw array
	for (int a = 0; a < obj.fetch_init_scores().size(); a++)
	{ 
		histogram_conv[a] = obj.fetch_init_scores()[a];
	}
	
	ImGui::PlotHistogram("##Rolled results", histogram_conv, IM_ARRAYSIZE(histogram_conv), 0, NULL, 1.0, 20.0, ImVec2(520.0f, 200.0f));
	
	ImGui::BeginDisabled(swap_disabled);

	for (auto y : obj.skills)
	{
		int ymarker = 0;
		ImGui::PushID(ymarker);
		const char* sbuffer;
		sbuffer = y.c_str();
		ImGui::Button(sbuffer, ImVec2(80.0f, 60.0f));
		ImGui::PopID();
		ImGui::SameLine();
		ymarker++;
	}

	ImGui::Spacing();
	const char* swap_array[6]; //creating a swap array for drag and drop of const char*; will be filled with data from the init_scores vector

	for (int v = 0; v < obj.fetch_init_scores().size(); v++)
	{
		//long laborious process to meet the const char* label reqs for buttons and text --
		//use sprintf_s to gt the ints to chars and shunt each int-to-char to the Button
		char ibuffer[50];
		int cti = 0;
		cti = obj.fetch_init_scores()[v]; //we also need an explicit int to sort values
		sprintf_s(ibuffer, "%d", cti);
		const char* si = ibuffer;
		swap_array[v] = si;

		ImGui::PushID(v);

		ImGui::Button(si, ImVec2(80.0f, 60.0f));

		//*****DRAG DROP*****

		if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None))
		{
			ImGui::SetDragDropPayload("PASS_PAYLOAD", &v, sizeof(int));
			ImGui::EndDragDropSource();
		}
		if (ImGui::BeginDragDropTarget())
		{
			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("PASS_PAYLOAD"))
			{
				IM_ASSERT(payload->DataSize == sizeof(int));
				int payload_v = *(const int*)payload->Data;
				const char* tmp = swap_array[v];
				swap_array[v] = swap_array[payload_v];
				swap_array[payload_v] = tmp;
				std::iter_swap(obj.fetch_init_scores().begin() + payload_v, obj.fetch_init_scores().begin() + v); //swap the elements in the ACTUAL vector

			}
			ImGui::EndDragDropTarget();
		}

		ImGui::PopID();
		ImGui::SameLine();
	}

	ImGui::EndDisabled();

	ImGui::Spacing();

	int abm_array[6]; //set up ability modifier scores into an array so we can convert to const char*
	for (int abm_ticker = 0; abm_ticker < 6; abm_ticker++)
	{
		if (!obj.fetch_init_scores().empty())
		{
			abm_array[abm_ticker] = obj.ability_modifier(obj.fetch_init_scores()[abm_ticker]);
		}
	}
}

void ImGuiUtil::SpeciesList(Abilityscore& abilities, Species species) {
	const char* species_selec[] = { " ", "Dwarf", "Elf", "Halfling", "Human", "Dragonborn", "Gnome", "Half-Elf", "Half-Orc", "Tiefling" };
	static int species_current_idx = 0;
	static bool species_picked = false;
	ImGui::BeginDisabled(species_picked);
	//if (ImGui::BeginListBox("##listbox_species", ImVec2(-FLT_MIN, 5 * ImGui::GetTextLineHeightWithSpacing())))
	ImGui::Text("Species Selection: ");
	if (ImGui::BeginListBox("##listbox_species", ImVec2(425, 0)))
	{
		for (int n = 0; n < IM_ARRAYSIZE(species_selec); n++)
		{
			const bool is_selected = (species_current_idx == n);
			if (ImGui::Selectable(species_selec[n], is_selected))
				species_current_idx = n;

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();
			//if (is_selected && ImGui::IsItemClicked(0))
			if (ImGui::IsItemClicked(0) && is_selected)
			{

				if (species_current_idx == 1)
				{
					species.default_dwarf(abilities);
					ImGui::OpenPopup("Please select a dwarf sub-species");
				}
				if (species_current_idx == 2)
				{
					species.default_elf(abilities);
					ImGui::OpenPopup("Please select an elf sub-species");
				}
				if (species_current_idx == 3)
				{
					species.default_halfling(abilities);
					ImGui::OpenPopup("Please select a halfling sub-species");
				}
				if (species_current_idx == 4)
				{
					species.human(abilities);
					species_picked = true; //no popup here so we can disable the block straight away
				}
				if (species_current_idx == 5)
				{
					species.dragonborn(abilities);
					species_picked = true;
				}
				if (species_current_idx == 6)
				{
					species.default_gnome(abilities);
					ImGui::OpenPopup("Please select a gnome sub-species");
				}
				if (species_current_idx == 7)
				{
					species.default_halfelf(abilities);
					ImGui::OpenPopup("Please select (2) ability scores to boost by +1");
				}
				if (species_current_idx == 8)
				{
					species.halforc(abilities);
					species_picked = true;
				}
				if (species_current_idx == 9)
				{
					species.tiefling(abilities);
					species_picked = true;
				}
			}
		}

		//declaring the CENTER ImVec2 variable for the SetNextWindowPos function
		//this has a scope over all of the sub menus, and so only needs to be declared here for use down the line
		ImVec2 center = ImGui::GetMainViewport()->GetCenter();
		ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
		const char* subspecies_selec_dw[] = { "Hill Dwarf", "Mountain Dwarf" };
		static int subsp_curr_idx_dw = 0;
		if (ImGui::BeginPopupModal("Please select a dwarf sub-species", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::Text("Dwarf Sub-Species");
			if (ImGui::BeginListBox("##listbox_dwarf"))
			{
				for (int n = 0; n < IM_ARRAYSIZE(subspecies_selec_dw); n++)
				{
					const bool is_selected = (subsp_curr_idx_dw == n);
					if (ImGui::Selectable(subspecies_selec_dw[n], is_selected))
						subsp_curr_idx_dw = n;

					// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
					if (is_selected)
						ImGui::SetItemDefaultFocus();
					if (ImGui::IsItemClicked(0))
					{
						if (subsp_curr_idx_dw == 0)
						{
							species.hill_dwarf(abilities);
							ImGui::CloseCurrentPopup();
							species_picked = true;

						}
						if (subsp_curr_idx_dw == 1)
						{
							species.mountain_dwarf(abilities);
							ImGui::CloseCurrentPopup();
							species_picked = true;

						}
					}
				}
				ImGui::EndListBox();
			}

			//if (ImGui::Button("Close"))
			//{
			//	ImGui::CloseCurrentPopup();
			//}

			ImGui::EndPopup();
		}

		//ImVec2 center = ImGui::GetMainViewport()->GetCenter();
		ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
		const char* subspecies_selec_el[] = { "High Elf", "Wood Elf", "Dark Elf (Drow)" };
		static int subsp_curr_idx_el = 0;
		if (ImGui::BeginPopupModal("Please select an elf sub-species", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::Text("Elf Sub-Species");
			if (ImGui::BeginListBox("##listbox_elf"))
			{
				for (int n = 0; n < IM_ARRAYSIZE(subspecies_selec_el); n++)
				{
					const bool is_selected = (subsp_curr_idx_el == n);
					if (ImGui::Selectable(subspecies_selec_el[n], is_selected))
						subsp_curr_idx_el = n;

					// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
					if (is_selected)
						ImGui::SetItemDefaultFocus();
					if (ImGui::IsItemClicked(0))
					{
						if (subsp_curr_idx_el == 0)
						{
							species.high_elf(abilities);
							ImGui::CloseCurrentPopup();
							species_picked = true;

						}
						if (subsp_curr_idx_el == 1)
						{
							species.wood_elf(abilities);
							ImGui::CloseCurrentPopup();
							species_picked = true;

						}
						if (subsp_curr_idx_el == 3)
						{
							species.dark_elf(abilities);
							ImGui::CloseCurrentPopup();
							species_picked = true;
						}
					}
				}
				ImGui::EndListBox();
			}

			//if (ImGui::Button("Close"))
			//{
			//	ImGui::CloseCurrentPopup();
			//}

			ImGui::EndPopup();
		}

		ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
		const char* subspecies_selec_halfl[] = { "Lightfoot Halfling", "Stout Halfling" };
		static int subsp_curr_idx_halfl = 0;
		if (ImGui::BeginPopupModal("Please select a halfling sub-species", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::Text("Halfling Sub-Species");
			if (ImGui::BeginListBox("##listbox_halfl"))
			{
				for (int n = 0; n < IM_ARRAYSIZE(subspecies_selec_halfl); n++)
				{
					const bool is_selected = (subsp_curr_idx_halfl == n);
					if (ImGui::Selectable(subspecies_selec_halfl[n], is_selected))
						subsp_curr_idx_halfl = n;

					// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
					if (is_selected)
						ImGui::SetItemDefaultFocus();
					if (ImGui::IsItemClicked(0))
					{
						if (subsp_curr_idx_halfl == 0)
						{
							species.lightfoot_halfling(abilities);
							ImGui::CloseCurrentPopup();
							species_picked = true;

						}
						if (subsp_curr_idx_halfl == 1)
						{
							species.stout_halfling(abilities);
							ImGui::CloseCurrentPopup();
							species_picked = true;

						}

					}
				}
				ImGui::EndListBox();
			}

			//if (ImGui::Button("Close"))
			//{
			//	ImGui::CloseCurrentPopup();
			//}

			ImGui::EndPopup();
		}

		ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
		const char* subspecies_selec_gnome[] = { "Forest Gnome", "Rock Gnome" };
		static int subsp_curr_idx_gnome = 0;
		if (ImGui::BeginPopupModal("Please select a gnome sub-species", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::Text("Gnome Sub-Species");
			if (ImGui::BeginListBox("##listbox_gnome"))
			{
				for (int n = 0; n < IM_ARRAYSIZE(subspecies_selec_gnome); n++)
				{
					const bool is_selected = (subsp_curr_idx_gnome == n);
					if (ImGui::Selectable(subspecies_selec_gnome[n], is_selected))
						subsp_curr_idx_gnome = n;

					// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
					if (is_selected)
						ImGui::SetItemDefaultFocus();
					if (ImGui::IsItemClicked(0))
					{
						if (subsp_curr_idx_gnome == 0)
						{
							species.forest_gnome(abilities);
							ImGui::CloseCurrentPopup();
							species_picked = true;

						}
						if (subsp_curr_idx_halfl == 1)
						{
							species.rock_gnome(abilities);
							ImGui::CloseCurrentPopup();
							species_picked = true;

						}

					}
				}
				ImGui::EndListBox();
			}

			//if (ImGui::Button("Close"))
			//{
			//	ImGui::CloseCurrentPopup();
			//}

			ImGui::EndPopup();
		}

		ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
		if (ImGui::BeginPopupModal("Please select (2) ability scores to boost by +1", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{

			//static bool cha_a = false;
			//static bool cha_b = false;

			static bool halfelf_commit = false;

			ImGui::Text("Please select first score to +1:");
			ImGui::SameLine();
			//HelpMarker("NOTE: (1) You cannot boost your charisma score further as it is already +2; (2) You cannot boost the same score twice!");

			static bool str_a = false;
			static bool str_n = false;
			static bool dex_a = false;
			static bool dex_n = false;
			static bool con_a = false;
			static bool con_n = false;
			static bool intl_a = false;
			static bool intl_n = false;
			static bool wis_a = false;
			static bool wis_n = false;

			static bool choice_a_disabled = false;
			static bool choice_b_disabled = true;
			ImGui::BeginDisabled(choice_a_disabled);

			ImGui::Checkbox("STR##1", &str_a);
			ImGui::Checkbox("DEX##1", &dex_a);
			ImGui::Checkbox("CON##1", &con_a);
			ImGui::Checkbox("INT##1", &intl_a);
			ImGui::Checkbox("WIS##1", &wis_a);
			//ImGui::Checkbox("CHA", &cha_a);

			if (str_a == true || dex_a == true || con_a == true || intl_a == true || wis_a == true)
			{
				choice_a_disabled = true;
				choice_b_disabled = false;
			}
			ImGui::EndDisabled();


			static bool str_b = false;
			static bool dex_b = false;
			static bool con_b = false;
			static bool intl_b = false;
			static bool wis_b = false;
			//static bool choice_b_disabled = false;
			ImGui::BeginDisabled(choice_b_disabled);

			ImGui::Text("Please select second score to +1:");
			ImGui::BeginDisabled(str_a);
			ImGui::Checkbox("STR##2", &str_b);
			ImGui::EndDisabled();
			ImGui::BeginDisabled(dex_a);
			ImGui::Checkbox("DEX##2", &dex_b);
			ImGui::EndDisabled();
			ImGui::BeginDisabled(con_a);
			ImGui::Checkbox("CON##2", &con_b);
			ImGui::EndDisabled();
			ImGui::BeginDisabled(intl_a);
			ImGui::Checkbox("INT##2", &intl_b);
			ImGui::EndDisabled();
			ImGui::BeginDisabled(wis_a);
			ImGui::Checkbox("WIS##2", &wis_b);
			ImGui::EndDisabled();
			//ImGui::Checkbox("CHA", &cha_b);

			if (str_b == true || dex_b == true || con_b == true || intl_b == true || wis_b == true)
			{
				choice_b_disabled = true;
			}
			ImGui::EndDisabled();

			char a = 'z';
			char b = 'z';

			if (str_a == true)
			{
				a = 's';
			}
			else if (dex_a == true)
			{
				a = 'd';
			}
			else if (con_a == true)
			{
				a = 'c';
			}
			else if (intl_a == true)
			{
				a = 'i';
			}
			else if (wis_a == true)
			{
				a = 'w';
			}

			else
			{
				//std::cout << "char a conditionals have a problem" << std::endl;
			}

			if (str_b == true)
			{
				b = 's';
			}
			else if (dex_b == true)
			{
				b = 'd';
			}
			else if (con_b == true)
			{
				b = 'c';
			}
			else if (intl_b == true)
			{
				b = 'i';
			}
			else if (wis_b == true)
			{
				b = 'w';
			}

			else
			{
				//std::cout << "char b conditionals have a problem" << std::endl;
			}

			if (ImGui::Button("COMMIT"))
			{
				species.halfelf_plustwo(abilities, a, b);
				ImGui::CloseCurrentPopup();
				species_picked = true;
			}

			ImGui::EndPopup();
		}

		//SPECIES LIST BOX ENDS HERE
		ImGui::EndListBox();
	}
	//ENDDISABLED MARKER FOR SPECIES LIST BOX
	ImGui::EndDisabled();
}

void ImGuiUtil::ClassList(Abilityscore& abilities, Charclass& chrctr) {
	const char* clss_selec[] =
	{
		" ", "Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"
	};
	static int clss_current_idx = 0;
	static bool clss_picked = false;
	ImGui::BeginDisabled(clss_picked == true);
	ImGui::Text("Class Selection: ");
	if (ImGui::BeginListBox("##listbox_class", ImVec2(425, 0)))
	{
		for (int n = 0; n < IM_ARRAYSIZE(clss_selec); n++)
		{
			const bool is_selected = (clss_current_idx == n);
			if (ImGui::Selectable(clss_selec[n], is_selected))
				clss_current_idx = n;
			if (is_selected)
				ImGui::SetItemDefaultFocus();
			if (ImGui::IsItemClicked(0) && is_selected)
			{
				if (clss_current_idx == 1)
				{
					chrctr.barbarian(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 2)
				{
					chrctr.bard(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 3)
				{
					chrctr.cleric(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 4)
				{
					chrctr.druid(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 5)
				{
					chrctr.fighter(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 6)
				{
					chrctr.monk(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 7)
				{
					chrctr.paladin(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 8)
				{
					chrctr.ranger(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 9)
				{
					chrctr.rogue(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 10)
				{
					chrctr.sorcerer(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 11)
				{
					chrctr.warlock(abilities);
					clss_picked = true;
				}
				else if (clss_current_idx == 12)
				{
					chrctr.wizard(abilities);
					clss_picked = true;
				}
				else {}
			}
		}
		ImGui::EndListBox();
	}
	ImGui::EndDisabled();
}

void ImGuiUtil::LevelUp(Abilityscore& abilities, Charclass& chrctr, int& abscore_total, Invoker* cmt_inv) {
	static int lvl_int = 1;
	// should we make this global?
	//yes
	//int abscore_total = 0; 
	static bool lvl_picked = false;
	ImGui::BeginDisabled(lvl_picked == true);
	ImGui::PushItemWidth(425);
	ImGui::DragInt("##levelselection", &lvl_int, 0.5f, 1, 20, "%d");
	if (ImGui::Button("COMMIT LEVEL SELECTION"))
	{
		chrctr.csumm.level = lvl_int; //is this really necessary?
		chrctr.prof_incr();
		abscore_total = chrctr.ab_upscore();
		lvl_picked = true;
		std::cout << "abscore_total: " << abscore_total << std::endl;
	};
	ImGui::EndDisabled();
	if (abscore_total > 0)
	{
		ImGui::OpenPopup("ABILITY SCORE UPGRADES");
	}
	ImVec2 center = ImGui::GetMainViewport()->GetCenter();
	ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
	if (ImGui::BeginPopupModal("ABILITY SCORE UPGRADES", NULL, ImGuiWindowFlags_AlwaysAutoResize))
	{

		ImGui::Text("Select ability scores to increase");
		ImGui::SameLine();
		HelpMarker("When you reach certain levels, you get to increase your scores in increments of +2 and +1; you cannot increase any ability score beyond level 20 with this feature.");
		bool disable_str_decr = false;
		bool disable_str_incr = false;
		bool disable_dex_decr = false;
		bool disable_dex_incr = false;
		bool disable_con_decr = false;
		bool disable_con_incr = false;
		bool disable_intl_decr = false;
		bool disable_intl_incr = false;
		bool disable_wis_decr = false;
		bool disable_wis_incr = false;
		bool disable_cha_decr = false;
		bool disable_cha_incr = false;

		
		static int str_up = abilities.StrengthScore();
		static int dex_up = abilities.DexterityScore();
		static int con_up = abilities.ConstitutionScore();
		static int intl_up = abilities.IntelligenceScore();
		static int wis_up = abilities.WisdomScore();
		static int cha_up = abilities.CharismaScore();

		//start strength incr/decr here
		//<><><><><><><><><><><><><><><>
		ImGui::Text("Points available: %d", abscore_total);
		ImGui::Text("STR: %d", str_up);
		ImGui::SameLine();
		//if (str_up == abilities.ability_summary.str)
		if (str_up == abilities.StrengthScore())
		{
			disable_str_decr = true;
		}
		ImGui::BeginDisabled(disable_str_decr == true);
		if (ImGui::SmallButton("UNDO##strclr"))
		{
			//int undo = str_up - abilities.ability_summary.str; //obtain the difference between incr score and original score
			int undo = str_up - abilities.StrengthScore();
			abscore_total += undo; //add the difference back to the abscore_total
			str_up -= undo; //return str_up to original value (ability_summary.str)

		}
		//ImGui::SameLine();
		ImGui::EndDisabled();
		ImGui::SameLine();
		if (str_up == 20 || abscore_total == 0)
		{
			disable_str_incr = true;
		}
		ImGui::BeginDisabled(disable_str_incr == true);
		if (ImGui::SmallButton("+2##stri2"))
		{
			str_up += 2;
			abscore_total -= 2;
		}
		ImGui::SameLine();
		if (ImGui::SmallButton("+1##stri1"))
		{
			str_up++;
			abscore_total--;
		}
		ImGui::EndDisabled();

		//<><><><><><><><><>
		//end str incr/decr here

		//<><><><><><><><><><>
		//begin dex incr/decr here
		ImGui::Text("DEX: %d", dex_up);
		ImGui::SameLine();
		//if (dex_up == abilities.ability_summary.dex)
		if (dex_up == abilities.DexterityScore())
		{
			disable_dex_decr = true;
		}
		ImGui::BeginDisabled(disable_dex_decr == true);
		if (ImGui::SmallButton("UNDO##dexclr"))
		{
			//int undo = dex_up - abilities.ability_summary.dex; //obtain the difference between incr score and original score
			int undo = dex_up - abilities.DexterityScore();
			abscore_total += undo; //add the difference back to the abscore_total
			dex_up -= undo; //return str_up to origina value (ability_summary.dex)
		}
		ImGui::EndDisabled();
		ImGui::SameLine();
		if (dex_up == 20 || abscore_total == 0)
		{
			disable_dex_incr = true;
		}
		ImGui::BeginDisabled(disable_dex_incr == true);
		if (ImGui::SmallButton("+2##dexi2"))
		{
			dex_up += 2;
			abscore_total -= 2;
		}
		ImGui::SameLine();
		if (ImGui::SmallButton("+1##dexi1"))
		{
			dex_up++;
			abscore_total--;
		}
		ImGui::EndDisabled();
		//dex incr/decr ends here
		//<><><><><><><><><><><><>

		//<><><><><><><><><><><><>
		//con incr/decr begins here
		ImGui::Text("CON: %d", con_up);
		ImGui::SameLine();
		if (con_up == abilities.ConstitutionScore())
			//if (con_up == abilities.ability_summary.con)
		{
			disable_con_decr = true;
		}
		ImGui::BeginDisabled(disable_con_decr == true);
		if (ImGui::SmallButton("UNDO##conclr"))
		{
			int undo = con_up - abilities.ConstitutionScore();
			//int undo = con_up - abilities.ability_summary.con; //obtain the difference between incr score and original score
			abscore_total += undo; //add the difference back to the abscore_total
			con_up -= undo; //return str_up to original value (ability_summary.con)
		}
		ImGui::EndDisabled();
		ImGui::SameLine();
		if (con_up == 20 || abscore_total == 0)
		{
			disable_con_incr = true;
		}
		ImGui::BeginDisabled(disable_con_incr == true);
		if (ImGui::SmallButton("+2##coni2"))
		{
			con_up += 2;
			abscore_total -= 2;
		}
		ImGui::SameLine();
		if (ImGui::SmallButton("+1##coni1"))
		{
			con_up++;
			abscore_total--;
		}
		ImGui::EndDisabled();
		//con incr/decr ends here
		//<><><><><><><><>

		//<><><><><><><><>
		//intl incr/decr begins here
		ImGui::Text("INT: %d", intl_up);
		ImGui::SameLine();
		if (intl_up == abilities.IntelligenceScore())
			//if (intl_up == abilities.ability_summary.intl)
		{
			disable_intl_decr = true;
		}
		ImGui::BeginDisabled(disable_intl_decr == true);
		if (ImGui::SmallButton("UNDO##intlclr"))
		{
			//int undo = intl_up - abilities.ability_summary.intl; //obtain the difference between incr score and original score
			int undo = intl_up - abilities.IntelligenceScore();
			abscore_total += undo; //add the difference back to the abscore_total
			intl_up -= undo; //return str_up to origina value (ability_summary.dex)
		}
		ImGui::EndDisabled();
		ImGui::SameLine();
		if (intl_up == 20 || abscore_total == 0)
		{
			disable_intl_incr = true;
		}
		ImGui::BeginDisabled(disable_intl_incr == true);
		if (ImGui::SmallButton("+2##intli2"))
		{
			intl_up += 2;
			abscore_total -= 2;
		}
		ImGui::SameLine();
		if (ImGui::SmallButton("+1##intli1"))
		{
			intl_up++;
			abscore_total--;
		}
		ImGui::EndDisabled();
		//intl incr/decr ends here
		//<><><><><><><><><><><><>

		//<><><><><><><><><><><><>
		//wis incr/decr begins here

		ImGui::Text("WIS: %d", wis_up);
		ImGui::SameLine();
		if (wis_up == abilities.WisdomScore())
			//if (wis_up == abilities.ability_summary.wis)
		{
			disable_wis_decr = true;
		}
		ImGui::BeginDisabled(disable_wis_decr == true);
		if (ImGui::SmallButton("UNDO##wisclr"))
		{
			int undo = wis_up - abilities.WisdomScore();
			//int undo = wis_up - abilities.ability_summary.wis; //obtain the difference between incr score and original score
			abscore_total += undo; //add the difference back to the abscore_total
			wis_up -= undo; //return str_up to origina value (ability_summary.dex)
		}
		ImGui::EndDisabled();
		ImGui::SameLine();
		if (wis_up == 20 || abscore_total == 0)
		{
			disable_wis_incr = true;
		}
		ImGui::BeginDisabled(disable_wis_incr == true);
		if (ImGui::SmallButton("+2##wisi2"))
		{
			wis_up += 2;
			abscore_total -= 2;
		}
		ImGui::SameLine();
		if (ImGui::SmallButton("+1##wisi1"))
		{
			wis_up++;
			abscore_total--;
		}
		ImGui::EndDisabled();
		//wis incr/decr ends here
		//<><><><><><><><><><><><><>

		//<><><><><><><><><><><><><>
		//cha incr/decr begins here
		ImGui::Text("CHA: %d", cha_up);
		ImGui::SameLine();
		if (cha_up == abilities.CharismaScore())
		{
			disable_cha_decr = true;
		}
		ImGui::BeginDisabled(disable_cha_decr == true);
		if (ImGui::SmallButton("UNDO##chaclr"))
		{
			int undo = cha_up - abilities.CharismaScore();
			abscore_total += undo; //add the difference back to the abscore_total
			cha_up -= undo; //return str_up to origina value (ability_summary.dex)
		}
		ImGui::EndDisabled();
		ImGui::SameLine();
		if (cha_up == 20 || abscore_total == 0)
		{
			disable_cha_incr = true;
		}
		ImGui::BeginDisabled(disable_cha_incr == true);
		if (ImGui::SmallButton("+2##chai2"))
		{
			cha_up += 2;
			abscore_total -= 2;
		}
		ImGui::SameLine();
		if (ImGui::SmallButton("+1##chai1"))
		{
			cha_up++;
			abscore_total--;
		}
		ImGui::EndDisabled();
		//cha incr/decr ends here
		//<><><><><><><><><><><><><><><><>

		if (ImGui::Button("COMMIT SCORE INCREASES"))
		{
			abilities.clr_init();
			abilities.pushback_init(str_up);
			abilities.pushback_init(dex_up);
			abilities.pushback_init(con_up);
			abilities.pushback_init(intl_up);
			abilities.pushback_init(wis_up);
			abilities.pushback_init(cha_up);
			cmt_inv->invoke();
			ImGui::CloseCurrentPopup();
		}


		ImGui::EndPopup();

	}
}

void ImGuiUtil::ScoreDisplay(Abilityscore& abilities)
{
	ImGui::NextColumn();
	ImGui::Text("Strength:      %d", abilities.StrengthScore());
	ImGui::SameLine();
	ImGui::Text(" + (%d)", abilities.StrAbm());
	ImGui::Spacing();
	ImGui::Text("Dexterity:     %d", abilities.DexterityScore());
	ImGui::SameLine();
	ImGui::Text(" + (%d)", abilities.DexAbm());
	ImGui::Spacing();
	ImGui::Text("Constitution:  %d", abilities.ConstitutionScore());
	ImGui::SameLine();
	ImGui::Text(" + (%d)", abilities.ConAbm());
	ImGui::Spacing();
	ImGui::Text("Intelligence:  %d", abilities.IntelligenceScore());
	ImGui::SameLine();
	ImGui::Text(" + (%d)", abilities.IntAbm());
	ImGui::Spacing();
	ImGui::Text("Wisdom:        %d", abilities.WisdomScore());
	ImGui::SameLine();
	ImGui::Text(" + (%d)", abilities.WisAbm());
	ImGui::Spacing();
	ImGui::Text("Charisma:      %d", abilities.CharismaScore());
	ImGui::SameLine();
	ImGui::Text(" + (%d)", abilities.ChaAbm());
	ImGui::Spacing();
	ImGui::Text("Armor Class (AC): %d", abilities.ArmorClass());
	ImGui::SameLine();
}

void ImGuiUtil::Update(int& abscore_total, bool mode, bool is_commit_clicked, Abilityscore& abilities, Species species, 
	Charclass& chrctr, Invoker res_inv, Invoker clr_inv, Invoker roll_inv, Invoker cmt_inv, ImGuiUtil util) {

	if (mode == true) {
		ImGui::ShowDemoWindow();
	}

	ImGui::Begin("Character Builder Console", nullptr, ImGuiWindowFlags_NoCollapse);
	ImGui::Columns(3);
	ImGui::SetColumnOffset(1, 600);

	static bool press_to_roll = false;
	static int three_rollctr = 0;
	static bool dm_roll_override = false; //for checkbox allowing user to roll as many times as they wish (DM mode)
	static bool three_rolls = false; //disables the roll button after three rolls
	static bool disabled_marker = false;
	static bool hstgrm_dm = false;

	//for undo experimentation, HistoUndo
	static bool swap_disabled = false;

	if (ImGui::BeginMenuBar) {
		if (ImGui::SmallButton("<< UNDO")) {
			std::cout << "<< pressed" << std::endl;
			HistoUndo(swap_disabled, three_rolls, three_rollctr, abilities);
			std::cout << "undo three roll ctr: " << three_rollctr << std::endl;
		}
		ImGui::SameLine();
		if (ImGui::SmallButton("REDO >>")) {
			std::cout << ">> pressed" << std::endl;
		}
	}

	//ImGui::Checkbox("DM Override", &dm_roll_override);
	//ImGui::SameLine();
	//HelpMarker("EXPERIMENTAL: Check the box here to roll more than 3x and get access to previous disabled sections.  Please consult your DM before checking this box, as unlimited score rolling can give an unfair ability score advantage to players!");
	//ImGui::BeginDisabled(dm_roll_override == false);
	/*
	if (ImGui::Button("Resort Scores?"))
	{
		res_inv.invoke();
	}
	ImGui::SameLine();
	HelpMarker("Resorts your rolled scores from left to right, highest to lowest");
	ImGui::SameLine();
	if (ImGui::Button("Clear Scores?"))
	{
		hstgrm_dm = true;
		clr_inv.invoke();
	}
	ImGui::SameLine();
	HelpMarker("Deletes your current scores so you can roll them again");
	ImGui::SameLine();
	if (ImGui::Button("Select New Species?"))
	{

	}
	ImGui::SameLine();
	HelpMarker("Select a different species to play");
	if (ImGui::Button("Select New Class?"))
	{

	}
	ImGui::SameLine();
	HelpMarker("Select a different class to play");
	ImGui::EndDisabled();
	*/
	ImGui::BeginDisabled(disabled_marker);
	//if (dm_roll_override == false && three_rolls == true)
	if (three_rolls == true)
	{
		disabled_marker = true;
	}
	if (three_rolls == false)
	{
		disabled_marker = false;
	}
	/*
	if (dm_roll_override == true)
	{
		disabled_marker = false;
	}
	*/
	ImGui::Spacing();
	
	if (ImGui::Button("PRESS TO ROLL"))
	{
		press_to_roll = true;
		three_rollctr++;
		std::cout << "counter: " << three_rollctr << std::endl;
	}
	ImGui::SameLine();
	HelpMarker("Press the 'PRESS TO ROLL' button to automatically generate a random spread of scores for your abilities.  You can roll up to three times.");

	if (press_to_roll == true)
	{
		
		roll_inv.invoke();
		press_to_roll = false;
	}
	//if (three_rollctr == 3 && dm_roll_override == false)
	if (three_rollctr == 3)
	{
		three_rolls = true;
	}
	ImGui::EndDisabled();


	ImGui::Text("Ability Scores");
	
	//static bool swap_disabled = false;
	util.Histogram(abilities, swap_disabled);
	/*
	if (dm_roll_override == true)
	{
		is_commit_clicked = false;
		swap_disabled = false;
	}
	*/
	ImGui::BeginDisabled(is_commit_clicked);
	if (ImGui::Button("COMMIT SCORE ROLL"))
	{
		cmt_inv.invoke();
		
		is_commit_clicked = true;
		swap_disabled = true;
	}
	ImGui::EndDisabled();

	ImGui::Spacing();



	ImGui::NextColumn();
	util.SpeciesList(abilities, species);

	util.ClassList(abilities, chrctr);
	
	ImGui::Text("Level Selection: ");
	ImGui::SameLine();
	HelpMarker("You can click and drag to desired level, or double click to enter manually");
	util.LevelUp(abilities, chrctr, abscore_total, &cmt_inv);
	util.ScoreDisplay(abilities);
	
	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	ImGui::End();
	
}

void ImGuiUtil::Render() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiUtil::Shutdown() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}