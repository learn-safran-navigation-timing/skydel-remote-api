
#include "SetQzssUraIndexForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssUraIndexForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssUraIndexForSV::CmdName = "SetQzssUraIndexForSV";
    const char* const SetQzssUraIndexForSV::Documentation = "Set the URA index of a QZSS satellite\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.\n"
      "Urai        int             URA index.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssUraIndexForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssUraIndexForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssUraIndexForSV);


    SetQzssUraIndexForSV::SetQzssUraIndexForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssUraIndexForSV::SetQzssUraIndexForSV(int svId, int urai, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setUrai(urai);
      setDataSetName(dataSetName);
    }

    SetQzssUraIndexForSVPtr SetQzssUraIndexForSV::create(int svId, int urai, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssUraIndexForSV>(svId, urai, dataSetName);
    }

    SetQzssUraIndexForSVPtr SetQzssUraIndexForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssUraIndexForSV>(ptr);
    }

    bool SetQzssUraIndexForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Urai"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssUraIndexForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssUraIndexForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Urai", "DataSetName"}; 
      return names; 
    }


    int SetQzssUraIndexForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetQzssUraIndexForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssUraIndexForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetQzssUraIndexForSV::urai() const
    {
      return parse_json<int>::parse(m_values["Urai"]);
    }

    void SetQzssUraIndexForSV::setUrai(int urai)
    {
      m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetQzssUraIndexForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssUraIndexForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
