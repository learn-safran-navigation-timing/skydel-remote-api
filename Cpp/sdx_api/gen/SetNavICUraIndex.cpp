
#include "SetNavICUraIndex.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICUraIndex
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICUraIndex::CmdName = "SetNavICUraIndex";
    const char* const SetNavICUraIndex::Documentation = "Please note the command SetNavICUraIndex is deprecated since 21.3. You may use SetNavICUraIndexForSV.\n"
      "\n"
      "Set the URA index of a NavIC satellite\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.\n"
      "Urai        int             URA index.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICUraIndex::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICUraIndex);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICUraIndex);


    SetNavICUraIndex::SetNavICUraIndex()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICUraIndex::SetNavICUraIndex(int svId, int urai, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setUrai(urai);
      setDataSetName(dataSetName);
    }

    SetNavICUraIndexPtr SetNavICUraIndex::create(int svId, int urai, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICUraIndex>(svId, urai, dataSetName);
    }

    SetNavICUraIndexPtr SetNavICUraIndex::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICUraIndex>(ptr);
    }

    bool SetNavICUraIndex::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Urai"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICUraIndex::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICUraIndex::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Urai", "DataSetName"}; 
      return names; 
    }


    int SetNavICUraIndex::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetNavICUraIndex::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICUraIndex::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetNavICUraIndex::urai() const
    {
      return parse_json<int>::parse(m_values["Urai"]);
    }

    void SetNavICUraIndex::setUrai(int urai)
    {
      m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetNavICUraIndex::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICUraIndex::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
