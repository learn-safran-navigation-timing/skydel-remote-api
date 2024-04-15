
#include "SetBeiDouUraIndexForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouUraIndexForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouUraIndexForSV::CmdName = "SetBeiDouUraIndexForSV";
    const char* const SetBeiDouUraIndexForSV::Documentation = "Set the ura index of a BeiDou satellite\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.\n"
      "Urai        int             URA index.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetBeiDouUraIndexForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetBeiDouUraIndexForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetBeiDouUraIndexForSV);


    SetBeiDouUraIndexForSV::SetBeiDouUraIndexForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetBeiDouUraIndexForSV::SetBeiDouUraIndexForSV(int svId, int urai, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setUrai(urai);
      setDataSetName(dataSetName);
    }

    SetBeiDouUraIndexForSVPtr SetBeiDouUraIndexForSV::create(int svId, int urai, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouUraIndexForSV>(svId, urai, dataSetName);
    }

    SetBeiDouUraIndexForSVPtr SetBeiDouUraIndexForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouUraIndexForSV>(ptr);
    }

    bool SetBeiDouUraIndexForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Urai"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouUraIndexForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetBeiDouUraIndexForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Urai", "DataSetName"}; 
      return names; 
    }


    int SetBeiDouUraIndexForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetBeiDouUraIndexForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouUraIndexForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetBeiDouUraIndexForSV::urai() const
    {
      return parse_json<int>::parse(m_values["Urai"]);
    }

    void SetBeiDouUraIndexForSV::setUrai(int urai)
    {
      m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouUraIndexForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouUraIndexForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
