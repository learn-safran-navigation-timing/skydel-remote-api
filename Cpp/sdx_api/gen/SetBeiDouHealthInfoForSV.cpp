
#include "SetBeiDouHealthInfoForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouHealthInfoForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouHealthInfoForSV::CmdName = "SetBeiDouHealthInfoForSV";
    const char* const SetBeiDouHealthInfoForSV::Documentation = "Set BeiDou satellite health info\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
      "Health      int             Health Info, 9-bit integer : 0, 2, 64, 66, 128, 130, 192, 194, 256 or 511\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouHealthInfoForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouHealthInfoForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouHealthInfoForSV);


    SetBeiDouHealthInfoForSV::SetBeiDouHealthInfoForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouHealthInfoForSV::SetBeiDouHealthInfoForSV(int svId, int health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetBeiDouHealthInfoForSVPtr SetBeiDouHealthInfoForSV::create(int svId, int health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouHealthInfoForSV>(svId, health, dataSetName);
    }

    SetBeiDouHealthInfoForSVPtr SetBeiDouHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouHealthInfoForSV>(ptr);
    }

    bool SetBeiDouHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouHealthInfoForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouHealthInfoForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetBeiDouHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouHealthInfoForSV::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void SetBeiDouHealthInfoForSV::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetBeiDouHealthInfoForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouHealthInfoForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
