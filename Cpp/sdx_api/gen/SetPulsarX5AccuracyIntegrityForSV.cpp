
#include "SetPulsarX5AccuracyIntegrityForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPulsarX5AccuracyIntegrityForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPulsarX5AccuracyIntegrityForSV::CmdName = "SetPulsarX5AccuracyIntegrityForSV";
    const char* const SetPulsarX5AccuracyIntegrityForSV::Documentation = "Set PULSAR X5 Accuracy Integrity Flag (Accuracy Integrity of X5 Signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ---------------------------------------------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "Health      bool            X5 accuracy integrity, false = User Range Error exceeds alarm threshold, true = User Range Error does not exceed alarm threshold.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetPulsarX5AccuracyIntegrityForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPulsarX5AccuracyIntegrityForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPulsarX5AccuracyIntegrityForSV);


    SetPulsarX5AccuracyIntegrityForSV::SetPulsarX5AccuracyIntegrityForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetPulsarX5AccuracyIntegrityForSV::SetPulsarX5AccuracyIntegrityForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetPulsarX5AccuracyIntegrityForSVPtr SetPulsarX5AccuracyIntegrityForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetPulsarX5AccuracyIntegrityForSV>(svId, health, dataSetName);
    }

    SetPulsarX5AccuracyIntegrityForSVPtr SetPulsarX5AccuracyIntegrityForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPulsarX5AccuracyIntegrityForSV>(ptr);
    }

    bool SetPulsarX5AccuracyIntegrityForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetPulsarX5AccuracyIntegrityForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPulsarX5AccuracyIntegrityForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetPulsarX5AccuracyIntegrityForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetPulsarX5AccuracyIntegrityForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPulsarX5AccuracyIntegrityForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetPulsarX5AccuracyIntegrityForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetPulsarX5AccuracyIntegrityForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetPulsarX5AccuracyIntegrityForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetPulsarX5AccuracyIntegrityForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
