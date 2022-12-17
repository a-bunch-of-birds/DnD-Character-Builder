#ifndef COMMAND_H
#define COMMAND_H

#include "abilityscore.h"

class IComm {
private:

public:
	virtual ~IComm() {}
	virtual void Execute() const = 0;
};

class RollComm : public IComm {
private:
	Abilityscore* objptr;
public:
	RollComm(Abilityscore* receiver) : objptr(receiver) {}
	void Execute() const override;
};

class ResortComm : public IComm {
private:
	Abilityscore* objptr;
public:
	ResortComm(Abilityscore* receiver) : objptr(receiver) {}
	void Execute() const override;
};

class ClrComm : public IComm {
private:
	Abilityscore* objptr;
public:
	ClrComm(Abilityscore* receiver) : objptr(receiver) {}
	void Execute() const override;
};

class CommitRollComm : public IComm {
private:
	Abilityscore* objptr;
public:
	CommitRollComm(Abilityscore* receiver) : objptr(receiver) {}
	void Execute() const override;
};

/*
class CommitLvlComm : public IComm {
private:
	Abilityscore* objptr;
public:
	CommitLvlComm(Abilityscore* receiver) : objptr(receiver) {}
	void Execute() const override;
};
*/

class Invoker {
private:
	IComm* cmd;
public:
	Invoker(IComm* icommand) : cmd(icommand) {}
	~Invoker() {}
	void invoke();
};

#endif COMMAND_H