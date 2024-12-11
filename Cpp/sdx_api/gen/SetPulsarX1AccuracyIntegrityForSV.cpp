
#include "SetPulsarX1AccuracyIntegrityForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPulsarX1AccuracyIntegrityForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPulsarX1AccuracyIntegrityForSV::CmdName = "SetPulsarX1AccuracyIntegrityForSV";
    const char* const SetPulsarX1AccuracyIntegrityForSV::Documentation = "Set PULSAR X1 Accuracy Integrity Flag (Accuracy Integrity of X1 Signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ---------------------------------------------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "Health      bool            X1 accuracy integrity, false = User Range Error exceeds alarm threshold, true = User Range Error does not exceed alarm threshold.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetPulsarX1AccuracyIntegrityForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPulsarX1AccuracyIntegrityForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPulsarX1AccuracyIntegrityForSV);


    SetPulsarX1AccuracyIntegrityForSV::SetPulsarX1AccuracyIntegrityForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetPulsarX1AccuracyIntegrityForSV::SetPulsarX1AccuracyIntegrityForSV(int svId, bool health, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    SetPulsarX1AccuracyIntegrityForSVPtr SetPulsarX1AccuracyIntegrityForSV::create(int svId, bool health, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetPulsarX1AccuracyIntegrityForSV>(svId, health, dataSetName);
    }

    SetPulsarX1AccuracyIntegrityForSVPtr SetPulsarX1AccuracyIntegrityForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPulsarX1AccuracyIntegrityForSV>(ptr);
    }

    bool SetPulsarX1AccuracyIntegrityForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetPulsarX1AccuracyIntegrityForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPulsarX1AccuracyIntegrityForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
      return names; 
    }


    int SetPulsarX1AccuracyIntegrityForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetPulsarX1AccuracyIntegrityForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPulsarX1AccuracyIntegrityForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetPulsarX1AccuracyIntegrityForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetPulsarX1AccuracyIntegrityForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> SetPulsarX1AccuracyIntegrityForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetPulsarX1AccuracyIntegrityForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
