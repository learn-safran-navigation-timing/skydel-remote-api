
#include "GetSbasDegradationParametersResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasDegradationParametersResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasDegradationParametersResult::CmdName = "GetSbasDegradationParametersResult";
    const char* const GetSbasDegradationParametersResult::Documentation = "Result of GetSbasDegradationParameters.\n"
      "\n"
      "Name                          Type               Description\n"
      "----------------------------- ------------------ -----------------------------------------------------------------------------------------\n"
      "ServiceProvider               string             Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\", \"BDSBAS\" and \"KASS\".\n"
      "DegradationParameterValueDict dict string:double A dictionary of degradationparameter value pairs.\n"
      "                                                 Accepted keys are: \"BRRC\", \"CLTC_LSB\", \"CLTC_V1\", \"ILTC_V1\", \"CLTC_V0\",\n"
      "                                                                    \"ILTC_V0\", \"CGEO_LSB\", \"CGEO_V\", \"IGEO\", \"CER\", \"CIONO_STEP\",\n"
      "                                                                    \"IIONO\", \"CIONO_RAMP\", \"RSSUDRE\", \"RSSIONO\" and \"CCOVARIANCE\"";
    const char* const GetSbasDegradationParametersResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasDegradationParametersResult);


    GetSbasDegradationParametersResult::GetSbasDegradationParametersResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSbasDegradationParametersResult::GetSbasDegradationParametersResult(const std::string& serviceProvider, const std::map<std::string, double>& degradationParameterValueDict)
      : CommandResult(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setDegradationParameterValueDict(degradationParameterValueDict);
    }

    GetSbasDegradationParametersResult::GetSbasDegradationParametersResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, const std::map<std::string, double>& degradationParameterValueDict)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setServiceProvider(serviceProvider);
      setDegradationParameterValueDict(degradationParameterValueDict);
    }


    GetSbasDegradationParametersResultPtr GetSbasDegradationParametersResult::create(const std::string& serviceProvider, const std::map<std::string, double>& degradationParameterValueDict)
    {
      return std::make_shared<GetSbasDegradationParametersResult>(serviceProvider, degradationParameterValueDict);
    }

    GetSbasDegradationParametersResultPtr GetSbasDegradationParametersResult::create(CommandBasePtr relatedCommand, const std::string& serviceProvider, const std::map<std::string, double>& degradationParameterValueDict)
    {
      return std::make_shared<GetSbasDegradationParametersResult>(relatedCommand, serviceProvider, degradationParameterValueDict);
    }

    GetSbasDegradationParametersResultPtr GetSbasDegradationParametersResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasDegradationParametersResult>(ptr);
    }

    bool GetSbasDegradationParametersResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["DegradationParameterValueDict"])
        ;

    }

    std::string GetSbasDegradationParametersResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasDegradationParametersResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "DegradationParameterValueDict"}; 
      return names; 
    }


    std::string GetSbasDegradationParametersResult::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasDegradationParametersResult::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> GetSbasDegradationParametersResult::degradationParameterValueDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["DegradationParameterValueDict"]);
    }

    void GetSbasDegradationParametersResult::setDegradationParameterValueDict(const std::map<std::string, double>& degradationParameterValueDict)
    {
      m_values.AddMember("DegradationParameterValueDict", parse_json<std::map<std::string, double>>::format(degradationParameterValueDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
