
#include "GetPulsarX1AccuracyIntegrityForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPulsarX1AccuracyIntegrityForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPulsarX1AccuracyIntegrityForSV::CmdName = "GetPulsarX1AccuracyIntegrityForSV";
    const char* const GetPulsarX1AccuracyIntegrityForSV::Documentation = "Get PULSAR X1 Accuracy Integrity Flag (Accuracy Integrity of X1 Signal)\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetPulsarX1AccuracyIntegrityForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPulsarX1AccuracyIntegrityForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPulsarX1AccuracyIntegrityForSV);


    GetPulsarX1AccuracyIntegrityForSV::GetPulsarX1AccuracyIntegrityForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPulsarX1AccuracyIntegrityForSV::GetPulsarX1AccuracyIntegrityForSV(int svId, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetPulsarX1AccuracyIntegrityForSVPtr GetPulsarX1AccuracyIntegrityForSV::create(int svId, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetPulsarX1AccuracyIntegrityForSV>(svId, dataSetName);
    }

    GetPulsarX1AccuracyIntegrityForSVPtr GetPulsarX1AccuracyIntegrityForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPulsarX1AccuracyIntegrityForSV>(ptr);
    }

    bool GetPulsarX1AccuracyIntegrityForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetPulsarX1AccuracyIntegrityForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPulsarX1AccuracyIntegrityForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "DataSetName"}; 
      return names; 
    }


    int GetPulsarX1AccuracyIntegrityForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetPulsarX1AccuracyIntegrityForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPulsarX1AccuracyIntegrityForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetPulsarX1AccuracyIntegrityForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetPulsarX1AccuracyIntegrityForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
