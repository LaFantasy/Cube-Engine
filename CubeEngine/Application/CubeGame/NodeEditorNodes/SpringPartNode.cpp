#include "ControlPartNode.h"
#include "CubeGame/BearPart.h"
#include "SpringPartNode.h"
#include "CubeGame/SpringPart.h"

namespace tzw
{
	SpringPartNode::SpringPartNode(SpringPart * part)
	{
		m_part = part;
		SpringPartNode::syncName();
	}

	void SpringPartNode::privateDraw()
	{
		handleNameEdit();
		float stiffness, damping;
		stiffness = m_part->getStiffness();
		damping = m_part->getDamping();
		bool isInputStiffness = false, isInputDamping = false;
		isInputStiffness = ImGui::InputFloat(u8"����ϵ��", &stiffness);
		if(isInputStiffness)
		{
			m_part->setStiffness(stiffness);
		}
		isInputDamping = ImGui::InputFloat(u8"����", &damping);
		if(isInputDamping)
		{
			m_part->setStiffness(damping);
		}
	}

	GamePart* SpringPartNode::getProxy()
	{
		return m_part;
	}

	void SpringPartNode::onLinkOut(int startID, int endID, GameNodeEditorNode* other)
	{
		
	}

	void SpringPartNode::load(rapidjson::Value& partData)
	{
	}

	void SpringPartNode::dump(rapidjson::Value& partDocObj, rapidjson::Document::AllocatorType& allocator)
	{
		partDocObj.AddMember("Type", std::string("Resource"), allocator);
		partDocObj.AddMember("ResType", std::string("SpringPart"), allocator);
		partDocObj.AddMember("ResUID", std::string(m_part->getGUID()), allocator);
		partDocObj.AddMember("UID", std::string(getGUID()), allocator);
	}

	void SpringPartNode::syncName()
	{
		char formatName[512];
		sprintf_s(formatName, 512, u8"���� %s",m_part->getName().c_str());
		name = formatName;
	}
}
