
#include "SetBeiDouCNavHealthInfoForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouCNavHealthInfoForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouCNavHealthInfoForSV::CmdName = "SetBeiDouCNavHealthInfoForSV";
    const char* const SetBeiDouCNavHealthInfoForSV::Documentation = "Set BeiDou CNav satellite health info\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "Health      int             Health Info, 8-bit integer : 0, 32, 64, 96, 128 or 255\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouCNavHealthInfoForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouCNavHealthInfoForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouCNavHealthInfoForSV);


    SetBeiDouCNavHealthInfoForSV::SetBeiDouCNavHealthInfoForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouCNavHealthInfoForSV::SetBeiDouCNavHealthInfoForSV(int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetBeiDouCNavHealthInfoForSVPtr SetBeiDouCNavHealthInfoForSV::create(int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouCNavHealthInfoForSV>(svId, health, dataSetName);
    }

    SetBeiDouCNavHealthInfoForSVPtr SetBeiDouCNavHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouCNavHealthInfoForSV>(ptr);
    }

    bool SetBeiDouCNavHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouCNavHealthInfoForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouCNavHealthInfoForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetBeiDouCNavHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouCNavHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouCNavHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouCNavHealthInfoForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouCNavHealthInfoForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouCNavHealthInfoForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouCNavHealthInfoForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
