
#include "SetQzssUraIndex.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssUraIndex
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssUraIndex::CmdName = "SetQzssUraIndex";
    const char* const SetQzssUraIndex::Documentation = "Please note the command SetQzssUraIndex is deprecated since 21.3. You may use SetQzssUraIndexForSV.\n"
      "\n"
      "Set the URA index of a QZSS satellite\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.\n"
      "Urai        int             URA index.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetQzssUraIndex::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetQzssUraIndex);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetQzssUraIndex);


    SetQzssUraIndex::SetQzssUraIndex()
      : CommandBase(CmdName, TargetId)
    {}

    SetQzssUraIndex::SetQzssUraIndex(int svId, int urai, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setUrai(urai);
      setDataSetName(dataSetName);
    }

    SetQzssUraIndexPtr SetQzssUraIndex::create(int svId, int urai, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetQzssUraIndex>(svId, urai, dataSetName);
    }

    SetQzssUraIndexPtr SetQzssUraIndex::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssUraIndex>(ptr);
    }

    bool SetQzssUraIndex::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Urai"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetQzssUraIndex::documentation() const { return Documentation; }

    const std::vector<std::string>& SetQzssUraIndex::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Urai", "DataSetName"}; 
      return names; 
    }


    int SetQzssUraIndex::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetQzssUraIndex::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssUraIndex::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetQzssUraIndex::urai() const
    {
      return parse_json<int>::parse(m_values["Urai"]);
    }

    void SetQzssUraIndex::setUrai(int urai)
    {
      m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetQzssUraIndex::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetQzssUraIndex::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
