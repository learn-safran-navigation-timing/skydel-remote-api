
#include "GetPulsarX5AccuracyIntegrityForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPulsarX5AccuracyIntegrityForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPulsarX5AccuracyIntegrityForSV::CmdName = "GetPulsarX5AccuracyIntegrityForSV";
    const char* const GetPulsarX5AccuracyIntegrityForSV::Documentation = "Get PULSAR X5 Accuracy Integrity Flag (Accuracy Integrity of X5 Signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPulsarX5AccuracyIntegrityForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPulsarX5AccuracyIntegrityForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPulsarX5AccuracyIntegrityForSV);


    GetPulsarX5AccuracyIntegrityForSV::GetPulsarX5AccuracyIntegrityForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPulsarX5AccuracyIntegrityForSV::GetPulsarX5AccuracyIntegrityForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetPulsarX5AccuracyIntegrityForSVPtr GetPulsarX5AccuracyIntegrityForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX5AccuracyIntegrityForSV>(svId, dataSetName);
    }

    GetPulsarX5AccuracyIntegrityForSVPtr GetPulsarX5AccuracyIntegrityForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPulsarX5AccuracyIntegrityForSV>(ptr);
    }

    bool GetPulsarX5AccuracyIntegrityForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPulsarX5AccuracyIntegrityForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPulsarX5AccuracyIntegrityForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetPulsarX5AccuracyIntegrityForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetPulsarX5AccuracyIntegrityForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPulsarX5AccuracyIntegrityForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetPulsarX5AccuracyIntegrityForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPulsarX5AccuracyIntegrityForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
