
#include "SetSbasDegradationParameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasDegradationParameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasDegradationParameters::CmdName = "SetSbasDegradationParameters";
    const char* const SetSbasDegradationParameters::Documentation = "Set the SBAS degradation parameters for the specified service provider.\n"
      "\n"
      "Name                          Type               Description\n"
      "----------------------------- ------------------ -----------------------------------------------------------------------------------------\n"
      "ServiceProvider               string             Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\", \"BDSBAS\" and \"KASS\".\n"
      "DegradationParameterValueDict dict string:double A dictionary of degradationparameter value pairs.\n"
      "                                                 Accepted keys are: \"BRRC\", \"CLTC_LSB\", \"CLTC_V1\", \"ILTC_V1\", \"CLTC_V0\",\n"
      "                                                                    \"ILTC_V0\", \"CGEO_LSB\", \"CGEO_V\", \"IGEO\", \"CER\", \"CIONO_STEP\",\n"
      "                                                                    \"IIONO\", \"CIONO_RAMP\", \"RSSUDRE\", \"RSSIONO\" and \"CCOVARIANCE\"";
    const char* const SetSbasDegradationParameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasDegradationParameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasDegradationParameters);


    SetSbasDegradationParameters::SetSbasDegradationParameters()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasDegradationParameters::SetSbasDegradationParameters(const std::string& serviceProvider, const std::map<std::string, double>& degradationParameterValueDict)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setDegradationParameterValueDict(degradationParameterValueDict);
    }

    SetSbasDegradationParametersPtr SetSbasDegradationParameters::create(const std::string& serviceProvider, const std::map<std::string, double>& degradationParameterValueDict)
    {
      return std::make_shared<SetSbasDegradationParameters>(serviceProvider, degradationParameterValueDict);
    }

    SetSbasDegradationParametersPtr SetSbasDegradationParameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasDegradationParameters>(ptr);
    }

    bool SetSbasDegradationParameters::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<std::map<std::string, double>>::is_valid(m_values["DegradationParameterValueDict"])
        ;

    }

    std::string SetSbasDegradationParameters::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasDegradationParameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "DegradationParameterValueDict"}; 
      return names; 
    }


    int SetSbasDegradationParameters::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSbasDegradationParameters::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void SetSbasDegradationParameters::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, double> SetSbasDegradationParameters::degradationParameterValueDict() const
    {
      return parse_json<std::map<std::string, double>>::parse(m_values["DegradationParameterValueDict"]);
    }

    void SetSbasDegradationParameters::setDegradationParameterValueDict(const std::map<std::string, double>& degradationParameterValueDict)
    {
      m_values.AddMember("DegradationParameterValueDict", parse_json<std::map<std::string, double>>::format(degradationParameterValueDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
