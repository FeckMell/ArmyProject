#pragma once
#include "stdafx.h"
#include "Interfaces/STR.h"

class ValStoreTree
{
private:

	class ValStoreTreeEntry
	{
	private:

		std::string thatName;
		std::string thatData;
		std::map<std::string, ValStoreTreeEntry> thatDataTree;

	public:
		///**/void SetName(string name_) { thatName = name_; }
		/**/std::string NodeName() { return thatName; }
		std::string ToString(std::string path_);
		std::string PrintAll(unsigned lvl_);

		ValStoreTreeEntry() {}
		ValStoreTreeEntry(std::string name_);

		std::string Val(std::vector<std::string> name_, unsigned& lvl_);
		void SetVal(std::vector<std::string> name_, unsigned& lvl_, std::string val_);
		void DelVal(std::vector<std::string> name_, unsigned& lvl_);

		ValStoreTreeEntry ValSubTree(std::vector<std::string> name_, unsigned& lvl_);
		void SetValSubTree(std::vector<std::string> name_, unsigned& lvl_, ValStoreTreeEntry val_);
		void DelValSubTree(std::vector<std::string> name_, unsigned& lvl_);

		std::map<std::string, ValStoreTreeEntry> ChildNodes(std::vector<std::string> name_, unsigned& lvl_);
		std::vector<std::string> ChildNodesNames(std::vector<std::string> name_, unsigned& lvl_);

	};

	std::map<std::string, ValStoreTreeEntry> thatDataTree;

public:

	std::string ToString();
	std::string PrintAll();
	ValStoreTree() {}

	std::string Val(std::string name_);
	void SetVal(std::string name_, std::string val_);
	void DelVal(std::string name_);

	ValStoreTree ValSubTree(std::string name_);
	void SetValSubTree(std::string name_, ValStoreTree val_);
	void DelValSubTree(std::string name_);

};

