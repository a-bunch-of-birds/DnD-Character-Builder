#include "command.h"
#include "abilityscore.h"


void RollComm::Execute() const {
	objptr->sextuple_score();
	std::cout << "RollComm -> Execute() -> receiver.sextuple_score()" << std::endl;
};

void ResortComm::Execute() const {
	objptr->resort_init_scores();
	std::cout << "ResortComm -> Execute() -> receiver.resort_init_scores()" << std::endl;
}

void ClrComm::Execute() const {
	objptr->clear_init_scores();
	std::cout << "ClrComm -> Execute() -> receiver.clear_init_scores()" << std::endl;
}

void CommitRollComm::Execute() const {
	objptr->commit_scores();
	std::cout << "CommitRollComm -> Execute() -> receiver.commit_scores()" << std::endl;
}

/*
void CommitLvlComm::Execute() const {
	objptr->clr_init();
	objptr->pushback_init(str_up);
	objptr->pushback_init(dex_up);
	objptr->pushback_init(con_up);
	objptr->pushback_init(intl_up);
	objptr->pushback_init(wis_up);
	objptr->pushback_init(cha_up);
}
*/

void Invoker::invoke() {
	cmd->Execute();
}
