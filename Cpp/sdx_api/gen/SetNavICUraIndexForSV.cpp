
#include "SetNavICUraIndexForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICUraIndexForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICUraIndexForSV::CmdName = "SetNavICUraIndexForSV";
    const char* const SetNavICUraIndexForSV::Documentation = "Set the URA index of a NavIC satellite\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.\n"
      "Urai        int             URA index.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICUraIndexForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICUraIndexForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICUraIndexForSV);


    SetNavICUraIndexForSV::SetNavICUraIndexForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICUraIndexForSV::SetNavICUraIndexForSV(int svId, int urai, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setUrai(urai);
      setDataSetName(dataSetName);
    }

    SetNavICUraIndexForSVPtr SetNavICUraIndexForSV::create(int svId, int urai, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICUraIndexForSV>(svId, urai, dataSetName);
    }

    SetNavICUraIndexForSVPtr SetNavICUraIndexForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICUraIndexForSV>(ptr);
    }

    bool SetNavICUraIndexForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Urai"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICUraIndexForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICUraIndexForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Urai", "DataSetName"}; 
      return names; 
    }


    int SetNavICUraIndexForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetNavICUraIndexForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICUraIndexForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetNavICUraIndexForSV::urai() const
    {
      return parse_json<int>::parse(m_values["Urai"]);
    }

    void SetNavICUraIndexForSV::setUrai(int urai)
    {
      m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetNavICUraIndexForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICUraIndexForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
